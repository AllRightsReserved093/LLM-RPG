#include "worldcreation.h"
#include "ui_worldcreation.h"

WorldCreation::WorldCreation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WorldCreation)
{
    ui->setupUi(this);
}

WorldCreation::~WorldCreation()
{
    delete ui;
}
