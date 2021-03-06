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
    enum Amaliat {
        Jam,
        Zarb,
        Taghsim,
        Tafrigh
    };

    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void adadClicked(int);

    void on_calcButton_clicked();

    void operatorClicked(int);

private:
    Ui::MainWindow* ui;

    bool isOperatorClicked = false;
    Amaliat currentAmaliat;
    double a = 0, b = 0;
};
#endif // MAINWINDOW_H
