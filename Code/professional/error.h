#ifndef ERROR_H
#define ERROR_H

#include <QDialog>

namespace Ui {
class error;
}

class error : public QDialog
{
    Q_OBJECT

public:
    explicit error(QWidget *parent = 0);
    ~error();
private slots:
    void on_yes_clicked();
private:
    Ui::error *ui;
};

#endif // ERROR_H
