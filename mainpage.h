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

    /*!
     * Overloaded constructor.
     * Used to pass the current player names to start a new game with the same players.
     */
    explicit MainPage(QString p1Name, QString p2Name, QWidget *parent = 0);
    ~MainPage();

private slots:
    void on_pushButtonPlayNow_clicked();

private:
    Ui::MainPage *ui;
    bool checkPlayerNames();
    MainPage *tc;
    PlayPage *pPage;
    QString str;
    void initialiseStart();
};

#endif // MAINPAGE_H
