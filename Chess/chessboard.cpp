//подключение класов игры(основные)
#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
//подключение фигур
#include "queen.h"//королева
#include "rook.h"//ладья
#include "pawn.h"//пешка
#include "king.h"//король
#include "knight.h"//конь
#include "bishop.h" //слон
extern Game *game; //создание глобальной переменной game для реализации расположения фигур на доске
ChessBoard::ChessBoard()
{
    setUpBlack();//установка чёрных
    setUpWhite();//установка белых
}
void ChessBoard::drawBoxes(int x,int y) // прорисовка доски
{
    int SHIFT = 100;//размер стороны клетки
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox(); //создание клетки
            game->collection[i][j] = box; //создание двумерного массива клеток
            box->rowLoc = i;// i в массиве - строки
            box->colLoc = j;//j в массиве - колонки
            box->setPos(x+SHIFT*j,y+SHIFT*i);//создание клетки размером 100 на 100
            if((i+j)%2==0) //прорисовка клеток в шахматном порядке
                box->setOriginalColor(Qt::lightGray);
            else
                box->setOriginalColor(Qt::darkGray);
            game->addToScene(box);// добавление доски
        }
    }
}


void ChessBoard::addChessPiece() { // прорисовка фигуры
    for(int i = 0; i < 8; i++) {//счётчик строк
        for(int j = 0; j < 8; j++)//счётчик колонок
        {
            ChessBox *box =game->collection[i][j];
            if(i < 2) { //чёрные фигуры(если счётчик строки меньше второй по счёту сверху)
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) { //белые фигуры(если счётчик строки больше 5 строки)
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }
        }
    }
}

void ChessBoard::setUpWhite() //расположение всех фигур белого цвета
{
    ChessPiece *piece; //сначала рисуется ряд из 8 пешек с помощью цикла
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("WHITE");
        white.append(piece);
    }
    //потом все остальные белые фигуры в порядке соответствующем правилам игры
    piece = new Rook("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Queen("WHITE");
    white.append(piece);
    piece = new King("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Knight("WHITE");
    white.append(piece);
    piece = new Rook("WHITE");
    white.append(piece);

}

void ChessBoard::setUpBlack() //расположение всех фигур чёрного цвета
{
    //сначала все чёрные фигуры в порядке соответствующем правилам игры
    ChessPiece *piece;
    piece = new Rook("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Queen("BLACK");
    black.append(piece);
    piece = new King("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Knight("BLACK");
    black.append(piece);
    piece = new Rook("BLACK");
    black.append(piece);
    //потом рисуется ряд из 8 пешек с помощью цикла
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("BLACK");
        black.append(piece);
    }
}


void ChessBoard::reset() { //установка фигур заново после того как кто-то выиграл
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {//счётчик строк
        for(int j = 0; j < 8; j++)//счётчик колонок
        {
            ChessBox *box =game->collection[i][j];//очистка всех клеток от оставшихся фигур
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i < 2) {                         //установка чёрных
                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);
            }
            if(i > 5) {                         //установка белых
                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);
            }
        }
    }
}
