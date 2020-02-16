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

int main()
{
	/*
	**注意每个SolutionList所记录的第一个溶液，也就是索引为0的溶液，是用作对比的溶液
	*/
	SolutionList solutions_CuSO4(CuSO4, 7);
	SolutionList solutions_CoSO4(CoSO4, 7);
	SolutionList solutions_NiSO4(NiSO4, 7);
	SolutionOperator CuSO4_operator(solutions_CuSO4);
	SolutionOperator CoSO4_operator(solutions_CoSO4);
	SolutionOperator NiSO4_operator(solutions_NiSO4);
	cout << "------------------------------------------------------------------" << endl;

	/*计算平均RGB--*/
	for (int i = 0; i < 7; i++)
	{
		CuSO4_operator.getRGB_average(i);
		CoSO4_operator.getRGB_average(i);
		NiSO4_operator.getRGB_average(i);
	}
	/*--计算平均RGB*/

	/*设置溶液浓度--*/
	for (int i = 0; i < 6; i++)
	{
		CuSO4_operator.set_mol(i, i * 0.1);
		CoSO4_operator.set_mol(i, i * 0.1);
		NiSO4_operator.set_mol(i, i * 0.1);
	}
	/*--设置溶液浓度*/

	solutions_CuSO4.showSolutions();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showSolutions();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showSolutions();

	/*计算对比RGB_P--*/
	/*注意！！！！！！！！！！！！！
	**此处只计算了6处RGP_P
	**因为用于对比的溶液(索引号0)的被跳过计算
	*/
	double* CuSO4_RGB_n = CuSO4_operator.compute_RGB_P();
	double* CoSO4_RGB_n = CoSO4_operator.compute_RGB_P();
	double* NiSO4_RGB_n = NiSO4_operator.compute_RGB_P();
	for (int i = 0; i < 6; i++)
		cout<<"solution_CuSO4 "<< i + 1 << " : " << CuSO4_RGB_n[i] << endl;
	cout << "------------------------------------------------------------------" << endl;
	/*--计算对比RGB_P*/

	cout << "------------------------------------------------------------------" << endl;
	solutions_CuSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showRGB_P();
	cout << "------------------------------------------------------------------" << endl;
	
	/*获取RGB单通道的值-->*/
	cout << "获取RGB单通道的值(以CuSO4溶液为例)" << endl;
	int R[7], G[7], B[7], RGB[7];
	for (int i = 0; i < 7; i++)
	{
		R[i] = CuSO4_operator.get_signal_RGB(RGB_type::R, i);
		G[i] = CuSO4_operator.get_signal_RGB(RGB_type::G, i);
		B[i] = CuSO4_operator.get_signal_RGB(RGB_type::B, i);
		RGB[i] = CuSO4_operator.get_signal_RGB(RGB_type::RGB, i);
		printf_s("R[%d] = %d, G[%d] = %d, B[%d] = %d, RGB[%d] = %d \n" ,i ,R[i], i, G[i], i, B[i], i, RGB[i]);
	}
	cout << "------------------------------------------------------------------" << endl;
	/*-->获取RGB单通道的值*/

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
	CuSO4_operator.polyfit(CuSO4_vector);
	CoSO4_operator.polyfit(CoSO4_vector);
	NiSO4_operator.polyfit(NiSO4_vector);
	cout << CuSO4_operator.get_x_mol(solutions_CuSO4[6]->RGB_P) << endl
		<< CoSO4_operator.get_x_mol(solutions_CoSO4[6]->RGB_P) << endl
		<< NiSO4_operator.get_x_mol(solutions_NiSO4[6]->RGB_P) << endl;
	return 0;
}
