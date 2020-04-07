#include "SolutionOperator.h"

SolutionList::SolutionList(const string* path, int path_length)
	:head(new Solution()), length(0)
{
	Solution* p = head;
	for (int i = 0; i < path_length; i++)
	{
		Solution* tmp = new Solution(i, path[i]);
		tmp->id = i;
		p->next = tmp;	p = tmp;
		length++;
	}
}

SolutionList::~SolutionList()
{
	Solution* q = head;
	Solution* p = head->next;
	while (length != 0)
	{
		q = p;	p = p->next;	//位移
		delete q; length--;		//删除
	}
	delete head;	//掐头
	length = 0;
}

Solution* SolutionList::operator[](int index) const
{
	if (index >= length)
	{
		cout << "索引越界" << endl;
		return NULL;
	}
	Solution* p = head->next;
	for (int i = 0; i < index && p != NULL; i++)
	{
		p = p->next;
	}
	return p;
}
int SolutionList::Length()
{
	return this->length;
}
void SolutionList::append(int i, string path)
{
	Solution* p = head;
	while (p->next)	p = p->next;
	p->next = new Solution(i, path); length++;
}
void SolutionList::showSolutions()
{
	Solution* p = head->next;
	cout << "id\tRGB_average\tmol\t\tpath " << endl;
	for (int i = 0; i < this->length; i++)
	{
		cout << p->id << "\t" << p->RGB_average << "\t\t" << p->mol << "\t" << p->path << endl;
		p = p->next;
	}
}
void SolutionList::showRGB_P()
{
	Solution* p = head->next;
	cout << "id\tRGB_average\tmol\tRGB_P " << endl;
	for (int i = 0; i < this->length; i++)
	{
		cout << p->id << "   \t" << p->RGB_average << "\t\t" << p->mol << "\t" << p->RGB_P << "\t" << endl;
		p = p->next;
	}
}
/********************************************************************/
double SolutionOperator::getRGB_average(string path)
{
	Mat img = imread(path);
	/*判断路径是否合法*/
	if (img.empty())
	{
		cout << "读取图片失败，请检测路径是否正确" << endl;
		exit(-1);
	}
	double RGB_average = 0;
	/*读取图像的RGB信息——区域每像素的平均RGB*/
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			double RGB_tmp = img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2];
			RGB_tmp /= 3;
			RGB_average += RGB_tmp;
		}
	}
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素
}

double SolutionOperator::compute_RGB_P(int index)
{
	return this->solutions[index]->RGB_P
		= log10((double)solutions[0]->RGB_average / solutions[index]->RGB_average);
}

void SolutionOperator::compute_mol(double y, bool log_flag)
{
	if(log_flag)
		y = log10((double)solutions[0]->RGB_average / y);	//把x转换为RGB_P
	double k_line = line_area[1] / line_area[0];	//计算k
	double b = line_area[3] - k_line * line_area[2];
	solution_mol = (y - b) / k_line;
}

double SolutionOperator::getRGB_average(int index)
{
	solutions[index]->RGB_average = this->getRGB_average(solutions[index]->path);
	return solutions[index]->RGB_average;
}

double* SolutionOperator::compute_RGB_P()
{
	double* RGB_n = new double[this->solutions.Length()];
	/*链表第一个结点的溶液是参考溶液，因此跳过计算*/
	for (int i = 0; i < this->solutions.Length(); i++)
	{
		RGB_n[i] = this->compute_RGB_P(i);
	}
	return RGB_n;
}

bool SolutionOperator::set_mol(int index, double mol)
{

	return solutions[index]->set_mol(mol);
}

Vec4d SolutionOperator::polyfit(vector<Point2d>& solutions_vector)
{
	fitLine(solutions_vector, line_area, DIST_L2, 0, 1e-6, 1e-1);		//DIST_L2代表最小二乘法
	return line_area;
}

double SolutionOperator::get_x_mol(double y, bool log_flag)
{
	compute_mol(y, log_flag);
	return this->solution_mol;
}

double SolutionOperator::get_signal_RGB(RGB_type type, int index)
{
	if (type == RGB_type::RGB)
	{
		return getRGB_average(solutions[index]->path);
	}
	Mat img = imread(solutions[index]->path);
	//cout << "path is " << solutions[index]->path << ", the type is " << type << endl;
	/*判断路径是否合法*/
	if (img.empty())
	{
		cout << "读取图片失败，请检测路径是否正确" << endl;
		exit(-1);
	}
	double RGB_average = 0;
	/*读取图像的RGB信息——区域每像素的平均RGB*/
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			double RGB_tmp = img.at<Vec3b>(i, j)[type];
			RGB_average += RGB_tmp;
		}
	}
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素

}
