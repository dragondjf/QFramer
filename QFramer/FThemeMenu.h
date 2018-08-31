#ifndef FTHEMEMENU_H
#define FTHEMEMENU_H

#include <QMenu>
#include <QList>
#include <QMap>

class FThemeMenu : public QMenu
{
    Q_OBJECT
private:
    QMap<QString, QAction*> actionMaps;
    QMap<QString, QString>  filePathMaps;

    void initData();
    void initUI();
    void initConnect();


public:
    explicit FThemeMenu(QWidget *parent = nullptr);

    void addTheme(const QString &title, const QString &filePath);

    QMap<QString, QAction*> getActionMaps();
signals:

public slots:
    void changeThemeFromFile();
    void checkedAction(QAction* action);

};

#endif // FTHEMEMENU_H
