#include "exam.h"
#include "ui_exam.h"
#include "project2004.h"
#include "mainwindow.h"
#include <QMessageBox>
static int p=0;
static int s=0;
QString select;
QString answer;
exam::exam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exam)
{
    ui->setupUi(this);
    ui->label_2->setText("lesson "+QString::number(Database::Number));
    if(s<=3){
        ui->label->setText("what is the mining of "+QString::fromStdString(Database::words504[Database::Number-1][s][0]));
        for(int i = 1;i<=4;i++){
            QRadioButton *g=findChild<QRadioButton*>("G"+QString::number(i));
            if(Database::Number==42){
                g->setText(QString::fromStdString(Database::words504[Database::Number-2][rand()%12][1]));
            }
            else{
                g->setText(QString::fromStdString(Database::words504[Database::Number][rand()%12][1]));
            }

        }
        answer = QString::fromStdString(Database::words504[Database::Number-1][s][1]);
    }else if(s<=6) {
        ui->label->setText("what is the mining of "+QString::fromStdString(Database::words504[Database::Number-1][s][1]));
        for(int i = 1;i<=4;i++){
            QRadioButton *g=findChild<QRadioButton*>("G"+QString::number(i));
            if(Database::Number==42){
                g->setText(QString::fromStdString(Database::words504[Database::Number-2][rand()%12][1]));
            }
            else{
                g->setText(QString::fromStdString(Database::words504[Database::Number][rand()%12][1]));
            }
        }
        answer = QString::fromStdString(Database::words504[Database::Number-1][s][0]);
    }else{
        string sent = Database::words504[Database::Number-1][s-1][rand()%3+2];
        string word = Database::words504[Database::Number-1][s-1][0];
        answer = QString::fromStdString(word);
        sent.replace(sent.find(word),word.length(),".........");
        ui->label->setText(QString::number(s)+")" + QString::fromStdString(sent)+"?");
        for(int i = 1;i<=4;i++){
            QRadioButton *g=findChild<QRadioButton*>("G"+QString::number(i));
            if(Database::Number==42){
                g->setText(QString::fromStdString(Database::words504[Database::Number-2][rand()%12][1]));
            }
            else{
                g->setText(QString::fromStdString(Database::words504[Database::Number][rand()%12][1]));
            }
        }
    }

    QRadioButton *a=findChild<QRadioButton*>("G"+QString::number(rand()%4+1));
    a->setText(answer);
}

exam::~exam()
{
    delete ui;
}

void exam::on_pushButton_2_clicked()
{
   if(s>10){
        QMessageBox::warning(this,"","finished your score: "+QString::number(p));
   }
   else{
       if(ui->G1->isChecked()){
           select = ui->G1->text();


       }
       else if(ui->G2->isChecked()){
           select = ui->G2->text();
       }

       else if(ui->G3->isChecked()){
           select = ui->G3->text();
       }
       else if(ui->G4->isChecked()){
           select = ui->G4->text();
       }
       if(answer==select){
           p++;

       }
       s++;
       this->close();
       exam *Exam = new exam;
       Exam->show();
   }

}


void exam::on_pushButton_clicked()
{
    this->close();
   MainWindow *page1 = new MainWindow;
   page1->show();
}

