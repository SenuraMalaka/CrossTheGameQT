#include "mainpage.h"
#include "ui_mainpage.h"
#include "QMovie"
#include "QSize"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);



    //only for windows
    #if defined(Q_OS_WIN)
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    #endif



    //setting up the background
    QPixmap bkgnd(":images/clouds.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    //bkgnd.sca
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


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
