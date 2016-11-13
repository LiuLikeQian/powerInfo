#include "powertable.h"

powerTable::powerTable(QWidget *parent)
    : QWidget(parent)
{
   QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));

   /*控件定义*/
    power_headInfo = new QLabel(tr("主变保护信息图"));
    power_MainLineBtn = new QPushButton(tr("主接线图"));
    power_LineIndexBtn = new QPushButton(tr("光字牌索引"));
    power_TestInfoBtn = new QPushButton(tr("测控信息"));

    /*大布局*/
    power_BtnLayout = new QHBoxLayout;
    power_mainLayout = new QVBoxLayout(this);
    Power_TableLayout = new QHBoxLayout;

    QFile qss(":/image/black.qss");
    qss.open(QFile::ReadOnly);
    qDebug()<<"qss"<<qss.readAll();
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    //qApp->setStyleSheet("background-color: rgb(0, 0, 0);");

    /*布局图标不变动的按钮信息*/
    power_BtnLayout->addStretch(5);
    power_BtnLayout->addWidget(power_MainLineBtn);
    power_BtnLayout->addWidget(power_LineIndexBtn);
    power_BtnLayout->addWidget(power_TestInfoBtn);
    power_BtnLayout->addStretch(5);

    power_mainLayout->addWidget(power_headInfo);
    power_mainLayout->addLayout(power_BtnLayout);
    power_mainLayout->addLayout(Power_TableLayout);


    power_headInfo->setAlignment(Qt::AlignCenter);

    /*结构,布局初始化,表格长度powersize暂定3*/
    for(int i=0;i<powerSize;i++)
    {
    PowermapTable[i] = new Powermap;
    PoweramapLayout[i] = new PowerLayout;
    IniPower(PowermapTable[i]);
    IniLayout(PoweramapLayout[i]);
    setLayout(PowermapTable[i],PoweramapLayout[i]);
    }

    setObjectName("powerTable");
    setStyleSheet("QWidget#powerTable{background-color: rgb(0, 0, 0);}\
                  QLabel{ color: white }\
                  QTableView { background-color: rgb(0,0,0);\
                  border: 19px solid rgb(0, 0, 0);}QTableView::item {  border: 1px solid rgb(255,255,255);background: rgb(0,0, 0);border-top: 1px solid rgb(45, 45, 45);border-bottom: 1px solid rgb(45, 45, 45);}");

}

powerTable::~powerTable()
{

}

/*表结构初始化*/
void powerTable::IniPower(Powermap *index)
{
    index->Power_icon = new QLabel;
    index->Power_icon->setAlignment(Qt::AlignCenter);
    index->Power_icon->setPixmap(QPixmap(":/image/mouse.png"));
    index->Power_vauleLabel = new QLabel(tr("主变保护当前定值区:"));
    index->Power_vauleLabel->setFrameShape(QFrame::Box);
    index->Power_Edit = new QLineEdit;
    index->power_hard = new QLabel(tr("保护硬压板"));
    index->power_soft = new QLabel(tr("保护软压板"));
    index->power_fix_Btn = new QToolButton;
    index->power_cout_Btn = new QToolButton;
    index->power_protect = new QLabel(tr("保护装置远方复归"));
    index->power_end = new QLabel(tr("智能终继远方复归"));
    index->power_protect_Btn = new QPushButton(tr("保护装置复归"));
    index->power_end_Btn = new QPushButton(tr("智能终继复归"));
    index->power_ViewInfo = new QLabel(tr("#2主变第一套信息保护光字牌"));
    power_Model = new tableModel;

    index->Power_vauleLabel->setAlignment(Qt::AlignCenter);
    index->power_hard->setAlignment(Qt::AlignCenter);
    index->power_soft->setAlignment(Qt::AlignCenter);
    index->power_protect->setAlignment(Qt::AlignCenter);
    index->power_end->setAlignment(Qt::AlignCenter);
    index->power_ViewInfo->setAlignment(Qt::AlignCenter);

    index->power_fix_Btn->setText(tr("装置检修"));
    index->power_cout_Btn->setText(tr("装置总出口"));

    index->power_view = new QTableView;
    index->power_view->setModel(power_Model);
    index->power_view->horizontalHeader()->hide();


    QStringList power_List;
    /*从ini文件读取数据保存到view上面*/
    QSettings power_set(":/image/power.ini",QSettings::IniFormat);
    /*设置编码,防止读入烫烫烫*/
    power_set.setIniCodec(QTextCodec::codecForName("UTF-8"));

    /*这里暂读入26条信息*/
    for(int i=1;i<=26;i++)
    {
        QString power_Str;
        power_set.setArrayIndex(i);
        power_Str = power_set.value(QString("data%1").arg(i)).toString();
        power_List.append(power_Str);
    }
    power_Model->setPowerData(power_List);

    index->power_view->resizeColumnsToContents();
}

/*布局初始化*/
void powerTable::IniLayout(PowerLayout *layout)
{
    layout->power_InfoLayout = new QVBoxLayout;
    layout->power_valueLayout = new QHBoxLayout;
    /*软板硬板layout*/
    layout->power_hardLayout = new QVBoxLayout;
    layout->power_softLayout = new QVBoxLayout;
    layout->power_protectLayout = new QVBoxLayout;
    layout->power_endLayout = new QVBoxLayout;
    /*复归layout*/
    layout->power_boardLayout = new QHBoxLayout;
    layout->power_returnLayout = new QHBoxLayout;

    /*整体结构上下两部分layout*/
    layout->power_topLayout = new QVBoxLayout;
    layout->power_bottomLayout = new QVBoxLayout;
}
/*表各个控件布局*/
void powerTable::setLayout(Powermap *index,PowerLayout *layout)
{
      /*布局第一块 水平*/
      layout->power_valueLayout->addStretch(5);
      layout->power_valueLayout->addWidget(index->Power_vauleLabel);
      layout->power_valueLayout->addStretch(10);
      layout->power_valueLayout->addWidget(index->Power_Edit);
      layout->power_valueLayout->addStretch(20);

      /*布局第二块 垂直*/
      layout->power_hardLayout->addWidget(index->power_hard);
      layout->power_hardLayout->addWidget(index->power_fix_Btn);

      layout->power_softLayout->addWidget(index->power_soft);
      layout->power_softLayout->addWidget(index->power_cout_Btn);

      /*布局第三块 垂直*/
      layout->power_protectLayout->addWidget(index->power_protect);
      layout->power_protectLayout->addWidget(index->power_protect_Btn);
      layout->power_protectLayout->setMargin(marginsSize);

      layout->power_endLayout->addWidget(index->power_end);
      layout->power_endLayout->addWidget(index->power_end_Btn);
      layout->power_endLayout->setMargin(marginsSize);


      /*硬板软板布局*/
      layout->power_boardLayout->addLayout(layout->power_hardLayout);
      layout->power_boardLayout->addLayout(layout->power_softLayout);
      /*复归布局*/
      layout->power_returnLayout->addLayout(layout->power_protectLayout);
      layout->power_returnLayout->addLayout(layout->power_endLayout);

      /*上部分结构布局*/
      layout->power_topLayout->addWidget(index->Power_icon);
      layout->power_topLayout->addLayout(layout->power_valueLayout);
      layout->power_topLayout->addLayout(layout->power_boardLayout);
      layout->power_topLayout->addLayout(layout->power_returnLayout);

      /*下部分结构布局*/
      layout->power_bottomLayout->addWidget(index->power_ViewInfo);
      layout->power_bottomLayout->addWidget(index->power_view);

      /*整体布局*/
      layout->power_InfoLayout->addLayout(layout->power_topLayout);
      layout->power_InfoLayout->addLayout(layout->power_bottomLayout);


      /*将完整小布局加入table布局*/
      Power_TableLayout->addLayout(layout->power_InfoLayout);
      Power_TableLayout->setMargin(marginsSize);
      Power_TableLayout->setSpacing(10);




}
