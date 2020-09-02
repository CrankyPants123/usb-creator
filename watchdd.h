#ifndef WATCHDD_H
#define WATCHDD_H

#include <QObject>
#include <QThread>
#include <QObject>
#include <QProcess>
#include <QDebug>

class Watchdd:public QObject
{
    Q_OBJECT
public:
    explicit Watchdd(QObject *parent=0);
    ~Watchdd();

signals:
    //void setinfo(QString);

public slots:
    void watchStart(QString);

private slots:
   void readBashStandardErrorInfo();


private:
    QProcess *command_watch;
    QString keyword;
    bool canWatch;
};

#endif // WATCHDD_H
