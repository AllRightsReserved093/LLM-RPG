#include "pagenavigator.h"

PageNavigator::PageNavigator(QStackedWidget *stack, QObject *parent) : QObject(parent), m_stack(stack) {
    
}

PageNavigator::~PageNavigator() {}

int PageNavigator::set_main_menu(QWidget *mainmenu) {
    m_main_menu = mainmenu;
    m_stack->addWidget(m_main_menu);
    return 0;
}

int PageNavigator::set_chat_view(QWidget *chatview) {
    m_chat_view = chatview;
    m_stack->addWidget(m_chat_view);
    return 0;
}

int PageNavigator::set_world_creation(QWidget *worldcreation) {
    m_world_creation = worldcreation;
    m_stack->addWidget(m_world_creation);
    return 0;
}

void PageNavigator::goTo_main_menu() {
    if (m_main_menu) {
        m_stack->setCurrentWidget(m_main_menu);
    }
}

void PageNavigator::goTo_chat_view() {
    if (m_chat_view) {
        m_stack->setCurrentWidget(m_chat_view);
    }
}

void PageNavigator::goTo_world_creation() {
    qDebug() << "Navigating to World Creation page.";
    if (m_world_creation) {
        m_stack->setCurrentWidget(m_world_creation);
    }
}
