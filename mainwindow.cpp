#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setValue();
    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::setValue()
{
    ui->label_00->setText(QString::number(board[0][0].getValue().toInt()));
    ui->label_01->setText(QString::number(board[0][1].getValue().toInt()));
    ui->label_02->setText(QString::number(board[0][2].getValue().toInt()));
    ui->label_03->setText(QString::number(board[0][3].getValue().toInt()));

    ui->label_10->setText(QString::number(board[1][0].getValue().toInt()));
    ui->label_11->setText(QString::number(board[1][1].getValue().toInt()));
    ui->label_12->setText(QString::number(board[1][2].getValue().toInt()));
    ui->label_13->setText(QString::number(board[1][3].getValue().toInt()));

    ui->label_20->setText(QString::number(board[2][0].getValue().toInt()));
    ui->label_21->setText(QString::number(board[2][1].getValue().toInt()));
    ui->label_22->setText(QString::number(board[2][2].getValue().toInt()));
    ui->label_23->setText(QString::number(board[2][3].getValue().toInt()));

    ui->label_30->setText(QString::number(board[3][0].getValue().toInt()));
    ui->label_31->setText(QString::number(board[3][1].getValue().toInt()));
    ui->label_32->setText(QString::number(board[3][2].getValue().toInt()));
    ui->label_33->setText(QString::number(board[3][3].getValue().toInt()));
}
int MainWindow::CountNumberUpDown(int line)
{
    int count = 0;
    for (int q = 0; q < 4; ++q)
    {
        int test = board[q][line].getValue().toInt();
        if (board[q][line].getValue().toInt() != 0)
        {
            ++count;
        }
    }

    return count;
}
void MainWindow::CountZero(bool& zero, int count)
{
    if (count == 0)
    {
        zero = true;
    }
}
void MainWindow::ScoreIncrease(const Delegate& delegate) {
    score += delegate.getValue().toInt();
}

void MainWindow::MoveUp() {
    qDebug() << "2ц";
        for (int i = 0; i < 4; ++i)
    {
        for (int next = 0; next < 3; ++next)
        {
            bool zeroFlag = false;
            bool endWhile = false;

            while (!endWhile)
            {
                int itL = next;
                int itR = -1;
                int count = CountNumberUpDown(i);

                CountZero(endWhile, count);

                if (!endWhile)
                {
                    while (true)
                    {
                        int qq =board[itL][i].getValue().toInt();
                        if (board[itL][i].getValue().toInt() != 0 || itL > 3)
                        {
                            break;
                        }
                        ++itL;
                    }

                    if (count > 1)
                    {
                        while (true)
                        {
                            if (itL == itR)
                            {
                                ++itR;

                            }
                            if (itR > 3)
                            {
                                itR = -1;
                                break;
                            }
                            if (board[itR][i] != 0 && itL < itR)
                            {
                                break;
                            }
                            ++itR;
                        }
                    }

                    if (itL < 4 && itR < 4)
                    {
                        for (int j = 0; j < 4; ++j)
                        {
                            int tttt = board[itR][i].getValue().toInt();
                            int tttt1 = board[itL][i].getValue().toInt();
                            if (board[itR][i].getValue().toInt() == board[itL][i].getValue().toInt() /*&& board[j][i] == Delegate(0) && j < itL*/)
                            {
                                board[j][i] = board[itL][i] * 2;
                                board[itR][i] = 0;
                                board[itL][i] = 0;
                                --j;
                                ScoreIncrease(board[j][i]);
                                break;
                            }
                            else if (board[itR][i] == board[itL][i] && j > itL)
                            {
                                board[itL][i] = board[itL][i] * 2;
                                board[itR][i] = 0;
                                --j;
                                ScoreIncrease(board[itL][i]);
                                break;
                            }
                            else if (board[itR][i] != board[itL][i] && count > 1 && itL < j && itR > j && board[j][i] == Delegate(0))
                            {
                                board[j][i] = board[itR][i];
                                board[itR][i] = 0;
                                break;
                            }
                            else if (board[itR][i] != board[itL][i] && count > 1 && itL > j && itR > j && board[j][i] == Delegate(0))
                            {
                                board[j][i] = board[itL][i];
                                board[itL][i] = board[itR][i];
                                board[itR][i] = 0;
                                break;
                            }
                            else if (board[j][i] == Delegate(0) && itL != 0 && j < itL)
                            {
                                board[j][i] = board[itL][i];
                                board[itL][i] = 0;
                                next = 4;
                                break;
                            }
                        }
                    }

                }
                endWhile = true;
            }
        }
    }

}
void MainWindow::MoveLeft() {
    qDebug() << "2A";
}
void MainWindow::MoveDown() {
    qDebug() << "3S";
}
void MainWindow::MoveRight() {
    qDebug() << "4D";
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W)
    {
        MoveUp();
    }
    else if (event->key() == Qt::Key_A)
    {
        MoveLeft();
    }
    else if (event->key() == Qt::Key_S)
    {
        MoveDown();
    }
    else if (event->key() == Qt::Key_D)
    {
        MoveRight();
    }
    setValue();
    QWidget::keyPressEvent(event);
}
