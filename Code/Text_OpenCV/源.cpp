#include <iostream>
#include <opencv.hpp>

#include"SolutionOperator.h"

using namespace std;
using namespace cv;

const string CuSO4[7] = {"./��Һͼ��/����ͭ(0).jpg",
					     "./��Һͼ��\\����ͭ(1).jpg",
					     "./��Һͼ��\\����ͭ(2).jpg",
					     "./��Һͼ��\\����ͭ(3).jpg",
					     "./��Һͼ��\\����ͭ(4).jpg",
					     "./��Һͼ��\\����ͭ(5).jpg",
					     "./��Һͼ��\\����ͭ(x).jpg",};

int main()
{
	//cout << "����ͭ0: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(0).jpg") << endl;
	//cout << "����ͭ1: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(1).jpg") << endl;
	//cout << "����ͭ2: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(2).jpg") << endl;
	//cout << "����ͭ3: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(3).jpg") << endl;
	//cout << "����ͭ4: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(4).jpg") << endl;
	//cout << "����ͭ5: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(5).jpg") << endl;
	//cout << "����ͭx: " << getRGB_average("Z:\\ͼ����\\��Һͼ��\\����ͭ(x).jpg") << endl;
	cout << "------------------------------------------------------------------" << endl;
	SolutionList solutions_CuSO4(CuSO4, 7);
	SolutionOperator CuSO4(solutions_CuSO4);
	for (int i = 0; i < 7; i++)
		cout << i << " : " << CuSO4.getRGB_average(i) << endl;	//��ȡRGB

	return 0;
}
