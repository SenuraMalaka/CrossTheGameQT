#ifndef EVENTHANDLEPLAYPAGE_H
#define EVENTHANDLEPLAYPAGE_H

#include <QObject>
#include <QPushButton>

class EventHandlePlayPage : public QObject
{
    Q_OBJECT
public:
    explicit EventHandlePlayPage(QObject *parent = 0);
    bool returnBoxState(qint8);
    bool isPlayer1Won();
    bool isPlayer2Won();
    bool isAllBoxesFilled();

signals:


public slots:
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
