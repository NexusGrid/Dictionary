#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_SPushButton_abort_clicked()
{

    QWidget::close();
}

void SecondWindow::on_SPushButton_add_clicked()
{
    value = ui->SValue->toPlainText();
    QWidget::close();
}
