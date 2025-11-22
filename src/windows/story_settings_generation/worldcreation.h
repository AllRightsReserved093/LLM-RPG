#ifndef WORLDCREATION_H
#define WORLDCREATION_H

#include <QWidget>

namespace Ui {
class WorldCreation;
}

class WorldCreation : public QWidget
{
    Q_OBJECT

public:
    explicit WorldCreation(QWidget *parent = nullptr);
    ~WorldCreation();

private:
    Ui::WorldCreation *ui;
};

#endif // WORLDCREATION_H
