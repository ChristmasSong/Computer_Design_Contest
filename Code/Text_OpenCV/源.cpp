#include <iostream>
#include <opencv.hpp>

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
	
	return 0;
}
