#include "knight.h"
#include "game.h"
extern Game *game;

Knight::Knight(QString team,QGraphicsItem *parent):ChessPiece(team,parent)//класс "шахматная фигура" является базовым
                                                                                //для дочернего класа "коня"
{
    setImage();
}

void Knight::setImage()//подрузка картинки из ресурсов
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/images/horse1.png"));
    else
        setPixmap(QPixmap(":/images/horse.png"));
}



void Knight::moves()//функция движений
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    int i ,j;
    QString team  = this->getSide();

    //вверх вверх и влево
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //вверх вверх и вправо
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //вниз вниз и влево
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //вниз вниз и вправо
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //влево влево и вверх
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //влево влево и вниз
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //вправо вправо и вверх
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    //вправо вправо и вниз
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}
