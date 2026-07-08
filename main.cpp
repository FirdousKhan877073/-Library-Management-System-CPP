#include "LibrarySystem.h"
#include <iostream>
using namespace std;

int main() {
    LibrarySystem lib;
    
    cout << "=========================================" << endl;
    cout << "📚 LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "   (Using Real Kaggle Dataset)" << endl;
    cout << "=========================================" << endl;
    
    // Load books from CSV
    lib.loadFromCSV("books.csv");
    
    // === AUTO-TEST: Verify Kaggle Dataset ===
    cout << "\n🔍 VERIFYING KAGGLE DATASET..." << endl;
    cout << "=====================================" << endl;
    
    // Test 1: Check if specific books exist
    int testIDs[] = {1, 10, 100, 1000, 5000, 9999};
    int foundCount = 0;
    
    for (int id : testIDs) {
        Book* b = lib.searchByID(id);
        if (b != nullptr) {
            cout << "✅ Book " << id << " found: \"" << b->title << "\" by " << b->author << endl;
            foundCount++;
        } else {
            cout << "❌ Book " << id << " NOT found!" << endl;
        }
    }
    
    cout << "\n📊 Found " << foundCount << " out of " << sizeof(testIDs)/sizeof(testIDs[0]) << " test books." << endl;
    
    if (foundCount > 0) {
        cout << "✅✅✅ DATASET WORKING PERFECTLY! ✅✅✅" << endl;
    } else {
        cout << "❌❌❌ DATASET NOT LOADED CORRECTLY! ❌❌❌" << endl;
        cout << "💡 Please check if books.csv is in the right folder." << endl;
        return 0;
    }
    cout << "=====================================\n" << endl;
    
    // Main menu
    int choice;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. 🔍 Search Book by ID" << endl;
        cout << "2. 📖 Borrow a Book" << endl;
        cout << "3. 📚 Display All Books" << endl;
        cout << "4. 🔥 Display Top 5 Popular Books" << endl;
        cout << "5. 💾 Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int id;
                cout << "Enter Book ID (1-10000): ";
                cin >> id;
                Book* b = lib.searchByID(id);
                if (b != nullptr) {
                    cout << "✅ Book Found: ";
                    b->display();
                } else {
                    cout << "❌ Book with ID " << id << " not found!" << endl;
                }
                break;
            }
            case 2: {
                int id;
                cout << "Enter Book ID to borrow (1-10000): ";
                cin >> id;
                lib.borrowBook(id);
                break;
            }
            case 3: {
                lib.displayAllBooks();
                break;
            }
            case 4: {
                lib.displayTop5Popular();
                break;
            }
            case 5: {
                lib.saveToCSV("books_kaggle_updated.csv");
                cout << "✅ Data saved. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    } while (choice != 5);
    
    return 0;
}