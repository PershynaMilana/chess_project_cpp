#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>


class Button:public QObject, public QGraphicsRectItem //класс "QGraphicsRectItem"(для прорисовки квадратов обьектов на поле)
                                                        //является базовым для дочернего класа button
{
     Q_OBJECT
public:

    Button(QString name, QGraphicsItem * parent = NULL); //конструктор
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // игрок нажал на кнопку
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event); // навёл мышку на кнопку
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event); //убрал мышку с кнопки
signals:
    void clicked(); //фунция по нажатию
private:
    QGraphicsTextItem *text; //переменная текста над полем
};
#endif // BUTTON_H
