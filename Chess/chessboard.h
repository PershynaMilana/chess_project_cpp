#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "chesspiece.h"
class ChessBoard
{
public:
    ChessBoard();
    void drawBoxes(int x, int y);// прорисовка доски
    void setUpWhite();//устнаовка белых фигур
    void setUpBlack();//устнаовка чёрных фигур
    void addChessPiece();//установка фигуры
    void reset();//сброс и установка фигур заново после того как кто-то выиграл
private:
    QList <ChessPiece *> white;//список белых фигур
    QList <ChessPiece *> black;//список чёрных фигур
};

#endif // CHESSBOARD_H
