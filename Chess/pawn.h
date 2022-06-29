#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
class Pawn:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "пешка"
{
public:
    Pawn(QString team,QGraphicsItem *parent = 0);//конструктор
    void setImage();//подрузка картинки из ресурсов
    void moves();//функция движений
 private:
};

#endif // PAWN_H
