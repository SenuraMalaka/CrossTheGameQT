#include "playpage.h"
#include "ui_playpage.h"
#include "mainpage.h"
#include <QDebug>

PlayPage::PlayPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayPage)
{
    ui->setupUi(this);

    //set the player 1 as the first player
    isPlayer1Chance=true;
    ui->labelArrowRed_P2->setVisible(!isPlayer1Chance);
    ui->pushButtonNewGameWSameP->setVisible(false);
    btnPath=":images/btns/cross/tomato_btn.png"; //set the first click btn as Player1

    eventHandlePP=new EventHandlePlayPage();

    QObject::connect(this, SIGNAL(playerChanceChanged(bool)),this, SLOT(toggleRedArrow(bool)));
    QObject::connect(this, SIGNAL(boxClicked(qint8, bool)),eventHandlePP, SLOT(checkTheBox(qint8, bool)));



    //setting up the background
    QPixmap bkgnd(":images/clouds.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    isTimerRunning=false;
    didSomeoneWon=false;
    isAllBoxesFilled=false;

}

PlayPage::~PlayPage()
{
    delete ui;
}

void PlayPage::setPlayer1(QString p){

    ui->labelPlayer1->setText(p.toLatin1());

}

void PlayPage::setPlayer2(QString p){

    ui->labelPlayer2->setText(p.toLatin1());

}


void PlayPage::showTime(){

    if(!didSomeoneWon && !isAllBoxesFilled) {
    qDebug()<<"Time refresh goes now";

    qint32 tm=myTimer.elapsed()/1000;

    ui->lcdNumberTime->display((double)tm);
    }

}

void PlayPage::togglePlayerChance(){

    //start the timer if it is not started yet
    if(!isTimerRunning) {

        myTimer.start();

        timerQ =new QTimer(this);
        QObject::connect(timerQ, SIGNAL(timeout()),this, SLOT(showTime()));
        timerQ->start(1000);

        isTimerRunning=true;
    }


    //set the button pic
    QPixmap pixmap(btnPath);
    QIcon ButtonIcon(pixmap);
    selectedBtn->setIcon(ButtonIcon);



    //check if they have won
    bool isPlayer1Won=false;
    bool isPlayer2Won=false;
    if(isPlayer1Chance)
    isPlayer1Won=eventHandlePP->isPlayer1Won();
    else isPlayer2Won=eventHandlePP->isPlayer2Won();

    if(isPlayer1Won || isPlayer2Won)
    {
        didSomeoneWon=true;
        ui->pushButtonNewGameWSameP->setVisible(true);

        if(isPlayer1Won){
            //p1 act goes here
            ui->labelStatusInfo->setText(ui->labelPlayer1->text()+" Won");
        }
        else {
            //p2 act goes here
            ui->labelStatusInfo->setText(ui->labelPlayer2->text()+" Won");
        }

    }



    if(isPlayer1Chance)isPlayer1Chance=false;
    else isPlayer1Chance=true;



    isAllBoxesFilled = eventHandlePP->isAllBoxesFilled();

    //emit the changed value
    emit playerChanceChanged(isPlayer1Chance);

    //change the button pic dir
    if(isPlayer1Chance) btnPath=":images/btns/cross/tomato_btn.png";
    else btnPath=":images/btns/cross/leave_btn.png";


    if(isAllBoxesFilled && !didSomeoneWon){
    ui->labelStatusInfo->setText("Draw");
    ui->pushButtonNewGameWSameP->setVisible(true);
    }


}


void PlayPage::toggleRedArrow(bool isPlayer1)
{
    if(!didSomeoneWon && !isAllBoxesFilled){
        ui->labelArrowRed_P1->setVisible(isPlayer1);
        ui->labelArrowRed_P2->setVisible(!isPlayer1);
    }else{
        ui->labelArrowRed_P1->setVisible(false);
        ui->labelArrowRed_P2->setVisible(false);
    }

}

//set the togglePlayerChance() to the Boxes
void PlayPage::on_pushButton1X1_clicked()
{

    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(1)){
        emit boxClicked(1, isPlayer1Chance);
        selectedBtn= ui->pushButton1X1;
        togglePlayerChance();
        }
    }

}



//void PlayPage::setSomeoneWonValue(bool state){
//    didSomeoneWon=state; //change val
//}



void PlayPage::on_pushButton1X2_clicked()
{


    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(2)){
        emit boxClicked(2, isPlayer1Chance);
        selectedBtn= ui->pushButton1X2;
        togglePlayerChance();
        }
    }

//    qint64 tm=myTimer.elapsed()/1000;

//     qDebug()<<tm;

}

void PlayPage::on_pushButton1X3_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(3)){
        emit boxClicked(3, isPlayer1Chance);
        selectedBtn= ui->pushButton1X3;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton2X1_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(4)){
        emit boxClicked(4, isPlayer1Chance);
        selectedBtn= ui->pushButton2X1;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton2X2_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(5)){
        emit boxClicked(5, isPlayer1Chance);
        selectedBtn= ui->pushButton2X2;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton2X3_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(6)){
        emit boxClicked(6, isPlayer1Chance);
        selectedBtn= ui->pushButton2X3;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton3X1_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(7)){
        emit boxClicked(7, isPlayer1Chance);
        selectedBtn= ui->pushButton3X1;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton3X2_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(8)){
        emit boxClicked(8, isPlayer1Chance);
        selectedBtn= ui->pushButton3X2;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButton3X3_clicked()
{
    if(!didSomeoneWon){
        if(eventHandlePP->returnBoxState(9)){
        emit boxClicked(9, isPlayer1Chance);
        selectedBtn= ui->pushButton3X3;
        togglePlayerChance();
        }
    }

}

void PlayPage::on_pushButtonNewGame_clicked()
{

        MainPage *mainPg;
        mainPg =new MainPage();
        mainPg->show();
        this->close();

}

void PlayPage::on_pushButtonNewGameWSameP_clicked()
{
        MainPage *mainPg;
        mainPg =new MainPage(ui->labelPlayer1->text(),ui->labelPlayer2->text());
        mainPg->show();
        this->close();
}
