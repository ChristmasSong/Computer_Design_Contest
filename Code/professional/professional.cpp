#include "professional.h"
#include "ui_professional.h"

Professional::Professional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Professional)
{
    ui->setupUi(this);
    picnum=0;//初始化图片个数为0
    ui->prompt->setVisible(false);//提示语句默认隐藏
}

Professional::~Professional()
{
    delete ui;
}
//上传图片upload
void Professional::on_upload_clicked()
{
    //打开系统目录
    open_fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.bmp)"));
    QSize picSize(101,101);//设置预览小图格式picSize
    QSize showpicSize(291,291);//设置右侧预览大图格式showpicSize
    if(open_fileName!=NULL){
        picnum++;
        Pic.load(open_fileName);//载入图片格式文件到Pic
        showPic=Pic.scaled(showpicSize);//原图缩放到右侧预览大小showpicSize
        ui->cal_show->setPixmap(showPic);//右侧预览设置
        viewPic=Pic.scaled(picSize);//原图缩放到picSize的大小，保存至viewPic待用
        switch (picnum) {//好low的操作..没有高级的算法，就根据上传图片个数显示各自label的图片预览
        case 1:
            pic1show();
            break;
        case 2:
            pic2show();
            break;
        case 3:
            pic3show();
            break;
        case 4:
            pic4show();
            break;
        case 5:
            pic5show();
            break;
        case 6:
            pic6show();
            break;
        default:
            break;
        }
    }
    else{
        qDebug()<<"图片未导入"<<endl;
    }

}
//添加按钮add
void Professional::on_add_clicked()
{
    con=ui->c_value->text().toFloat();//浓度数值由QString转化为float，并保存至con
    if(con&&ui->rgb_value!=NULL){//若rgb、浓度均不空
        ui->prompt->setVisible(false);//隐藏提示语句（这里隐藏是为了防止之前显示过还在）
        mol.append(con);//con压入mol数组中
        value.append(ui->rgb_value->text());//图像RGB信息压入value数组
    }
    else{
        ui->prompt->setVisible(true);//显示提示语句
        qDebug()<<"条件不完整！"<<endl;
    }
}
//拟合按钮fit
void Professional::on_fit_clicked()
{
    if(mol.count()>=3){//已知数据个数不少于3组（mol、value一一对应，仅需判断一个>3即可）

      //(1)QLabel show中显示拟合曲线
    //ui->show->setPixmap(图片名);//图片需为QPixmap类型
    //(2)QLabel r2中显示R方
    //ui->r2->setText(...);
    //(3)QLabel cal_mol中显示测得的溶液浓度
    //ui->cal_mol->
    }
    else{
        e.show();//弹出错误对话框
        qDebug()<<"现有已知信息个数少于3个！"<<endl;
    }
}

//下面都是小窗口预览的函数
void Professional::pic1show()
{
    ui->pic1->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic
    //调用opencv函数，计算rgb值填入r_value,b_value,g_value和rgb_value
    //ui->r_value->
    //ui->b_value->
}
void Professional::pic2show()
{
    ui->pic2->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic
   //同上pic1show调用
}
void Professional::pic3show()
{
    ui->pic3->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic

}
void Professional::pic4show()
{
    ui->pic4->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic

}
void Professional::pic5show()
{
    ui->pic5->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic

}
void Professional::pic6show()
{
    ui->pic6->setPixmap(viewPic);//预览窗口显示缩小后的图viewPic

}
