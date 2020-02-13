#include "professional.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Professional w;
    w.show();

    return a.exec();
}

