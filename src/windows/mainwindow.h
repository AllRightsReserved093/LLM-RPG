#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pagenavigator.h"
#include "chatview.h"
#include "mainmenu.h"
#include "story_settings_generation/worldcreation.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PageNavigator *page_navigator;
    Ui::MainWindow *ui;
    MainMenu *main_menu_page;
    ChatView *chat_view_page;
    WorldCreation *world_creation;
};
#endif // MAINWINDOW_H
