#include "pawn.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
extern Game * game;
Pawn::Pawn(QString team,QGraphicsItem *parent):ChessPiece(team,parent)//конструктор
{
    setImage();
    firstMove = true;
}

void Pawn::setImage()//подрузка картинки из ресурсов
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/images/pawn1.png"));
    else
        setPixmap(QPixmap(":/images/pawn.png"));
}



void Pawn::moves()//функция движений
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    if(this->getSide() == "WHITE")  {
        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getChessPieceColor() == "BLACK") {//влево
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getChessPieceColor() == "BLACK") {//вправо
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasChessPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasChessPiece()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getChessPieceColor() == "WHITE") {//влево
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getChessPieceColor() == "WHITE") {//вправо
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasChessPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasChessPiece()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}


