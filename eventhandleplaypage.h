#ifndef EVENTHANDLEPLAYPAGE_H
#define EVENTHANDLEPLAYPAGE_H

#include <QObject>
#include <QPushButton>

class EventHandlePlayPage : public QObject
{
    Q_OBJECT
public:
    explicit EventHandlePlayPage(QObject *parent = 0);

    /*!
     * returns the Box availability.
     * If the passed Box (Box number) has been clicked already, it will return false. Otherwise true.
     * Used to check the Box status when user tries to click on a Box.
     */
    bool returnBoxState(qint8);

    /*!
     * Returns whether the player 1 has won or not.
     * This will check if the player 1 has already clicked on 3 boxes in straight.
     */
    bool isPlayer1Won();

    /*!
     * Returns whether the player 2 has won or not.
     * This will check if the player 2 has already clicked on 3 boxes in straight.
     */
    bool isPlayer2Won();

    /*!
     * Returns whether the all the boxes have been filled by the players.
     * Used to check if the game status is draw.
     */
    bool isAllBoxesFilled();

signals:


public slots:

    /*!
     * Mark the Box as checked.
     * Will pass the Box number and the Player identification. Player 1 represents true.
     * This is used to remember who has clicked what.
     */
    void checkTheBox(qint8, bool);

private:
    bool isBox1X1CheckedP1;
    bool isBox1X2CheckedP1;
    bool isBox1X3CheckedP1;
    bool isBox2X1CheckedP1;
    bool isBox2X2CheckedP1;
    bool isBox2X3CheckedP1;
    bool isBox3X1CheckedP1;
    bool isBox3X2CheckedP1;
    bool isBox3X3CheckedP1;

    bool isBox1X1CheckedP2;
    bool isBox1X2CheckedP2;
    bool isBox1X3CheckedP2;
    bool isBox2X1CheckedP2;
    bool isBox2X2CheckedP2;
    bool isBox2X3CheckedP2;
    bool isBox3X1CheckedP2;
    bool isBox3X2CheckedP2;
    bool isBox3X3CheckedP2;


    bool isBox1X1AvailableToClick;
    bool isBox1X2AvailableToClick;
    bool isBox1X3AvailableToClick;
    bool isBox2X1AvailableToClick;
    bool isBox2X2AvailableToClick;
    bool isBox2X3AvailableToClick;
    bool isBox3X1AvailableToClick;
    bool isBox3X2AvailableToClick;
    bool isBox3X3AvailableToClick;

    int boxClickCount;

};

#endif // EVENTHANDLEPLAYPAGE_H
