#include <stdio.h>


void findAndMarkX(char matrix[5][5], int row, int col){	 //This function that finds all connected X's and replaces X's with blank space so it won't try to find the same X's again
   
    if(row<0 || col<0 || row>=5 || col>=5){	 // Checks if celss are out of limits
    	
        return; 
    }
    
	if(matrix[row][col] != 'X'){	//  Checks if the character is 'X', if not it stops function
    	
        return; 
    }
    
    matrix[row][col] = ' ';		 // Marking 'X' as blank so it becouse we dont want to search again
    
	//all X's that are connected we seach nad mark again so we wont have to count again
    findAndMarkX(matrix, row+1, col);  //All Xs that on rigth	
    findAndMarkX(matrix, row, col+1);  //All Xs that on up	
	findAndMarkX(matrix, row-1, col);  //All Xs that on left
    findAndMarkX(matrix, row, col-1);  //All Xs that on down
}


int restX(char matrix[5][5]){  //Rerstricted area count
	
    int count=0, checkrow, checkcolm;

     for(checkrow=0 ; checkrow<5 ; checkrow+=1){	//Checks all matrix and searches for X
    	
        for(checkcolm=0 ; checkcolm<5 ; checkcolm+=1){
        	
            if(matrix[checkrow][checkcolm] == 'X'){	//When we find X, marks all X's that are connected to original X's as blank so we wont count them again
            	
                count+=1;
                findAndMarkX(matrix, checkrow, checkcolm);	
            }
        }
    }

    return count; 
}

int main(){
	
    char matrix[5][5]; 

    printf("Enter 5x5 matrix 'O' for free cells, 'X' for restricted cells:\n");
	
	int row, colm;
	
	//Input for matrix
    for(row=0 ; row<5 ; row+=1){		//For inputing 2d Array
    	
        for(colm=0 ; colm<5 ; colm+=1){ 
        	
            scanf(" %c", &matrix[row][colm]);
        }
    }

    printf("Number of restricted areas is: %d\n", restX(matrix));

    return 0;
}
