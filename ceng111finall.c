#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Randoms(int lower, int upper){                              /*Fuction for rondom number genarator*/
    
    int gen = (rand() % (upper - lower + 1)) + lower;
    
    return(gen);
}

int throwdice() {

	int dice = rand() % 6 + 1;	
	
  	return(dice);
}

void dicecheck() {
    int sum1 = 2, sum2 = 3, d1, d2, d3, d4, s, player = 2, counter = 0, k = 1;

    srand(time(0));

    while (sum1 != sum2 * 2 && sum2 != sum1 * 2) {
        if (k == 1) {
            sum1 = 0;
            sum2 = 0;
            k++;
        }

        // Player 1's turn
        d1 = throwdice();
        d2 = throwdice();
        counter += 2;

        printf("player 1 throws %d %d \n", d1, d2);
        if ((d1 - d2 == 4) || (d2 - d1 == 4)) {
            for (; d1 + d2 <= 8;) {
                d1 = throwdice();
                d2 = throwdice();
                counter += 2;

                if (d1 + d2 > 8) {
                    sum1 = sum1 + d1 + d2;
                }
                printf("player 1 throws rule 4 %d %d\n", d1, d2);
            }
        } 
        else if ((d1 == 3 && d2 == 3) || (d1 == 6 && d2 == 6)) {
            for (s = 0; s < 3; s++) {
                d1 = throwdice();
                d2 = throwdice();
                counter += 2;

                printf("player 1 throws 3-3 or 6-6 rule: %d %d\n", d1, d2);
                if (d1 != d2) {
                    sum1 = sum1 + d1 + d2;
                } else {
                    continue;
                }
            }
        } 
        else {
            sum1 = sum1 + (d1 + d2) / 2;
        }

        // Player 2's turn
        d3 = throwdice();
        d4 = throwdice();
        counter += 2;

        printf("player 2 throws %d %d \n", d2, d3);
        if ((d3 - d4 == 4) || (d4 - d3 == 4)) {
            for (; d3 + d4 <= 8;) {
                d3 = throwdice();
                d4 = throwdice();
                counter += 2;

                if (d3 + d4 > 8) {
                    sum2 = sum2 + d3 + d4;
                }
                printf("player 2 throws rule 4 %d %d\n", d3, d4);
            }
        } 
        else if ((d3 == 3 && d4 == 3) || (d3 == 6 && d4 == 6)) {
            for (s = 0; s < 3; s++) {
                d3 = throwdice();
                d4 = throwdice();
                counter += 2;

                printf("player 2 throws 3-3 or 6-6 rule: %d %d\n", d3, d4);
                if (d3 != d4) {
                    sum2 = sum2 + d3 + d4;
                } 
                else {
                    continue;

	                                //printf("%d %d 3-3 6-6 kuralı\n",d1,d2);
	            }
	         }
	                            
	    }
	                    
	    else{
	        sum2=sum2+(d3+d4)/2;
	                        //printf("%d %d bitis \n",d3,d4);
	                            
	    }
        //printf("%d %d \n",sum1, sum2);
	}
		
		printf("Total of %d throws are performed.\n \n",counter);
		
		printf("%d %d \n",sum1, sum2);
		
		if(sum1<sum2){
			printf("+*+*+*+*+* Winner is: Player 2 +*+*+*+*+*+*+*\n");
		}
		
		else{
			printf("+*+*+*+*+* Winner is: Player 1 +*+*+*+*+*+*+*\n");
		}       
            
    
}

int main(){                                            //Main Fuction//
       
    while(1){                                       //For infinite loop unless a break//
        
        int a, b, c, d, countg = 0, countq = 0;     /*a For game select; b for rondom numbers; c,d for user inputed numbers; countg for guess counter; countq for asked question counter*/
        char x, y, z;                               /*x for user inputed charcters,      */
    
        printf("*****Welcome to Space Track Platform******\n \n");
        printf("1. Play the Number Guessing Game\n");
        printf("2. Play the Dice Game\n");
        printf("3. Exit\n \n");
        printf("Choose what to do (1,2,3): ");
        scanf("%d",&a);
        
    
            for(;a==1;){                                                               /* Number guessing Game*/
                printf("*****Welcome to Number Guessing Game******\n");

                srand(time(0));                     /*--------------------------------------------*/                   
                                                    /*genarating a random number between 1 and 100*/
                b=Randoms(1,100);                   /*--------------------------------------------*/
                
                
                for(int n = 0; n < 11 ;){         /* For loop with end*/
                   
                    if(countg>=10){                                                         /*if user exceeds 10 guesses outputs
                                                                                             a error and restarts the pragram*/
                        printf("\n You exceed maxumum guesses\n Answer was %d \n",b);
                        a=10;
                        break;
                    }            
                                
                    
                    printf("Make guess or Ask a question (Input M or A): ");
                    scanf(" %c", &x);  
                    
                    
                    
                            
                    switch(x){
                        case'M':                    //For guessing numbers
                            
                               
                            printf("\nMake your best guess for the number between 1-100: ");
                            scanf("%d", &c);
                                
                            if(c>100 || c<1){
                                                                                    //range is 1-100 so prints a warning fo invalid values
                                printf("Input correct number value\n");
                                break;
                                
                            }
                                
                            else if(c==b){
                                                                                                                        //Win condition and exit for prgram
                                printf("Congratulations!! You guessed the number correctly!!!!\n");
                                printf("You have made %d guesses, you asked %d questions.\n \n", countg + 1, countq);
                                printf("**********************************************\n \n");
                                a=0; //stops while loop that starts the number game again
                                n=11; //stops for loop that gets numbers
                                break;
                            }
                            
                            
                            else if (b < c){
                                printf("Your number is bigger\n");
                                countg++;
                                n++;
                                                                                //printf("%d", b); for testing random number
                                break;
                            }  
                            
                            
                            else if(b > c){
                                printf("Your number is smaller\n");
                                countg++;
                                n++;
                                                                               //printf("%d", b); for testing random number
                                break;
                            }
                            
                             
                            
                                
                        case 'A':         //for Asking Questions
                            
                            countq++;
                            printf("Questions to ask:\n");
                            printf("1. Is it even or odd?\n");
                            printf("2. Is it >50?\n");
                            printf("Choose question: ");
                            scanf( "%d", &d);
                            
                            if (d==1){
                                
                                if(b%2==0){
                                    printf("Number is eveen\n");
                                }
                                else{
                                    printf("Number is odd\n");
                                }
                                
                            }
                            else if (d == 2){
                                if (b < 50 ){
                                    printf("Number is not >50\n");
                                }
                                else if ( b > 50){
                                    printf("Number is >50\n");
                                }
                                
                                
                            }
                    }
                }        
            }
        
        for(;a==2;){
				
				dicecheck();	
                
                break;
        }        
            
        if(a==3){                       //Exit for The pragram 
                printf("Bye!");
            	break;
            }        
    }

    
    return 0;
}
