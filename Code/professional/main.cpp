#include "professional.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Professional w;
    w.show();
	SolutionList solutions;
	SolutionOperator solutionsOperator(solutions);
    return a.exec();
}