#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int n=0;
    changeMonney(n);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMonney(int n){
    monney += n;
    ui->lcdNumber->display(QString::number(monney));
    ui->pbCoffee->setEnabled(monney >= 100);
    ui->pbTea->setEnabled(monney >= 150);
    ui->pbGongCha->setEnabled(monney >= 200);
}

void Widget::on_pb10_clicked()
{
    changeMonney(10);
}

void Widget::on_pb50_clicked()
{
    changeMonney(50);
}

void Widget::on_pb100_clicked()
{
    changeMonney(100);
}

void Widget::on_pb500_clicked()
{
    changeMonney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMonney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMonney(-150);
}

void Widget::on_pbGongCha_clicked()
{
    changeMonney(-200);
}

void Widget::on_pbReset_clicked()
{
    int out_500=0, out_100=0, out_50=0, out_10=0;
    QMessageBox msg;
    //QString info;
    //info.append("return coin");
    //info.append(monney);
    if (monney >= 500) {
        out_500=monney/500;
        monney = monney % 500;
    }
    if (monney >= 100) {
        out_100=monney/100;
        monney = monney % 100;
    }
    if (monney >= 50) {
        out_50=monney/50;
        monney = monney % 50;
    }
    if (monney >= 10) {
        out_10=monney/10;
    }
    changeMonney(-monney);
    msg.information(nullptr, "Return Coin", QString("10: %1 \n50: %2 \n100: %3 \n500: %4").arg(out_10).arg(out_50).arg(out_100).arg(out_500));
}
