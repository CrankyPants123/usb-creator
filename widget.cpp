#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    getStorageInfo();//获取磁盘信息

    command_dd = new QProcess();
    connect(command_dd,&QProcess::readyReadStandardOutput,this,&Widget::readBashStandardOutputInfo);
    connect(command_dd,&QProcess::readyReadStandardError,this,&Widget::readBashStandardErrorInfo);
    connect(command_dd,&QProcess::stateChanged,this,&Widget::stateChanged);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout, this,&Widget::startWatch);

    //查看进度线程（sudo -S watch -n 3 killall -USR1 dd）
    Watchdd *watch = new Watchdd();
    QThread *watch_thread = new QThread();
    watch->moveToThread(watch_thread);
    watch_thread->start();
    connect(this,&Widget::watchStart,watch,&Watchdd::watchStart);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::getStorageInfo()//获取磁盘信息
{
    QList<QStorageInfo> list = QStorageInfo::mountedVolumes();//获取磁盘列表

    for(QStorageInfo& si : list)
    {
        if(""==si.displayName())//名称为空的磁盘不显示
            continue;
        if(si.bytesTotal()/1048576<1024||si.bytesTotal()/1048576>1024*64)//小于1G或大于64G的磁盘不显示
            continue;
        if("tmpfs"==si.fileSystemType())//tmpfs类型的磁盘不显示
            continue;


        QString displayName=si.displayName();
        if(displayName.length()>15)
            displayName=displayName.mid(0,14)+"…";
        while(displayName.length()<15)
            displayName+="  ";

        QString info=displayName+"  |  剩余"+QString::number(si.bytesFree()/1048576)+"MB/总共"+QString::number(si.bytesTotal()/1048576)+"MB  |  类型"+si.fileSystemType();

        ui->comboBox->addItem(info,si.device());
    }
}

void Widget::on_pushButton_clicked()
{
    command_dd->start("bash");
    command_dd->waitForStarted();
//    ISO路径 + U盘路径组成一句完整的dd语句
//    暂时先向比特桶中写，省去插入U盘的步骤  方便调试
//    ui->comboBox->currentText() = "/dev/null";
//    QString ddshell="echo 6886868|sudo -S dd if="+ui->lineEdit->text()+" of="+ui->comboBox->itemData(ui->comboBox->currentIndex()).toString()+"\n";
//    QString ddshell="echo p][p12 |sudo -S dd if="+ui->lineEdit->text()+" of /dev/null \n";
    QString ddshell="echo p][p12 | sudo -S dd if=/home/andrew/iso/test.iso of=/dev/null status=progress";
    //command_dd->write(ddshell.toLocal8Bit() + '\n');
    qDebug()<<ddshell;
}


void Widget::readBashStandardOutputInfo()
{
    QByteArray cmdout = command_dd->readAllStandardOutput();
    if(!cmdout.isEmpty()){
         ui->textEdit->append(QString::fromLocal8Bit(cmdout));
         qDebug()<<"++++";
    }
}

bool first=true;
void Widget::readBashStandardErrorInfo()
{
    if(first)
    {
        first=false;
        timer->start(5000);
    }
    else
    {
        timer->stop();
        qDebug()<<"stop";
    }
    QByteArray cmdout = command_dd->readAllStandardError();
    if(!cmdout.isEmpty()){
         ui->textEdit->append(QString::fromLocal8Bit(cmdout));
         qDebug()<<"----";
    }
}

void Widget::stateChanged(QProcess::ProcessState state)
{
    qDebug()<<state;
}

void Widget::startWatch()
{
    timer->stop();
    emit watchStart("");
    qDebug()<<"watch";
}
