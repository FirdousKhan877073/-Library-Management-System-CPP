#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "Book.h"
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class LibrarySystem {
private:
    // Data Structures to store books
    unordered_map<int, Book> hashTable;   // For O(1) search by ID
    map<int, Book> bstCatalog;            // For sorted display by ID
    priority_queue<pair<int, int>> popularHeap; // <borrowCount, bookID>

public:
    // Function to load books from CSV file
    void loadFromCSV(string filename);
    
    // Function to save books to CSV file
    void saveToCSV(string filename);
    
    // Function to search a book by ID (O(1) time)
    Book* searchByID(int id);
    
    // Function to borrow a book (increases borrow count)
    void borrowBook(int id);
    
    // Function to display all books sorted by ID
    void displayAllBooks();
    
    // Function to display top 5 most popular books
    void displayTop5Popular();
    
    // Function to generate 10,000 dummy books (if CSV doesn't exist)
    void generateDummyData();
};

#endif