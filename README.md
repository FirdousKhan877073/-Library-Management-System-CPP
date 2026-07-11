# 📚 Library Management System in C++

A high-performance library management system built in C++ that demonstrates advanced Data Structures and OOP principles.

## 🎯 Features

- 🔍 **Instant Search:** O(1) search by Book ID using Hash Tables
- 📊 **Sorted Catalog:** Browse all books sorted by ID using BST
- 🔥 **Popularity Analytics:** Track and display Top 5 most borrowed books using Heap
- 📂 **Real Data:** Integrated with 10,000+ real books from Kaggle's Goodbooks-10k dataset
- 💾 **Data Persistence:** CSV import/export with proper header handling

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ (STL) | Core programming language |
| unordered_map | O(1) Hash Table for search |
| map (BST) | Sorted book catalog |
| priority_queue | Max-Heap for popularity tracking |
| fstream | File I/O for CSV handling |

## 📊 Data Structures Used

| Data Structure | Time Complexity | Use Case |
|----------------|-----------------|----------|
| unordered_map (Hash Table) | O(1) average | Search book by ID |
| map (Red-Black Tree) | O(log n) | Sorted display of books |
| priority_queue (Heap) | O(log n) | Top 5 popular books |

## 🚀 How to Run

### Prerequisites
- C++ Compiler (g++ recommended)
- VS Code or any IDE

### Steps
1. Clone this repository
2. Ensure `books.csv` (Kaggle dataset) is in the project folder
3. Compile:
   ```bash
   g++ -std=c++11 -o LibrarySystem Book.cpp LibrarySystem.cpp main.cpp
4. Run ./LibrarySystem   

=========================================
📚 LIBRARY MANAGEMENT SYSTEM
   (Using Real Kaggle Dataset)
=========================================
📋 Skipping header row...
✅ Loaded 10000 books successfully from Kaggle dataset!

🔍 VERIFYING KAGGLE DATASET...
=====================================
✅ Book 1 found: "The Hunger Games" by Suzanne Collins
✅ Book 10 found: "The Hobbit" by J.R.R. Tolkien
✅ Book 100 found: "To Kill a Mockingbird" by Harper Lee

--- MENU ---
1. 🔍 Search Book by ID
2. 📖 Borrow a Book
3. 📚 Display All Books
4. 🔥 Display Top 5 Popular Books
5. 💾 Save and Exit

LibrarySystem/
├── Book.h              # Book class definition
├── Book.cpp            # Book class implementation
├── LibrarySystem.h     # System class definition
├── LibrarySystem.cpp   # System class implementation
├── main.cpp            # Main program with menu
├── books.csv           # Kaggle dataset (10,000 books)
└── README.md           # This file