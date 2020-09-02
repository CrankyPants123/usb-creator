#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStorageInfo>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include <QBoxLayout>
#include "combostyle.h"
#include "watchdd.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

signals:
    void watchStart(QString);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void getStorageInfo();

private slots:
    void on_pushButton_clicked();

    void readBashStandardOutputInfo();
    void readBashStandardErrorInfo();
    void stateChanged(QProcess::ProcessState);
    void startWatch();

private:
    Ui::Widget *ui;
    QProcess *command_dd;

    QTimer *timer;
};
#endif // WIDGET_H
