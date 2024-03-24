#include <iostream>
#include <string>

using namespace std;

class  Car{
private:
	
    string model;
    string color;
    double speed;
	int running;
	
public:
	
    Car(string& a, string& b, int& c){
    	
    	model=a;
		color=b; 
		speed=c; 
		running=0; 
		
        cout << "A new car has been created." << endl;
    }
 
	
	void isRunning(){
	
		if(running == 1)
			cout << "Car is currently running" << endl;
		else if(running == 0)
			cout << "Car is currently not running" << endl;
	
	}
	
	void print(){
	
		cout << model;
	}
	
	string modelName(){
		
		return model;
	}
	string colorName(){
		
		return color;
	}
	
	double speedVal(){
		
		return speed;
	}
	
    void start();
    
    void stop();
	
	void accelerate(double& amount);
	
	void decelerate(double& amount);
	
	void details();
	
	~Car(){
		cout << "The car has been destroyed." << endl;
	}
};

int main(){
	
    string model, color;
    
    int speed;
    
    int choice;
    
    double amount;
    
    int end = 1;
    
    cout << "Enter car model: ";
    getline(cin, model);
    cout << "Enter car color: ";
    getline(cin, color);
    cout << "Initial speed (km/h): ";
    cin >> speed;

    Car myCar(model, color, speed);

	while(end == 1){
		
		cout << "\n\nCar actions:" << endl;
		cout << "1. Start" << endl;
		cout << "2. Stop" << endl;
		cout << "3. Accelerate" << endl;
		cout << "4. Decelerate" << endl;
		cout << "5. Display Details" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		
		if(choice == 1){
			
			myCar.start();
		}
		
		else if(choice == 2){
			
			myCar.stop();
			
		}
		
		else if(choice == 3){
			
			cout << "Enter Acceleration amount: ";
			cin >> amount;
			myCar.accelerate(amount);
			
		}
		
		else if(choice == 4){
			
			cout << "Enter Deceleration amount: ";
			cin >> amount;
			myCar.decelerate(amount);
			
		}
		
		else if(choice == 5){
			
			myCar.details();
			
		}
		
		else if(choice == 0){
			
			cout << "Exiting..." << endl;
			
			end = 0;
		}
		
		else{
			cout << "Enter valid number" << endl;
		}
	}

    return 0;
}


void Car::start() {
	
    if (running == 0) {
            
		running = 1;
        cout << "Car has been started." << endl;
    } 
	else {
		
        cout << "Car is already started." << endl;
    }
}

void Car::stop(){
	
	if (running == 1) {
            
		running = 0;
        cout << "Car has been stoped." << endl;
    } 
	else {
		
        cout << "Car is not running, cannot stop" << endl;
    }
}

void Car::accelerate(double& amount){
	
	speed +=amount; 
	cout << "Car has been accelrated. Current speed: " << speedVal() << "km/h";
}

void Car::decelerate(double& amount){
	
	if(speed >= amount){
	
		speed -=amount; 	
		cout << "Car has been decelrated. Current speed: " << speedVal() << "km/h";
	}
	else
		cout << "Cannot decalerate more than current speed";
}

void Car::details(){
	
    isRunning();
    cout << "Model: " << modelName() << endl;
	cout << "Color: " << colorName() << endl;    
    cout << "Speed: " << speedVal() << " km/h" << endl;
	
}

