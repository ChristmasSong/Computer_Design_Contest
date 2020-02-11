#include <iostream>
#include <opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include"SolutionOperator.h"

using namespace std;
using namespace cv;

const string CuSO4[7] = {"./溶液图像/硫酸铜(0).jpg",
					     "./溶液图像/硫酸铜(1).jpg",
					     "./溶液图像/硫酸铜(2).jpg",
					     "./溶液图像/硫酸铜(3).jpg",
					     "./溶液图像/硫酸铜(4).jpg",
					     "./溶液图像/硫酸铜(5).jpg",
					     "./溶液图像/硫酸铜(x).jpg"};

const string CoSO4[7] = {"./溶液图像/硫酸钴(0).jpg",
						 "./溶液图像/硫酸钴(1).jpg",
						 "./溶液图像/硫酸钴(2).jpg",
						 "./溶液图像/硫酸钴(3).jpg",
						 "./溶液图像/硫酸钴(4).jpg",
						 "./溶液图像/硫酸钴(5).jpg",
						 "./溶液图像/硫酸钴(x).jpg"};


const string NiSO4[7] = {"./溶液图像/硫酸镍(0).jpg",
						 "./溶液图像/硫酸镍(1).jpg",
						 "./溶液图像/硫酸镍(2).jpg",
						 "./溶液图像/硫酸镍(3).jpg",
						 "./溶液图像/硫酸镍(4).jpg",
						 "./溶液图像/硫酸镍(5).jpg",
						 "./溶液图像/硫酸镍(x).jpg" };

Mat polyfit(vector<Point2d>& solutions_vector, int n, double x);
double get_mol(Vec4d line_para, double x);

int main()
{
	SolutionList solutions_CuSO4(CuSO4, 7);
	SolutionList solutions_CoSO4(CoSO4, 7);
	SolutionList solutions_NiSO4(NiSO4, 7);
	SolutionOperator CuSO4(solutions_CuSO4);
	SolutionOperator CoSO4(solutions_CoSO4);
	SolutionOperator NiSO4(solutions_NiSO4);
	cout << "------------------------------------------------------------------" << endl;
	/*计算平均RGB--*/
	for (int i = 0; i < 7; i++)
	{
		CuSO4.getRGB_average(i);
		CoSO4.getRGB_average(i);
		NiSO4.getRGB_average(i);
	}
	/*--计算平均RGB*/
	//double* CuSO4_RGB_n = CuSO4.compute_RGB_P();
	//double* CoSO4_RGB_n = CoSO4.compute_RGB_P();
	//double* NiSO4_RGB_n = NiSO4.compute_RGB_P();
	//for (int i = 0; i < 6; i++)
	//	cout << i + 1 << " : " << CuSO4_RGB_n[i] << endl;
	//cout << "------------------------------------------------------------------" << endl;
	/*设置溶液浓度--*/
	for (int i = 0; i < 6; i++)
	{
		CuSO4.set_mol(i, i * 0.1);
		CoSO4.set_mol(i, i * 0.1);
		NiSO4.set_mol(i, i * 0.1);
	}
	/*--设置溶液浓度*/
	solutions_CuSO4.showSolutions();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showSolutions();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showSolutions();
	/*计算对比RGB_P--*/
	CuSO4.compute_RGB_P();
	CoSO4.compute_RGB_P();
	NiSO4.compute_RGB_P();
	/*--计算对比RGB_P*/
	cout << "------------------------------------------------------------------" << endl;
	solutions_CuSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	
	/*坐标赋值-->*/
	Point2d CuSO4_Point[5];	//Point2d代表point的x和y是double型
	Point2d CoSO4_Point[5];
	Point2d NiSO4_Point[5];
	for (int i = 1; i <= 5; i++)
	{
		CuSO4_Point[i - 1].x = solutions_CuSO4[i]->RGB_P; CuSO4_Point[i - 1].y = solutions_CuSO4[i]->mol;
		CoSO4_Point[i - 1].x = solutions_CoSO4[i]->RGB_P; CoSO4_Point[i - 1].y = solutions_CoSO4[i]->mol;
		NiSO4_Point[i - 1].x = solutions_NiSO4[i]->RGB_P; NiSO4_Point[i - 1].y = solutions_NiSO4[i]->mol;
	}
	vector<Point2d> CuSO4_vector(begin(CuSO4_Point), end(CuSO4_Point));
	vector<Point2d> CoSO4_vector(begin(CoSO4_Point), end(CoSO4_Point));
	vector<Point2d> NiSO4_vector(begin(NiSO4_Point), end(NiSO4_Point));
	cout << "\t RGB_P(x) \t mol(y)" << endl
		<< CuSO4_vector << "\n" << endl
		<< CoSO4_vector << "\n" << endl
		<< NiSO4_vector << "\n" << endl;
	/*-->坐标赋值*/
	CuSO4.polyfit(CuSO4_vector);
	CoSO4.polyfit(CoSO4_vector);
	NiSO4.polyfit(NiSO4_vector);
	cout << CuSO4.get_x_mol(solutions_CuSO4[6]->RGB_P) << endl
		<< CoSO4.get_x_mol(solutions_CoSO4[6]->RGB_P) << endl
		<< NiSO4.get_x_mol(solutions_NiSO4[6]->RGB_P) << endl;
	return 0;
}
/*参数n暂时没用*/
/*以下函数已封装入SolutionOperator类中*/
Mat polyfit(vector<Point2d>& solutions_vector, int n, double x)
{
	Mat Solution_image = cv::Mat::zeros(480, 640, CV_8UC3);
	Vec4d line_para;
	fitLine(solutions_vector, line_para, DIST_L2, 0, 1e-6, 1e-1);		//DIST_L2代表最小二乘法
	double k_line = line_para[1] / line_para[0];	//计算k
	Point2d p1(0, k_line * (0 - line_para[2]) + line_para[3]);
	Point2d p2(Solution_image.cols - 1, k_line * ((double)Solution_image.cols - 1 - line_para[2]) + line_para[3]);
	char text_equation[1024];
	sprintf_s(text_equation, "y=%.2f(x-%.2f)+%.2f", line_para[3], k_line, line_para[2]);
	double y = get_mol(line_para, x);
	cout << "y is :" << y << endl;

	putText(Solution_image, text_equation, Point(60, 50), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 255), 1, 8);
	line(Solution_image, p1, p2, Scalar(0, 0, 255), 2);
	return Solution_image;
}	
double get_mol(Vec4d line_para, double x)
{
	Mat Solution_image = cv::Mat::zeros(480, 640, CV_8UC3);
	double k_line = line_para[1] / line_para[0];	//计算k
	Point2d p1(0, k_line * (0 - line_para[2]) + line_para[3]);
	Point2d p2(Solution_image.cols - 1, k_line * ((double)Solution_image.cols - 1 - line_para[2]) + line_para[3]);
	double y = p1.y + ((p2.y - p1.y) / (p2.x - p1.x)) * (x - p1.x);
	return y;
}
