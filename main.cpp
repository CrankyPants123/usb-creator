#include "mainwindow.h"


//#define ITEMHEIGHT 60//标签高度
//#define TITLEH 0//标题栏高度
#define SHADOW 6//阴影宽度
//#define WIDGETRADIUS 4//窗口圆角
#define BUTTONRADIUS 0//按钮圆角
#define SHADOWALPHA 0.16//阴影透明度
#include "stylewidgetshadow.h"
#include "stylecombobox.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    StyleComboBox scb(200,30);
//    scb.show();



//    //设置阴影
//    StyleWidgetAttribute s(300,90,1,WIDGETRADIUS,SHADOW,SHADOWALPHA,TITLEH);
//    //StyleWidgetAttribute swa(300,30,0,WIDGETRADIUS);
//    StyleWidgetShadow w(s);
//    w.show();





    return a.exec();
}
