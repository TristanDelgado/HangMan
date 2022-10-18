#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

bool any_wrong = false,
     head = false,
     body = false,
     l_arm = false,
     r_arm = false,
     l_leg = false,
     r_leg = false,
     letter1_show = false,
     letter2_show = false,
     letter3_show = false,
     letter4_show = false,
     letter5_show = false,
     letter6_show = false,
     letter7_show = false,
     letter8_show = false,
     continue_game = true,
     lost_game = false,
     won_game = false;

 char letter1,
     letter2,
     letter3,
     letter4,
     letter5,
     letter6,
     letter7,
     letter8,
     pre_guess = '?';

     //the letters will be set to false because they have not been guessed yet
    bool A = false, B = false, C = false, D = false, E = false, F = false,
         G = false, H = false, I = false, J = false, K = false, L = false,
         M = false, N = false, O = false, P = false, Q = false, R = false,
         S = false, T = false, U = false, V = false, W = false, X = false,
         Y = false, Z = false,
         guessed_a_letter = false;

    int num_wrong_guesses = 0;
    char guess;

void introduction() //instructions
{
    cout << "This is a hangman game!\n";
    cout << "Hit enter to continue\n";
    cin.get();
    cout << "Please enter all letters capitalized!!\n";
    cout << "Hit enter to continue\n";
    cin.get();
    cout << "How the word bank works:\n";
    cout << "If the letter is capitalized then you have not guessed it yet\n";
    cout << "If the letter is lowercase then you have already guessed that letter\n";
    cout << "Hit enter to continue\n";
    cin.get();
}
void print() //prints the hangman
{
    int row = 2, column = 1; //The basis of how the program prints is by row and column numbers
    //Row is set to 2 because the first row is taken care of with the first while statement

    while (column < 41)
    {
        cout << "#";
        column += 1;
    }
    cout << endl;
    //First row done
    column = 1;
    while (row >= 2 && row < 15)
    {
        while (column < 41)
        {
            if (column == 1 || column == 40)
            {
                cout << "#";
                column +=1;
            }
            else
            {
                if (head == true && row == 6 && column == 21 )
                {
                    cout << "( )";
                    column += 2;
                }
                else if (body == true && (row == 7 || row == 8) && column == 22)
                    cout << "|";
                else if (r_arm == true && row == 7 && column == 21)
                    cout << "/";
                else if (l_arm == true && row == 7 && column == 23)
                    cout << "\\";
                else if (l_leg == true && row == 9 && column == 21)
                    cout << "/";
                else if (r_leg == true && row == 9 && column == 23)
                    cout << "\\";
                else if (column == 4 && row > 3 && row < 12)
                    cout << "|";
                else if (column == 22 && row > 3 && row < 6)
                    cout << "|";
                else if (column > 4 && column < 22 && row == 3)
                    cout << "-";
                else if (column > 4 && column < 30 && row == 12)
                    cout << "-";
                else
                    cout << " ";

                column += 1;
            }

        }
        cout << endl;
        column = 1;
        row += 1;
    }
    column = 1;
    while (column < 41)
    {
        cout << "#";
        column += 1;
    }
    cout << endl;
}
void word_picker()//finished and works
{
    //Because of the knowledge I currently have I am going to only have 5 words that will randomly be picked for the word
    int rand_num;
    srand(time(0));
    rand_num = rand() % 5 + 1; //You add one unit to the total because you can get 0 and need to make it one or you can get four and need to get to five. This is for a random number between 1 and 5

    switch(3) // manually put in a number in order to test all words: Flaship doesnt work. The I and P dont register
    {
    case 1:
        letter1 = 'A';
        letter2 = 'C';
        letter3 = 'A';
        letter4 = 'D';
        letter5 = 'E';
        letter6 = 'M';
        letter7 = 'I';
        letter8 = 'C';
        break;
    case 2:
        letter1 = 'D';
        letter2 = 'A';
        letter3 = 'Y';
        letter4 = 'L';
        letter5 = 'I';
        letter6 = 'G';
        letter7 = 'H';
        letter8 = 'T';
        break;
    case 3:
        letter1 = 'F';
        letter2 = 'L';
        letter3 = 'A';
        letter4 = 'G';
        letter5 = 'S';
        letter6 = 'H';
        letter7 = 'I';
        letter8 = 'P';
        break;
    case 4:
        letter1 = 'L';
        letter2 = 'E';
        letter3 = 'A';
        letter4 = 'R';
        letter5 = 'N';
        letter6 = 'I';
        letter7 = 'N';
        letter8 = 'G';
        break;
    case 5:
        letter1 = 'S';
        letter2 = 'E';
        letter3 = 'A';
        letter4 = 'S';
        letter5 = 'O';
        letter6 = 'N';
        letter7 = 'A';
        letter8 = 'L';
        break;
    default:
        cout << "Error in wordpicker\n";

    }

}

void game_engine() //still needs a lot of work
{


        if('A' == guess)
            {
                A = true;
                cout << "(a) ";
            }
        else if(A == false)
            cout << "A ";
        else
            cout << "(a) ";

        if('B' == guess)
            {
                B = true;
                cout << "(b) ";
            }
        else if(B == false)
            cout << "B ";
        else
            cout << "(b) ";

        if('C' == guess)
        {
            C = true;
            cout << "(c) ";
        }
        else if(C == false)
            cout << "C ";
        else
            cout << "(c) ";

        if('D' == guess)
            {
                D = true;
                cout << "(d) ";
            }
        else if(D == false)
            cout << "D ";
        else
            cout << "(d) ";

        if('E' == guess)
            {
                E = true;
                cout << "(e) ";
            }
        else if(E == false)
            cout << "E ";
        else
            cout << "(e) ";
        if('F' == guess)
            {
                F = true;
                cout << "(f) ";
            }
        else if(F == false)
            cout << "F ";
        else
            cout << "(f) ";

        if('G' == guess)
            {
                G = true;
                cout << "(g) ";
            }
        else if(G == false)
            cout << "G ";
        else
            cout << "(g) ";

        if('H' == guess)
            {
                H = true;
                cout << "(h) ";
            }
        else if(H == false)
            cout << "H ";
        else
            cout << "(h) ";

        if('I' == guess)
            {
                I = true;
                cout << "(i) ";
            }
        else if(I == false)
            cout << "I ";
        else
            cout << "(i) ";

        if('J' == guess)
            {
                J = true;
                cout << "(j) ";
            }
        else if(J == false)
            cout << "J ";
        else
            cout << "(j) ";

        if('K' == guess)
            {
                K = true;
                cout << "(k) ";
            }
        else if(K == false)
            cout << "K ";
        else
            cout << "(k) ";

        if('L' == guess)
            {
                L = true;
                cout << "(l) ";
            }
        else if(L == false)
            cout << "L ";
        else
            cout << "(l) ";

        if('M' == guess)
            {
                M = true;
                cout << "(m) ";
            }
        else if(M == false)
            cout << "M ";
        else
            cout << "(m) ";

        if('N' == guess)
            {
                N = true;
                cout << "(n) ";
            }
        else if(N == false)
            cout << "N ";
        else
            cout << "(n) ";

        if('O' == guess)
            {
                O = true;
                cout << "(o) ";
            }
        else if(O == false)
            cout << "O ";
        else
            cout << "(o) ";

        if('P' == guess)
            {
                P = true;
                cout << "(p) ";
            }
        else if(P == false)
            cout << "P ";
        else
            cout << "(p) ";

        if('Q' == guess)
            {
                Q = true;
                cout << "(q) ";
            }
        else if(Q == false)
            cout << "Q ";
        else
            cout << "(q) ";

        if('R' == guess)
            {
                R = true;
                cout << "(r) ";
            }
        else if(R == false)
            cout << "R ";
        else
            cout << "(r) ";

        if('S' == guess)
            {
                S = true;
                cout << "(s) ";
            }
        else if(S == false)
            cout << "S ";
        else
            cout << "(s) ";

        if('T' == guess)
            {
                T = true;
                cout << "(t) ";
            }
        else if(T == false)
            cout << "T ";
        else
            cout << "(t) ";

        if('U' == guess)
            {
                U = true;
                cout << "(u) ";
            }
        else if(U == false)
            cout << "U ";
        else
            cout << "(u) ";

        if('V' == guess)
            {
                V = true;
                cout << "(v) ";
            }
        else if(V == false)
            cout << "V ";
        else
            cout << "(v) ";

        if('W' == guess)
            {
                W = true;
                cout << "(w) ";
            }
        else if(W == false)
            cout << "W ";
        else
            cout << "(w) ";

        if('X' == guess)
            {
                X = true;
                cout << "(x) ";
            }
        else if(X == false)
            cout << "X ";
        else
            cout << "(x) ";

        if('Y' == guess)
            {
                Y = true;
                cout << "(y) ";
            }
        else if(Y == false)
            cout << "Y ";
        else
            cout << "(y) ";

        if('Z' == guess)
            {
                Z = true;
                cout << "(z) ";
            }
        if(Z == false)
            cout << "Z ";
        else
            cout << "(z) ";
        cout << endl;
        //Make a way to show what letter in the word have already been guessed
        if(letter1_show == true)
            cout << letter1;
        else
            cout << "_";
        if (letter2_show == true)
            cout << letter2;
        else
            cout << "_";
        if (letter3_show == true)
            cout << letter3;
        else
            cout << "_";
        if (letter4_show == true)
            cout << letter4;
        else
            cout << "_";
        if (letter5_show == true)
            cout << letter5;
        else
            cout << "_";
        if (letter6_show == true)
            cout << letter6;
        else
            cout << "_";
        if (letter7_show == true)
            cout << letter7;
        else
            cout << "_";
        if (letter8_show == true)
            cout << letter8;
        else
            cout << "_";

        cout << endl; // This makes the instructions appear on the line below the word you are guessing

        cout << "Pre guess: " << pre_guess << endl;
        //Now ask the user to enter their next guess
        cout << "Please enter a capital letter for your guess\n" << "Guess: ";
        cin >> guess;
        pre_guess = guess;
        //This part of the algorithm determines if the guess is one of the letters
        //if yes then the letter will now be shown and it will remember that a letter has been guessed
        if(letter1 == guess)
           {
                letter1_show = true;
                guessed_a_letter = true;
           }
        if (letter2 == guess)
            {
                letter2_show = true;
                guessed_a_letter = true;
            }
        if (letter3 == guess)
            {
                letter3_show = true;
                guessed_a_letter = true;
            }
        if (letter4 == guess)
            {
                letter4_show = true;
                guessed_a_letter = true;
            }
        if (letter5 == guess)
            {
                letter5_show = true;
                guessed_a_letter = true;
            }
        if (letter6 == guess)
            {
                letter6_show = true;
                guessed_a_letter = true;
            }
        if (letter7 == guess)
            {
                letter7_show = true;
                guessed_a_letter = true;
            }
        if (letter8 == guess)
            {
                letter8_show = true;
                guessed_a_letter = true;
            }

            //Determines if the game has been won yet
        if(letter1_show == true && letter2_show == true && letter3_show == true && letter4_show == true &&
           letter5_show == true && letter6_show == true && letter7_show == true && letter8_show == true)
        {
            continue_game = false;
            won_game = true;
        }
        //This part will do something if a letter is not guessed
        if (guessed_a_letter == false)
        {
            num_wrong_guesses++;
            switch(num_wrong_guesses)
            {
                case 1:
                    head = true;
                    break;
                case 2:
                    body = true;
                    break;
                case 3:
                    l_arm = true;
                    break;
                case 4:
                    r_arm = true;
                    break;
                case 5:
                    l_leg = true;
                    break;
                case 6:
                    r_leg = true;
                    continue_game = false;
                    lost_game = true;
                    break;
            }
        }


        guessed_a_letter = false;

}

void initialize_var()
{
    any_wrong = false,
     head = false,
     body = false,
     l_arm = false,
     r_arm = false,
     l_leg = false,
     r_leg = false,
     letter1_show = false,
     letter2_show = false,
     letter3_show = false,
     letter4_show = false,
     letter5_show = false,
     letter6_show = false,
     letter7_show = false,
     letter8_show = false,
     continue_game = true,
     lost_game = false,
     won_game = false;
     A = false, B = false, C = false, D = false, E = false, F = false,
     G = false, H = false, I = false, J = false, K = false, L = false,
     M = false, N = false, O = false, P = false, Q = false, R = false,
     S = false, T = false, U = false, V = false, W = false, X = false,
     Y = false, Z = false,
     guessed_a_letter = false;

     int num_wrong_guesses = 0;

    char guess;
    pre_guess = '?';
}


int main()
{
    char Y_N;
    bool play_game;

    cout << "Would you like to play a Hangman game?\n(Y/N):";
    cin >> Y_N;

    if(Y_N == 'Y' || Y_N == 'y')
        play_game = true;
    while(play_game == true)
    {
        initialize_var();
        word_picker();
       introduction();
        while(continue_game == true)
        {
            print();
            game_engine();
            system("cls");
        }
        if(won_game == true)
        {
            print();
            cout << "You have won the game! The word was \"";
            cout << letter1 << letter2 << letter3 << letter4 << letter5 << letter6 << letter7 << letter8;
            cout << "\"";
        }
        if(lost_game == true)
        {
            print();
            cout << "You have lost the game. The word was \"";
            cout << letter1 << letter2 << letter3 << letter4 << letter5 << letter6 << letter7 << letter8;
            cout << "\"";
        }

        play_game = false;

        cout << "\n\nPlay again?\n(Y/N):";
        cin >> Y_N;

        if(Y_N == 'Y' || Y_N == 'y')
            play_game = true;


        system("cls");

    }

   cout << endl << endl << endl << endl;
   cout << "END";

    return 0;
}
