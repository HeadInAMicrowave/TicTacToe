#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, char player1_choice) : QMainWindow(parent){
    round = 0;
    win = false;

    if ('X' == player1_choice) {
        player1_figure = static_cast<QString>('X');
        player2_figure = static_cast<QString>('O');
    }
    else if ('O' == player1_choice) {
        player1_figure = static_cast<QString>('O');
        player2_figure = static_cast<QString>('X');
    }

    int buttonSizeX = this->width() / 3;
    int buttonSizeY = this->height() / 3;
    for (int i = 0; i < 9; i++) {
        QPushButton* button = new QPushButton("", this);
        m_buttonArray[i] = button;
    }

    for (int j = 0; j <= 2; j++) {
        m_buttonArray[j]->setGeometry(buttonSizeX * j, 0, buttonSizeX, buttonSizeY);
        m_buttonArray[j+3]->setGeometry(buttonSizeX * j, buttonSizeY, buttonSizeX, buttonSizeY);
        m_buttonArray[j+6]->setGeometry(buttonSizeX * j, buttonSizeY * 2, buttonSizeX, buttonSizeY);

        connect(m_buttonArray[j], &QPushButton::released, this, [this, j] { MainWindow::handleButton(j); });
        connect(m_buttonArray[j+3], &QPushButton::released, this, [this, j] { MainWindow::handleButton(j+3); });
        connect(m_buttonArray[j+6], &QPushButton::released, this, [this, j] { MainWindow::handleButton(j+6); });
    }
}

void MainWindow::handleButton(int index) {
    if (round % 2 == 1) {
        m_buttonArray[index]->setText(player1_figure);
    }
    else {
        m_buttonArray[index]->setText(player2_figure);
    }

    round++;
    check_game_state();
}

void MainWindow::check_game_state() {
    int i = 0;
    while (i < 9) {
        if (player1_figure == m_buttonArray[i]->text() && player1_figure == m_buttonArray[i+1]->text() && player1_figure == m_buttonArray[i+2]->text()) win = true;
        if (player2_figure == m_buttonArray[i]->text() && player2_figure == m_buttonArray[i+1]->text() && player2_figure == m_buttonArray[i+2]->text()) win = true;

        i += 3;
    }

    for (int i = 0; i < 3; i++) {
        if (player1_figure == m_buttonArray[i]->text() && player1_figure == m_buttonArray[i+3]->text() && player1_figure == m_buttonArray[i+6]->text()) win = true;
        if (player2_figure == m_buttonArray[i]->text() && player2_figure == m_buttonArray[i+3]->text() && player2_figure == m_buttonArray[i+6]->text()) win = true;
    }

    if (player1_figure == m_buttonArray[0]->text() && player1_figure == m_buttonArray[4]->text() && player1_figure == m_buttonArray[8]->text()) win = true;
    if (player2_figure == m_buttonArray[0]->text() && player2_figure == m_buttonArray[4]->text() && player2_figure == m_buttonArray[8]->text()) win = true;

    if (player1_figure == m_buttonArray[2]->text() && player1_figure == m_buttonArray[4]->text() && player1_figure == m_buttonArray[6]->text()) win = true;
    if (player2_figure == m_buttonArray[2]->text() && player2_figure == m_buttonArray[4]->text() && player2_figure == m_buttonArray[6]->text()) win = true;

    win = false;

}