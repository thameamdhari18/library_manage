#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Define Book class to represent individual books
class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;
    time_point<system_clock> dueDate;

public:
    // Constructor
    Book(string t, string a, string i) : title(t), author(a), ISBN(i), available(true) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool isAvailable() const { return available; }
    time_point<system_clock> getDueDate() const { return dueDate; }

    // Mark the book as checked out and set due date
    void checkOut() {
        available = false;
        dueDate = system_clock::now() + hours(72); // Set due date 3 days from now
    }

    // Mark the book as returned
    void returnBook() { available = true; }
};

// Define Library class to manage books and transactions
class Library {
private:
    vector<Book> books;

public:
    // Add a new book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Search for a book by title, author, or ISBN
    vector<Book> searchBooks(const string& searchTerm) {
        vector<Book> results;
        for (const Book& book : books) {
            if (book.getTitle() == searchTerm || book.getAuthor() == searchTerm || book.getISBN() == searchTerm) {
                results.push_back(book);
            }
        }
        return results;
    }

    // Check out a book
    void checkOutBook(const string& ISBN) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) { return b.getISBN() == ISBN && b.isAvailable(); });
        if (it != books.end()) {
            it->checkOut();
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book not available for checkout." << endl;
        }
    }

    // Return a book and calculate fine if overdue
    void returnBook(const string& ISBN) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) { return b.getISBN() == ISBN && !b.isAvailable(); });
        if (it != books.end()) {
            it->returnBook();
            time_point<system_clock> now = system_clock::now();
            auto dueDate = it->getDueDate();
            if (now > dueDate) {
                int daysOverdue = duration_cast<hours>(now - dueDate).count() / 24;
                int fineAmount = daysOverdue * 3; // Standard fine amount of 3 rupees per day
                cout << "Book returned successfully. Fine amount: " << fineAmount << " rupees." << endl;
            } else {
                cout << "Book returned successfully." << endl;
            }
        } else {
            cout << "Invalid ISBN or book already returned." << endl;
        }
    }

    // Print all books in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const Book& book : books) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
            }
        }
    }
};

int main() {
    Library library;

    int choice;
    do {
        cout << "1. Add a book \n2. Search for a book\n3. Check out a book\n4. Return a book\n5. Display all books\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author, ISBN;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                cin >> ISBN;
                library.addBook(Book(title, author, ISBN));
                cout << "Book added successfully." << endl;
                break;
            }
            case 2: {
                cout << "Enter search term: ";
                string searchTerm;
                cin >> searchTerm;
                vector<Book> results = library.searchBooks(searchTerm);
                if (results.empty()) {
                    cout << "No matching books found." << endl;
                } else {
                    cout << "Matching books:" << endl;
                    for (const Book& book : results) {
                        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
                    }
                }
                break;
            }
            case 3: {
                cout << "Enter ISBN of the book to check out: ";
                string ISBN;
                cin >> ISBN;
                library.checkOutBook(ISBN);
                break;
            }
            case 4: {
                cout << "Enter ISBN of the book to return: ";
                string ISBN;
                cin >> ISBN;
                library.returnBook(ISBN);
                break;
            }
            case 5: {
                library.displayBooks();
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

