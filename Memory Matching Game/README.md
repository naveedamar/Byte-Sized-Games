# 🧠 Memory Matching Game (C++ Command Line Interface)

This is a classic Memory Matching Game (also known as Concentration or Pairs) implemented entirely in C++. Players flip cards to find matching pairs, aiming to clear the board in the fewest turns possible. This version features user score tracking and a customizable board size.

---

## 🚀 Features:

* **CLI-Based Gameplay:** Play directly in your terminal or command prompt.
* **User Persistence:** Tracks individual player scores, welcoming returning users and saving their progress.
* **Dynamic Board Generation:** Allows players to set their desired board dimensions (rows x columns), ensuring an even number of cells for pairs.
* **Randomized Card Values:** Cards are assigned random alphanumeric characters (0-9, a-z, A-Z) to create unique game boards each time.
* **Match Tracking:** Keeps count of found matches and total turns taken.

---

## 🛠️ How to Play:

1.  **Start the Game:** Run the compiled executable.
2.  **Enter Your Name:** The game will prompt you for your name to track your score.
3.  **Set Board Dimensions:** Enter the desired number of rows and columns. Remember, the total number of cells (rows \* columns) must be an even number.
4.  **Flip Cards:** During your turn, you will be prompted to enter the row and column coordinates for two cards you wish to flip.
5.  **Find Matches:** If the two selected cards reveal the same character, they are considered a match and remain face up. If they don't match, they will be flipped back face down.
6.  **Win:** The game ends when all pairs have been found. Your score (number of wins) will be updated.
7.  **Play Again:** You'll have the option to play another round.

---

## ⚙️ How to Run:

1.  **Prerequisites:** You need a C++ compiler (like g++ which is part of GCC) installed on your system.
2.  **Clone the Repository**
3.  **Compile:** Open your terminal or command prompt in the `MemoryMatchingGame` directory and compile the source code:
4.  **Run:** Execute the compiled program
---

## 📁 File Handling:

This game utilizes a local file named `user_file.txt` to store player names and their win counts. This file will be created automatically if it doesn't exist.

---

## 💻 Technologies Used:

* **C++**
* Standard C++ Libraries (iostream, string, fstream, cstdio, random, cstdlib, ctime)

---

## ⚖️ License:

This project is open-sourced under the **MIT License**. See the `LICENSE` file in the root of the `my-mini-games` repository for more details.

---

## 🌱 My Learning Journey:

Developing this C++ Memory Matching Game helped me solidify concepts like:

* **File I/O:** Reading from and writing to files for user data persistence.
* **2D Arrays:** Implementing and managing game boards.
* **Randomization:** Generating random numbers and characters for unique game setups.
* **Function Design:** Breaking down complex logic into modular functions (e.g., `check_name`, `update_score`, `display_Board`).
* **Basic Game Logic:** Implementing turn-based gameplay, match checking, and win conditions.
* **Command Line Interface (CLI) design:** Crafting user-friendly interactions in a console environment.

Feel free to explore the code, play the game, and provide any feedback or suggestions!

---
