#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "iostream"
#include "fstream"
#include "logic.h"
#include "facade.h"
using namespace std;
bool balanced(const std::string &s);
std::string getTextFile(string filePath);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, " ", "C:\\Users", "*.json").toStdString();
    WorkWithFile file(filePath);
    Facade facade(&file);
    textFile = facade.read_operation();
    ui->plainTextEdit->setPlainText(QString::fromStdString(textFile));

}

void MainWindow::on_pushButton_2_clicked()
{
    JsonChecker checker(textFile);
    Facade facade(nullptr ,&checker);
    AllInformationsAboutError tmp = facade.check_operation();
    if(tmp.containError)
        ui->label->setText(QString::fromStdString(tmp.errorType) + " cols " + QString::number(tmp.cols) + " rows " + QString::number(tmp.rows));
    else
        ui->label->setText("norm");
}

