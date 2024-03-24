#include <iostream>
#include <vector>


using namespace std;

class Book {
private:
	
    string title;
    string author;
    int year;
    
public:
	
	
    Book(string& title, string& author, int& year): title(title), author(author), year(year){
	
		cout << "New book '" << title << "' has been created" << endl << endl;
		
	}    
	
    ~Book(){ 	
    
    	cout << "The book '" << title << "' has been removed\n";
	}
	
	
	void display(int i){
        cout << i+1 << ".Title: " << title << ", Author: " << author << ", Year: " << year << endl << endl;
    }
		    
};

void displayBooks(vector<Book*>& Library){
	
    if (Library.size() == 0){
    	
        cout << "No books in the library.\n";
    }
	else{
    	
        cout << "Books in the Library:\n";
        
        for (int i = 0; i < Library.size(); i++){
        	
            Library[i]->display(i);
        }
    }
}
int main() {
	
	vector<Book*> Library;
	
	int choice(0);
	
	while(choice != 3){
		
		cout << "Choose an operation:" << endl;
		cout << "1.Add a book" << endl;
		cout << "2.Display all books" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
		
		if(choice == 1){
		    string title, author;
		    int year;
		
		    cout << "Enter book title: ";
		    cin.ignore();
		    getline(cin, title);
		
		    cout << "Enter book author: ";
		    cin.ignore();
		    getline(cin, author);
		
		    cout << "Enter publication year: ";
		    cin >> year;
		
		    Book* newBook = new Book(title, author, year);
		    Library.push_back(newBook);
		}

		else if(choice == 2){
			
			displayBooks(Library);
			
		}
		else if(choice == 3){
			
			cout << "Exiting..." << endl;
		}
		else
			cout << "Input valid number";
	}


	for (int i = 0; i < Library.size(); i++) {
    	 delete Library[i];
 	}


    return 0;
}
 
	

