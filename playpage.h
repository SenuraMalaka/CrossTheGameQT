#ifndef PLAYPAGE_H
#define PLAYPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QElapsedTimer>
#include <QTimer>
#include "eventhandleplaypage.h"
namespace Ui {
class PlayPage;
}

class PlayPage : public QWidget
{
    Q_OBJECT

public:
    explicit PlayPage(QWidget *parent = 0);
    ~PlayPage();


public slots:
    void setPlayer1(QString p);
    void setPlayer2(QString p);
    void showTime();
//    void setSomeoneWonValue(bool);

signals:
    void playerChanceChanged(bool);
    void boxClicked(qint8, bool);

private slots:
    void on_pushButton1X1_clicked();
    void toggleRedArrow(bool isPlayer1);

    void on_pushButton1X2_clicked();

    void on_pushButton1X3_clicked();

    void on_pushButton2X1_clicked();

    void on_pushButton2X2_clicked();

    void on_pushButton2X3_clicked();

    void on_pushButton3X1_clicked();

    void on_pushButton3X2_clicked();

    void on_pushButton3X3_clicked();


private:
    Ui::PlayPage *ui;
    QString player1Name;
    QString player2Name;
    QString btnPath;
    bool isPlayer1Chance;
    void togglePlayerChance();
    EventHandlePlayPage *eventHandlePP;
    QPushButton *selectedBtn;
    QElapsedTimer myTimer;
    QTimer *timerQ;
    bool isTimerRunning;
    bool didSomeoneWon;
    bool isAllBoxesFilled;

};

#endif // PLAYPAGE_H
