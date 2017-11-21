#include "mainpage.h"
#include "ui_mainpage.h"
#include "QMovie"
#include "QSize"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    QMovie *movie = new QMovie(":images/gif/introLogo.gif");

    movie->setScaledSize(ui->labelMainPageLogo->size());
    ui->labelMainPageLogo->setMovie(movie);
    movie->start();


}

MainPage::~MainPage()
{
    delete ui;
}
