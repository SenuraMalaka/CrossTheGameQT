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

private:
    Ui::PlayPage *ui;
};

#endif // PLAYPAGE_H
