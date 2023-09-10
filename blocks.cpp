#include "blocks.h"

MoveItem::MoveItem(QObject* parent) :
    QObject(parent), QGraphicsItem()
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    m_color = Qt::white;
}


/*MoveItem::MoveItem(QWidget* parentWidget, QGraphicsItem* parent) :
    QGraphicsItem(parent),
    m_parentWidget(parentWidget)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
}*/


MoveItem::~MoveItem()
{

}


QRectF MoveItem::boundingRect() const
{
    return QRectF (-30, -30, 60, 60);
}


void MoveItem::setColor(QColor color)
{
    m_color = color;
    update(); // перерисовываем виджет
}


const QColor& MoveItem::getColor() const
{
        return m_color;
}


void MoveItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(m_color);
    painter->drawRect(-30,-30,60,60);
    painter->drawText(boundingRect(), Qt::AlignCenter, m_name);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos() + m_shiftMouseCoords));
    emit itemMoved();
}


void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (QApplication::mouseButtons() == Qt::LeftButton)
    {
        emit itemSelected(this);
    }

    if (QApplication::mouseButtons() == Qt::RightButton)
    {
        emit selectionChanged(this);
    }

    QGraphicsItem::mousePressEvent(event);

    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}


void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}


QString MoveItem::get_name()
{
    return this->m_name;
}


void MoveItem::set_name(QString name)
{
    this->m_name = name;
    QFont m_font("Arial", 16);
    QFontMetrics metrics(m_font);
    QSizeF textSize = metrics.size(Qt::TextSingleLine, m_name);
    QRectF(0, 0, textSize.width(), textSize.height()).setWidth(textSize.width());
    QRectF(0, 0, textSize.width(), textSize.height()).setHeight(textSize.height());
    prepareGeometryChange();
}


void MoveItem::set_value(QString value)
{
    this->filters_value.append(value);
}


void MoveItem::set_value(QString label, QString value)
{
    if (filters_values.contains(label))
        filters_values[label] = value;
    else
        filters_values.insert(label, value);
}


QString MoveItem::get_values(QString name)
{
    return filters_values[name];
}

