#ifndef PLAYPAGE_H
#define PLAYPAGE_H

#include <QWidget>

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

private:
    Ui::PlayPage *ui;
    QString player1Name;
    QString player2Name;
};

#endif // PLAYPAGE_H
