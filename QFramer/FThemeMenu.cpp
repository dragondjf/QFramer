#include "FThemeMenu.h"
#include "futil.h"
#include <QApplication>
#include <QFileDialog>
#include <QDir>

FThemeMenu::FThemeMenu(QWidget *parent)
    : QMenu(parent)
{
    initData();
    initUI();
    initConnect();
}

void FThemeMenu::initData()
{

}

void FThemeMenu::initUI()
{
    QAction *action = new QAction(tr("Custom"), this);
    action->setCheckable(true);
    actionMaps[tr("Custom")] = action;
    addAction(action);

    addTheme(tr("Blank"), QString(""));
}

void FThemeMenu::initConnect()
{
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(checkedAction(QAction*)));
    connect(actionMaps[tr("Custom")], SIGNAL(triggered()), this, SLOT(changeThemeFromFile()));
}

QMap<QString, QAction *> FThemeMenu::getActionMaps()
{
    return actionMaps;
}

void FThemeMenu::addTheme(const QString &title, const QString &filePath)
{
    if (title.isEmpty())
        return;

    QAction *action = new QAction(title, this);
    action->setCheckable(true);
    actionMaps[title] = action;
    filePathMaps[title] = filePath;
    addAction(action);
}

void FThemeMenu::changeThemeFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Laod qss"),
                                                    QDir::currentPath(),
                                                    tr("Qss Files (*.qss)"));
    if (fileName != "") {
        qApp->setStyleSheet(getQssFromFile(fileName));
    }
}

void FThemeMenu::checkedAction(QAction *action)
{
    for (auto it = actionMaps.begin(); it != actionMaps.end(); ++it) {
        if (it.value() == action) {
            it.value()->setChecked(true);
            auto iter = filePathMaps.find(it.key());
            if (iter != filePathMaps.end()) {
                qApp->setStyleSheet(getQssFromFile(iter.value()));
            }
        } else {
            it.value()->setChecked(false);
        }
    }
}
