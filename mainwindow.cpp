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
    ui->aEdit->setText(ui->aEdit->text() + ui->adadGroup->button(index)->text());
}

void MainWindow::on_calcButton_clicked()
{
    QStringList inputs = ui->aEdit->text().split(" ");
    if (inputs.size() < 2) {
        return;
    }

    b = ui->aEdit->text().split(" ").at(2).toDouble();

    double result
        = 0;
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

    ui->resultLabel->display(QString::number(result));

    isOperatorClicked = false;
    ui->aEdit->clear();
}

void MainWindow::operatorClicked(int index)
{
    a = ui->aEdit->text().toDouble();

    ui->aEdit->setText(ui->aEdit->text() + " " + ui->operatorGroup->button(index)->text() + " ");

    currentAmaliat = static_cast<Amaliat>(ui->operatorGroup->button(index)->property("amaliat").toInt());

    isOperatorClicked = true;
}
