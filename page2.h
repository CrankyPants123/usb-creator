#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QMovie>
#include <QBoxLayout>
class Page2 : public QWidget
{
    Q_OBJECT
public:
    explicit Page2(QWidget *parent = nullptr);

signals:
    void makeFinish();
    void returnMain();

public slots:
    void makeStart();

private:
    void playLoadingGif();
    void playFinishGif();
    QMovie *movieLoading=nullptr;
    QMovie *movieFinish=nullptr;
    QLabel *lableMovie=nullptr;
    QLabel *lableText=nullptr;
    QLabel *lableNum=nullptr;
    QPushButton *returnPushButton=nullptr;
    int frameCount=0;
};

#endif // PAGE2_H
