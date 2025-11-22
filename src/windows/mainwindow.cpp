#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , main_menu_page(new MainMenu(this))
    , chat_view_page(new ChatViewPage(this))
{
    ui->setupUi(this);

    // Populate stacked widget with pages; default to chat view
    ui->stackedWidget->addWidget(main_menu_page);
    ui->stackedWidget->addWidget(chat_view_page);
    ui->stackedWidget->setCurrentWidget(chat_view_page);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete main_menu_page;
    delete chat_view_page;
}

