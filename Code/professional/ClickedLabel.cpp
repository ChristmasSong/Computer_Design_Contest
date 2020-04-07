#include "ClickedLabel.h"

void ClickedLabel::mouseReleaseEvent(QMouseEvent*)
{
	emit clicked(this); // 在点击事件中发送信号
}

void ClickedLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
	emit doubleClicked(this); // 在双击事件中发送信号
}
