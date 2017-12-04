#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

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
    void checkPlayerNames();
    MainPage *tc;
};

#endif // MAINPAGE_H
