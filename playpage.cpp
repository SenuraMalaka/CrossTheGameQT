#include "playpage.h"
#include "ui_playpage.h"
#include <QDebug>

PlayPage::PlayPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayPage)
{
    ui->setupUi(this);


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
