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

//���嵱ǰһ�����ݽṹȥ�洢��һ��ͼ
typedef struct{
    QLabel      *Power_icon;       //ͼ��
    QLabel      *Power_vauleLabel; //��ֵ��ǩ
    QLineEdit   *Power_Edit;       //������-pst120IA��ǰ��ֵ��
    QLabel      *power_hard;       //����Ӳѹ���ǩ
    QLabel      *power_soft;       //������ѹ���ǩ
    QToolButton *power_fix_Btn;    //װ�����ް�ť
    QToolButton *power_cout_Btn;   //װ���ܳ��ڰ�ť
    QLabel      *power_protect;    //����װ��Զ�������ǩ
    QLabel      *power_end;        //�����ռ�Զ�������ǩ
    QPushButton *power_protect_Btn;//����װ��Զ�����鰴ť
    QPushButton *power_end_Btn;    //�����ռ�Զ�����鰴ť
    QLabel      *power_ViewInfo;   //������ͷ��Ϣ

    QTableView  *power_view;       //������Ϣ������

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

    void IniPower(Powermap *index);                                       //��ʼ����ṹ
    void IniLayout(PowerLayout *layout);
    void setLayout(Powermap *index,PowerLayout *layout);                                      //���ָ��ؼ�
private:
    QLabel *power_headInfo;                                               //��ͷ��Ϣ
    QPushButton *power_MainLineBtn,*power_LineIndexBtn,*power_TestInfoBtn;//��ͷ��ť��Ϣ

    Powermap *PowermapTable[powerSize];                                              //�洢����Ϣ�ṹ
    PowerLayout *PoweramapLayout[powerSize];                              //�洢���ֽṹ
    QVBoxLayout *power_mainLayout;                                        //�����Ҫ����
    QHBoxLayout *power_BtnLayout;                                         //��ͷ��ť����
    tableModel  *power_Model;                                             //ģ��
    QHBoxLayout *Power_TableLayout;                                       //���viewlayout


};

#endif // POWERTABLE_H
