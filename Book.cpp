#include "Book.h"
#include <iostream>
using namespace std;

// Default constructor
Book::Book() {
    id = 0;
    title = "";
    author = "";
    price = 0.0;
    year = 0;
    borrowCount = 0;
}

// Parameterized constructor
Book::Book(int i, string t, string a, double p, int y) {
    id = i;
    title = t;
    author = a;
    price = p;
    year = y;
    borrowCount = 0;  // New books start with 0 borrows
}

// Display book details
void Book::display() const {
    cout << "ID: " << id 
         << " | Title: " << title 
         << " | Author: " << author 
         << " | Price: $" << price 
         << " | Year: " << year 
         << " | Borrows: " << borrowCount << endl;
}