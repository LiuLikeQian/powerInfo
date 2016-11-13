#ifndef POWERTABLE_H
#define POWERTABLE_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QTextCodec>
#include "tablemodel.h"
#include <QSettings>
#include <QHeaderView>
#include <QFrame>
#include <QFile>
#include <QApplication>

#define marginsSize 10
#define powerSize 3

//定义当前一个数据结构去存储第一个图
typedef struct{
    QLabel      *Power_icon;       //图标
    QLabel      *Power_vauleLabel; //区值标签
    QLineEdit   *Power_Edit;       //主保护-pst120IA当前定值区
    QLabel      *power_hard;       //保护硬压板标签
    QLabel      *power_soft;       //保护软压板标签
    QToolButton *power_fix_Btn;    //装置抢修按钮
    QToolButton *power_cout_Btn;   //装置总出口按钮
    QLabel      *power_protect;    //保护装置远方复归标签
    QLabel      *power_end;        //智能终继远方复归标签
    QPushButton *power_protect_Btn;//保护装置远方复归按钮
    QPushButton *power_end_Btn;    //智能终继远方复归按钮
    QLabel      *power_ViewInfo;   //电力表头信息

    QTableView  *power_view;       //保护信息光字牌

}Powermap;


typedef struct{
    QVBoxLayout *power_InfoLayout;
    QHBoxLayout *power_valueLayout;
    QVBoxLayout *power_hardLayout;
    QVBoxLayout *power_softLayout;
    QVBoxLayout *power_protectLayout;
    QVBoxLayout *power_endLayout;
    QHBoxLayout *power_boardLayout;
    QHBoxLayout *power_returnLayout;

    QVBoxLayout *power_topLayout;
    QVBoxLayout *power_bottomLayout;
}PowerLayout;

class powerTable : public QWidget
{
    Q_OBJECT

public:
    powerTable(QWidget *parent = 0);
    ~powerTable();

    void IniPower(Powermap *index);                                       //初始化表结构
    void IniLayout(PowerLayout *layout);
    void setLayout(Powermap *index,PowerLayout *layout);                                      //布局各控件
private:
    QLabel *power_headInfo;                                               //表头信息
    QPushButton *power_MainLineBtn,*power_LineIndexBtn,*power_TestInfoBtn;//表头按钮信息

    Powermap *PowermapTable[powerSize];                                              //存储表信息结构
    PowerLayout *PoweramapLayout[powerSize];                              //存储表布局结构
    QVBoxLayout *power_mainLayout;                                        //表的主要布局
    QHBoxLayout *power_BtnLayout;                                         //表头按钮布局
    tableModel  *power_Model;                                             //模型
    QHBoxLayout *Power_TableLayout;                                       //多个viewlayout


};

#endif // POWERTABLE_H
