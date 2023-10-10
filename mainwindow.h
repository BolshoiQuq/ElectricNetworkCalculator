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

    //void set_selected_item(MoveItem *item);
    //void define_order(MoveItem* item);
    //void add_pattern_on_scene();
    //void ReDrawLines();
    //void insert_copy();

    QString open_dialog();

    //void on_save_pattern_clicked();

    void on_save_network_clicked();

    void on_pushButton_clicked();

    void on_load_button_clicked();

    void on_build_graph_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;

    QVector<MoveItem*> item_list; // вектор объектов
    QVector<QGraphicsLineItem*> line_list;
    QVector<MoveItem*> item_list_in_order; //В каком порядке идут объекты

    //MoveItem* m_selected_item = nullptr;
    //MoveItem* m_first_selected = nullptr; // первый выбранный филтр для соединения
    //MoveItem* m_second_selected = nullptr; // второй выбранный филтр для соединения

    MoveItem* m_moderation_item = nullptr;
    bool m_second_inside_orader = false;

//  client code
    quint16 nextBlockSize;

    QString pattern_path;


//
};

#endif // MAINWINDOW_H
