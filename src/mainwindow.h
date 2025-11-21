#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "json_message_handler.h"
#include "deepseek_api_services.h"

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

    int chat_view_add_new_message(QString role, QString content);
    int chat_view_add_new_message(QJsonObject message_obj);

private slots:
    void on_pushButtonEnter_clicked();
    void onReplyReady(const QByteArray replyContent);

private:
    Ui::MainWindow *ui;

    // JSON handler instance, the main one for the MainWindow
    json_message_handler json_handler_instance;

    // Deepseek API service instance
    deepseek_api_services api_service_instance;

    int main_window_json_message_handler_setup();
};
#endif // MAINWINDOW_H
