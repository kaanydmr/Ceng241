#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

// Function declarations
int square(int num);
int sum(int num);
int half(int num);


//Random for functions to apply in array
void randomFunc(int* array, vector<int(*)(int)> &functions){
	
	int i;
	
    for (i = 0; i < 3; i++) {
    	
        int func = rand() % 3;
        array[i] = functions[func](array[i]);
    }
}

int main(){

    srand(time(0));

    int* arr = new int[100];

	int a, i;
	
    //Add random numbers between 1 and 100 array
    for (i = 0; i < 100; i++){
    	
        arr[i] = rand() % 100 + 1;
    }

    //Vector of pointers to the three functions
    vector<int(*)(int)> functions = {&square, &sum, &half};
    
	//Random for functions to apply in array
    randomFunc(arr, functions);

    //Partially sort the array
    partial_sort(arr, arr + 5, arr + 100);

    //Print first 50 elements of the array
    cout << "First 50 elements of array: " << endl;
    for (a = 0; a < 50; a++){
    	
        cout <<arr[a] << " ";
    }

    // Clean memory
    delete[] arr;

    return 0;
}


int square(int num){
    return num * num;
}

int sum(int num){
    return num + num;
}

int half(int num){
    return num / 2;
}
