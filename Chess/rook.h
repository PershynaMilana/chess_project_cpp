#ifndef ROOK_H
#define ROOK_H

#include "chesspiece.h"
class Rook:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "ладьи"
{
public:
    Rook(QString team, QGraphicsItem *parent = 0);//конструктор
    void setImage();//подрузка картинки из ресурсов
    void moves();//функция движений
};

#endif // ROOK_H
