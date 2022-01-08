#include <iostream>
#include <vector>
#include "ooptool.h"
#include "ooptoolg.h"
#include "Board.h"

using namespace std;

Board* board;



bool check_free(vector<int>& a, int row, int column, bool display, Board*& board) {
	for (int i=0; i < row; ++i) {
		if (display) {
			board->setSquare(row, column, Gruen);
			board->render();
			schlafeMs(30);
		}
		if ((a[i] == column) || abs(a[i] - column) == abs(i - row)) {
			board->resetSquare(row, column);
			board->render();
			schlafeMs(30);
			return false;
		}
	}
	return true;
}

bool Dame (vector<int>& a, int row, int n, bool display, Board*& board) {
	if (row == n) {
		return true;
	}
	for (int column=0; column < n; ++column) {
		if (check_free(a, row, column, display, board)) {
			a[row] = column;
			if (display) {
				board->setSquare(row, column, Gruen);
				board->render();
				schlafeMs(30);
			}
			if (Dame(a, row + 1, n, display, board)) {
				return true;
			}
			if (display) {
				board->resetSquare(row, column);
				board->render();
				schlafeMs(30);
			}
		}
	}
	return false;
}

void ausgabe(vector<int>& a, int n) {
	for (int i = n - 1; i >= 0; --i) {
		cout << i << "|";
		for (int j = 0; j < n; ++j) {
			if (a[j] == i) {
				cout << "* ";
			} else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main (int argc, char* argv[]) {
	argsp_t argsp(argc, argv);
	bool display = argsp.flag("d");
	board = new Board(atoi(argv[1]));
	for (int i = 1; i < argc; ++i) {
		vector<int> a (atoi(argv[i]));
		bool lsg = Dame(a, 0, atoi(argv[i]), display, board);
		if (lsg) {
			ausgabe(a, atoi(argv[i]));
		} else {
			cout << "Es wurde keine Loesung gefunden!" << endl;
		}
		if (display) {
			break;
		}
	}
	schlafeMs(5000);
}

//hallo test
