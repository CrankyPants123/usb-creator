#include "watchdd.h"

Watchdd::Watchdd(QObject *parent):QObject(parent)
{
//    command_watch = new QProcess(this);
//    connect(command_watch,&QProcess::readyReadStandardOutput,this,&Watchdd::readBashStandardErrorInfo);
//    connect(command_watch,&QProcess::readyReadStandardError,this,&Watchdd::readBashStandardErrorInfo);

    canWatch=false;
}
Watchdd::~Watchdd()
{
    command_watch->close();
}

void Watchdd::readBashStandardErrorInfo()
{
    QByteArray cmdout = command_watch->readAllStandardOutput();
    if(!cmdout.isEmpty()){
        qDebug()<<"wa-----------"<<QString(cmdout);
    }
}

void Watchdd::watchStart(QString kw)
{
    command_watch = new QProcess();
    bool test = false;
    connect(command_watch,&QProcess::readyReadStandardOutput,this,&Watchdd::readBashStandardErrorInfo);
    connect(command_watch,&QProcess::readyReadStandardError,this,&Watchdd::readBashStandardErrorInfo);

    qDebug()<<"watch&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
    int i=0;
    command_watch->start("bash");
    command_watch->waitForStarted();
//    for(;;)
//    {i++;
        command_watch->write("echo 6886868|sudo -S watch -n 5 killall -USR1 dd");    //echo 6886868|sudo -S watch -n 5 killall -USR1 dd");

        test = command_watch->waitForFinished();
        qDebug()<<"=="<<test;
//    }
    command_watch->close();
    qDebug()<<"watch&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
}

