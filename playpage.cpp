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


    QObject::connect(this, SIGNAL(playerChanceChanged(bool)),this, SLOT(toggleRedArrow(bool)));



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
    togglePlayerChance();
}

void PlayPage::on_pushButton1X2_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton1X3_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton2X1_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton2X2_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton2X3_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton3X1_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton3X2_clicked()
{
    togglePlayerChance();
}

void PlayPage::on_pushButton3X3_clicked()
{
    togglePlayerChance();
}
