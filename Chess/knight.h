#ifndef KNIGHT_H
#define KNIGHT_H

#include "chesspiece.h"
class Knight:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "коня"
{
public:
    Knight(QString team,QGraphicsItem *parent = 0);//конструктор
    void setImage();//подрузка картинки из ресурсов
    void moves();//функция движений
};

#endif // KNIGHT_H
