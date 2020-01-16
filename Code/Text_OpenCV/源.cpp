#include <iostream>
#include <opencv.hpp>

#include"SolutionOperator.h"

using namespace std;
using namespace cv;

const string CuSO4[7] = {"./ÈÜÒºÍ¼Ïñ/ÁòËáÍ­(0).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(1).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(2).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(3).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(4).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(5).jpg",
					     "./ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(x).jpg",};

int main()
{
	//cout << "ÁòËáÍ­0: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(0).jpg") << endl;
	//cout << "ÁòËáÍ­1: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(1).jpg") << endl;
	//cout << "ÁòËáÍ­2: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(2).jpg") << endl;
	//cout << "ÁòËáÍ­3: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(3).jpg") << endl;
	//cout << "ÁòËáÍ­4: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(4).jpg") << endl;
	//cout << "ÁòËáÍ­5: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(5).jpg") << endl;
	//cout << "ÁòËáÍ­x: " << getRGB_average("Z:\\Í¼Ïñ´¦Àí\\ÈÜÒºÍ¼Ïñ\\ÁòËáÍ­(x).jpg") << endl;
	cout << "------------------------------------------------------------------" << endl;
	SolutionList solutions_CuSO4(CuSO4, 7);
	SolutionOperator CuSO4(solutions_CuSO4);
	for (int i = 0; i < 7; i++)
		cout << i << " : " << CuSO4.getRGB_average(i) << endl;	//»ñÈ¡RGB

	return 0;
}
