#include "eventhandleplaypage.h"
#include <QDebug>

EventHandlePlayPage::EventHandlePlayPage(QObject *parent) : QObject(parent)
{

    //initialise player 2 values
    isBox1X1CheckedP1=false;
    isBox1X2CheckedP1=false;
    isBox1X3CheckedP1=false;
    isBox2X1CheckedP1=false;
    isBox2X2CheckedP1=false;
    isBox2X3CheckedP1=false;
    isBox3X1CheckedP1=false;
    isBox3X2CheckedP1=false;
    isBox3X3CheckedP1=false;

    //initialise player 2 values
    isBox1X1CheckedP2=false;
    isBox1X2CheckedP2=false;
    isBox1X3CheckedP2=false;
    isBox2X1CheckedP2=false;
    isBox2X2CheckedP2=false;
    isBox2X3CheckedP2=false;
    isBox3X1CheckedP2=false;
    isBox3X2CheckedP2=false;
    isBox3X3CheckedP2=false;


    //initialise the box btn availability
    isBox1X1AvailableToClick=true;
    isBox1X2AvailableToClick=true;
    isBox1X3AvailableToClick=true;
    isBox2X1AvailableToClick=true;
    isBox2X2AvailableToClick=true;
    isBox2X3AvailableToClick=true;
    isBox3X1AvailableToClick=true;
    isBox3X2AvailableToClick=true;
    isBox3X3AvailableToClick=true;



}



void EventHandlePlayPage::checkTheBox(qint8 boxNum, bool isPlayer1)
{


    switch(boxNum) {
        case 1  :
          isBox1X1AvailableToClick=false;
          break;
        case 2  :
          isBox1X2AvailableToClick=false;
          break;
        case 3  :
           isBox1X3AvailableToClick=false;
           break;
        case 4  :
           isBox2X1AvailableToClick=false;
           break;
        case 5  :
           isBox2X2AvailableToClick=false;
           break;
        case 6  :
           isBox2X3AvailableToClick=false;
           break;
        case 7  :
           isBox3X1AvailableToClick=false;
           break;
        case 8  :
           isBox3X2AvailableToClick=false;
           break;
        case 9  :
           isBox3X3AvailableToClick=false;
           break;

           default : qDebug()<<"passed parameter 1 is invalid in checkTheBox(qint8, bool)";

    }




    if(isPlayer1){
        qDebug()<<"Player 1 clicked";
           if (boxNum == 1) isBox1X1CheckedP1=true;
           else if (boxNum == 2) isBox1X2CheckedP1=true;
           else if (boxNum == 3) isBox1X3CheckedP1=true;
           else if (boxNum == 4) isBox2X1CheckedP1=true;
           else if (boxNum == 5) isBox2X2CheckedP1=true;
           else if (boxNum == 6) isBox2X3CheckedP1=true;
           else if (boxNum == 7) isBox3X1CheckedP1=true;
           else if (boxNum == 8) isBox3X2CheckedP1=true;
           else if (boxNum == 9) isBox3X3CheckedP1=true;


    }else{
        qDebug()<<"Player 2 clicked";
        if (boxNum == 1) isBox1X1CheckedP2=true;
        else if (boxNum == 2) isBox1X2CheckedP2=true;
        else if (boxNum == 3) isBox1X3CheckedP2=true;
        else if (boxNum == 4) isBox2X1CheckedP2=true;
        else if (boxNum == 5) isBox2X2CheckedP2=true;
        else if (boxNum == 6) isBox2X3CheckedP2=true;
        else if (boxNum == 7) isBox3X1CheckedP2=true;
        else if (boxNum == 8) isBox3X2CheckedP2=true;
        else if (boxNum == 9) isBox3X3CheckedP2=true;

    }

}


bool EventHandlePlayPage::returnBoxState(qint8 boxNum)
{

    if (boxNum == 1) return isBox1X1AvailableToClick;
    else if (boxNum == 2) return isBox1X2AvailableToClick;
    else if (boxNum == 3) return isBox1X3AvailableToClick;
    else if (boxNum == 4) return isBox2X1AvailableToClick;
    else if (boxNum == 5) return isBox2X2AvailableToClick;
    else if (boxNum == 6) return isBox2X3AvailableToClick;
    else if (boxNum == 7) return isBox3X1AvailableToClick;
    else if (boxNum == 8) return isBox3X2AvailableToClick;
    else if (boxNum == 9) return isBox3X3AvailableToClick;
    else return false;
}



bool EventHandlePlayPage::isPlayer1Won()
{


    if(isBox1X1CheckedP1 && isBox1X2CheckedP1 && isBox1X3CheckedP1){
        qDebug()<<"Player 1 Won - 1 2 3 boxes filled";
    return true;
    }

    else if(isBox1X1CheckedP1 && isBox2X1CheckedP1 && isBox3X1CheckedP1){
        qDebug()<<"Player 1 Won - 1 4 7 boxes filled";
    return true;
    }

    else if(isBox1X1CheckedP1 && isBox2X2CheckedP1 && isBox3X3CheckedP1){
        qDebug()<<"Player 1 Won - 1 5 9 boxes filled";
    return true;
    }

    else if(isBox1X3CheckedP1 && isBox2X3CheckedP1 && isBox3X3CheckedP1){
        qDebug()<<"Player 1 Won - 3 6 9 boxes filled";
    return true;
    }

    else if(isBox1X3CheckedP1 && isBox2X2CheckedP1 && isBox3X1CheckedP1){
        qDebug()<<"Player 1 Won - 3 5 7 boxes filled";
    return true;
    }

    else if(isBox3X1CheckedP1 && isBox3X2CheckedP1 && isBox3X3CheckedP1){
        qDebug()<<"Player 1 Won - 7 8 9 boxes filled";
    return true;
    }

    else if(isBox1X2CheckedP1 && isBox2X2CheckedP1 && isBox3X2CheckedP1){
        qDebug()<<"Player 1 Won - 2 5 8 boxes filled";
    return true;
    }

    else if(isBox2X1CheckedP1 && isBox2X2CheckedP1 && isBox2X3CheckedP1){
        qDebug()<<"Player 1 Won - 5 6 7 boxes filled";
    return true;
    }

    else return false; //not won


}

bool EventHandlePlayPage::isPlayer2Won()
{

    if(isBox1X1CheckedP2 && isBox1X2CheckedP2 && isBox1X3CheckedP2){
        qDebug()<<"Player 2 Won - 1 2 3 boxes filled";
    return true;
    }

    else if(isBox1X1CheckedP2 && isBox2X1CheckedP2 && isBox3X1CheckedP2){
        qDebug()<<"Player 2 Won - 1 4 7 boxes filled";
    return true;
    }

    else if(isBox1X1CheckedP2 && isBox2X2CheckedP2 && isBox3X3CheckedP2){
        qDebug()<<"Player 2 Won - 1 5 9 boxes filled";
    return true;
    }

    else if(isBox1X3CheckedP2 && isBox2X3CheckedP2 && isBox3X3CheckedP2){
        qDebug()<<"Player 2 Won - 3 6 9 boxes filled";
    return true;
    }

    else if(isBox1X3CheckedP2 && isBox2X2CheckedP2 && isBox3X1CheckedP2){
        qDebug()<<"Player 2 Won - 3 5 7 boxes filled";
    return true;
    }

    else if(isBox3X1CheckedP2 && isBox3X2CheckedP2 && isBox3X3CheckedP2){
        qDebug()<<"Player 2 Won - 7 8 9 boxes filled";
    return true;
    }

    else if(isBox1X2CheckedP2 && isBox2X2CheckedP2 && isBox3X2CheckedP2){
        qDebug()<<"Player 2 Won - 2 5 8 boxes filled";
    return true;
    }

    else if(isBox2X1CheckedP2 && isBox2X2CheckedP2 && isBox2X3CheckedP2){
        qDebug()<<"Player 2 Won - 5 6 7 boxes filled";
    return true;
    }

    else return false; //not won

}

