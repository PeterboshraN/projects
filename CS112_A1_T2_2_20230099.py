# File : CS112_A1_T2_2_20230099.py
""" Purpose : Number Scrabble game is played with a list of numbers between 1 and 9.
              Each player takes turns picking a number from the list.
              If a player has picked numbers that add up to 15, that player wins the game
"""
# Author : Peter Boshra Noshy Abdullah
# ID : 20230099
import itertools  # Importing itertools module for combinations

def checknum_and_list():
    listofnums = list(range(1, 10))  # Creating a list containing numbers from 1 to 9
    player_choices = [[], []] 
    
    current_player = 0  
    
    while True:  # Limiting the number of turns to 9
        print(f"Player {current_player + 1}, it's your turn.")  # Displaying the current player's turn

        print("Available numbers:", listofnums)  # Displaying the available numbers to choose from
        chosen_number = input(f"Choose a number from the list for player {current_player + 1}: ")  

       
        if chosen_number.isdigit() and 1 <= int(chosen_number) and int(chosen_number) <= 9:
            chosen_number = int(chosen_number)

            # Checking if the chosen number is in the available list of numbers
            if chosen_number in listofnums:
                listofnums.remove(chosen_number)  # Removing the chosen number from the available list
                player_choices[current_player].append(chosen_number)  # Adding the chosen number to the player's choices

                # Check if any combination of three numbers chosen by the current player sums up to 15
                combinations = itertools.combinations(player_choices[current_player], 3)
                for combo in combinations:
                    if sum(combo) == 15:  
                        print(f"Player {current_player + 1} wins! Their choices {combo} sum up to 15.")
                        return

                     # Switch to the next player
                current_player = (current_player + 1) % 2
            else:
              print("The chosen number is not in the list. Please choose again.")  # Error message for an invalid choice
        else:
           print("Invalid input. Please enter a number between 1 and 9.")  # Error message for invalid input

        # Check if all numbers are selected but no player wins
        if not listofnums:
            print("No player wins. Game over.")  # If all numbers are chosen and no player wins, game over
            return
    if len(listofnums) == 0 :
        False 

      

if __name__ == "__main__":
    # Displaying the game rules and instructions
    print("WELCOME YOU IN NUMBER SCRABBLE GAME")
    print("Number Scrabble game is played with a list of numbers between 1 and 9.")
    print("Each player takes turns picking a number from the list.")
    print("If a player has picked numbers that add up to 15, that player wins the game.\n")

    # Starting the game loop
    while True:
        checknum_and_list()  
        play_again = input("Do you want to play again? (yes/no): ")  # Asking if the player wants to play again
        if play_again.lower() != "yes":
            continue
        elif play_again.lower() == "no" :
            print("Thank you for playing!")  
            break  

