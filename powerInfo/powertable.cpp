#include "powertable.h"

powerTable::powerTable(QWidget *parent)
    : QWidget(parent)
{
   QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));

   /*�ؼ�����*/
    power_headInfo = new QLabel(tr("���䱣����Ϣͼ"));
    power_MainLineBtn = new QPushButton(tr("������ͼ"));
    power_LineIndexBtn = new QPushButton(tr("����������"));
    power_TestInfoBtn = new QPushButton(tr("�����Ϣ"));

    /*�󲼾�*/
    power_BtnLayout = new QHBoxLayout;
    power_mainLayout = new QVBoxLayout(this);
    Power_TableLayout = new QHBoxLayout;

    QFile qss(":/image/black.qss");
    qss.open(QFile::ReadOnly);
    qDebug()<<"qss"<<qss.readAll();
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    //qApp->setStyleSheet("background-color: rgb(0, 0, 0);");

    /*����ͼ�겻�䶯�İ�ť��Ϣ*/
    power_BtnLayout->addStretch(5);
    power_BtnLayout->addWidget(power_MainLineBtn);
    power_BtnLayout->addWidget(power_LineIndexBtn);
    power_BtnLayout->addWidget(power_TestInfoBtn);
    power_BtnLayout->addStretch(5);

    power_mainLayout->addWidget(power_headInfo);
    power_mainLayout->addLayout(power_BtnLayout);
    power_mainLayout->addLayout(Power_TableLayout);


    power_headInfo->setAlignment(Qt::AlignCenter);

    /*�ṹ,���ֳ�ʼ��,��񳤶�powersize�ݶ�3*/
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

/*��ṹ��ʼ��*/
void powerTable::IniPower(Powermap *index)
{
    index->Power_icon = new QLabel;
    index->Power_icon->setAlignment(Qt::AlignCenter);
    index->Power_icon->setPixmap(QPixmap(":/image/mouse.png"));
    index->Power_vauleLabel = new QLabel(tr("���䱣����ǰ��ֵ��:"));
    index->Power_vauleLabel->setFrameShape(QFrame::Box);
    index->Power_Edit = new QLineEdit;
    index->power_hard = new QLabel(tr("����Ӳѹ��"));
    index->power_soft = new QLabel(tr("������ѹ��"));
    index->power_fix_Btn = new QToolButton;
    index->power_cout_Btn = new QToolButton;
    index->power_protect = new QLabel(tr("����װ��Զ������"));
    index->power_end = new QLabel(tr("�����ռ�Զ������"));
    index->power_protect_Btn = new QPushButton(tr("����װ�ø���"));
    index->power_end_Btn = new QPushButton(tr("�����ռ̸���"));
    index->power_ViewInfo = new QLabel(tr("#2�����һ����Ϣ����������"));
    power_Model = new tableModel;

    index->Power_vauleLabel->setAlignment(Qt::AlignCenter);
    index->power_hard->setAlignment(Qt::AlignCenter);
    index->power_soft->setAlignment(Qt::AlignCenter);
    index->power_protect->setAlignment(Qt::AlignCenter);
    index->power_end->setAlignment(Qt::AlignCenter);
    index->power_ViewInfo->setAlignment(Qt::AlignCenter);

    index->power_fix_Btn->setText(tr("װ�ü���"));
    index->power_cout_Btn->setText(tr("װ���ܳ���"));

    index->power_view = new QTableView;
    index->power_view->setModel(power_Model);
    index->power_view->horizontalHeader()->hide();


    QStringList power_List;
    /*��ini�ļ���ȡ���ݱ��浽view����*/
    QSettings power_set(":/image/power.ini",QSettings::IniFormat);
    /*���ñ���,��ֹ����������*/
    power_set.setIniCodec(QTextCodec::codecForName("UTF-8"));

    /*�����ݶ���26����Ϣ*/
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

/*���ֳ�ʼ��*/
void powerTable::IniLayout(PowerLayout *layout)
{
    layout->power_InfoLayout = new QVBoxLayout;
    layout->power_valueLayout = new QHBoxLayout;
    /*���Ӳ��layout*/
    layout->power_hardLayout = new QVBoxLayout;
    layout->power_softLayout = new QVBoxLayout;
    layout->power_protectLayout = new QVBoxLayout;
    layout->power_endLayout = new QVBoxLayout;
    /*����layout*/
    layout->power_boardLayout = new QHBoxLayout;
    layout->power_returnLayout = new QHBoxLayout;

    /*����ṹ����������layout*/
    layout->power_topLayout = new QVBoxLayout;
    layout->power_bottomLayout = new QVBoxLayout;
}
/*������ؼ�����*/
void powerTable::setLayout(Powermap *index,PowerLayout *layout)
{
      /*���ֵ�һ�� ˮƽ*/
      layout->power_valueLayout->addStretch(5);
      layout->power_valueLayout->addWidget(index->Power_vauleLabel);
      layout->power_valueLayout->addStretch(10);
      layout->power_valueLayout->addWidget(index->Power_Edit);
      layout->power_valueLayout->addStretch(20);

      /*���ֵڶ��� ��ֱ*/
      layout->power_hardLayout->addWidget(index->power_hard);
      layout->power_hardLayout->addWidget(index->power_fix_Btn);

      layout->power_softLayout->addWidget(index->power_soft);
      layout->power_softLayout->addWidget(index->power_cout_Btn);

      /*���ֵ����� ��ֱ*/
      layout->power_protectLayout->addWidget(index->power_protect);
      layout->power_protectLayout->addWidget(index->power_protect_Btn);
      layout->power_protectLayout->setMargin(marginsSize);

      layout->power_endLayout->addWidget(index->power_end);
      layout->power_endLayout->addWidget(index->power_end_Btn);
      layout->power_endLayout->setMargin(marginsSize);


      /*Ӳ����岼��*/
      layout->power_boardLayout->addLayout(layout->power_hardLayout);
      layout->power_boardLayout->addLayout(layout->power_softLayout);
      /*���鲼��*/
      layout->power_returnLayout->addLayout(layout->power_protectLayout);
      layout->power_returnLayout->addLayout(layout->power_endLayout);

      /*�ϲ��ֽṹ����*/
      layout->power_topLayout->addWidget(index->Power_icon);
      layout->power_topLayout->addLayout(layout->power_valueLayout);
      layout->power_topLayout->addLayout(layout->power_boardLayout);
      layout->power_topLayout->addLayout(layout->power_returnLayout);

      /*�²��ֽṹ����*/
      layout->power_bottomLayout->addWidget(index->power_ViewInfo);
      layout->power_bottomLayout->addWidget(index->power_view);

      /*���岼��*/
      layout->power_InfoLayout->addLayout(layout->power_topLayout);
      layout->power_InfoLayout->addLayout(layout->power_bottomLayout);


      /*������С���ּ���table����*/
      Power_TableLayout->addLayout(layout->power_InfoLayout);
      Power_TableLayout->setMargin(marginsSize);
      Power_TableLayout->setSpacing(10);




}
