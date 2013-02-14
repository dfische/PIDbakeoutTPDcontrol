#include "serialdebugbuffer.h"

serialDebugBuffer::serialDebugBuffer(QObject *parent) :
    QAbstractListModel(parent),
    maxEntries(1000)
{
}

int serialDebugBuffer::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return buffer.size() ;
}

int serialDebugBuffer::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3 ;
}

QVariant serialDebugBuffer::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant() ;
    if (orientation == Qt::Vertical) return section ; // row number
    switch(section)
    {
    case 1:
        return "String" ;
    case 2:
        return "Hex Representation" ;
    }
    return QVariant() ;
}

QVariant serialDebugBuffer::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole) return QVariant() ;
    if (index.row() < 0 || index.row() >= buffer.size()) return QVariant() ;
    switch(index.column())
    {
    case 0:
        return buffer[index.row()].first ? QString("in") : QString("out") ;
    case 1:
        return QString(buffer[index.row()].second) ;
    case 2:
        return QString(hexRepresentation(buffer[index.row()].second)) ;
    }
    return QVariant() ;
}

QString serialDebugBuffer::hexRepresentation(const QByteArray &ba) const
{
    QString result(ba.toHex()) ;
    QString split ;
    for (int i = 0 ; i < result.size() ; i += 2)
        split += result.mid(i,2) += " " ;
    return split ;
}

void serialDebugBuffer::addIncomingEntry(const QByteArray &ba)
{
    addEntry(ba, true) ;
}

void serialDebugBuffer::addOutgoingEntry(const QByteArray &ba)
{
    addEntry(ba, false) ;
}

void serialDebugBuffer::addEntry(const QByteArray & ba, bool in)
{
    beginInsertRows(QModelIndex(),buffer.size(),buffer.size()) ;
    buffer << qMakePair(in, ba) ;
    endInsertRows();
    setMaxEntries(maxEntries);
}

void serialDebugBuffer::setMaxEntries(int num)
{
    maxEntries = num ;
    while (buffer.size() > maxEntries)
    {
        beginRemoveRows(QModelIndex(), 0,0);
        buffer.takeFirst() ;
        endRemoveRows();
    }
}
