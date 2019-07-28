#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);    //homework make change money button
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);

}


Widget::~Widget()
{
    delete ui;
}

void Widget::changemoney(int n){
    money +=n;
    ui->lcdNumber->display(QString::number(money));
}

void Widget::on_pb10_clicked()
{
    changemoney(10);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money>=150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(true);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }

}

void Widget::on_pb50_clicked()
{
    changemoney(50);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money>=150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(true);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }
}

void Widget::on_pb100_clicked()
{
    changemoney(100);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money>=150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(true);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }
}

void Widget::on_pb500_clicked()
{
    changemoney(500);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money>=150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbGongcha->setEnabled(true);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }
}

void Widget::on_pbCoffee_clicked()
{
    changemoney(-100);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<200){
        ui->pbGongcha->setEnabled(false);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }

}

void Widget::on_pbTea_clicked()
{
    changemoney(-150);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<200){
        ui->pbGongcha->setEnabled(false);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }
}

void Widget::on_pbGongcha_clicked()
{
    changemoney(-200);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
        ui->pbGongcha->setEnabled(false);
    }
    if(money<200){
        ui->pbGongcha->setEnabled(false);
    }
    if(money<=0){
        ui->change->setEnabled(false);
    }
}

void Widget::on_change_clicked()
{
     int ten;
     int hundred;
     int fifty;
     int fhundred;

     fhundred = money / 500;
     hundred = money % 500 / 100;
     fifty = money % 500 % 100 / 50;
     ten= money % 500 % 100 % 50 / 10;

     QString message;
     QMessageBox msg;

     message.sprintf("change: %d\n 10: %d\n 50: %d\n 100: %d\n 500: %d\n ", money, ten, fifty, hundred, fhundred);
     
     changemoney(0);

     msg.information(nullptr, "change", message);

     ui->lcdNumber->display(QString::number(money=0));

     if(money<100){
         ui->pbCoffee->setEnabled(false);
         ui->pbTea->setEnabled(false);
         ui->pbGongcha->setEnabled(false);
     }
     if(money<150){
         ui->pbTea->setEnabled(false);
         ui->pbGongcha->setEnabled(false);
     }
     if(money<200){
         ui->pbGongcha->setEnabled(false);
     }
     ui->change->setEnabled(false);
}
