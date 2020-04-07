#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QWidget>
#include <QLabel>

class ClickedLabel : public QLabel
{
	Q_OBJECT
public:
	ClickedLabel(QWidget* parent = 0) : QLabel(parent) {}
	~ClickedLabel() {}
signals:
	void clicked(ClickedLabel* click); // ����ź�
	void doubleClicked(ClickedLabel* click);	//˫���ź�
protected:
	void mouseReleaseEvent(QMouseEvent*); // ����������ͷ��¼�
	void mouseDoubleClickEvent(QMouseEvent*);	//���������˫�����ͷ��¼�
};

#endif // CLICKEDLABEL_H
