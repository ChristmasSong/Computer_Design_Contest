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
void SolutionList::showSolutions()
{
	Solution* p = head->next;
	cout << "id\tRGB_average\tmol\t\tpath "<< endl;
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
		cout << p->id << "   \t" << p->RGB_average << "\t\t" << p->mol << "\t" << p->RGB_P<< "\t" << endl;
		p = p->next;
	}
}
/********************************************************************/
int SolutionOperator::getRGB_average(string path)
{
	Mat img = imread(path);
	/*判断路径是否合法*/
	if (img.empty())
	{
		cout << "读取图片失败，请检测路径是否正确" << endl;
		exit(-1);
	}
	int RGB_average = 0;
	/*读取图像的RGB信息——区域每像素的平均RGB*/
	for (int i = 0; i < img.rows; i++) 
	{
		for (int j = 0; j < img.cols; j++)
		{
			int tmp = img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2];
			tmp /= 3;
			RGB_average += tmp;
		}
	}
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素
}

double SolutionOperator::compute_RGB_P(int index)
{
	return this->solutions[index]->RGB_P
	= log((double)solutions[0]->RGB_average / solutions[index]->RGB_average);
}

void SolutionOperator::compute_mol(double x)
{
	double k_line = line_area[1] / line_area[0];	//计算k
	Point2d p1(0, k_line * (0 - line_area[2]) + line_area[3]);
	Point2d p2(Solution_mat.cols - 1, k_line * ((double)Solution_mat.cols - 1 - line_area[2]) + line_area[3]);
	solution_mol = p1.y + ((p2.y - p1.y) / (p2.x - p1.x)) * (x - p1.x);
}

int SolutionOperator::getRGB_average(int index)
{
	if (solutions[index]->RGB_average != -1)
		return solutions[index]->RGB_average;
	solutions[index]->RGB_average = this->getRGB_average(solutions[index]->path);
	//cout << "solutions[index]->RGB_average 2 : " << solutions[index]->RGB_average << endl;
	return solutions[index]->RGB_average;
}

double* SolutionOperator::compute_RGB_P()
{
	double* RGB_n = new double[this->solutions.Length() - 1];
	/*链表第一个结点的溶液是参考溶液，因此跳过计算*/
	for (int i = 1; i < this->solutions.Length(); i++)
	{
		RGB_n[i - 1] = this->compute_RGB_P(i);
	}
	return RGB_n;
}

bool SolutionOperator::set_mol(int index, double mol)
{
	return solutions[index]->set_mol(mol);
}

Vec4d SolutionOperator::polyfit(vector<Point2d>& solutions_vector)
{
	Solution_mat = cv::Mat::zeros(480, 640, CV_8UC3);
	fitLine(solutions_vector, line_area, DIST_L2, 0, 1e-6, 1e-1);		//DIST_L2代表最小二乘法
	return line_area;
}

double SolutionOperator::get_x_mol(double x)
{
	compute_mol(x);
	return this->solution_mol;
}
