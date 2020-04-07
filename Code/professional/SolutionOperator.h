#pragma once
#include <iostream>
#include"qcustomplot.h"
#include<cmath>
#include <opencv.hpp>

using namespace std;
using namespace cv;

struct Solution {
	string path;
	int id;
	double RGB_average;
	double RGB_P;
	double mol;
	Solution* next;
	Solution()
		:path(""), id(-1), next(NULL), RGB_average(-1), RGB_P(-1), mol(-1) {}
	Solution(int i, string p)
		:path(p), id(i), next(NULL), RGB_average(-1), RGB_P(-1), mol(-1) {}
	bool set_mol(double m) { this->mol = m; return true; }
};

class SolutionList {
private:
	Solution* head;
	int length;
public:
	SolutionList() :head(new Solution()), length(0) {}
	SolutionList(const string* path, int path_length);
	~SolutionList();
	Solution* operator[](int index) const;
	int Length();
	void append(int i, string path);
	void showSolutions();
	void showRGB_P();
};

/*此枚举用来获取图像的RGB三通道的值*/
enum RGB_type { R, G, B, RGB };

class SolutionOperator {
private:
	SolutionList& solutions;
	double solution_mol = -1;
	Vec4d line_area;
protected:
	double getRGB_average(string path);
	double compute_RGB_P(int index);
	void compute_mol(double y, bool log_flag);
public:
	SolutionOperator(SolutionList& s) :solutions(s) {}
	~SolutionOperator() {}
	double getRGB_average(int index);
	double* compute_RGB_P();
	bool set_mol(int index, double mol);
	Vec4d polyfit(vector<Point2d>& solutions_vector);
	double get_x_mol(double y, bool log_flag);
	double get_signal_RGB(RGB_type type, int index);
};