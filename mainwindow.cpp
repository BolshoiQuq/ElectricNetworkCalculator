#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include <QDir>
#include <iostream>
#include "textcalc.h"

#include <QTcpSocket>
#include <QVariant>
#include <QGraphicsLineItem>
#include <QLineF>
#include <QDialogButtonBox>

#include "myplot.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MoveItem* static_settings_item = new MoveItem(); // начало
    item_list.push_back(static_settings_item);
    item_list_in_order.push_back(static_settings_item);
    static_settings_item->setColor(Qt::gray);
    static_settings_item->setData(Qt::UserRole, "settings");
    static_settings_item->set_name("settings");

    MoveItem* static_end_item = new MoveItem();
    item_list.push_back(static_end_item);
    item_list_in_order.push_back(static_end_item);
    static_end_item->setColor(Qt::gray);
    static_end_item->setData(Qt::UserRole, "конец");
    static_end_item->set_name("конец");


    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene->setSceneRect(0, 0, 300, 300); // Устанавливаем размер сцены


    scene->addItem(static_settings_item);
    scene->addItem(static_end_item);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_open_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл", "", "*.txt");
    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if  (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
        }
    }
}


QString MainWindow::open_dialog()
{
    // Создаем диалоговое окно
    QDialog *inputDialog = new QDialog(this);
    // Задаем название окна
    inputDialog->setWindowTitle("Название шаблона");
    // Создаем поле для ввода текста
    QLineEdit *lineEdit = new QLineEdit(inputDialog);
    // Задаем начальное значение поля
    lineEdit->setText("0");
    // Создаем кнопки "OK" и "Cancel"
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, inputDialog);
    // Подключаем сигналы от кнопок к слотам обработки событий
    connect(buttonBox, &QDialogButtonBox::accepted, inputDialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, inputDialog, &QDialog::reject);
    // Создаем вертикальный layout и добавляем на форму
    QVBoxLayout *layout = new QVBoxLayout(inputDialog);
    layout->addWidget(lineEdit);
    layout->addWidget(buttonBox);
    // Устанавливаем вертикальный layout
    inputDialog->setLayout(layout);
    // Отображаем диалоговое окно и ожидаем его закрытия
    QString value;
    if(inputDialog->exec() == QDialog::Accepted) {
       value = lineEdit->text();
    }
    delete inputDialog;
    return value;
}



void MainWindow::on_save_network_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "*.txt");
    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if  (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл", "", "*.txt");
    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if  (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
        }
    }
}


void MainWindow::on_load_button_clicked()
{
    if (!ui->path_file->size().isEmpty())
    {
        enet_calc(ui->EMF_Ampl->text().toDouble(), ui->Frequency->text().toDouble(), ui->Initial_Phase->text().toDouble(), ui->Time->text().toDouble(), ui->path_file->text().toStdString());
    }
    else
    {
        enet_calc(ui->EMF_Ampl->text().toDouble(), ui->Frequency->text().toDouble(), ui->Initial_Phase->text().toDouble(), ui->Time->text().toDouble(), "nin.txt");
    }
    QFile file("nout_calc.txt");
    if  (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        ui->text_edite->setPlainText(in.readAll());
        file.close();
    }
}



void MainWindow::on_build_graph_clicked()
{
    enet_graph(ui->EMF_Ampl->text().toDouble(), ui->Frequency->text().toDouble(), ui->Initial_Phase->text().toDouble(), ui->Elem_number->text().toInt(), "nin.txt");
    std::string plt_U = "nout_graph_U.txt";
    GraphWidget* plot_U = new GraphWidget(this);
    plot_U->set_settings(plt_U);
    plot_U->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
    plot_U->setWindowTitle("График U(t)");
    plot_U->show();

    std::string plt_I = "nout_graph_I.txt";
    GraphWidget* plot_I = new GraphWidget(this);
    plot_I->set_settings(plt_I);
    plot_I->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
    plot_I->setWindowTitle("График I(t)");
    plot_I->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл", "", "*.txt");
//    if (!file_name.isEmpty())
//    {
//        QFile file(file_name);
//        if  (file.open(QIODevice::ReadOnly | QIODevice::Text))
//        {
//            QTextStream in(&file);
//            ui->text_edite->setPlainText(in.readAll());
//            file.close();
//        }
//    }
    ui->path_file->setText(file_name);
}

