#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)                          //класс "QGraphicsRectItem"(для прорисовки квадратов обьектов на поле)
                                                    //является базовым для дочернего класа button
{
    //прорисовка квадрата
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //текст
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);

    //для наведения мыши
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)  // игрок нажал на кнопку
{
    if(event)
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) // навёл мышку на кнопку
{
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
    }
}
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) { //убрал мышку с кнопки
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    }
}
