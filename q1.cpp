#include <iostream>
#include <vector>

using namespace std;

//10 different print functions
void print1(){ cout << "function 1\n"; }

void print2(){ cout << "function 2\n"; }

void print3(){ cout << "function 3\n"; }

void print4(){ cout << "function 4\n"; }

void print5(){ cout << "function 5\n"; }

void print6(){ cout << "function 6\n"; }

void print7(){ cout << "function 7\n"; }

void print8(){ cout << "function 8\n"; }

void print9(){ cout << "function 9\n"; }

void print10(){ cout << "function 10\n"; }

int main(){
	
    // Create a vector of void function pointers
    vector<void (*)()> printFunctions;

    //add poiners o functions
    printFunctions.push_back(&print1);
    printFunctions.push_back(&print2);
    printFunctions.push_back(&print3);
    printFunctions.push_back(&print4);
    printFunctions.push_back(&print5);
    printFunctions.push_back(&print6);
    printFunctions.push_back(&print7);
    printFunctions.push_back(&print8);
    printFunctions.push_back(&print9);
    printFunctions.push_back(&print10);

    //Run all the functions inside the vector
    for(int i = 0; i<10 ;i++){
        
		printFunctions[i]();
    }

    return 0;
}
