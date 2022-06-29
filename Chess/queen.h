#ifndef QUEEN_H
#define QUEEN_H

#include "chesspiece.h"
class Queen:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "королевы"
{
public:
    Queen(QString team,QGraphicsItem *parent = 0);//конструктор
    void setImage();//подрузка картинки из ресурсов
    void moves();//функция движений
};

#endif // QUEEN_H
