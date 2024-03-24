#include <iostream>

using namespace std;

int main(){
	
    string name;
    
    double wage, hours, regularPay = 0, overtimePay = 0, totalPay = 0, bonusPay = 0;
	
	//Name input
    cout << "Enter worker name: ";
    getline (cin, name),
    
	//Wage input
    cout << "Enter hourly wage: $";
    cin >> wage;
    
    //Work hour input
    cout << "Enter the number of hours worked in the past week: ";
    cin >> hours;
    
    cout << endl << "--Output--" << endl;
    
    
    //calculates money to pay to worker
    //if 0 hour
    if(hours == 0){
    	
    	cout << "Wrokers is on leave" << endl;
		return 0;    	
    	
	}//less than 45 hours
    else if (hours <= 45){
    	
        regularPay = hours * wage;
        hours-=hours;
        
    } //between 45 and 55 hours
	else if (hours > 45 && hours <= 55){
		
        regularPay = 45 * wage;
        overtimePay = (hours - 45) * wage * 1.2;
        hours = hours - 45; 
        
    } //more tahn 55 hour
	else if(hours > 55){
		
        regularPay = 45 * wage;
        overtimePay = (hours - 45) * wage * 1.2;
        bonusPay = (hours - 55) * wage;
        hours = hours - 45;
        
    }
    
    //sum of all money to pay
    totalPay = regularPay + overtimePay + bonusPay;
    
    //Output table
    cout << "Regular Pay: $" << regularPay << endl;    
	cout << "Overtime Hours: " << hours << " hours"<< endl;	
    cout << "Overtime Pay: $" << overtimePay << endl;    
    cout << "Bonus Pay: $" << bonusPay << endl;    
	cout << "Total Pay: $" << totalPay;
	
    return 0;
}

