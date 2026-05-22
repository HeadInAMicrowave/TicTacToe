#include "mainwindow.h"
#include <iostream>
#include <QApplication>


class Game {
private:
	char board[3][3];
	char player1_figure;
	char player2_figure;
	int round;
public:

	Game(char player1_choice, char player2_choice) {
		player1_figure = player1_choice;
		player2_figure = player2_choice;
		round = 1;

		for (int i = 0; i < std::size(board); i++) {
			for (int j = 0; j < std::size(board[i]); j++) {
				board[i][j] = NULL;
			}
		}
	}
	~Game() {
		free(&this->board);
	}

	void print_board() const;
	void update_board(int board_cords[2], int player);
	int get_round();
	bool check_game_state();
};

void Game::print_board() const {
	for (int i = 0; i < std::size(this->board); i++) {
		for (int j = 0; j < std::size(this->board[i]); j++) {
			std::cout << "[" << this->board[i][j] << "]";
		}
		std::cout << std::endl;
	}
	return;
}

void Game::update_board(int board_cords[2], int player) {
	int X = board_cords[0];
	int Y = board_cords[1];

	if (1 == player) {
		this->board[X][Y] = this->player1_figure;
	} 
	else {
		this->board[X][Y] = this->player2_figure;
	}

	this->round++;

	return;
}

int Game::get_round() {
	return this->round;
}

bool Game::check_game_state() {
	for (int i = 0; i < std::size(this->board); i++) {
		if (this->board[i][0] == 'x' && this->board[i][1] == 'x' && this->board[i][2] == 'x') return true;

		if (this->board[i][0] == 'o' && this->board[i][1] == 'o' && this->board[i][2] == 'o') return true;
	}

	for (int j = 0; j < std::size(this->board[0]); j++) {
		if (this->board[0][j] == 'x' && this->board[1][j] == 'x' && this->board[2][j] == 'x') return true;

		if (this->board[0][j] == 'o' && this->board[1][j] == 'o' && this->board[2][j] == 'o') return true;
	}

	if (this->board[0][0] == 'x' && this->board[1][1] == 'x' && this->board[2][2] == 'x') return true;

	if (this->board[0][0] == 'o' && this->board[1][1] == 'o' && this->board[2][2] == 'o') return true;

	return false;
}

int main(int argc, char **argv) {
    int windowSizeX = 900;
    int windowSizeY = 900;
    QApplication app (argc, argv);

    MainWindow mainWindow;
    mainWindow.setFixedSize(windowSizeX, windowSizeY);


    mainWindow.show();
    return app.exec();
    // char player1_choice;
    // char player2_choice;
    // std::cout << "Welcome to the game! Player 1, select the figure you would like to use (x or o)." << std::endl;
    // std::cin >> player1_choice;

    // if ('x' == player1_choice) {
    // 	player2_choice = 'o';
    // }
    // else if ('o' == player1_choice) {
    // 	player2_choice = 'x';
    // }
    // else {
    // 	std::cout << "Invalid figure selection, the program will exit.";
    // 	return 0;
    // }
    // Game *game = new Game(player1_choice, player2_choice);

    // while (true) {
    // 	int cords[2];
    // 	std::cout << "Please make a move." << std::endl;

    // 	std::cin >> cords[0] >> cords[1];

    // 	if (game->get_round() % 2 == 1) {
    // 		game->update_board(cords, 1);
    // 	}
    // 	else {
    // 		game->update_board(cords, 2);
    // 	}

    // 	game->print_board();

    // 	if (true == game->check_game_state()) {
    // 		if (game->get_round() % 2 == 1) {
    // 			std::cout << "Player 2 Wins!";
    // 			return 0;
    // 		}
    // 		else {
    // 			std::cout << "Player 1 Wins!";
    // 			return 0;
    // 		}
    // 	}
    // }
}