//Create a class Book with a title and author as attributes.
// Implement a default constructor that initializes these 
// attributes to default values(e.g., "Unknown" for title and 
// "Unknown" for author).Write a method to display the book's 
// details.

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book() : title("Unknown"), author("Unknown") {}
    Book(string a, string b) : title(a), author(b) {}
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
    ~Book() {
        cout << "Destructor called for: " << title<<" " << author << endl;
    }
};

int main() {
    Book a;
    a.displayInfo();
    string t, au;
    cout << "Enter title: ";
    getline(cin, t);
    cout << "Enter author: ";
    getline(cin, au);
    Book b(t, au);
    b.displayInfo();

    system("pause");
    return 0;
}
