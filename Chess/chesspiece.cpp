#include "chesspiece.h"
#include "game.h"
#include <QDebug>
#include "king.h"

extern Game *game;
ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
  //класс "QGraphicsPixmapItem" является базовым для дочернего класа ChessPiece
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)//по нажатию мыши
{
    //убрать выбор фигуры
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
       return;
    }
    //если ход уже сделан или нет возможного хода этой фигурой
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    //выбор фигуры
    if(!game->pieceToMove){
        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::green);
        game->pieceToMove->moves();
    }
    //переход фигур к части поля врага
    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }
}

void ChessPiece::setCurrentBox(ChessBox *box)//сделать выбранной клеткой
{
    currentBox = box;
}

ChessBox *ChessPiece::getCurrentBox()//узнать какая клетка являеться выбранной
{
    return currentBox;
}

QString ChessPiece::getSide()// узнать сторону (чёрные/белые)
{
    return side;
}

void ChessPiece::setSide( QString value)//установить сторону
{
    side = value;
}

bool ChessPiece::getIsPlaced()//проверка на то размещена ли фигура
{
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value) // установить что фигура размещенна
{
    isPlaced = value;

}
QList<ChessBox *> ChessPiece::moveLocation() //список позиций
{
    return location;
}
void ChessPiece::decolor()// вернуть обычный цвет клетке
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}

bool ChessPiece::boxSetting(ChessBox *box)//настройка цвета подсветки клетки
{
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){//если шах то король подсвечивается синим
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::green);//если клетки не пусты но там не король то клетка подсвечивается красным
        return true;
    }
    else
        location.last()->setColor(Qt::darkGreen); //если клетка пуста то клетка подсвечивается тёмно красным
    return false;
}
