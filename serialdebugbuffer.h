#ifndef SERIALDEBUGBUFFER_H
#define SERIALDEBUGBUFFER_H

#include <QAbstractListModel>
#include <QList>
#include <QByteArray>
#include <QPair>

class serialDebugBuffer : public QAbstractListModel
{
    Q_OBJECT
private:
    int maxEntries ;
    typedef QPair<bool, QByteArray> commEntry ;
    QList<commEntry> buffer ;
    QString hexRepresentation(const QByteArray&) const ;
public:
    explicit serialDebugBuffer(QObject *parent = 0);
    void setMaxEntries(int num) ;
    void addIncomingEntry(const QByteArray&) ;
    void addOutgoingEntry(const QByteArray&) ;
    void addEntry(const QByteArray&, bool in) ;
    int rowCount(const QModelIndex &parent) const ;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const ;
    QVariant data(const QModelIndex &index, int role) const ;
    int columnCount(const QModelIndex &parent) const ;
};

#endif // SERIALDEBUGBUFFER_H
