 #include "fcheckablebutton.h"

FCheckabelButton::FCheckabelButton(const QString& text)
{
    setFlat(true);
    setCheckable(true);
    setFixedSize(80, 60);
    setText(text);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("checkable");
}
