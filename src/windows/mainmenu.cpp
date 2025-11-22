#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "pagenavigator.h"

#include <QPushButton>

MainMenu::MainMenu(PageNavigator *page_navigator, QWidget *parent): QWidget(parent), ui(new Ui::MainMenu), page_navigator(page_navigator){
    ui->setupUi(this);


    if (page_navigator && ui->NewGame) {
        connect(ui->NewGame, &QPushButton::clicked, page_navigator, &PageNavigator::goTo_world_creation);
    }
}

MainMenu::~MainMenu()
{
    delete ui;
}

