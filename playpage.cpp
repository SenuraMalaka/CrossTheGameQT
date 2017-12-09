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

    //check if they have won
    if(isPlayer1Chance)
    eventHandlePP->isPlayer1Won();
    else eventHandlePP->isPlayer2Won();


    if(isPlayer1Chance)isPlayer1Chance=false;
    else isPlayer1Chance=true;

    //emit the changed value
    emit playerChanceChanged(isPlayer1Chance);
}


void PlayPage::toggleRedArrow(bool isPlayer1)
{
    ui->labelArrowRed_P1->setVisible(isPlayer1);
    ui->labelArrowRed_P2->setVisible(!isPlayer1);
}

//set the togglePlayerChance() to the Boxes
void PlayPage::on_pushButton1X1_clicked()
{

    emit boxClicked(1, isPlayer1Chance);
    if(eventHandlePP->returnBoxState(1)) qDebug()<<"Box 1 is clicked";  //test ///finished from here (4th Dec)

    togglePlayerChance();

}

void PlayPage::on_pushButton1X2_clicked()
{
    emit boxClicked(2, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton1X3_clicked()
{
    emit boxClicked(3, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton2X1_clicked()
{
    emit boxClicked(4, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton2X2_clicked()
{
    emit boxClicked(5, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton2X3_clicked()
{
    emit boxClicked(6, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton3X1_clicked()
{
    emit boxClicked(7, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton3X2_clicked()
{
    emit boxClicked(8, isPlayer1Chance);
    togglePlayerChance();

}

void PlayPage::on_pushButton3X3_clicked()
{
    emit boxClicked(9, isPlayer1Chance);
    togglePlayerChance();

}
