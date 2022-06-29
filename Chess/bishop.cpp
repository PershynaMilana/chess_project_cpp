#include "bishop.h"
#include <QDebug>
#include "game.h"
extern Game *game; //создание глобальной переменной game для реализации движений фигуры

Bishop::Bishop(QString team,QGraphicsItem *parent):ChessPiece(team,parent) //установка картинки
{
    setImage();
}

void Bishop::setImage() //подгрузка картинки
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/images/bishop1.png")); //картинка белой фигуры если сторона белая
    else
        setPixmap(QPixmap(":/images/bishop.png")); //картинка чёрной фигуры если сторона чёрная
}


void Bishop::moves() //движения фигуры
{
    location.clear();//очищение локации фигуры из списка фигур list
    int row = this->getCurrentBox()->rowLoc;//установка "строки" где находиться фигура
    int col = this->getCurrentBox()->colLoc;//установка "колонки" где находиться фигура
    QString team = this->getSide();//узнать сторону (чёрая/белая)

    //ход в верх и влево
     for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
       if(game->collection[i][j]->getChessPieceColor() == team ) { //если фигура на которую можно походить того же
                                                                    //цвета как и цвет фигуры слона, то не показывать
                                                                    //возможные клетки на которые можно походить(фигуру своего цвета не бьют)
           break;
       }else{
           location.append(game->collection[i][j]);         //в ином случае, если фигура проивоположного цвета то
                                                            //подсвечивать клетки на которые можно походить
           if(boxSetting(location.last()) ){
               break;
           }
       }
    }

     //ход в верх и вправо
      for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
     }

      //ход вниз и вправо
       for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
         if(game->collection[i][j]->getChessPieceColor() == team ) {
             break;
         }else{
             location.append(game->collection[i][j]);
             if(boxSetting(location.last())){
                 break;
             }
         }
      }

       //ход вниз и влево
        for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
          if(game->collection[i][j]->getChessPieceColor() == team ) {
              break;
          }else{
              location.append(game->collection[i][j]);
              if(boxSetting(location.last())){
                  break;
              }
          }
       }
}
