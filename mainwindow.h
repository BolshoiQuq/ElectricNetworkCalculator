#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QListWidgetItem>
#include <QSettings>
#include <QString>
#include <QSqlTableModel>
#include "blocks.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_open_triggered();
    //void on_save_filters_clicked(QString s1,QString s2);
    //void on_push_button_clicked();
    void on_set_button_clicked();
    //void on_close_filters_clicked();
    void on_calculate_clicked();
    void on_delete_button_clicked();
    //void on_open_filters_clicked();
    //void on_copy_button_clicked();


    //void on_filters_itemChanged(QListWidgetItem *item);

    void settings_filter();
    void delete_item();
    //void open_settings();
    //void close_filter();
    void set_selected_item(MoveItem *item);
    void define_order(MoveItem* item);
    void add_pattern_on_scene();
    void ReDrawLines();
    void insert_copy();

    QString open_dialog();

    void on_save_pattern_clicked();

    void on_save_network_clicked();

    void on_pushButton_clicked();

    void on_load_button_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    QVector<MoveItem*> item_list; // вектор объектов
    QVector<QGraphicsLineItem*> line_list;
    QVector<MoveItem*> item_list_in_order; //В каком порядке идут объекты

    MoveItem* m_selected_item = nullptr;
    MoveItem* m_first_selected = nullptr; // первый выбранный филтр для соединения
    MoveItem* m_second_selected = nullptr; // второй выбранный филтр для соединения

    MoveItem* m_moderation_item = nullptr;
    bool m_second_inside_orader = false;

//  client code
    quint16 nextBlockSize;

    QString pattern_path;


//
};

#endif // MAINWINDOW_H
