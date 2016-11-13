#include "tablemodel.h"

tableModel::tableModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

QVariant tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole&&orientation == Qt::Horizontal)
        return headData[section];
    return QVariant();
}

int tableModel::rowCount(const QModelIndex &parent) const
{
    //qDebug()<<powerData.size();
    return 13;
}

int tableModel::columnCount(const QModelIndex &parent) const
{

    return headData.size();//规定一列只显示13行
}

QVariant tableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

    //qDebug()<<"column"<<column;
    switch(role)
    {
    case Qt::DisplayRole:
    {
        if(column == 0)
        {
            return powerData[row];
        }
        else if(column == 1)
        {

            //list存储到tableview，适当截取。
                return powerData[row+13];
        }
        else if(column == 2)
            return powerData[row+26];
        else if(column == 3)
            return powerData[row+39];
        else if(column == 4)
            return powerData[row+52];
        else
            return QVariant();
        break;
    }
    case Qt::EditRole:
    {
        if(column == 0)
            return powerData[row];
        else if(column == 1)
                return powerData[row];
        else if(column == 2)
            return powerData[row];
        else if(column == 3)
            return powerData[row];
        else if(column == 4)
            return powerData[row];
        else
            return QVariant();
        break;
    }
    case Qt::TextAlignmentRole:
    {
        if(role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;
        //return QAbstractTableModel::data(index, role);
    }
    default:
        return QVariant();
        break;
    }
    return QVariant();
}

bool tableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    int row = index.row();
    int column = index.column();

    switch(role)
    {
    case Qt::EditRole:
    {
        if(column == 0)
            powerData[row] = value.toString();
        else if(column == 1)
            powerData[row] = value.toString();
        else if(column == 2)
            powerData[row] = value.toString();
        else if(column == 3)
            powerData[row] = value.toString();
        else if(column == 4)
            powerData[row] = value.toString();
        else
            return false;
    }
    case Qt::DisplayRole:
    {

        if(column == 0)
            powerData[row] = value.toString();
        else if(column == 1)
            powerData[row] = value.toString();
        else if(column == 2)
            powerData[row] = value.toString();
        else if(column == 3)
            powerData[row] = value.toString();
        else if(column == 4)
            powerData[row] = value.toString();
        else
            return false;
    }
    default:
        return false;
        break;
    }
    return true;

}

/*设置数据源 一列显示13行，不够在加最多五列*/
void tableModel::setPowerData(QStringList list)
{
    powerData = list;
    int size = powerData.size()/13;
    if(powerData.size()%13==0)
    {
        for(int i=0;i<size;i++)
    headData<<QString::number(i);
    }
    else
    {
        size = size+1;
        for(int i=0;i<size;i++)
    headData<<QString::number(i);
    }
}
