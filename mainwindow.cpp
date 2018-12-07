#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMap>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

QMap<QString, QString> map;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_import_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/dictionary", tr("Text file (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)){
        QStringList lst;
        while(!file.atEnd())
        {
            QString str = file.readLine();
                    if(!str.contains("$endl\r\n")){
                        lst << str;
                    }else{
                        lst << str;
                        str = lst.join("");
                        str.chop(7);
                        lst = str.split("|");
                        map[lst.at(0)] = lst.at(1);
                        lst.clear();
                    }
          }

    }

}

void MainWindow::on_action_quit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_new_triggered()
{
    map.clear();
}

void MainWindow::on_action_export_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/dictionary", tr("Text file (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
		stream.setCodec("UTF-8");
        foreach(QString key, map.keys()){
            QString value = map.value(key);
			stream << key << "|" << value;
            stream <<"$endl\r\n";
        }
    }
    ui->output->setText(tr("Словарь экспортирован!"));

}

void MainWindow::on_pushButton_add_clicked()
{

    QString key = ui->input->text();
    QMap<QString, QString>::const_iterator iter = map.find(key);
    if(iter == map.end()){
        SecondWindow window2;
        window2.setModal(true);
        window2.exec();
        QString value = window2.value;
        map.insert(key,value);
        ui->output->setText(tr("Слово добавлено!"));
    }
    else{ QMessageBox::critical(this,tr("Ошибка"),tr("Слово уже добавлено!"));}

}

void MainWindow::on_pushButton_search_clicked()
{
     QString key = ui->input->text();
     QMap<QString, QString>::const_iterator iter = map.find(key);
     if(iter != map.end()){
	 ui->output->setText(map.value(key));
     }
     else{ QMessageBox::critical(this,tr("Ошибка"),tr("Слово не найдено!"));}
}

void MainWindow::on_pushButton_delete_clicked()
{
    QString key = ui->input->text();
    map.remove(key);
    ui->output->setText(tr("Слово удалено!"));
}


void MainWindow::on_pushButton_readd_clicked()
{
    QString key = ui->input->text();

    QMap<QString, QString>::const_iterator iter = map.find(key);
    if(iter != map.end()){
		SecondWindow window2;
        window2.value = map[key];
        window2.setModal(true);
        window2.exec(); 
        QString value = window2.value;
        map.insert(key,value);
		ui->output->setText(tr("Слово перезаписано!"));
    }
    else{ QMessageBox::critical(this,tr("Ошибка"),tr("Слово не найдено!"));}
}


