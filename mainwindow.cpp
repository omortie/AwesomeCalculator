#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->jamButton->setProperty("amaliat", Jam);
    ui->tafrighButton->setProperty("amaliat", Tafrigh);
    ui->zarbButton->setProperty("amaliat", Zarb);
    ui->taghsimButton->setProperty("amaliat", Taghsim);

    connect(ui->adadGroup, SIGNAL(buttonClicked(int)), this, SLOT(adadClicked(int)));
    connect(ui->operatorGroup, SIGNAL(buttonClicked(int)), this, SLOT(operatorClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adadClicked(int index)
{
    if (isJamClicked) {
        ui->bEdit->setText(ui->adadGroup->button(index)->text());
    } else {
        ui->aEdit->setText(ui->adadGroup->button(index)->text());
    }
}

void MainWindow::on_calcButton_clicked()
{
    int a = ui->aEdit->text().toInt();
    int b = ui->bEdit->text().toInt();

    int result = 0;
    switch (currentAmaliat) {
    case Jam:
        result = a + b;
        break;
    case Zarb:
        result = a * b;
        break;
    case Tafrigh:
        result = a - b;
        break;
    case Taghsim:
        result = a / b;
        break;
    }

    ui->resultLabel->setText(QString::number(result));

    isJamClicked = false;
    ui->aEdit->setText("");
    ui->bEdit->setText("");
}

void MainWindow::operatorClicked(int index)
{
    ui->operatorLabel->setText(ui->operatorGroup->button(index)->text());

    currentAmaliat = static_cast<Amaliat>(ui->operatorGroup->button(index)->property("amaliat").toInt());

    isJamClicked = true;
}
