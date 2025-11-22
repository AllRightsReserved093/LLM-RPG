#ifndef PAGENAVIGATOR_H
#define PAGENAVIGATOR_H

#include <QStackedWidget>

class PageNavigator : public QObject
{
    Q_OBJECT
public:
    PageNavigator(QStackedWidget *stack, QObject *parent = nullptr);
    ~PageNavigator();

    int set_main_menu(QWidget *mainmenu);
    int set_chat_view(QWidget *chatview);
    int set_world_creation(QWidget *worldcreation);

public slots:
    void goTo_main_menu();
    void goTo_chat_view();
    void goTo_world_creation();

private:
    QStackedWidget *m_stack = nullptr;
    QWidget *m_main_menu = nullptr;
    QWidget *m_chat_view = nullptr;
    QWidget *m_world_creation = nullptr;
};

#endif // PAGENAVIGATOR_H
