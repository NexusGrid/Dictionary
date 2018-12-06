#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    QString value;
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_SPushButton_abort_clicked();

    void on_SPushButton_add_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
