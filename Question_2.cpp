#include <iomanip> 
#include <iostream>

using namespace std;

//Struct for machines
typedef struct Machine{
	
    string name;
    int lifetime;
    int usage;
    
}Machine;

int main(){
    //array for 3 Machine structs 
    Machine mach[3];
	
	int x = 0, a = 0, i = 0;
	
	//STring for requrirement
	string req;
	
    // Input machine information for 3 machine
    while(i < 3){
    	
        cout << "Enter information for Machine " << i + 1  << endl;
        
		//Name
        cout << "Name: ";
        cin >> mach[i].name;
        
		//lifetime
        cout << "Life time (in years): ";
        cin >> mach[i].lifetime;
        
		//Usage
        cout << "Total usage (in years): ";
        cin >> mach[i].usage;
        i+=1;
    }
    
	cout << endl;
    
    //Top of the table
    cout << left << setw(15) << "Machine";
	cout << left << setw(15) << "Life time";
	cout << left << setw(20) << "Total Usage" << "New Machine Requirement" << endl;
	
	
	// for printing ------------...
	while(a <= 65){
		
		cout << "-";
		a+=1;
	}
	cout << endl;
	
    // Check and display machine information for 3 machine
    while(x < 3){
        
        if((mach[x].lifetime - mach[x].usage) <= 5){
        	
        	req = "Required";
		} 
		else{
			
			req = "Not Required";
		} 
        
        // Display machine information 
        cout << left << setw(15) << mach[x].name;
        cout << left << setw(15) << mach[x].lifetime;
        cout << left << setw(20) << mach[x].usage << req << endl;
        
        x+=1;
    }

    return 0;
}

