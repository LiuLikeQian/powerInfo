#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>
#include <QDebug>

class tableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit tableModel(QObject *parent = 0);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const ;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void setPowerData(QStringList list);
signals:

public slots:


private:
  QStringList powerData;
  QStringList headData;
};

#endif // TABLEMODEL_H
