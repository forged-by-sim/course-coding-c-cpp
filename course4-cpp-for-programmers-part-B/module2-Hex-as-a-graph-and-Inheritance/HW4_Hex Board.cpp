// Homework 4 – Hex Board Representation with ASCII Drawing and Graph Structure
// Description: Generates a Hex board of a given size (e.g., 7x7 or 11x11),
// accepts moves (B for Blue, R for Red), checks legality, and detects win condition (pathfinding).
// Game logic will be added in Homework 5.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>

class HexBoard {
private:
    int size;
    std::vector<std::vector<char>> board; // 'B', 'R', or '.'

    // Direction vectors for 6 possible neighbors in hex grid
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}
    };

    bool inBounds(int i, int j) const {
        return i >= 0 && i < size && j >= 0 && j < size;
    }

    // DFS to check win condition for player
    bool dfs(int i, int j, char player, std::vector<std::vector<bool>>& visited) const {
        if (!inBounds(i, j) || board[i][j] != player || visited[i][j]) return false;
        visited[i][j] = true;

        if ((player == 'B' && j == size - 1) || (player == 'R' && i == size - 1)) return true;

        for (auto [di, dj] : directions) {
            if (dfs(i + di, j + dj, player, visited)) return true;
        }

        return false;
    }

public:
    HexBoard(int s) : size(s), board(s, std::vector<char>(s, '.')) {}

    // Draw ASCII hex board
    void draw() const {
        for (int i = 0; i < size; ++i) {
            std::cout << std::string(2 * i, ' ');
            for (int j = 0; j < size; ++j) {
                std::cout << board[i][j];
                if (j != size - 1) std::cout << " - ";
            }
            std::cout << "\n";
            if (i != size - 1) {
                std::cout << std::string(2 * i + 1, ' ');
                for (int j = 0; j < size - 1; ++j)
                    std::cout << "\\ / ";
                std::cout << "\\" << std::endl;
            }
        }
    }

    // Attempt to place a move for a player ('B' or 'R')
    bool placeMove(int row, int col, char player) {
        if (!inBounds(row, col)) {
            std::cout << "Invalid move: Out of bounds." << std::endl;
            return false;
        }
        if (board[row][col] != '.') {
            std::cout << "Invalid move: Cell already occupied." << std::endl;
            return false;
        }
        board[row][col] = player;
        return true;
    }

    // Check if the given player has won
    bool checkWin(char player) const {
        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));

        if (player == 'B') {
            for (int i = 0; i < size; ++i)
                if (board[i][0] == 'B' && dfs(i, 0, 'B', visited)) return true;
        } else if (player == 'R') {
            for (int j = 0; j < size; ++j)
                if (board[0][j] == 'R' && dfs(0, j, 'R', visited)) return true;
        }

        return false;
    }
};

int main() {
    int boardSize = 7;
    HexBoard game(boardSize);
    game.draw();

    // Example moves
    game.placeMove(0, 0, 'B');
    game.placeMove(1, 0, 'R');
    game.placeMove(0, 1, 'B');
    game.placeMove(2, 0, 'R');

    std::cout << "\nAfter some moves:\n";
    game.draw();

    if (game.checkWin('B')) std::cout << "Blue wins!\n";
    else if (game.checkWin('R')) std::cout << "Red wins!\n";
    else std::cout << "No winner yet.\n";

    return 0;
}
