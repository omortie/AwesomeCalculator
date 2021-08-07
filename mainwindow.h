#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void adadClicked(int);

    void on_jamButton_clicked();

    void on_calcButton_clicked();

private:
    Ui::MainWindow* ui;

    bool isJamClicked = false;
};
#endif // MAINWINDOW_H
