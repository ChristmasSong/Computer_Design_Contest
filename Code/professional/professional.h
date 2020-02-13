#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include"error.h"
//加入错误提示类

#include <QMainWindow>
#include <QDebug>
#include<QDesktopServices>
#include <QUrl>
#include<QPixmap>
#include<QImage>
#include<QString>
#include<QSize>
#include<QFileDialog>
#include<QString>
#include<QVector>
namespace Ui {
class Professional;
}

class Professional : public QMainWindow
{
    Q_OBJECT

public:
    explicit Professional(QWidget *parent = 0);
    ~Professional();
private slots:
    void on_upload_clicked();//上传图片
    void on_add_clicked();//添加溶液浓度信息
    void on_fit_clicked();//拟合按钮fit

private:
    Ui::Professional *ui;
    error e;//错误对话框e
    QPixmap Pic,viewPic,showPic;//Pic保存当前上传的这张图片,viewPic为缩小预览,showPic为适于右侧预览的大小
    //QImage open_P;//资料说QImage可以对像素点操作，如果处理图像必要可以换这个
    QString open_fileName;
    int picnum;//上传图片个数
    float con;//用户输入的溶液浓度(concentration)，即c_value（Line Edit类型）中的值
    QVector <float> mol;//浓度数组
    QVector <QString> value;//RGB数组，由于只需显示出来，所以用字符串类型。避免三元数组或链表。计算后可用toString之类转化一下类型

    void pic1show();//小图预览
    void pic2show();
    void pic3show();
    void pic4show();
    void pic5show();
    void pic6show();
};

#endif // PROFESSIONAL_H
