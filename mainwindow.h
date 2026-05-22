#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr, char player1_choice = 'X');
    void check_game_state();
private slots:
    void handleButton(int index);
private:
    QPushButton *m_buttonArray[9];
    int round;
    QString player1_figure;
    QString player2_figure;
    bool win;
};
#endif // MAINWINDOW_H