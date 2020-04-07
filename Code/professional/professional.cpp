#include "professional.h"
#include "ui_professional.h"

Professional::Professional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Professional)
{
    ui->setupUi(this);
    img_index=0;//初始化图片索引为0
    ui->prompt->setVisible(false);//提示语句默认隐藏
	ui->tabWidget->setTabText(0, str2qstr("专业模式"));
	ui->tabWidget->setTabText(1, str2qstr("快捷模式"));
	setWindowIcon(QIcon("./Icon/Logo.png"));

	solutionsOperator = new SolutionOperator(solutions);
	solutionOperator_fast = new SolutionOperator(solution_fast);
	mol_show = new QVector<double>[7];
	value_show = new QVector<QString>[7];
	update_flag = true;	//初始为添加数据
	//connect(ui->add, &QPushButton::clicked, this, &Professional::on_add_clicked);
	connect(ui->pic1, &ClickedLabel::doubleClicked, this, &Professional::pic1_doubleClicked);
	connect(ui->pic2, &ClickedLabel::doubleClicked, this, &Professional::pic2_doubleClicked);
	connect(ui->pic3, &ClickedLabel::doubleClicked, this, &Professional::pic3_doubleClicked);
	connect(ui->pic4, &ClickedLabel::doubleClicked, this, &Professional::pic4_doubleClicked);
	connect(ui->pic5, &ClickedLabel::doubleClicked, this, &Professional::pic5_doubleClicked);
	connect(ui->pic6, &ClickedLabel::doubleClicked, this, &Professional::pic6_doubleClicked);
	connect(ui->pic7, &ClickedLabel::doubleClicked, this, &Professional::pic7_doubleClicked);
	connect(ui->restart, &QAction::triggered, this, &Professional::restart);
}

Professional::~Professional()
{
    delete ui;
	delete solutionsOperator;
	delete solutionOperator_fast;
	delete[] mol_show;
	delete[] value_show;
}

//添加按钮add
void Professional::on_add_clicked()
{
	con = ui->c_value->text().toDouble();//浓度数值由QString转化为double，并保存至con
	if (ui->c_value->text() != NULL && ui->rgb_value->text() != NULL)
	{
		ui->prompt->setVisible(false);//隐藏提示语句（这里隐藏是为了防止之前显示过还在）
		update_Parameter();	//更新Parameter信息
		if (mol_show->length() > 3)
		{
			ui->fit->setEnabled(true);
		}
		else
		{
			ui->fit->setEnabled(false);
		}
	}
	else if (ui->c_value->text() != NULL)
	{
		ui->prompt->setText(str2qstr(string("请上传图像!")));
		ui->prompt->setVisible(true);//显示提示语句
	}
	else
	{
		ui->prompt->setText(str2qstr(string("请输入浓度!")));
		ui->prompt->setVisible(true);//显示提示语句
	}
}
//拟合按钮fit
void Professional::on_fit_clicked()
{	//不需要判断数据个数，个数不够时按钮被锁定无法点击
	if (ui->cal_rgb->text() != NULL)
	{
		Vec4d line_area = polyfit();
		cout << "-----------------------------------------------------" << endl;
		cout << "line_area : " << line_area << endl;
		double mol_x = solutionsOperator->get_x_mol(ui->cal_rgb->text().toDouble(), true);	//目前的问题是没有计算为RGB_P

		double k_line = line_area[1] / line_area[0];	//计算k
		double b = line_area[3] - k_line * line_area[2];

		QString t, kk, bb;
		QString tmp = "y=" + kk.setNum(k_line) + "x +" + bb.setNum(b);
		ui->formula->setText(tmp);
		ui->cal_mol->setText(t.setNum(mol_x));

		QVector<double> x(solutions.Length() - 1), y(solutions.Length() - 1);	//拟合点, 带上索引为0的图像
		const double* rgb_p = solutionsOperator->compute_RGB_P();
		for (int i = 0; i < x.length(); i++)
		{
			y[i] = rgb_p[i];
			x[i] = solutionsOperator->get_x_mol(solutions[i]->RGB_P, false);
			cout << x[i] << " : " << y[i] << endl;
		}
		if (ui->show->graph(0) != NULL && ui->show->graph(1) != NULL)
		{
			ui->show->removeGraph(1);	ui->show->removeGraph(0);
		}
		ui->show->legend->setVisible(true);
		ui->show->addGraph();
		ui->show->graph(0)->setPen(QPen(Qt::black));
		ui->show->graph(0)->setName(str2qstr("拟合曲线"));
		ui->show->xAxis->setLabel("mol /dm^3");
		ui->show->xAxis->labelFont().setPixelSize(14);
		ui->show->yAxis->setLabel("RGB_P");
		ui->show->yAxis->labelFont().setPixelSize(14);
		ui->show->graph(0)->setData(x, y);
		ui->show->rescaleAxes();
		//ui->show->replot();

		QVector<double> xx(solutions.Length() - 1), yy(solutions.Length() - 1);	//实际点
		for (int i = 0; i < xx.length(); i++)
		{
			yy[i] = solutions[i]->RGB_P;
			xx[i] = solutions[i]->mol;
			cout << xx[i] << " : " << yy[i] << endl;
		}
		ui->show->addGraph();
		ui->show->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
		ui->show->graph(1)->setName(str2qstr("实际数据"));
		ui->show->graph(1)->setPen(QPen(Qt::red));
		ui->show->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
		ui->show->graph(1)->setData(xx, yy);
		ui->show->rescaleAxes();
		ui->show->replot();
	}
	else
	{
		QMessageBox::about(NULL, str2qstr("注意"), str2qstr("<font color='red'>请输入RGB(unkonwn)</font>"));
	}
}

void Professional::on_pic_clicked()
{
	QString path = upload_img_fast();
	if (!path.isEmpty())
	{
		if (solution_fast.operator[](0) == NULL)
			solution_fast.append(0, qstr2str(path));
		else
			solution_fast[0]->path = qstr2str(path);
		update_RGB_show_fast();
	}
}

void Professional::on_pic1_clicked()
{
	img_index = 0;
	if (ui->pic1->pixmap() == NULL)
	{
		update_flag = true;
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic1, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic1_doubleClicked()
{
	img_index = 0;
	if (ui->pic1->pixmap() == NULL)
		on_pic1_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic1, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic2_clicked()
{
	img_index = 1;
	if (ui->pic2->pixmap() == NULL)
	{
		update_flag = true;
		if(upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic2, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic2_doubleClicked()
{
	img_index = 1;
	if (ui->pic2->pixmap() == NULL)
		on_pic2_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic2, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic3_clicked()
{
	img_index = 2;
	if (ui->pic3->pixmap() == NULL)
	{
		update_flag = true;
		if(upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic3, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic3_doubleClicked()
{
	img_index = 2;
	if (ui->pic3->pixmap() == NULL)
		on_pic3_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic3, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic4_clicked()
{
	img_index = 3;
	if (ui->pic4->pixmap() == NULL)
	{
		update_flag = true;
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic4, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic4_doubleClicked()
{
	img_index = 3;
	if (ui->pic4->pixmap() == NULL)
		on_pic4_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic4, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic5_clicked()
{
	img_index = 4;
	if (ui->pic5->pixmap() == NULL)
	{
		update_flag = true;
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic5, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic5_doubleClicked()
{
	img_index = 4;
	if (ui->pic5->pixmap() == NULL)
		on_pic5_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic5, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic6_clicked()
{
	img_index = 5;
	if (ui->pic6->pixmap() == NULL)
	{
		update_flag = true;
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic6, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic6_doubleClicked()
{
	img_index = 5;
	if (ui->pic6->pixmap() == NULL)
		on_pic6_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic6, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_pic7_clicked()
{
	img_index = 6;
	if (ui->pic7->pixmap() == NULL)
	{
		update_flag = true;
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic7, Pic.scaled(QSize(101, 101)));
			mol_show->insert(img_index, 0);//con压入mol数组中
			value_show->insert(img_index, ui->rgb_value->text());//图像RGB信息压入value数组
		}
	}
	else
	{
		update_flag = false;
		pic_cal_show();
		update_RGB_show();
	}
}

void Professional::pic7_doubleClicked()
{
	img_index = 6;
	if (ui->pic7->pixmap() == NULL)
		on_pic7_clicked();	//使用单击事件逻辑
	/*说明要重新上传图像, 即修改数据*/
	else
	{
		if (upload_img())
		{
			update_RGB_show();
			update_pic(Picture::cal_show, Pic.scaled(QSize(291, 291)));
			update_pic(Picture::pic_show, Pic.scaled(QSize(471, 251)));
			update_pic(Picture::pic7, Pic.scaled(QSize(101, 101)));
			mol_show->operator[](img_index) = ui->c_value->text().toDouble();
			value_show->operator[](img_index) = ui->rgb_value->text();
		}
	}
}

void Professional::on_radioButton_CoSO4_clicked()
{
	//y=0.606723x +0.0388571
	ui->formula_fast->setText("y = 0.606723x + 0.0388571");
}

void Professional::on_radioButton_CuSO4_clicked()
{
	//y=0.442235x +0.00128054
	ui->formula_fast->setText("y = 0.442235x + 0.00128054");
}

void Professional::on_radioButton_NiSO4_clicked()
{
	//y=0.534524x - 0.018701
	ui->formula_fast->setText("y = 0.534524x - 0.018701");
}

void Professional::on_pushButton_compute_clicked()
{
	if (ui->formula_fast->text() != NULL && ui->rgb_value_fast->text() != NULL)
	{
		/*计算坐标点*/
		string solutions_path[6];
		if (ui->radioButton_CuSO4->isChecked())
		{
			solutions_path[0] = "./溶液图像/硫酸铜(0).jpg";
			solutions_path[1] = "./溶液图像/硫酸铜(1).jpg"; 
			solutions_path[2] = "./溶液图像/硫酸铜(2).jpg";
			solutions_path[3] = "./溶液图像/硫酸铜(3).jpg";
			solutions_path[4] = "./溶液图像/硫酸铜(4).jpg";
			solutions_path[5] = "./溶液图像/硫酸铜(5).jpg";
		}
		else if (ui->radioButton_CoSO4->isChecked())
		{
			solutions_path[0] = "./溶液图像/硫酸钴(0).jpg";
			solutions_path[1] = "./溶液图像/硫酸钴(1).jpg";
			solutions_path[2] = "./溶液图像/硫酸钴(2).jpg";
			solutions_path[3] = "./溶液图像/硫酸钴(3).jpg";
			solutions_path[4] = "./溶液图像/硫酸钴(4).jpg";
			solutions_path[5] = "./溶液图像/硫酸钴(5).jpg";
		}
		else if (ui->radioButton_NiSO4->isChecked())
		{
			solutions_path[0] = "./溶液图像/硫酸镍(0).jpg";
			solutions_path[1] = "./溶液图像/硫酸镍(1).jpg";
			solutions_path[2] = "./溶液图像/硫酸镍(2).jpg";
			solutions_path[3] = "./溶液图像/硫酸镍(3).jpg";
			solutions_path[4] = "./溶液图像/硫酸镍(4).jpg";
			solutions_path[5] = "./溶液图像/硫酸镍(5).jpg";
		}
		SolutionList tmp_solutions(solutions_path, 6);
		SolutionOperator tmp_operator(tmp_solutions);
		for (int i = 0; i < 6; i++)
		{
			tmp_operator.getRGB_average(i);
			tmp_operator.set_mol(i, i * 0.1); 
		}
		tmp_operator.compute_RGB_P();
		//tmp_solutions.showSolutions();
		//cout << "------------------------------------------------------------------" << endl;
		//tmp_solutions.showRGB_P();
		//cout << "------------------------------------------------------------------" << endl;
		Point2d tmp_point[6];
		for (int i = 0; i < 6; i++)
		{
			tmp_point[i].y = tmp_solutions[i]->RGB_P;
			tmp_point[i].x = tmp_solutions[i]->mol;
			cout << tmp_point[i].x << " : " << tmp_point[i].y << endl;
		}
		vector<Point2d> tmp_vector(begin(tmp_point), end(tmp_point));
		Vec4d line_area = tmp_operator.polyfit(tmp_vector);
		double mol_x = tmp_operator.get_x_mol(ui->rgb_value_fast->text().toDouble(), true);
		
		double k_line = line_area[1] / line_area[0];	//计算k
		double b = line_area[3] - k_line * line_area[2];
		QString t, kk, bb;
		QString tmp = "y=" + kk.setNum(k_line) + "x +" + bb.setNum(b);
		ui->formula_fast->setText(tmp);
		ui->label_mol_fast->setText(t.setNum(mol_x));

		QVector<double> x(5), y(5);	//拟合点
		QVector<double> xx(5), yy(5);	//实际点
		const double* rgb_p = tmp_operator.compute_RGB_P();
		for (int i = 0; i < x.length(); i++)
		{
			y[i] = rgb_p[i];
			x[i] = tmp_operator.get_x_mol(tmp_solutions[i]->RGB_P, false);
			yy[i] = tmp_solutions[i]->RGB_P;
			xx[i] = tmp_solutions[i]->mol;
			//cout << x[i] << " : " << y[i] << endl;
			//cout << xx[i] << " : " << yy[i] << endl;
		}
		if (ui->show_fast->graph(0) != NULL && ui->show_fast->graph(1) != NULL)
		{
			ui->show_fast->removeGraph(1);	ui->show_fast->removeGraph(0);
		}

		ui->show_fast->legend->setVisible(true);
		ui->show_fast->addGraph();
		ui->show_fast->graph(0)->setPen(QPen(Qt::black));
		ui->show_fast->graph(0)->setName(str2qstr("拟合曲线"));
		ui->show_fast->xAxis->setLabel("mol /dm^3");
		ui->show_fast->yAxis->setLabel("RGB_P");
		ui->show_fast->graph(0)->setData(x, y);

		ui->show_fast->addGraph();
		ui->show_fast->graph(1)->setPen(QPen(Qt::red));
		ui->show_fast->graph(1)->setName(str2qstr("实际散点"));
		ui->show_fast->graph(1)->setLineStyle(QCPGraph::lsLine);
		ui->show_fast->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
		ui->show_fast->graph(1)->setData(xx, yy);
		ui->show_fast->rescaleAxes();
		ui->show_fast->replot();
	}
	else if(ui->formula_fast->text() == NULL)
		QMessageBox::about(NULL, str2qstr("注意"), str2qstr("<font color='red'>先选择溶液类型哦~</font>"));
	else if (ui->rgb_value_fast->text() == NULL)
		QMessageBox::about(NULL, str2qstr("注意"), str2qstr("<font color='red'>请先上传图像哦~</font>"));
	else
		QMessageBox::about(NULL, str2qstr("注意"), str2qstr("<font color='red'>发生了未知的错误Σ(ŎдŎ|||)ﾉﾉ</font>"));
}

void Professional::restart()
{
	QString program = QApplication::applicationFilePath();
	QStringList arguments = QApplication::arguments();
	QString workingDirectory = QDir::currentPath();
	QProcess::startDetached(program, arguments, workingDirectory);
	QApplication::exit();
}

string Professional::qstr2str(const QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return std::string(cdata);
}

QString Professional::str2qstr(const string str)
{
	return QString::fromLocal8Bit(str.data());
}

void Professional::update_RGB_show()
{
	QString tmp;	//显示RGB信息
	solutionsOperator->getRGB_average(img_index);	//计算更新
	ui->rgb_value->setText(tmp.setNum(solutionsOperator->get_signal_RGB(RGB_type::RGB, img_index)));
	ui->r_value->setText(tmp.setNum(solutionsOperator->get_signal_RGB(RGB_type::R, img_index)));
	ui->g_value->setText(tmp.setNum(solutionsOperator->get_signal_RGB(RGB_type::G, img_index)));
	ui->b_value->setText(tmp.setNum(solutionsOperator->get_signal_RGB(RGB_type::B, img_index)));
}

void Professional::update_RGB_show_fast()
{
	QString tmp;	//显示RGB信息
	ui->rgb_value_fast->setText(tmp.setNum(solutionOperator_fast->get_signal_RGB(RGB_type::RGB, 0)));
	ui->r_value_fast->setText(tmp.setNum(solutionOperator_fast->get_signal_RGB(RGB_type::R, 0)));
	ui->g_value_fast->setText(tmp.setNum(solutionOperator_fast->get_signal_RGB(RGB_type::G, 0)));
	ui->b_value_fast->setText(tmp.setNum(solutionOperator_fast->get_signal_RGB(RGB_type::B, 0)));
}

bool Professional::upload_img()
{
	bool flag = false;
	//打开系统目录, 选择文件
	img_path = QFileDialog::getOpenFileName(nullptr, QObject::tr("Select Image"), QObject::tr("C:/Users/luo/Pictures/"),
		QObject::tr("(*.jpg *.png *.bmp *.tiff);;*.*);;"));
	if (!img_path.isEmpty()) {
		/*视图操作->*/
		Pic.load(img_path);//载入图片格式文件到Pic
		ui->add->setText(str2qstr("添加"));
		/*->视图操作*/

		/*数据操作->*/
		string path = qstr2str(img_path);
		if (solutions.operator[](img_index) == NULL)
			solutions.append(img_index, path);	//添加溶液
		else
			solutions.operator[](img_index)->path = path;
		/*->数据操作*/
		flag = true;
	}
	else {
		//qDebug()<<"图片未导入"<<endl;
		flag = false;
	}
	return flag;
}

QString Professional::upload_img_fast()
{
	QString path = QFileDialog::getOpenFileName(nullptr, QObject::tr("Select image"), QObject::tr("C:/Users/luo/Pictures/"),
		QObject::tr("(*.jpg *.png *.bmp *.tiff);;*.*);;"));
	if (!path.isEmpty())
	{
		QPixmap tmp;
		tmp.load(path);
		ui->pic->setPixmap(tmp.scaled(QSize(481, 351)));
		return path;
	}
	else
		return NULL;
}

void Professional::pic_cal_show()
{
	QPixmap tmp;
	tmp.load(str2qstr(solutions[img_index]->path));
	ui->pic_show->setPixmap(tmp.scaled(QSize(471, 251)));//上侧预览设置
	ui->cal_show->setPixmap(tmp.scaled(QSize(291, 291)));//右侧预览设置
	ui->add->setText(str2qstr("修改"));
}

Vec4d Professional::polyfit()
{
	Point2d solution_points[6];
	for (int i = 0; i < solutions.Length() - 1; i++)
	{
		solution_points[i].y = solutions[i]->RGB_P;
		solution_points[i].x = solutions[i]->mol;
	}
	vector<Point2d> solution_vector(begin(solution_points), end(solution_points));
	return solutionsOperator->polyfit(solution_vector);
}

void Professional::update_pic(Picture index, QPixmap pixmap)
{
	switch (index)
	{
	case Picture::pic_show:
		ui->pic_show->setPixmap(pixmap);	break;
	case Picture::pic1:
		ui->pic1->setPixmap(pixmap);	break;
	case Picture::pic2:
		ui->pic2->setPixmap(pixmap);	break;
	case Picture::pic3:
		ui->pic3->setPixmap(pixmap);	break;
	case Picture::pic4:
		ui->pic4->setPixmap(pixmap);	break;
	case Picture::pic5:
		ui->pic5->setPixmap(pixmap);	break;
	case Picture::pic6:
		ui->pic6->setPixmap(pixmap);	break;
	case Picture::pic7:
		ui->pic7->setPixmap(pixmap);	break;
	case Picture::cal_show:
		ui->cal_show->setPixmap(pixmap);	break;
	}
}

void Professional::update_Parameter()
{
	/*更新solutions数据->*/
	solutionsOperator->set_mol(img_index, con);	//设置mol
	solutionsOperator->getRGB_average(img_index);
	solutionsOperator->compute_RGB_P();
	/*->更新solutions数据*/
	//solutions.showSolutions();
	//cout << "-----------------------------------------------" << endl;
	//solutions.showRGB_P();
	//cout << "-----------------------------------------------" << endl;
	/*更新view数据->*/
	QString t;
	mol_show->operator[](img_index) = con;
	value_show->operator[](img_index) = t.setNum(solutions[img_index]->RGB_P);
	show_value_mol(img_index);
	/*->更新view数据*/
}

void Professional::show_value_mol(int index)
{
	QString m;
	m.setNum(mol_show->operator[](index));
	switch (index)
	{
	case 0:
		ui->v1->setText(value_show->operator[](index));
		ui->mol1->setText(m);
		m.append(" mol");
		ui->pic1_mol->setText(m);
		break;
	case 1:
		ui->v2->setText(value_show->operator[](index));
		ui->mol2->setText(m);
		m.append(" mol");
		ui->pic2_mol->setText(m);
		break;
	case 2:
		ui->v3->setText(value_show->operator[](index));
		ui->mol3->setText(m);
		m.append(" mol");
		ui->pic3_mol->setText(m);
		break;
	case 3:
		ui->v4->setText(value_show->operator[](index));
		ui->mol4->setText(m);
		m.append(" mol");
		ui->pic4_mol->setText(m);
		break;
	case 4:
		ui->v5->setText(value_show->operator[](index));
		ui->mol5->setText(m);
		m.append(" mol");
		ui->pic5_mol->setText(m);
		break;
	case 5:
		ui->v6->setText(value_show->operator[](index));
		ui->mol6->setText(m);
		m.append(" mol");
		ui->pic6_mol->setText(m);
		break;
	default:
		break;
	}
}
