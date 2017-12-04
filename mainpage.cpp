#include "mainpage.h"
#include "ui_mainpage.h"
#include "QMovie"
#include "QSize"
#include <QDebug>

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    //tc = new MainPage(this);

    //QObject::connect(ui->labelMainPageArrowBtn, SIGNAL(), this, SLOT(checkPlayerNames()));

    //To prevent resizing the window
    #if defined(Q_OS_WIN)//only for windows
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    #else//for all the other platforms
    this->setMaximumSize(this->size());
    #endif


    //setting up the background
    QPixmap bkgnd(":images/clouds.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    //set the text colour to white
    ui->labelMainPageInfoTop->setStyleSheet("QLabel {color : white; }");
    ui->labelMainPageInfoTop_2->setStyleSheet("QLabel {color : white; }");
    ui->labelMainPagePlayer1->setStyleSheet("QLabel {color : white; }");
    ui->labelMainPagePlayer2->setStyleSheet("QLabel {color : white; }");


    //setting up the intro logo gif
    QMovie *movie = new QMovie(":images/gif/introLogo.gif");

    movie->setScaledSize(ui->labelMainPageLogo->size());
    ui->labelMainPageLogo->setMovie(movie);
    movie->start();


}

MainPage::~MainPage()
{
    delete ui;
}

bool MainPage::checkPlayerNames(){

    bool ret=false;
    qDebug()<<"this ran";

    QString player1=ui->lineEditMainPagePlayer1->text();
    QString player2=ui->lineEditMainPagePlayer2->text();

    if(player1 == "" || player2 == "")
        qDebug()<<"Player name could not be blank";
    else if (player1 == player2)
        qDebug()<<"Player names should not be the same";
    else ret=true;


    return ret;
}

void MainPage::on_pushButtonPlayNow_clicked()
{
    bool py=false;
    py=checkPlayerNames();
    if(py){
        qDebug()<<"Now the player can play";

     pPage.show();
     this->destroy();
    }


}
