#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , main_menu_page(nullptr)
    , chat_view_page(nullptr)
    , world_creation(nullptr)
    , page_navigator(nullptr)
{
    ui->setupUi(this);

    page_navigator = new PageNavigator(ui->stackedWidget, this);

    // Create pages after UI is set up so stackedWidget is valid
    main_menu_page = new MainMenu(page_navigator, this);
    chat_view_page = new ChatView(this);
    world_creation = new WorldCreation(this);

    // Populate stacked widget with pages; default to main menu
    page_navigator->set_main_menu(main_menu_page);
    page_navigator->set_chat_view(chat_view_page);
    page_navigator->set_world_creation(world_creation);

    ui->stackedWidget->setCurrentWidget(main_menu_page);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete main_menu_page;
    delete chat_view_page;
    delete world_creation;

    delete page_navigator;
}
