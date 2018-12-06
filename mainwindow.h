#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_action_quit_triggered();

    void on_pushButton_add_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_delete_clicked();

    void on_action_new_triggered();

    void on_pushButton_readd_clicked();

    void on_action_export_triggered();

    void on_action_import_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
