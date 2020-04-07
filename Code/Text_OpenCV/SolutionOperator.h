#pragma once
#include <iostream>
#include<cmath>
#include <opencv.hpp>

using namespace std;
using namespace cv;

struct RGB_item {
	double R;	//各项均为计算得的平均值
	double G;
	double B;
	double RGB;
	double R_P;
	double G_P;
	double B_P;
	double RGB_P;
};

struct Solution{
	string path;
	int id;
	RGB_item rgb_item;
	double mol;
	Solution* next;
	Solution():path(""), id(-1), next(NULL), mol(-1)
	{
		rgb_item.RGB = -1;	rgb_item.RGB_P = -1;
	}
	Solution(int i, string p):path(p), id(-1), next(NULL), mol(-1)
	{
		rgb_item.RGB = -1;	rgb_item.RGB_P = -1;
	}
	bool set_mol(double m) { this->mol = m; return true; }
};

class SolutionList {
private:
	Solution* head;
	int length;
public:
	SolutionList():head(new Solution()), length(0){}
	SolutionList(const string* path, int path_length);
	~SolutionList();
	Solution* operator[](int index) const;
	int Length();
	void append(int i, string path);
	void showSolutions();
	void showRGB_P();
	void showRGB();
};

/*此枚举用来获取图像的RGB三通道的值*/
enum RGB_type {B, G, R, RGB};

class SolutionOperator {
private:
	SolutionList& solutions;
	double solution_mol = -1;
	Vec4d line_area;
protected:
	double getRGB_average(RGB_type type, string path);
	double compute_RGB_P(RGB_type type, int index);
	double compute_RGB(RGB_type type, Mat img);
	void compute_mol(double x);
public:
	SolutionOperator(SolutionList& s) :solutions(s) {}
	~SolutionOperator() {}
	double getRGB_average(RGB_type type, int index);
	double* compute_RGB_P(RGB_type type);
	bool set_mol(int index, double mol);
	Vec4d polyfit(vector<Point2d>& solutions_vector);
	double get_x_mol(double y);
	double get_signal_RGB(RGB_type type, int index);
};
