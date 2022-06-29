#ifndef KING_H
#define KING_H

#include "chesspiece.h"//подключение класса "шахматной фигуры"
class King:public ChessPiece//класс "шахматная фигура" является базовым для дочернего класа "короля"
{
public:
    King(QString team,QGraphicsItem *parent = 0);//конструктор
    void setImage();//подрузка картинки из ресурсов
    void findUnSafeLocation();//поиск безопасной позиции когда ставят шах
    void moves();//функция движений
};

#endif // KING_H
