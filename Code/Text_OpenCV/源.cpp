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

void computeSolutionRGB(SolutionOperator& solution) {
	for (int i = 0; i < 7; i++)
	{
		cout << i << "  ";
		cout << solution.getRGB_average(RGB_type::R, i) << "  \t";
		cout << solution.getRGB_average(RGB_type::G, i) << "  \t";
		cout << solution.getRGB_average(RGB_type::B, i) << "  \t";
		cout << solution.getRGB_average(RGB_type::RGB, i) << endl;
	}
}

void computeRGB_PAll(SolutionOperator& solution) {
	solution.compute_RGB_P(RGB_type::R);
	solution.compute_RGB_P(RGB_type::G);
	solution.compute_RGB_P(RGB_type::B);
	solution.compute_RGB_P(RGB_type::RGB);
}

void get_target_mol(SolutionList& solutions, SolutionOperator& solutionOp, RGB_type type) {
	cout << "未知溶液的浓度拟合为:" << endl;
	switch (type)
	{
	case R:
		cout << solutionOp.get_x_mol(solutions[6]->rgb_item.R_P) << endl;
		break;
	case G:
		cout << solutionOp.get_x_mol(solutions[6]->rgb_item.G_P) << endl;
		break;
	case B:
		cout << solutionOp.get_x_mol(solutions[6]->rgb_item.B_P) << endl;
		break;
	case RGB:
		cout << solutionOp.get_x_mol(solutions[6]->rgb_item.RGB_P) << endl;
		break;
	}
}

void get_all_mol(SolutionList& solutions, SolutionOperator& solutionOp, RGB_type type) {
	switch (type)
	{
	case R:
		for (int i = 1; i < 7; i++)
		{
			cout << "RGB_P is :" << solutions[i]->rgb_item.R_P
				<< " 拟合mol : " << solutionOp.get_x_mol(solutions[i]->rgb_item.R_P)
				<< " 原mol : " << solutions[i]->mol << endl;
		}
		break;
	case G:
		for (int i = 1; i < 7; i++)
		{
			cout << "RGB_P is :" << solutions[i]->rgb_item.G_P
				<< " 拟合mol : " << solutionOp.get_x_mol(solutions[i]->rgb_item.G_P)
				<< " 原mol : " << solutions[i]->mol << endl;
		}
		break;
	case B:
		for (int i = 1; i < 7; i++)
		{
			cout << "RGB_P is :" << solutions[i]->rgb_item.B_P
				<< " 拟合mol : " << solutionOp.get_x_mol(solutions[i]->rgb_item.B_P)
				<< " 原mol : " << solutions[i]->mol << endl;
		}
		break;
	case RGB:
		for (int i = 1; i < 7; i++)
		{
			cout << "RGB_P is :" << solutions[i]->rgb_item.RGB_P
				<< " 拟合mol : " << solutionOp.get_x_mol(solutions[i]->rgb_item.RGB_P)
				<< " 原mol : " << solutions[i]->mol << endl;
		}
		break;
	}
}

vector<Point2d> loadPoint2Vec(SolutionList& solution, RGB_type type) {
	Point2d points[6];
	switch (type)
	{
	case R:
		for (int i = 0; i < 6; i++)
		{
			points[i].x = solution[i]->mol; points[i].y = solution[i]->rgb_item.R_P;
		}
		break;
	case G:
		for (int i = 0; i < 6; i++)
		{
			points[i].x = solution[i]->mol; points[i].y = solution[i]->rgb_item.G_P;
		}
		break;
	case B:
		for (int i = 0; i < 6; i++)
		{
			points[i].x = solution[i]->mol; points[i].y = solution[i]->rgb_item.B_P;
		}
		break;
	case RGB:
		for (int i = 0; i < 6; i++)
		{
			points[i].x = solution[i]->mol; points[i].y = solution[i]->rgb_item.RGB_P;
		}
		break;
	}
	vector<Point2d> vector(begin(points), end(points));
	return vector;
}

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
	RGB_type type = RGB_type::R;
	cout << "------------------------------------------------------------------" << endl;

	/*计算平均RGB--*/
	computeSolutionRGB(CuSO4_operator);
	cout << "------------------------------------------------------------------" << endl;
	computeSolutionRGB(CoSO4_operator);
	cout << "------------------------------------------------------------------" << endl;
	computeSolutionRGB(NiSO4_operator);
	cout << "------------------------------------------------------------------" << endl;
	/*--计算平均RGB*/

	/*设置溶液浓度--*/
	for (int i = 0; i < 6; i++)
	{
		CuSO4_operator.set_mol(i, i * 0.1);
		CoSO4_operator.set_mol(i, i * 0.1);
		NiSO4_operator.set_mol(i, i * 0.1);
	}
	/*--设置溶液浓度*/

	solutions_CuSO4.showRGB();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showRGB();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showRGB();

	/*计算对比RGB_P--*/
	/*注意！！！！！！！！！！！！！
	xxx此处只计算了6处RGP_P
	xxx因为用于对比的溶液(索引号0)的被跳过计算
	** 2-29日修改，索引0的溶液被用来计算，即计算了7处
	*/
	computeRGB_PAll(CuSO4_operator);
	computeRGB_PAll(CoSO4_operator);
	computeRGB_PAll(NiSO4_operator);
	//solutions_CuSO4.showRGB();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CuSO4.showRGB();
	cout << "------------------------------------------------------------------" << endl;
	solutions_CoSO4.showRGB();
	cout << "------------------------------------------------------------------" << endl;
	solutions_NiSO4.showRGB();
	/*--计算对比RGB_P*/
	
	/*获取RGB单通道的值-->*/
	cout << "获取RGB单通道的值(以CuSO4溶液为例)" << endl;
	double R[7], G[7], B[7], RGB[7];
	for (int i = 0; i < 7; i++)
	{
		R[i] = CuSO4_operator.get_signal_RGB(RGB_type::R, i);
		G[i] = CuSO4_operator.get_signal_RGB(RGB_type::G, i);
		B[i] = CuSO4_operator.get_signal_RGB(RGB_type::B, i);
		RGB[i] = CuSO4_operator.get_signal_RGB(RGB_type::RGB, i);
		printf_s("R[%d] = %.4f, G[%d] = %.4f, B[%d] = %.4f, RGB[%d] = %.4f \n" ,i ,R[i], i, G[i], i, B[i], i, RGB[i]);
	}
	cout << "------------------------------------------------------------------" << endl;
	/*-->获取RGB单通道的值*/

	/*坐标赋值-->*/
	vector<Point2d> CuSO4_vector = loadPoint2Vec(solutions_CuSO4, type);
	vector<Point2d> CoSO4_vector = loadPoint2Vec(solutions_CoSO4, type);
	vector<Point2d> NiSO4_vector = loadPoint2Vec(solutions_NiSO4, type);
	cout << "\t mol(x) \t RGB_P(y)" << endl
		<< "CuSO4_vector is :\n" << CuSO4_vector << "\n" << endl
		<< "CoSO4_vector is :\n" << CoSO4_vector << "\n" << endl
		<< "NiSO4_vector is :\n" << NiSO4_vector << "\n" << endl;
	/*-->坐标赋值*/

	cout << "CuSO4 line_area: \n" << CuSO4_operator.polyfit(CuSO4_vector) << endl;
	cout << "CoSO4 line_area: \n" << CoSO4_operator.polyfit(CoSO4_vector) << endl;
	cout << "NiSO4 line_area: \n" << NiSO4_operator.polyfit(NiSO4_vector) << endl;

	get_target_mol(solutions_CuSO4, CuSO4_operator, type);
	get_target_mol(solutions_CoSO4, CoSO4_operator, type);
	get_target_mol(solutions_NiSO4, NiSO4_operator, type);
	cout << "------------------------------------------------------------------" << endl;
	get_all_mol(solutions_CuSO4, CuSO4_operator, type);
	cout << "------------------------------------------------------------------" << endl;
	get_all_mol(solutions_CoSO4, CoSO4_operator, type);
	cout << "------------------------------------------------------------------" << endl;
	get_all_mol(solutions_NiSO4, NiSO4_operator, type);
	return 0;
}
