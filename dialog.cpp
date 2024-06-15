#include "dialog.h"
#include "ui_dialog.h"
#include "QLabel"
#include "project2004.h"
#include "mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    for(int i=1 ; i<=12 ; i++){
            QLabel *word = findChild<QLabel*>("word"+QString::number(i));
            QString d = QString::fromStdString(Database::words504[Database::Number-1][i-1][0]);
            QString p = QString::fromStdString(Database::words504[Database::Number-1][i-1][1]);
            word->setText(QString::number(i)+"-" +d+" : "+p);


    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    this->close();
    MainWindow *page1=new MainWindow;
    page1->show();
}


void Dialog::on_pushButton_2_clicked()
{
    this->close();
    E = new exam();
    E->show();
}

