#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h" //подключение класса "шахматной фигуры"
class Bishop:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "слона"
{
public:
    Bishop(QString team,QGraphicsItem *parent = 0); //создание фигуры слона
    void setImage();//подключение картинки фигуры слона из ресурсов
    void moves();//функция движений
};

#endif // BISHOP_H
