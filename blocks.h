#ifndef BLOCKS_H
#define BLOCKS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QApplication>
#include <QWidget>
#include <QColor>
#include <QVector>
#include <QMap>
#include <QLabel>
#include <QLineEdit>


class MoveItem : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    MoveItem(QObject* parent = 0);
    MoveItem(QWidget* parentWidget, QGraphicsItem* parent);
    ~MoveItem();

    void setColor(QColor color);
    QString get_name();
    void set_name(QString name);
    void set_value(QString value);

    const QColor& getColor() const;
    QString get_values(QString name);

public slots:
    void set_value(QString label, QString value);


private:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

signals:
    void selectionChanged(MoveItem* item);
    void itemMoved();
    void itemSelected(MoveItem *item);


private:
    QRectF m_rect;

    QWidget* m_parentWidget;
    QPointF m_shiftMouseCoords;

    QColor m_color;
    QString m_name;

    QVector<QString> filters_value;
    QMap<QString, QString> filters_values;
};

#endif // BLOCKS_H
