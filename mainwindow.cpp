#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    myStyle();
}

MainWindow::~MainWindow()
{

}

void MainWindow::myStyle()
{
    //设置外观
    //int w, int h, bool allRadius, int radius,int shadow,double shadowAlpha, int titleHeight, int itemHeight, bool middle
    StyleWidgetAttribute swa(WINDOWW,WINDOWH,0,WIDGETRADIUS,SHADOW,SHADOWALPHA,TITLEH);
    StyleWidget *styleWidget=new StyleWidget(swa,tr("麒麟U盘启动器"));
    page1 = new Page1(swa);
    connect(styleWidget,&StyleWidget::allClose,page1,&Page1::allClose);
    connect(page1,&Page1::makeStart,this,&MainWindow::makeStart);

    page2 = new Page2;
    connect(page1,&Page1::makeStart,page2,&Page2::startMaking);

    connect(page2,&Page2::makeFinish,this,&MainWindow::makeFinish);
    connect(page2,&Page2::returnMain,this,&MainWindow::returnMain);
    QHBoxLayout *hblayout=new QHBoxLayout(styleWidget->body);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距
    hblayout->addWidget(this);

    //内部样式
    QSize pointSize(8,8);
    pointLable1=new QLabel;
    pointLable2=new QLabel;
    pointLable3=new QLabel;
    pointLable1->setFixedSize(pointSize);
    pointLable2->setFixedSize(pointSize);
    pointLable3->setFixedSize(pointSize);
    pointLable1->setStyleSheet("border-radius:4px;background:rgba(100, 105, 241, 1)");
    pointLable2->setStyleSheet("border-radius:4px;background:rgba(151, 151, 151, 1)");
    pointLable3->setStyleSheet("border-radius:4px;background:rgba(151, 151, 151, 1)");

    stackedWidget =new QStackedWidget;
    stackedWidget->addWidget(page1);
    stackedWidget->addWidget(page2);

    //布局
    QHBoxLayout *hlt =new QHBoxLayout;
    hlt->addStretch(15);
    hlt->addWidget(pointLable1);
    hlt->addStretch(1);
    hlt->addWidget(pointLable2);
    hlt->addStretch(1);
    hlt->addWidget(pointLable3);
    hlt->addStretch(15);
    QVBoxLayout *vlt =new QVBoxLayout;
    vlt->addWidget(stackedWidget,99);
    vlt->addLayout(hlt,1);
    vlt->addSpacing(7);
    this->setLayout(vlt);
}

void MainWindow::makeStart()
{
    stackedWidget->setCurrentIndex(changePage());
    pointLable1->setStyleSheet("border-radius:4px;background:rgba(151, 151, 151, 1)");
    pointLable2->setStyleSheet("border-radius:4px;background:rgba(100, 105, 241, 1)");
    qDebug()<<"start";
    emit setMakeStart();
}

int MainWindow::changePage()
{
    int count = stackedWidget->count();
    int index = stackedWidget->currentIndex();
    ++index;
    if (index >= count)index = 0;
    return index;
}

void MainWindow::makeFinish()
{
    qDebug()<<"finish";
//    stackedWidget->setCurrentIndex(changePage());
    pointLable3->setStyleSheet("border-radius:4px;background:rgba(100, 105, 241, 1)");
    pointLable2->setStyleSheet("border-radius:4px;background:rgba(151, 151, 151, 1)");
}

void MainWindow::returnMain()
{
    qDebug()<<"return main";
    stackedWidget->setCurrentIndex(changePage());
    pointLable1->setStyleSheet("border-radius:4px;background:rgba(100, 105, 241, 1)");
    pointLable3->setStyleSheet("border-radius:4px;background:rgba(151, 151, 151, 1)");
    qDebug()<<"back to mainwindow";
}
