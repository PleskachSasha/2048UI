#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "delegate.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event);

public:
    setValue();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int CountNumberUpDown(int line);
    void CountZero(bool &zero, int count);
    void ScoreIncrease(const Delegate &delegate);
private:
    const int BOARD_SIZE = 4;

    std::array<std::array<Delegate, 4>, 4> board = {{
        {Delegate(0), Delegate(0), Delegate(0), Delegate(0)},
        {Delegate(0), Delegate(0), Delegate(0), Delegate(0)},
        {Delegate(0), Delegate(0), Delegate(0), Delegate(0)},
        {Delegate(16), Delegate(8), Delegate(4), Delegate(2)}
    }};
    std::array<std::array<Delegate, 4>, 4> prevBoard {};

    int score = 0;

    enum EnumChoise
    {
        choice_Left_Arrow = 75,
        choice_Right_Arrow = 77,
        choice_Down_Arrow = 80,
        choice_Up_Arrow = 72,

        choice_a = 97,
        choice_d = 100,
        choice_s = 115,
        choice_w = 119,
        choice_e = 101,

        choice_A = 65,
        choice_D = 68,
        choice_S = 83,
        choice_W = 87,
        choice_E = 69
    };

    Ui::MainWindow *ui;

    void MoveUp();
    void MoveLeft();
    void MoveDown();
    void MoveRight();
};
#endif // MAINWINDOW_H
