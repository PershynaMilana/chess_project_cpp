#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QGraphicsPixmapItem>
#include "chessbox.h"
#include <QGraphicsSceneMouseEvent>

class ChessBox;
class ChessPiece:public QGraphicsPixmapItem
    //класс "QGraphicsPixmapItem" является базовым для дочернего класа ChessPiece
{
public:
    ChessPiece(QString team = "",QGraphicsItem *parent = 0); //конструктор

    void mousePressEvent(QGraphicsSceneMouseEvent *event); //по нажатию мыши
    void setCurrentBox(ChessBox *box); //сделать выбранной клеткой

    ChessBox *getCurrentBox() ; //узнать какая клетка являеться выбранной

    QString getSide() ; // узнать сторону (чёрные/белые)
    void setSide( QString value);//установить сторону
    virtual void setImage() = 0; //установить картинку фигуры

    bool getIsPlaced(); //проверка на то размещена ли фигура
    void setIsPlaced(bool value); // установить что фигура размещенна

    QList <ChessBox *> moveLocation(); //список позиций
    virtual void moves() = 0; //виртуальная функция движений фигур(перегружена под каждую фигуру по-своему)
    void decolor(); // вернуть обычный цвет клетке

    bool firstMove;//кто делает первый ход

    bool boxSetting(ChessBox *box); //настройка цвета подсветки клетки
protected:
    ChessBox *currentBox; //текущая клетка
    QString side; // сторна
    bool isPlaced; //размещена ли
    QList <ChessBox *> location; //позиция на поле фигуры
};

#endif // CHESSPIECE_H
