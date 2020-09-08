#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WINDOWW 680 //窗口宽度
#define WINDOWH 510//窗口高度
#define TITLEH 50//标题栏高度
#define SHADOW 6//阴影宽度
#define WIDGETRADIUS 12//窗口圆角
//#define BUTTONRADIUS 4//按钮圆角
#define SHADOWALPHA 0.16//阴影透明度

#include "stylewidget.h"
#include "page1.h"
#include "page2.h"
#include <QWidget>
//滑动效果
#include <QStackedWidget>
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void setMakeStart();

public slots:
    void makeStart();
    void makeFinish();
    void returnMain();

private:
    int changePage();
    void myStyle();//设定样式
    QStackedWidget *stackedWidget= nullptr;
    //页面小圆点
    QLabel *pointLable1 = nullptr;
    QLabel *pointLable2 = nullptr;
    QLabel *pointLable3 = nullptr;
    Page1 *page1=nullptr;
    Page2 *page2=nullptr;
};
#endif // MAINWINDOW_H
