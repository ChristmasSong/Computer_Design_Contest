#include "SolutionOperator.h"

SolutionList::SolutionList(const string * path, int path_length)
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
		exit(-1);
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
	cout << "id\tRGB_average\tmol\t\tpath "<< endl;
	for (int i = 0; i < this->length; i++)
	{
		cout << p->id << "\t" << p->rgb_item.RGB << "\t\t" << p->mol << "\t" << p->path << endl;
		p = p->next;
	}
}
void SolutionList::showRGB_P()
{
	Solution* p = head->next;
	cout << "id\tRGB_average\tmol\tRGB_P " << endl;
	for (int i = 0; i < this->length; i++)
	{
		cout << p->id << "   \t" << p->rgb_item.RGB << "\t\t" << p->mol << "\t" << p->rgb_item.RGB_P<< "\t" << endl;
		p = p->next;
	}
}
void SolutionList::showRGB()
{
	Solution* p = head->next;
	cout << "id  R  G  B  RGB  R_P  G_P  B_P  RGB_P" << endl;
	for (int i = 0; i < this->length; i++)
	{
		cout << p->id << "  " << p->rgb_item.R << "  " << p->rgb_item.G << "  " << p->rgb_item.B << "  "
			<< p->rgb_item.RGB << "  " << p->rgb_item.R_P << "  " << p->rgb_item.G_P << "  " << p->rgb_item.B_P << "  " << p->rgb_item.RGB_P << endl;
		p = p->next;
	}
}
/********************************************************************/
double SolutionOperator::getRGB_average(RGB_type type, string path)
{
	Mat img = imread(path);
	/*判断路径是否合法*/
	if (img.empty())
	{
		cout << "读取图片失败，请检测路径是否正确" << endl;
		exit(-1);
	}
	double RGB_average = compute_RGB(type, img);
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素
}

double SolutionOperator::compute_RGB_P(RGB_type type, int index)
{
	double tmp = 0.0;
	switch (type)
	{
	case R:
		tmp = log10((double)solutions[0]->rgb_item.R / solutions[index]->rgb_item.R);
		this->solutions[index]->rgb_item.R_P = tmp;
		break;
	case G:
		tmp = log10((double)solutions[0]->rgb_item.G / solutions[index]->rgb_item.G);
		this->solutions[index]->rgb_item.G_P = tmp;
		break;
	case B:
		tmp = log10((double)solutions[0]->rgb_item.B / solutions[index]->rgb_item.B);
		this->solutions[index]->rgb_item.B_P = tmp;
		break;
	case RGB:
		tmp = log10((double)solutions[0]->rgb_item.RGB / solutions[index]->rgb_item.RGB);
		this->solutions[index]->rgb_item.RGB_P = tmp;
		break;
	}
	return tmp;
}

double SolutionOperator::compute_RGB(RGB_type type, Mat img)
{
	double RGB_average = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			double RGB_tmp = 0;
			if (type == RGB_type::RGB)
			{
				for (int k = 0; k < type; k++)
					RGB_tmp += img.at<Vec3b>(i, j)[k];
				RGB_tmp /= 3;
			}
			else
				RGB_tmp += img.at<Vec3b>(i, j)[type];
			RGB_average += RGB_tmp;
		}
	}
	return RGB_average;
}

void SolutionOperator::compute_mol(double y)
{
	double k_line = line_area[1] / line_area[0];	//计算k
	double b = line_area[3] - k_line * line_area[2];
	// y = k*x + b
	cout << "k = " << k_line
		<< " b = -" << b << endl;
	solution_mol = (y - b) / k_line;
}

double SolutionOperator::getRGB_average(RGB_type type, int index)
{
	if (type > 3)	return -1;
	double tmp = this->get_signal_RGB(type, index);
	switch (type)
	{
	case R:
		solutions[index]->rgb_item.R = tmp;
		break;
	case G:
		solutions[index]->rgb_item.G = tmp;
		break;
	case B:
		solutions[index]->rgb_item.B = tmp;
		break;
	case RGB:
		solutions[index]->rgb_item.RGB = tmp;
		break;
	}
	//cout << "solutions[index]->rgb_item.RGB 2 : " << solutions[index]->rgb_item.RGB << endl;
	return tmp; 
}

double* SolutionOperator::compute_RGB_P(RGB_type type)
{
	double* RGB_n = new double[this->solutions.Length()];
	for (int i = 0; i < this->solutions.Length(); i++)
	{
		RGB_n[i] = this->compute_RGB_P(type, i);
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

double SolutionOperator::get_x_mol(double y)
{
	compute_mol(y);
	return this->solution_mol;
}

double SolutionOperator::get_signal_RGB(RGB_type type, int index)
{
	Mat img = imread(solutions[index]->path);
	/*判断路径是否合法*/
	if (img.empty())
	{
		cout << "读取图片失败，请检测路径是否正确" << endl;
		exit(-1);
	}
	double RGB_average = compute_RGB(type, img);
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素
}
