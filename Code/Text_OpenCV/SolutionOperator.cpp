#include "SolutionOperator.h"

SolutionList::SolutionList(const string * path, int path_length)
	:head(new Solution()), length(0)
{
	Solution* p = head;
	for (int i = 0; i < path_length; i++)
	{
		Solution* tmp = new Solution(i, path[i]);
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
	if (index >= length) {
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
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int tmp = img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2];
			tmp /= 3;
			RGB_average += tmp;
		}
	}
	return RGB_average /= img.rows * img.cols;	//rows*cols个像素
}

int SolutionOperator::getRGB_average(int index)
{
	if (solutions[index]->RGB_average != -1)
		return solutions[index]->RGB_average;
	solutions[index]->RGB_average = this->getRGB_average(solutions[index]->path);
	return solutions[index]->RGB_average;
}
