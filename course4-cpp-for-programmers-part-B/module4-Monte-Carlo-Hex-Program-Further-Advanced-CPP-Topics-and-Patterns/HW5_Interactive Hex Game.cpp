// Homework 5 – Interactive Hex Game with Monte Carlo AI
// Description: Player vs AI on Hex board. AI uses Monte Carlo simulations to evaluate best move.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

class HexGame {
private:
    int size;
    std::vector<std::vector<char>> board;
    std::vector<std::pair<int, int>> emptyCells;
    std::mt19937 rng;
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}
    };

    bool inBounds(int i, int j) const {
        return i >= 0 && i < size && j >= 0 && j < size;
    }

    bool dfs(int i, int j, char player, std::vector<std::vector<bool>>& visited) const {
        if (!inBounds(i, j) || board[i][j] != player || visited[i][j]) return false;
        visited[i][j] = true;

        if ((player == 'X' && j == size - 1) || (player == 'O' && i == size - 1)) return true;

        for (const auto& [di, dj] : directions)
            if (dfs(i + di, j + dj, player, visited)) return true;

        return false;
    }

    bool checkWin(char player) const {
        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
        if (player == 'X') {
            for (int i = 0; i < size; ++i)
                if (board[i][0] == 'X' && dfs(i, 0, 'X', visited)) return true;
        } else {
            for (int j = 0; j < size; ++j)
                if (board[0][j] == 'O' && dfs(0, j, 'O', visited)) return true;
        }
        return false;
    }

    void simulateGame(std::vector<std::vector<char>> trialBoard, std::vector<std::pair<int, int>> trialEmpty, char aiPlayer, char humanPlayer, int& wins, int trials) {
        std::shuffle(trialEmpty.begin(), trialEmpty.end(), rng);
        char turn = humanPlayer;
        for (const auto& [i, j] : trialEmpty) {
            trialBoard[i][j] = turn;
            turn = (turn == 'X') ? 'O' : 'X';
        }
        if (checkSimulatedWin(trialBoard, aiPlayer)) ++wins;
    }

    bool checkSimulatedWin(const std::vector<std::vector<char>>& trialBoard, char player) const {
        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
        if (player == 'X') {
            for (int i = 0; i < size; ++i)
                if (trialBoard[i][0] == 'X' && dfsSim(i, 0, 'X', visited, trialBoard)) return true;
        } else {
            for (int j = 0; j < size; ++j)
                if (trialBoard[0][j] == 'O' && dfsSim(0, j, 'O', visited, trialBoard)) return true;
        }
        return false;
    }

    bool dfsSim(int i, int j, char player, std::vector<std::vector<bool>>& visited, const std::vector<std::vector<char>>& b) const {
        if (!inBounds(i, j) || b[i][j] != player || visited[i][j]) return false;
        visited[i][j] = true;
        if ((player == 'X' && j == size - 1) || (player == 'O' && i == size - 1)) return true;
        for (const auto& [di, dj] : directions)
            if (dfsSim(i + di, j + dj, player, visited, b)) return true;
        return false;
    }

public:
    HexGame(int s) : size(s), board(s, std::vector<char>(s, '.')) {
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                emptyCells.emplace_back(i, j);
    }

    void drawBoard() const {
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

    bool makeMove(int i, int j, char player) {
        if (!inBounds(i, j) || board[i][j] != '.') return false;
        board[i][j] = player;
        emptyCells.erase(std::remove(emptyCells.begin(), emptyCells.end(), std::make_pair(i, j)), emptyCells.end());
        return true;
    }

    std::pair<int, int> bestMonteCarloMove(char aiPlayer, char humanPlayer, int trialsPerMove = 1000) {
        int bestWins = -1;
        std::pair<int, int> bestMove = {-1, -1};
        for (const auto& [i, j] : emptyCells) {
            auto trialBoard = board;
            auto trialEmpty = emptyCells;
            trialBoard[i][j] = aiPlayer;
            trialEmpty.erase(std::remove(trialEmpty.begin(), trialEmpty.end(), std::make_pair(i, j)), trialEmpty.end());

            int wins = 0;
            for (int t = 0; t < trialsPerMove; ++t)
                simulateGame(trialBoard, trialEmpty, aiPlayer, humanPlayer, wins, trialsPerMove);

            if (wins > bestWins) {
                bestWins = wins;
                bestMove = {i, j};
            }
        }
        return bestMove;
    }

    bool isGameOver() const {
        return checkWin('X') || checkWin('O');
    }

    void play() {
        char human = 'O', ai = 'X';
        std::cout << "Choose your color (X = first, O = second): ";
        char choice; std::cin >> choice;
        if (choice == 'X' || choice == 'x') { human = 'X'; ai = 'O'; }

        drawBoard();
        while (!isGameOver()) {
            if (human == 'X') {
                int i, j;
                std::cout << "Enter your move (row col): ";
                std::cin >> i >> j;
                while (!makeMove(i, j, human)) {
                    std::cout << "Invalid move. Try again: ";
                    std::cin >> i >> j;
                }
                drawBoard();
                if (isGameOver()) break;
            }

            std::cout << "AI thinking...\n";
            auto [aii, aij] = bestMonteCarloMove(ai, human);
            makeMove(aii, aij, ai);
            drawBoard();
            if (isGameOver()) break;

            if (human == 'O') {
                int i, j;
                std::cout << "Enter your move (row col): ";
                std::cin >> i >> j;
                while (!makeMove(i, j, human)) {
                    std::cout << "Invalid move. Try again: ";
                    std::cin >> i >> j;
                }
                drawBoard();
            }
        }

        if (checkWin(human)) std::cout << "You win!\n";
        else if (checkWin(ai)) std::cout << "AI wins!\n";
    }
};

int main() {
    int boardSize = 5; // Try 5x5 first, then scale to 11
    HexGame game(boardSize);
    game.play();
    return 0;
}
