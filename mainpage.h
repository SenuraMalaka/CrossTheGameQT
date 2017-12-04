#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "playpage.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private slots:
    void on_pushButtonPlayNow_clicked();

private:
    Ui::MainPage *ui;
    bool checkPlayerNames();
    MainPage *tc;
    PlayPage pPage;
};

#endif // MAINPAGE_H
