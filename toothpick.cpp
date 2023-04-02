#include <iostream>    
#include <iomanip>     
using namespace std;

int main()
{
        
        cout << "Program #1: Toothpicks" << endl << "Class: CS 141" << endl
			 << "Author: Gina Gerace" << endl << "Lab: Tues. 11am" << endl
             << "System: C++ Windows DevC++" << endl
             << endl;
        
        cout << "Welcome to the Toothpick Puzzle, where the goal is to get an equal" << endl
			 << "number of toothpicks in each stack, in three moves." << endl
        	 << endl << setw(22) <<  "Stack: " << setw(8) << "A  B  C" << endl
        	 << "Number of Toothpicks: " << setw(8) << "11  7  6" << endl
        	 << endl << "A move consists of moving toothpicks from one stack to a second stack,"
			 << endl << "where the number of toothpicks moved is exactly the number that is in the"
			 << endl << "destination stack.  In other words, to move from stack B (7 toothpicks)"
			 << endl << "to stack C (6) as shown above, we would move 6 from B to C, leaving us"
			 << endl << "with 1 in B and 12 in stack C." << endl
			 << endl << "Here we go..." << endl;
			 		
        char moveFrom = ' ';
        char moveTo = ' ';
        
        int stackA = 11;
        int stackB = 7;
        int stackC = 6;
        
	    cout << endl << setw(24) << "Stack:  " << setw(4) << "A" << setw(4) << "B" << setw(4) << "C" << endl;
	    cout << " Number of Toothpicks:	" << setw(4) << stackA << setw(4) << stackB << setw(4) << stackC << endl;
        
        int loopCounter = 1;
        
        while( loopCounter <= 3) {
	      
	        cout << endl << loopCounter << ". Enter FROM and TO stack letters: ";
	        cin >> moveFrom >> moveTo;
	        
			moveFrom = toupper (moveFrom); 
	        moveTo = toupper (moveTo);
        
	        if( moveFrom == 'A' && moveTo == 'B' ) {
				if( stackA >= stackB) {
					stackA = stackA - stackB;
					stackB = stackB * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in A. Retry..." << endl;
					continue;
	            }
	    	}
	        if( moveFrom == 'A' && moveTo == 'C' ) {
				if( stackA >= stackC) {
					stackA = stackA - stackC;
					stackC = stackC * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in A. Retry..." << endl;
					continue;
	            }
	    	}
	        if( moveFrom == 'B' && moveTo == 'C' ) {
				if( stackB >= stackC) {
					stackB = stackB - stackC;
					stackC = stackC * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in B. Retry..." << endl;
					continue;
	            }
	    	}
	        if( moveFrom == 'B' && moveTo == 'A' ) {
				if( stackB >= stackA) {
					stackB = stackB - stackA;
					stackA = stackA * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in B. Retry..." << endl;
					continue;
	            }
	    	}
	        if( moveFrom == 'C' && moveTo == 'A' ) {
				if( stackC >= stackA) {
					stackC = stackC - stackA;
					stackA = stackA * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in C. Retry..." << endl;
					continue;
	            }
	    	}
	        if( moveFrom == 'C' && moveTo == 'B' ) {
				if( stackC >= stackB) {
					stackC = stackC - stackB;
					stackB = stackB * 2;
					loopCounter = loopCounter + 1;
	            }
				else {
					cout << "Sorry, not enough toothpicks in C. Retry..." << endl;
					continue;
	            }
	    	}
	        cout << endl << setw(24) << "Stack:  " << setw(4) << "A" << setw(4) << "B" << setw(4) << "C" << endl;
	   		cout << " Number of Toothpicks:	" << setw(4) << stackA << setw(4) << stackB << setw(4) << stackC << endl;
		}
		
		if( stackA == stackB && stackB == stackC) {
			cout << endl << "Congratulations! You did it! Great job!" << endl;
		}
		else {
			cout << endl << "Nope, sorry, that's not it. Try again." << endl;
		}
	
	return 0;
}
