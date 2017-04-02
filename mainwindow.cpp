#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/qmath.h>

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

bool plus, minus, times, divide;
double a, b, c;

void MainWindow::on_zero_clicked(){
    ui->upperLine->setText(ui->upperLine->text() + "0");
}
void MainWindow::on_one_clicked(){
    ui->upperLine->setText(ui->upperLine->text() + "1");
}
void MainWindow::on_two_clicked(){
    ui->upperLine->setText(ui->upperLine->text() + "2");
}
void MainWindow::on_three_clicked(){
    ui->upperLine->setText(ui->upperLine->text() + "3");
}
void MainWindow::on_four_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "4");
}
void MainWindow::on_five_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "5");
}
void MainWindow::on_six_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "6");
}
void MainWindow::on_seven_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "7");
}
void MainWindow::on_eight_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "8");
}
void MainWindow::on_nine_clicked(){
  ui->upperLine->setText(ui->upperLine->text() + "9");
}

void MainWindow::on_decimal_clicked(){
   ui->upperLine->setText(ui->upperLine->text() + ".");
}

void MainWindow::on_clearButton_clicked(){
    ui->upperLine->setText("");
    ui->lowerLine->setText("");
    ui->operation->setValue(0);
    ui->operationLabel->setText("");
    a = NULL;
}


void MainWindow::on_operation_sliderMoved(int position){
    switch (position){
    case 0:{
        ui->lowerLine->setText("");
        ui->operationLabel->setText("");
    }
    case 1:{
        if (a == NULL){
            a = ui->upperLine->text().toDouble();
        }
        plus = true;
        minus = times = divide = false;
        ui->lowerLine->setText("+");
        ui->upperLine->setText("");
        ui->operationLabel->setText("+");
        break;

    }
    case 2:{
        if (a == NULL){
            a = ui->upperLine->text().toDouble();
        }
        minus = true;
        plus = times = divide = false;
        ui->lowerLine->setText("-");
        ui->upperLine->setText("");
        ui->operationLabel->setText("-");
        break;

    }
    case 3:{
        if (a == NULL){
            a = ui->upperLine->text().toDouble();
        }
        times = true;
        plus = minus = divide = false;
        ui->lowerLine->setText("*");
        ui->upperLine->setText("");
        ui->operationLabel->setText("*");
        break;

    }
    case 4:{
        if (a == NULL){
            a = ui->upperLine->text().toDouble();
        }
        divide = true;
        plus = minus = times = false;
        ui->lowerLine->setText("/");
        ui->upperLine->setText("");
        ui->operationLabel->setText("/");
        break;

    }

   }
}

void MainWindow::on_equals_clicked(){
    b = ui->upperLine->text().toDouble();
    if(plus == true){
        c = a + b;
        ui->upperLine->setText(QString::number(c));
    }
    else if(minus == true){
        c = a - b;
        ui->upperLine->setText(QString::number(c));
    }
    else if(times == true){
        c = a * b;
        ui->upperLine->setText(QString::number(c));
    }
    else if(divide == true){
        c = a / b;
        ui->upperLine->setText(QString::number(c));
    }
    plus = minus = times = divide = false;
    ui->operation->setValue(0);
    ui->operationLabel->setText("");
    a = ui->upperLine->text().toDouble();
}

void MainWindow::on_square_clicked(){
    ui->lowerLine->setText("²");
    a = ui->upperLine->text().toDouble();
    c = a * a;
    ui->upperLine->setText(QString::number(c));
}

void MainWindow::on_sign_clicked(){
    if(ui->upperLine->text().contains("-")){
        ui->upperLine->setCursorPosition(1);
        ui->upperLine->backspace();
    }
    else{
        ui->upperLine->setText("-" + ui->upperLine->text());
    }
}

void MainWindow::on_backspace_clicked(){
    ui->upperLine->backspace();
}

void MainWindow::on_copyright_clicked(){
    ui->upperLine->setText("");
    ui->lowerLine->setText("");
    ui->operation->setValue(0);
    ui->upperLine->setText("© Copyright info here.");
}

void MainWindow::on_squareRoot_clicked(){
    ui->lowerLine->setText("√");
    a = ui->upperLine->text().toDouble();
    c = sqrt(a);
    ui->upperLine->setText(QString::number(c));
}

void MainWindow::on_percentage_clicked(){
    b = ui->upperLine->text().toDouble();
    if (times == true){
        c = a * b * 0.01;
        ui->upperLine->setText(QString::number(c));
    }


    plus = minus = times = divide = false;
    ui->operation->setValue(0);
    ui->lowerLine->setText("%");
    ui->operationLabel->setText("");
}

