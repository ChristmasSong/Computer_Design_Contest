#include "ClickedLabel.h"

void ClickedLabel::mouseReleaseEvent(QMouseEvent*)
{
	emit clicked(this); // �ڵ���¼��з����ź�
}

void ClickedLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
	emit doubleClicked(this); // ��˫���¼��з����ź�
}
