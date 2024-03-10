#include <iostream>
#include <algorithm>
#include <numeric>
#include <cctype>

using namespace std;

const int LIST_SIZE = 9;

void printList(const int list[]) {
    cout << "Available numbers: ";
    for (int i = 0; i < LIST_SIZE; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}

bool checkWin(const int choices[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                if (choices[i] + choices[j] + choices[k] == 15) {
                    cout << "Player wins! Their choices [";
                    cout << choices[i] << ", ";
                    cout << choices[j] << ", ";
                    cout << choices[k] << "] sum up to 15.\n";
                    return true;
                }
            }
        }
    }
    return false;
}

void checknum_and_list() {
    int listofnums[LIST_SIZE];
    iota(listofnums, listofnums + LIST_SIZE, 1); // Initialize listofnums with numbers 1 to 9
    int player_choices[2][LIST_SIZE];
    int choices_size[2] = {0, 0};

    int current_player = 0;

    while (true) {
        cout << "Player " << current_player + 1 << ", it's your turn.\n";
        printList(listofnums);

        int chosen_number;
        cout << "Choose a number from the list for player " << current_player + 1 << ": ";
        cin >> chosen_number;

        if (cin.fail() || chosen_number < 1 || chosen_number > 9) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        bool found = false;
        for (int i = 0; i < LIST_SIZE; ++i) {
            if (listofnums[i] == chosen_number) {
                listofnums[i] = 0; // mark as chosen
                player_choices[current_player][choices_size[current_player]++] = chosen_number;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "The chosen number is not in the list. Please choose again.\n";
            continue;
        }

        if (checkWin(player_choices[current_player], choices_size[current_player])) {
            return;
        }

        current_player = (current_player + 1) % 2;

        if (choices_size[0] + choices_size[1] == LIST_SIZE) {
            cout << "No player wins. Game over.\n";
            return;
        }
    }
}

int main() {
    cout << "WELCOME YOU IN NUMBER SCRABBLE GAME\n";
    cout << "Number Scrabble game is played with a list of numbers between 1 and 9.\n";
    cout << "Each player takes turns picking a number from the list.\n";
    cout << "If a player has picked numbers that add up to 15, that player wins the game.\n\n";

    while (true) {
        checknum_and_list();
        string play_again;
        cout << "Do you want to play again? (yes/no): ";
        cin >> play_again;
        transform(play_again.begin(), play_again.end(), play_again.begin(), ::tolower);

        if (play_again != "yes") {
            cout << "Thank you for playing!\n";
            break;
        }
    }

    return 0;
}
