#include "page2.h"

Page2::Page2(QWidget *parent) : QWidget(parent)
{
    movieLoading = new QMovie(":/data/loading.gif");
    movieFinish = new QMovie(":/data/finish.gif");
    frameCount=movieFinish->frameCount();
    connect(movieFinish,&QMovie::frameChanged,this,[=](int num){if(frameCount-1==num)movieFinish->stop();});
    lableMovie=new QLabel;
    QSize movieSize(130,130);
    lableMovie->setFixedSize(movieSize);
    movieLoading->setScaledSize(movieSize);
    movieFinish->setScaledSize(movieSize);
    lableText=new QLabel;
    lableNum=new QLabel(lableMovie);
    lableNum->setFixedSize(36,22);
    lableNum->move((lableMovie->width()-lableNum->width())/2,(lableMovie->height()-lableNum->height())/2);
    lableNum->setAlignment(Qt::AlignRight);    // 设置对齐方式
    returnPushButton=new QPushButton;
    connect(returnPushButton,&QPushButton::clicked,this,&Page2::returnMain);
    returnPushButton->setFixedSize(200,30);

    QHBoxLayout *hlt1=new QHBoxLayout;
    hlt1->setMargin(0);
    hlt1->setSpacing(0);
    hlt1->addStretch(9);
    hlt1->addWidget(lableMovie);
    hlt1->addStretch(9);
    QHBoxLayout *hlt2=new QHBoxLayout;
    hlt2->setMargin(0);
    hlt2->setSpacing(0);
    hlt2->addStretch(9);;
    hlt2->addWidget(lableText);
    hlt2->addStretch(9);
    QHBoxLayout *hlt3=new QHBoxLayout;
    hlt3->setMargin(0);
    hlt3->setSpacing(0);
    hlt3->addStretch(9);;
    hlt3->addWidget(returnPushButton);
    hlt3->addStretch(9);;
    QVBoxLayout *vlt1=new QVBoxLayout;
    vlt1->setMargin(0);
    vlt1->setSpacing(0);
    vlt1->addSpacing(108);
    vlt1->addLayout(hlt1);
    vlt1->addSpacing(26);
    vlt1->addLayout(hlt2);
    vlt1->addSpacing(124);
    vlt1->addLayout(hlt3);
    vlt1->addSpacing(31);
    this->setLayout(vlt1);

    lableNum->setStyleSheet("background-color:rgba(236, 236, 236,0);color:rgba(100, 105, 241, 1);font-size:16px;");
}

void Page2::playLoadingGif()
{
    lableNum->setText("10%");
    lableNum->show();
    returnPushButton->setEnabled(false);
    returnPushButton->setText(tr("正在制作中"));
    returnPushButton->setStyleSheet("background-color:rgba(236, 236, 236, 1);color:rgba(100, 105, 241, 1)");
    lableText->setText(tr("制作时请不要移除磁盘或关机"));
    lableMovie->setMovie(movieLoading); //为label设置movie
    movieLoading->start();         //开始显示
}

void Page2::playFinishGif()
{
    lableNum->hide();
    returnPushButton->setEnabled(true);
    returnPushButton->setText(tr("返回"));
    returnPushButton->setStyleSheet(".QPushButton{background-color:rgba(100, 105, 241, 1);color:#fff;border-radius:4px;}"
                          ".QPushButton:hover{background-color:rgba(136,140,255,1);}"
                          ".QPushButton:pressed{background-color:rgba(82,87,217,1);}");
    lableText->setText(tr("制作完成"));
    lableMovie->clear();
    lableMovie->setMovie(movieFinish);
    movieFinish->start();

}

void Page2::makeStart()
{
    playLoadingGif();

    //playFinishGif();
}
