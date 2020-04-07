#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include<QMainWindow>
#include<qmessagebox.h>
#include<QDebug>
#include<QDesktopServices>
#include<QUrl>
#include<QPixmap>
#include<QImage>
#include<QString>
#include<QSize>
#include<QFileDialog>
#include<QString>
#include<QVector>
#include"SolutionOperator.h"
#include"ClickedLabel.h"

namespace Ui 
{
	class Professional;
}

enum Picture{pic_show, pic1, pic2, pic3, pic4, pic5, pic6, pic7, cal_show};

class Professional : public QMainWindow
{
    Q_OBJECT
public:
    explicit Professional(QWidget *parent = 0);
    ~Professional();
private slots:
    void on_add_clicked();//添加溶液浓度信息
    void on_fit_clicked();//拟合按钮fit
	void on_pic_clicked();

	void on_pic1_clicked();  
	void pic1_doubleClicked();
	void on_pic2_clicked();
	void pic2_doubleClicked();
	void on_pic3_clicked();
	void pic3_doubleClicked();
	void on_pic4_clicked();
	void pic4_doubleClicked();
	void on_pic5_clicked();
	void pic5_doubleClicked();
	void on_pic6_clicked();
	void pic6_doubleClicked();
	void on_pic7_clicked();
	void pic7_doubleClicked();
	void on_radioButton_CoSO4_clicked();
	void on_radioButton_CuSO4_clicked();
	void on_radioButton_NiSO4_clicked();
	void on_pushButton_compute_clicked();

	void restart();

private:
    Ui::Professional *ui;
    QPixmap Pic,viewPic,showPic;		//Pic保存当前上传的这张图片,viewPic为缩小预览,showPic为适于右侧预览的大小
    //QImage open_P;					//资料说QImage可以对像素点操作，如果处理图像必要可以换这个
    QString img_path;
    int img_index;						//上传图片个数
    double con;							//用户输入的溶液浓度(concentration)，即c_value（Line Edit类型）中的值
    QVector <double>* mol_show;			//浓度数组
    QVector <QString>* value_show;		//RGB数组，由于只需显示出来，所以用字符串类型。避免三元数组或链表。计算后可用toString之类转化一下类型
	SolutionList solutions;
	SolutionOperator *solutionsOperator;
	SolutionList solution_fast;
	SolutionOperator* solutionOperator_fast;
	//控制变量
	bool update_flag;					//true为添加数据，false为修改数据

	//提高内聚度
	string qstr2str(const QString qstr);
	QString str2qstr(const string str);
	void update_RGB_show();				//更新视图界面
	void update_RGB_show_fast();		//更新视图界面
	bool upload_img();					//上传图像
	QString upload_img_fast();
	void pic_cal_show();
	Vec4d polyfit();
	//代码重构
	void update_pic(Picture index, QPixmap pixmap);	//pic_show => 0, cal_show =>8 
	//
	void update_Parameter();			// 更新界面Parameter同时计算得出RGB_P
	void show_value_mol(int index);
};

#endif // PROFESSIONAL_H
