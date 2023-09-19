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
    ui->graphics_view->setScene(scene); //  Устанавливаем графическую сцену в graphics_view
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene->setSceneRect(0, 0, 300, 300); // Устанавливаем размер сцены


    scene->addItem(static_settings_item);
    scene->addItem(static_end_item);

    connect(static_settings_item, &MoveItem::selectionChanged, this, &MainWindow::define_order);
    connect(static_end_item, &MoveItem::selectionChanged, this, &MainWindow::define_order);
    connect(static_settings_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    connect(static_end_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);
    connect(static_settings_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item);
    connect(static_end_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item);
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


void MainWindow::on_calculate_clicked()
{
    //connect(ui->calculate, &on_pushButton_clicked, this, &MainWindow::ReDrawLines);
}


void MainWindow::on_set_button_clicked()
{
    add_pattern_on_scene();
}


void MainWindow::on_delete_button_clicked()
{
    delete_item();
}


void MainWindow::settings_filter()
{

}


/*void MainWindow::on_save_filters_clicked(QString s1, QString s2)
{
    m_moderation_item->set_value(s1, s2);
    qDebug() << s1 << " " << s2;
}*/


/*void MainWindow::on_push_button_clicked()
{
    QSettings settings("Path", "\0");
    QString filePath = settings.value("Path").toString();
    if (filePath.size() > 0)
    {
        qDebug() << filePath;
    }
    else
    {
        QFileDialog dialog;
        QString file_name;
        dialog.setNameFilter("Executable (*.o)");
        if (dialog.exec() == QDialog::Accepted)
        {
                file_name = dialog.selectedFiles().first();
                qDebug() << "Выбранный файл: " << file_name;
        }
        char* path = new char [file_name.size()];
        strcpy(path, file_name.toUtf8().constData());

    }

    QString label = item_list_in_order[item_list_in_order.size()-1]->get_name();
    QString result_path = item_list_in_order[item_list_in_order.size()-1]->get_values(label);

}*/


void MainWindow::add_pattern_on_scene()
{

    QString filter_name[] = { "Резистор", "Ток", "Лампа", "Земля"};


    QTreeWidgetItem* current_item = ui->filters_information->currentItem();
    if (!current_item)
        return;
    int order_number = ui->filters_information->currentIndex().row();

    MoveItem* filter_item = new MoveItem();
    item_list.push_back(filter_item);

    filter_item->set_name(filter_name[order_number]);
    filter_item->setData(Qt::UserRole, filter_name[order_number]);
    filter_item->setToolTip(filter_name[order_number]);

    scene->addItem(filter_item);


    connect(filter_item, &MoveItem::itemMoved, this, &MainWindow::ReDrawLines);

    connect(filter_item, &MoveItem::itemSelected, this, &MainWindow::set_selected_item); // связь с кнопкой удалить
    connect(filter_item, &MoveItem::selectionChanged, this, &MainWindow::define_order); // связь с порядком связи шаблонов

}


void MainWindow::ReDrawLines()
{
    for (int i = 0; i < line_list.size(); i++)
    {
        scene->removeItem(line_list[i]);
    }
    line_list.clear();
    for (int i = 0; i < item_list_in_order.size() - 1; i++)
    {
        QPointF center_1 = item_list_in_order[i]->pos() + QPointF(item_list_in_order[i]->childrenBoundingRect().width() / 2.0, item_list_in_order[i]->childrenBoundingRect().height() / 2.0);
        QPointF center_2 = item_list_in_order[i + 1]->pos() + QPointF(item_list_in_order[i + 1]->childrenBoundingRect().width() / 2.0, item_list_in_order[i + 1]->childrenBoundingRect().height() / 2.0);
        QGraphicsLineItem* connect_line = new QGraphicsLineItem(0, 0, 50, 50);
        scene->addItem(connect_line);
        connect_line->setZValue(-1);
        connect_line->setLine(QLineF(center_1, center_2));
        line_list.push_back(connect_line);
    }
}


void MainWindow::define_order(MoveItem* item)
{
    for (int i = 0; i < item_list_in_order.size(); ++i)
    {
        if (item == item_list_in_order[i])
        {
                if (m_first_selected == nullptr && i < item_list_in_order.size() - 1)
                {
                    m_first_selected = item;
                    return;
                }
                else if (m_first_selected == item)
                {
                    m_first_selected = nullptr;
                    return;
                }
                else if (m_first_selected && m_second_selected == nullptr)
                {
                    m_second_selected = item;
                    m_second_inside_orader = true;
                    break;
                }
        }
    }
    if (m_first_selected && m_second_selected == nullptr)
    {
        m_second_selected = item;
        m_second_inside_orader = false;
    }
    if (m_second_inside_orader)
    {
        int first = 0, second = 0;
        for (int i = 0; i < item_list_in_order.size(); ++i)
        {
                if (m_first_selected == item_list_in_order[i])
                    first = i;
                if (m_second_selected == item_list_in_order[i])
                    second = i;
        }
        if (first > second)
        {
            m_second_selected = nullptr;
            return;
        }
        item_list_in_order.remove(second);
        if (first < item_list_in_order.size() - 1)
                item_list_in_order.insert(first + 1, m_second_selected);
        else
                item_list_in_order.append(m_second_selected);
    }
    else
    {
        for (int i = 0; i < item_list_in_order.size(); ++i)
        {
                if (m_first_selected == item_list_in_order[i])
                {
                    if (i < item_list_in_order.size() - 1)
                        item_list_in_order.insert(i + 1, m_second_selected);
                    else
                        item_list_in_order.append(m_second_selected);
                }

        }
    }
    m_first_selected = nullptr;
    m_second_selected = nullptr;
    ReDrawLines();
}


/*void MainWindow::on_filters_itemChanged(QListWidgetItem *item)
{
    QString itemText = item->text();

    // Создать QSettings объект
    //QSettings settings("MyCompany", "MyApp");

    // Сохранить itemText в качестве значения параметра
    //settings.setValue("MyParameter", itemText);

    qDebug() << "Value entered: " << itemText;
}
*/

void MainWindow::set_selected_item(MoveItem *item)
{
    this->m_selected_item = item;
}


void MainWindow::delete_item()
{
    if (m_selected_item && m_selected_item != item_list_in_order[0] && m_selected_item != item_list_in_order[item_list_in_order.size() - 1])
    {
       for (int i = 0; i < item_list.size(); ++i)
       {
            if (m_selected_item == item_list[i])
            {
                item_list.remove(i);
                break;
            }
       }
       for (int i = 0; i < item_list_in_order.size(); ++i)
       {
            if (m_selected_item == item_list_in_order[i])
            {
                item_list_in_order.remove(i);
                break;
            }
       }
       m_selected_item->deleteLater();
       m_selected_item = nullptr;
    }
    ReDrawLines();
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


/*void MainWindow::on_copy_button_clicked()
{
    insert_copy();
}*/


void MainWindow::insert_copy()
{

}


void MainWindow::on_save_pattern_clicked()
{

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
    GraphWidget* plot = new GraphWidget(this);
    plot->set_settings(file_name.toStdString());
    plot->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    plot->setWindowTitle("График");
    plot->show();
}


void MainWindow::on_load_button_clicked()
{
    main11(ui->EMF_Ampl->text().toDouble(), ui->Frequency->text().toDouble(), ui->Initial_Phase->text().toDouble(), ui->Time->text().toDouble(), "nin.txt");
}


