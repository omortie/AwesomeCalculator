#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->adadGroup, SIGNAL(buttonClicked(int)), this, SLOT(adadClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->aEdit->setText(ui->pushButton_2->text());
}

void MainWindow::adadClicked(int index)
{
    if (isJamClicked) {
        ui->bEdit->setText(ui->adadGroup->button(index)->text());
    } else {
        ui->aEdit->setText(ui->adadGroup->button(index)->text());
    }
}

void MainWindow::on_jamButton_clicked()
{
    isJamClicked = true;
}

void MainWindow::on_calcButton_clicked()
{
    int a = ui->aEdit->text().toInt();
    int b = ui->bEdit->text().toInt();

    int result = a + b;
    ui->resultLabel->setText(QString::number(result));

    isJamClicked = false;
    ui->aEdit->setText("");
    ui->bEdit->setText("");
}
