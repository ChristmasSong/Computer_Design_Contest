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

Mat polyfit(vector<Point2d>& solutions_vector, int n);


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
	 
	Mat CuSO4_image = cv::Mat::zeros(480, 640, CV_8UC3);
	//for (int i = 0; i < 5; i++)
	//	circle(CuSO4_image, CuSO4_vector[i], 0, cv::Scalar(255, 255, 255), 2, 8, 5);
	Vec4d line_para;
	fitLine(CuSO4_vector, line_para, DIST_L2, 0, 1e-6, 1e-1);		//DIST_L2代表最小二乘法
	cout << "line_para = " << line_para << endl;
	double k_line = line_para[1] / line_para[0];
	Point p1(0, k_line * (0 - line_para[2]) + line_para[3]);
	Point p2(CuSO4_image.cols - 1, k_line * ((double)CuSO4_image.cols - 1 - line_para[2]) + line_para[3]);
	char text_equation[1024];
	sprintf_s(text_equation, "y=%.2f(x-%.2f)+%.2f", line_para[3], k_line, line_para[2]);
	putText(CuSO4_image, text_equation, Point(60, 50), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 255), 1, 8);
	line(CuSO4_image, p1, p2, Scalar(0, 0, 255), 2);
	cv::imshow("CuSO4_image", CuSO4_image);
	cv::waitKey(0);
	return 0;
}
/*暂时没用*/
Mat polyfit(vector<Point2d>& solutions_vector, int n)
{
	size_t size = solutions_vector.size();
	//所求未知数个数
	int x_num = n + 1;
	//构造矩阵U和Y
	Mat mat_u(size, x_num, CV_64F);
	Mat mat_y(size, 1, CV_64F);
	for (int i = 0; i < mat_u.rows; ++i)
		for (int j = 0; j < mat_u.cols; ++j)
			mat_u.at<double>(i, j) = pow(solutions_vector[i].x, j);
	for (int i = 0; i < mat_y.rows; ++i)
		mat_y.at<double>(i, 0) = solutions_vector[i].y;
	//矩阵运算，获得系数矩阵K
	Mat mat_k(x_num, 1, CV_64F);
	mat_k = (mat_u.t() * mat_u).inv() * mat_u.t() * mat_y;
	cout<<"mat_k is : "<< mat_k << endl;
	return mat_k;
}
