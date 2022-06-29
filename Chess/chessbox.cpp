#include "chessbox.h"
#include "game.h"
#include <QDebug>
#include "king.h"

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent) //класс "QGraphicsRectItem" является базовым
                                                                        //для дочернего класа "шахматной коробки"
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

ChessBox::~ChessBox() //деструктор
{
    delete this;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)  //действия по нажатию мыши на фигуру
{
      //  qDebug() << getChessPieceColor();
        //отмена выбора когда игрок дотронулся определенной фигуры
        if(currentPiece == game->pieceToMove && currentPiece){
            currentPiece->mousePressEvent(event);
            return;
        }
        //если фигура выбрана
        if(game->pieceToMove){
            //проверка - фигура того же цвета который ходит
            if(this->getChessPieceColor() == game->pieceToMove->getSide())
                return;
            //убрать убитую фигуру
            QList <ChessBox *> movLoc = game->pieceToMove->moveLocation();
            //проверка можно ли ходить туда куда нажал игрок
            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this) {
                    check++;
                }
            }
            if(check == 0)
                return;
            //вернуть цвет клеток к обычному
             game->pieceToMove->decolor();
             //первый ход может сделать только пешка
             game->pieceToMove->firstMove = false;
             //убить врага если он находится в клетках на которые может походить игрок чтоб убить его
            if(this->getHasChessPiece()){
                this->currentPiece->setIsPlaced(false);
                this->currentPiece->setCurrentBox(NULL);
                game->placeInDeadPlace(this->currentPiece);

            }
            //вернуть клетку в начальное положение только уже без фигуры т.к. фигуру преместили
            game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
            game->pieceToMove->getCurrentBox()->currentPiece = NULL;
            game->pieceToMove->getCurrentBox()->resetOriginalColor();
            placePiece(game->pieceToMove);

            game->pieceToMove = NULL;
            //смена очереди
            game->changeTurn();
            checkForCheck();
        }
        //выбор фигуры
        else if(this->getHasChessPiece())
        {
            this->currentPiece->mousePressEvent(event);
        }
}

void ChessBox::setColor(QColor color) //установка цвета клетки
{
    brush.setColor(color);
    setBrush(color);
}

void ChessBox::placePiece(ChessPiece *piece) // размещение фигуры
{
    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;
}

void ChessBox::resetOriginalColor() //вернуть начальный цвет клетки
{
    setColor(originalColor);
}

void ChessBox::setOriginalColor(QColor value) //начальный цвет клетки
{
    originalColor = value;
    setColor(originalColor);
}

bool ChessBox::getHasChessPiece() //проверка - имеет ли клетка шахматную фигуру
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece *piece)  //установка фигуры на клетку
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}

void ChessBox::checkForCheck() // проверка шаха (если король находится в поле где его могут убить)
{
    int c = 0;
    QList <ChessPiece *> pList = game->alivePiece; //список живых фигур
    for(size_t i = 0,n=pList.size(); i < n; i++ ) {
        King * p = dynamic_cast<King *> (pList[i]);
        if(p){
            continue;
        }
        pList[i]->moves();
        pList[i]->decolor();
        QList <ChessBox *> bList = pList[i]->moveLocation();
        for(size_t j = 0,n = bList.size(); j < n; j ++) {
            King * p = dynamic_cast<King *> (bList[j]->currentPiece);
            if(p) {
                if(p->getSide() == pList[i]->getSide())
                    continue;
                bList[j]->setColor(Qt::blue);//клетка синяя если король подпадает под удар
                pList[i]->getCurrentBox()->setColor(Qt::darkGreen);//если в клетке нет ничего - тёмно красная
                if(!game->check->isVisible())
                    game->check->setVisible(true);
                else{
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentBox()->resetOriginalColor();
                    game->gameOver();
                }
                c++;
            }
        }
    }
    if(!c){
        game->check->setVisible(false);
        for(size_t i = 0,n=pList.size(); i < n; i++ )
            pList[i]->getCurrentBox()->resetOriginalColor();
    }
}

QString ChessBox::getChessPieceColor() //установка цета фигуры(геттер)
{
    return chessPieceColor;
}

void ChessBox::setChessPieceColor(QString value) //установка цета фигуры
{
    chessPieceColor = value;
}
