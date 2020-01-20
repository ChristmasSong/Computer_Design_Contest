#pragma once
#include <iostream>
#include<cmath>
#include <opencv.hpp>

using namespace std;
using namespace cv;

struct Solution{
	string path;
	int id;
	int RGB_average;
	double RGB_P;
	double mol;
	Solution* next;
	Solution()
		:path(""), id(-1), next(NULL), RGB_average(-1), RGB_P(-1), mol(-1){}
	Solution(int i, string p)
		:path(p), id(-1), next(NULL), RGB_average(-1), RGB_P(-1), mol(-1){}
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
	void showSolutions();
	void showRGB_P();
};

class SolutionOperator {
private:
	SolutionList& solutions;
protected:
	int getRGB_average(string path);
	double compute_RGB_P(int index);
public:
	SolutionOperator(SolutionList& s) :solutions(s) {}
	~SolutionOperator() {}
	int getRGB_average(int index);
	double* compute_RGB_P();
	bool set_mol(int index, double mol);
};
