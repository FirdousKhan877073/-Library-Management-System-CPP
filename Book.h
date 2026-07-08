#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    // Attributes (Properties of a Book)
    int id;
    string title;
    string author;
    double price;
    int year;
    int borrowCount;

    // Constructors (Ways to create a Book)
    Book();  // Default constructor
    Book(int i, string t, string a, double p, int y);

    // Method to display book details
    void display() const;
};

#endif