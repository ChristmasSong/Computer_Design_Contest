#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QLabel>
#include<QLineEdit>
#include<QDebug>

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

void MainWindow::on_toolButton_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        QImage* img=new QImage;
        if(! ( img->load(path) ) ) //加载图像
        {
            QMessageBox::information(this,
                         tr("打开图像失败"),
                         tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label_4->setPixmap(QPixmap::fromImage(*img));
        ui->label_4->setScaledContents(true);
        file.close();
        m=1;
    }
}
void MainWindow::on_radioButton_clicked()
{
    t=1;
}
void MainWindow::on_toolButton_5_clicked()
{
    if(t==1&&m==1)
    {
        ui->toolButton_5->setText("硫酸铜");
    }
    else if (l==1&m==1)
    {
         ui->toolButton_5->setText("硫酸镍");
    }
    else if(g==1&m==1)
    {
         ui->toolButton_5->setText("硫酸古");
    }

}

void MainWindow::on_radioButton_2_clicked()
{
    l=1;
}

void MainWindow::on_radioButton_3_clicked()
{
    g=1;
}

void MainWindow::on_toolButton_7_clicked()
{
    if(m==1)
    {
      ui->toolButton_3->setText("0");
      ui->toolButton_4->setText("0");
      ui->toolButton_2->setText("0");
    }
}






