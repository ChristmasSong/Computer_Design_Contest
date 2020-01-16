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
		q = p;	p = p->next;	//λ��
		delete q; length--;		//ɾ��
	}
	delete head;	//��ͷ
	length = 0;
}

Solution* SolutionList::operator[](int index) const
{
	if (index >= length) {
		cout << "����Խ��" << endl;
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
	/*�ж�·���Ƿ�Ϸ�*/
	if (img.empty())
	{
		cout << "��ȡͼƬʧ�ܣ�����·���Ƿ���ȷ" << endl;
		exit(-1);
	}
	int RGB_average = 0;
	/*��ȡͼ���RGB��Ϣ��������ÿ���ص�ƽ��RGB*/
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int tmp = img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2];
			tmp /= 3;
			RGB_average += tmp;
		}
	}
	return RGB_average /= img.rows * img.cols;	//rows*cols������
}

int SolutionOperator::getRGB_average(int index)
{
	if (solutions[index]->RGB_average != -1)
		return solutions[index]->RGB_average;
	solutions[index]->RGB_average = this->getRGB_average(solutions[index]->path);
	return solutions[index]->RGB_average;
}
