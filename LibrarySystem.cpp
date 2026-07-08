#include "LibrarySystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// === LOAD BOOKS FROM CSV FILE ===
void LibrarySystem::loadFromCSV(string filename) {
    ifstream file(filename);
    
    // Check if file exists
    if (!file.is_open()) {
        cout << "❌ File not found! Please make sure books.csv is in the project folder." << endl;
        return;
    }

    string line;
    int count = 0;
    bool isFirstLine = true;
    
    // Read file line by line
    while (getline(file, line)) {
        // Skip the header row (first line)
        if (isFirstLine) {
            isFirstLine = false;
            cout << "📋 Skipping header row..." << endl;
            continue;
        }
        
        stringstream ss(line);
        string token;
        vector<string> tokens;
        
        // Split the line by commas
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        // Goodbooks-10k has 23 columns
        // We need: book_id (col 0), authors (col 7), original_publication_year (col 8), title (col 10)
        if (tokens.size() >= 11) {
            try {
                int id = stoi(tokens[0]);                // book_id
                string title = tokens[10];               // title
                string author = tokens[7];               // authors
                int year = stoi(tokens[8]);              // original_publication_year
                double price = 15.99;                    // Default price (Kaggle doesn't have price data)
                
                Book b(id, title, author, price, year);
                
                // Store in both data structures
                hashTable[id] = b;
                bstCatalog[id] = b;
                count++;
                
            } catch (const exception& e) {
                // Skip lines with errors (like missing data)
                continue;
            }
        }
    }
    file.close();
    cout << "✅ Loaded " << count << " books successfully from Kaggle dataset!" << endl;
}

// === SAVE BOOKS TO CSV FILE ===
void LibrarySystem::saveToCSV(string filename) {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not save file!" << endl;
        return;
    }
    
    // Write header
    file << "book_id,title,authors,price,original_publication_year,borrowCount\n";
    
    for (auto &pair : bstCatalog) {
        Book &b = pair.second;
        file << b.id << "," << b.title << "," << b.author << "," 
             << b.price << "," << b.year << "," << b.borrowCount << "\n";
    }
    file.close();
    cout << "✅ Saved " << bstCatalog.size() << " books to " << filename << endl;
}

// === SEARCH BOOK BY ID (O(1) using Hash Table) ===
Book* LibrarySystem::searchByID(int id) {
    auto it = hashTable.find(id);
    if (it != hashTable.end()) {
        return &(it->second);
    }
    return nullptr;
}

// === BORROW A BOOK ===
void LibrarySystem::borrowBook(int id) {
    Book* b = searchByID(id);
    if (b != nullptr) {
        b->borrowCount++;
        popularHeap.push({b->borrowCount, id});
        cout << "✅ Book '" << b->title << "' borrowed successfully!" << endl;
        cout << "   📊 This book has been borrowed " << b->borrowCount << " times." << endl;
    } else {
        cout << "❌ Book with ID " << id << " not found!" << endl;
    }
}

// === DISPLAY ALL BOOKS (Sorted by ID using BST) ===
void LibrarySystem::displayAllBooks() {
    cout << "\n📚 === ALL BOOKS (Sorted by ID) ===" << endl;
    cout << "=====================================" << endl;
    
    int count = 0;
    for (auto &pair : bstCatalog) {
        pair.second.display();
        count++;
        if (count % 10 == 0) {
            cout << "--- Press Enter to continue ---" << endl;
            cin.get();
            cin.get();
        }
    }
    cout << "Total: " << count << " books" << endl;
}

// === DISPLAY TOP 5 MOST POPULAR BOOKS (Using Heap) ===
void LibrarySystem::displayTop5Popular() {
    cout << "\n🔥 === TOP 5 MOST POPULAR BOOKS ===" << endl;
    cout << "=====================================" << endl;
    
    vector<pair<int, int>> temp;
    
    while (!popularHeap.empty()) {
        temp.push_back(popularHeap.top());
        popularHeap.pop();
    }
    
    int count = 0;
    for (auto &p : temp) {
        if (count >= 5) break;
        int id = p.second;
        Book* b = searchByID(id);
        if (b != nullptr) {
            cout << "#" << (count+1) << " ";
            b->display();
        }
        popularHeap.push(p);
        count++;
    }
    
    if (count == 0) {
        cout << "No books have been borrowed yet!" << endl;
    }
}

// === GENERATE DUMMY BOOKS (Fallback if CSV doesn't exist) ===
void LibrarySystem::generateDummyData() {
    // We don't need this anymore since we're using Kaggle data
    cout << "⚠️  Using Kaggle dataset instead of generating dummy data." << endl;
}