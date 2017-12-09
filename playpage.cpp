#include "playpage.h"
#include "ui_playpage.h"
#include <QDebug>

PlayPage::PlayPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayPage)
{
    ui->setupUi(this);

    //set the player 1 as the first player
    isPlayer1Chance=true;
    ui->labelArrowRed_P2->setVisible(!isPlayer1Chance);
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

void PlayPage::togglePlayerChance(){

    //set the button pic
    QPixmap pixmap(btnPath);
    QIcon ButtonIcon(pixmap);
    selectedBtn->setIcon(ButtonIcon);

    //check if they have won
    if(isPlayer1Chance)
    eventHandlePP->isPlayer1Won();
    else eventHandlePP->isPlayer2Won();


    if(isPlayer1Chance)isPlayer1Chance=false;
    else isPlayer1Chance=true;

    //emit the changed value
    emit playerChanceChanged(isPlayer1Chance);

    //change the button pic dir
    if(isPlayer1Chance) btnPath=":images/btns/cross/tomato_btn.png";
    else btnPath=":images/btns/cross/leave_btn.png";

}


void PlayPage::toggleRedArrow(bool isPlayer1)
{
    ui->labelArrowRed_P1->setVisible(isPlayer1);
    ui->labelArrowRed_P2->setVisible(!isPlayer1);
}

//set the togglePlayerChance() to the Boxes
void PlayPage::on_pushButton1X1_clicked()
{

    if(eventHandlePP->returnBoxState(1)){
    emit boxClicked(1, isPlayer1Chance);
    selectedBtn= ui->pushButton1X1;
    togglePlayerChance();
    }


}

void PlayPage::on_pushButton1X2_clicked()
{
    if(eventHandlePP->returnBoxState(2)){
    emit boxClicked(2, isPlayer1Chance);
    selectedBtn= ui->pushButton1X2;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton1X3_clicked()
{
    if(eventHandlePP->returnBoxState(3)){
    emit boxClicked(3, isPlayer1Chance);
    selectedBtn= ui->pushButton1X3;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton2X1_clicked()
{
    if(eventHandlePP->returnBoxState(4)){
    emit boxClicked(4, isPlayer1Chance);
    selectedBtn= ui->pushButton2X1;
    togglePlayerChance();
    }
}

void PlayPage::on_pushButton2X2_clicked()
{
    if(eventHandlePP->returnBoxState(5)){
    emit boxClicked(5, isPlayer1Chance);
    selectedBtn= ui->pushButton2X2;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton2X3_clicked()
{
    if(eventHandlePP->returnBoxState(6)){
    emit boxClicked(6, isPlayer1Chance);
    selectedBtn= ui->pushButton2X3;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton3X1_clicked()
{
    if(eventHandlePP->returnBoxState(7)){
    emit boxClicked(7, isPlayer1Chance);
    selectedBtn= ui->pushButton3X1;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton3X2_clicked()
{
    if(eventHandlePP->returnBoxState(8)){
    emit boxClicked(8, isPlayer1Chance);
    selectedBtn= ui->pushButton3X2;
    togglePlayerChance();
    }

}

void PlayPage::on_pushButton3X3_clicked()
{
    if(eventHandlePP->returnBoxState(9)){
    emit boxClicked(9, isPlayer1Chance);
    selectedBtn= ui->pushButton3X3;
    togglePlayerChance();
    }

}
