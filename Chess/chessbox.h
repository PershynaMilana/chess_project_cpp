#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem> //библиотека для прорисовки квадратов на поле
#include <QBrush> // зарисовка квадратов цветом
#include "chesspiece.h" //добавление класа "шахматной фигуры"
#include <QGraphicsSceneMouseEvent> // библиотека для обработки действий мыши на поле

class ChessPiece;
class ChessBox:public QGraphicsRectItem//класс "QGraphicsRectItem" является базовым для дочернего класа "шахматной коробки"
{
public:
    ChessBox(QGraphicsItem *parent=0); //конструктор(принимает переменную для прорисовки квадратов на поле)
    ~ChessBox(); //деструктор

    void mousePressEvent(QGraphicsSceneMouseEvent *event); //действия по нажатию мыши на фигуру
    void setColor(QColor color); //установка цвета
    void placePiece(ChessPiece *piece); //размещение фигуры на поле


    void resetOriginalColor();                      //установка цвета клеток
    void setOriginalColor(QColor value);            //вернуть начальный цвет клетки

    bool getHasChessPiece(); //проверка - имеет ли клетка шахматную фигуру
    void setHasChessPiece(bool value,ChessPiece *piece = 0); //установка фигуры на клетку

    void checkForCheck(); //проверка есть ли шах

    QString getChessPieceColor(); //узнать цвет фигуры
    void setChessPieceColor(QString value); //установить цвет фигуры

    int rowLoc; //переменная строк
    int colLoc; //переменная колонок

    ChessPiece * currentPiece; //переменная хранящая текущую фигуру

private:
    QBrush brush; //переменная для прорисовки
    QColor originalColor; //переменая цвета
    bool hasChessPiece; // есть ли фигура
    QString chessPieceColor; //цвет фигуры
};

#endif // CHESSBOX_H
