#pragma once
#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

struct Solution
{
	string path;
	int id;
	int RGB_average;
	Solution* next;
	Solution():path(""), id(-1), next(NULL), RGB_average(-1){}
	Solution(int i, string p):path(p), id(-1), next(NULL), RGB_average(-1){}
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
};

class SolutionOperator {
private:
	SolutionList& solutions;
	int getRGB_average(string path);
public:
	SolutionOperator(SolutionList& s):solutions(s){}
	~SolutionOperator() {}
	int getRGB_average(int index);
};