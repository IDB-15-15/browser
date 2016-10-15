#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include "network.h"
#include "iostream"
#include "string"
#include "vector"
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_backbutton_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString some = ui->lineEdit->text();
    string site=some.toStdString();
    //ui->test->setText(some);
    vector<string> res;
    vector<string> header;
    vector<string> main;
    res=geth(site);
    int i = 0;
    int k = 0;
     while(res[i] != "\r" && res[i+1] != "\r"){
         i++;
         header.push_back(res[k]);
         k++;
     }
     while(k != res.size()-1){
         main.push_back(res[k]);
         k++;
     }
     QString str="";
     QString add="";
   for(i = 0;i<header.size();i++){
         add = QString::fromUtf8(header[i].c_str());
         //str=str+header[i];
         str+=add;

   }
         //cout<<header[i]<<endl;
   for(i = 0;i<main.size();i++){
        add = QString::fromUtf8(main[i].c_str());
         //cout<<main[i]<<endl;
        str+=add;
   }
   ui->test->setText(str);
     //return 0;
}
