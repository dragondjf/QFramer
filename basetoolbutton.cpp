#include "basetoolbutton.h"

BaseToolButton::BaseToolButton(const QString& text)
{
    setFlat(true);
    setCheckable(true);
    setFixedSize(80, 60);
    setText(text);
    setFocusPolicy(Qt::NoFocus);

}
