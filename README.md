This code is a game of Tic-Tac-Toe that you can play, I have also done this in C# but C++ is more enjoyable. Here's the fun part:

When the game starts, it shows an empty Tic-Tac-Toe board, which is a 3x3 grid where players will take turns to place their marks ('X' or 'O').
Two players play the game, taking turns. One player is 'X', and the other player is 'O'. The game tells you whose turn it is and asks where you want to place your mark. You tell the game by entering a row and a column number (both between 1 and 3).
If someone tries to place a mark outside the grid or in a spot that's already taken, the game says it's an invalid move and asks you to try again.
After every turn, the game checks if there's a winner. A player wins if they get three of their marks in a row, in a column, or diagonally across the board.
The game keeps going until one player wins or all the spots are filled up, which means it's a draw.
If there's a winner, the game shows the final board and announces who won. If the board is filled and there's no winner, it says it's a draw.
It's a simple console version of the classic Tic-Tac-Toe game, where you can play against a friend by taking turns typing your moves.

*can be run by entering g++ main.cpp into your terminal, click enter, then type ./a.out
