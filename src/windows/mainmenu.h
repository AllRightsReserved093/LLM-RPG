#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class PageNavigator;

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(PageNavigator *page_navigator, QWidget *parent = nullptr);
    ~MainMenu();

signals:
    void NewGameClicked();

private:
    Ui::MainMenu *ui;
    PageNavigator *page_navigator;
};

#endif // MAINMENU_H
