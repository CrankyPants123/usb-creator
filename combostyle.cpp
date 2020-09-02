#include "combostyle.h"

ComboStyle::ComboStyle()
{
    //this->setStyleSheet("QComboBox::drop-down{border-left: 3px solid #000; } ");

//    this->setLayout();

//    QHBoxLayout *lay=new QHBoxLayout;
//    lay->addWidget();

//    qDebug()<< this->children();

//    QAbstractItemModel * model=new QAbstractItemModel;
//    model->


    for(int i=0;i<5;i++)
        this->addItem(QString::asprintf("Item %d",i)); //不带图标

 //   QItemSelectionModel *theSelection=this->children().at(0);


}
