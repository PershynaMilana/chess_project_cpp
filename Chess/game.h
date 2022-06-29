#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene> // библиотека для работы с 2д объектами
#include <chessboard.h>
#include "chesspiece.h"
class Game:public QGraphicsView //класс "QGraphicsView"(для прорисовки 2д обьектов на поле) является базовым для дочернего класа game
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);//коструктор

    void drawDeadHolder(int x, int y, QColor color); // прорисовка полей для размещения мёртвых фигур
    void drawChessBoard(); //прорисовка поля
    void displayDeadWhite(); //прорисовка убитых белых фигур
    void displayDeadBlack();//прорисовка убитых чёрных фигур
    void placeInDeadPlace(ChessPiece *piece); //убрать убитую фигуру в сторону

    void addToScene(QGraphicsItem *item); //добавление на поле
    void removeFromScene(QGraphicsItem *item); //удаление с поля

    ChessPiece *pieceToMove; //создание переменной для фигур на поле
    QString getTurn(); //узнать очередь кто ходит
    void setTurn( QString value); //установить очередь
    void changeTurn(); //смена очереди

    ChessBox *collection[8][8]; //двумерный массив фигур одного цвета
    QGraphicsTextItem *check; //переменная с текстом над полем
    QList <ChessPiece *> alivePiece; //список живых фигур

    void displayMainMenu();//отображение начального меню
    void gameOver();//проигрыш
    void removeAll();//убрать все после проигрыша
public slots:
    void start(); //начало
private:
    QGraphicsScene *gameScene; //переменная поля
    QList <ChessPiece *> whiteDead;//список убитых белых
    QList <ChessPiece *> blackDead;//список убитых чёрных
    QGraphicsRectItem * deadHolder; //переменная для прорисовки места для размещения убитых фигур
    QString turn; //переменная очереди
    ChessBoard *chess; //переменая для одной фигуры
    QList <QGraphicsItem *> listG; //список для добаления картинок фигур на поле
    QGraphicsTextItem * turnDisplay;//отображение очереди
};

#endif // GAME_H
