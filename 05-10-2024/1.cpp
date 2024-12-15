/*
1. Library and Books System (Aggregation and Composition)
Scenario:
A library system is designed to manage books and members. Each Library has a list of Books. Each Book has a title, an author, and an ISBN. Members of the library can borrow books, but the library owns the books, so when a library closes, the books are lost too.

Question:

Model the relationship between Library and Book using composition (since the library "owns" the books).
Model the relationship between Library and Member using aggregation (since members can exist independently of the library).
Write C++ classes for Library, Book, and Member. Ensure that deleting a Library will delete all associated Book objects but will not delete Member objects
*/

#include <iostream>
#include <string>
using namespace std;

class book {
protected:
    string title;
    string author;
    string isbn;

public:
    book(const string& t, const string& a, const string& in) : title(t), author(a), isbn(in) {
        cout << "Book created: " << title << endl;
    }

    ~book() {
        cout << "Book deleted: " << title << endl;
    }
};

class member {
private:
    string name;

public:
    member(const string& n) : name(n) {
        cout << "Member created: " << name << endl;
    }

    ~member() {
        cout << "Member deleted: " << name << endl;
    }
};

class library {
private:
    book* books[2];
    member* members[2];
    int bookcount;
    int membercount;

public:
    library() : bookcount(0), membercount(0) {}

    void addbook(const string& ti, const string& au, const string& inn) {
        if (bookcount < 2) {
            books[bookcount++] = new book(ti, au, inn);
        }
        else {
            cout << "Cannot add more books. Library is full.\n";
        }
    }

    void addmember(member* m) {
        if (membercount < 2) {
            members[membercount++] = m;
        }
        else {
            cout << "Cannot add more members. Member list is full.\n";
        }
    }

    ~library() {
        for (int i = 0; i < bookcount; ++i) {
            delete books[i];
        }
        cout << "Library closed, but members still exist.\n";
    }
};

int main() {
    library l;
    l.addbook("bookA", "authorX", "123");
    l.addbook("bookB", "authorA", "456");
    member* m1 = new member("M1");
    member* m2 = new member("M2");
    l.addmember(m1);
    l.addmember(m2);

    system("pause");
    delete m1;
    delete m2;

    return 0;
}
