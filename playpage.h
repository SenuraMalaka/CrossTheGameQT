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

    /*!
     * Sets the Player 1 Name in the Label at the left side
     */
    void setPlayer1(QString p);

    /*!
     * Sets the Player 2 Name in the Label at the right side
     */
    void setPlayer2(QString p);

    /*!
     * Shows The Time on the LCD Display
     */
    void showTime();

signals:
    /*!
     * Emits when the other player has got the chance. If true, Player 1 has the chance.
     */
    void playerChanceChanged(bool);

    /*!
     * Emits the Box number and the Player. If True, Player 1 has clicked the box.
     */
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


    void on_pushButtonNewGame_clicked();

    void on_pushButtonNewGameWSameP_clicked();

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
