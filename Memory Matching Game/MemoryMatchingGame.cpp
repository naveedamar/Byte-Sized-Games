#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include <cstdio>

#include <random>
#include <cstdlib>
#include <ctime>


//constants
const int MAX_ROWS = 10; 
const int MAX_COLS = 10; 

//file handling
string MYFILE = "user_file.txt";

//adds a new user at end with name 0 (0 becuase just added user)
void add_new_user(string name){				
	ofstream myfile;
	myfile.open(MYFILE, ios::app);
	myfile << name << " " << 0;
	myfile << endl;
	myfile.close();
}

//checking file for specific name
bool check_name(string name){
	string file_name;
	int score;
	
	ifstream myfile(MYFILE);
	
	//special way opens my file ignors whitespacesname score
	while (myfile >> file_name >> score) {
        if (file_name == name) {
            myfile.close(); 
			return true;    
        }
    }
    myfile.close(); 
    return false;
}

//checks for score for a given user
int check_score(string name){
	string file_name;
	int score;
	
	ifstream myfile(MYFILE);
	while (myfile >> file_name >> score) {
        if (file_name == name) {
            myfile.close(); 
			return score;    
        }
    }
    myfile.close(); 
    //user not found
    return -1;
}

/**
creating a temp file, copying data from origial
if specific name found incrementing score and turning flag to true
deleting original 
renaming temp to original name
**/
void update_score(string name) {
    
    ifstream inFile(MYFILE);
    ofstream outFile("temp_user_file.txt");

    string current_file_name;
    int current_file_score;
    bool updated = false; 
    
    while (inFile >> current_file_name >> current_file_score) {
        if (current_file_name == name) {
            int new_score = current_file_score + 1;
            outFile << name << " " << new_score << "\n";
            updated = true;
        } else {
            outFile << current_file_name << " " << current_file_score << "\n";
        }
    }
    inFile.close();
    outFile.close();

    if (updated) {
        remove(MYFILE.c_str());
        rename("temp_user_file.txt", MYFILE.c_str());
    } else {
        remove("temp_user_file.txt");
        cerr << "Warning: User '" << name << "' not found in file for score increment. No update performed.\n";
    }
}
//end of file finctions

//checking if board is even or not
bool is_Even(int a, int b){
	int product = a * b;
	if(	product % 2 == 0 ){
		return true;
	}
	return false;
}

//create board
void create_Board(char board[MAX_ROWS][MAX_COLS],int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			board[i][j] = '*';
		}
	}
}

//displaying borad
void display_Board(char board[MAX_ROWS][MAX_COLS], bool reveal_Board[MAX_ROWS][MAX_COLS], int row, int col){
	cout << "\n\t Current Board\n";
	
	//makes a line for user to easy see the col key values
	cout << "\t   ";
	for (int j = 0; j < col; j++) {
        cout << j << "  ";
    }
    cout << endl;
	for(int i = 0; i < row; i++){
		//makes a line for user to easy see the row key values
		cout << "\t" << i << "  "; 
		for(int j = 0; j < col; j++){
			
			//if true then shoing the values if not then *
			if (reveal_Board[i][j]){
				cout << board[i][j]  << "  ";
			}else {
				cout << "*" << "  ";
			}
		}
		cout << endl;
	}
}

//creating rand valuse includeing alphas and nums
char rand_value(){		
	char return_Char;
	
	//only defined a bec will use addition to create other chars;
	//ASCII a = 97, b = 98 so on till z = 122
	char small_chars = 'a';
	//ASCII A = 65 ----- Z = 90
	char capital_char = 'A';
		
    int choice = rand() % 3;
    
    switch (choice){
    	case 0:
    		//generates rand value bt 0-9
    		choice = rand() % 10;
    		//converting to char
    		return_Char = static_cast<char> (choice + '0');
    		return return_Char;
    	case 1:
			//generates rand value bt 0-25
    		choice = rand() % 26;
    		return_Char = static_cast<char>(small_chars + choice);
    		return return_Char;
    	case 2:
    		choice = rand() % 26;
    		return_Char = static_cast<char>(capital_char + choice);
    		return return_Char;
	}
	return return_Char;
}

//assigning rand chars
void assign_Rand_values(char board[MAX_ROWS][MAX_COLS], int row, int col){
	
	//will use in loops to iterate effectivly
	int total = row * col;
    int pairs = total / 2;

	//tempt array to store rand_values 
    char temp[MAX_ROWS * MAX_COLS];

    int index = 0;
	//iterating and calling rand_value and stroing in tempt	
    for (int i = 0; i < pairs; i++) {
        char rand_char = rand_value();
        temp[index++] = rand_char;
        temp[index++] = rand_char;
    }

	//suffling board
    for (int i = 0; i < total; ++i) {
        int rand_pos = rand() % total;
        char s_val = temp[i];
        temp[i] = temp[rand_pos];
        temp[rand_pos] = s_val;
    }

	//assigning values from tempt to original array
    index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = temp[index++];
        }
    } 
}


int main(){

	/**
	Semester Project
	Name: Memory Matching Game
	**/
		
	//Seeding value that will be const though out program
	srand( time(0) );
	
	//if user wants to play again!
	char choices;
	
	//row and col for initial matrix, willl use for both the initial and also to take choices
	int arry_Row, arry_Col;
	
	//board will remain the same
	char board[MAX_ROWS][MAX_COLS];
	bool show_board[MAX_ROWS][MAX_COLS];
	
	
	do{
		cout << "\t\t Memory Matching Game\n\n";
		/**
			performing file operations
		**/
		
		//to store user name and score
		string name;
		int score;
	
		cout << "Enter your name: ";
		getline(cin,name);
		
		if ( check_name(name) ){
			score =  check_score(name);
			cout << "HELLO " << name << "! WELCOME BACK, YOUR CURRENT SCORE IS " << score;
		}else{
			add_new_user(name);
			cout << "HELLO " << name << "! WELCOME, THIS IS YOUR FIRST TIME PLAYING SO YOU SCORE IS SET TO 0" ;
		}

		cout << "\n\nLet's set up the size of your game board.\n";
	    cout << "You'll enter the number of rows and then the number of columns.\n";
		do{
		    cout << "Keep in mind that the total number of cards on the board (rows multiplied by columns)\n";
		    cout << "must be an even number. This is necessary because each card needs to have a matching pair.\n";
		    cout << "For example, a 4x4 board (16 cells) is valid, but a 3x3 board (9 cells) is not.\n\n";

			cout << "Enter Dimensions (Max: " << MAX_ROWS << " rows x " << MAX_COLS << " columns)\n";

			cout << "Row: ";
			cin >> arry_Row;

			cout << "Col: ";
			cin >> arry_Col;

		}while( is_Even(arry_Row, arry_Col) == false );


		int matches = 0;
		int total_matches = ( arry_Row* arry_Col) / 2;
		int turns = 0;

		create_Board(board,arry_Row, arry_Col);
		assign_Rand_values(board,arry_Row, arry_Col);
		
		for(int i = 0; i < arry_Row; ++i) {
            for(int j = 0; j < arry_Col; ++j) {
                show_board[i][j] = false;
            }
        }

		cout << "\nGame starting!\n";
		while (matches < total_matches) {
			turns++;
			cout << "\n--- Turn " << turns << " ---\n";
			display_Board(board,show_board,arry_Row, arry_Col); 

			int r1, c1, r2, c2;

			cout << "1st card (row col): ";
			cin >> r1 >> c1;
			show_board[r1][c1] = true;
			display_Board(board, show_board, arry_Row, arry_Col);

			cout << "2nd card (row col): ";
			cin >> r2 >> c2; 
			show_board[r2][c2] = true;
			display_Board(board, show_board, arry_Row, arry_Col);


			if (board[r1][c1] == board[r2][c2]) {
				cout << "\nMatch found :) \n";
				matches++;
			} else {
				cout << "\nNo match found :(\n";
				show_board[r1][c1] = false;
				show_board[r2][c2] = false;
				
			}
		}

		cout << "\n\nYOU WON IN " << turns << " TURNS!\n";
		update_score(name);

		cout << "DO YOU WISH TO PLAY AGAIN? (Y for Yes | N for No) : ";
		cin >> choices;
	}while( choices == 'Y' || choices == 'y' );
}
