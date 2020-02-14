#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_radioButton_clicked();

    void on_toolButton_5_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_toolButton_7_clicked();

private:
    Ui::MainWindow *ui;
    int m=0,t=0,l=0,g=0;
};

#endif // MAINWINDOW_H
