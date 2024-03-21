#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

class BookManagementSystem {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Your book was added!\n";
    }

    void removeBook(const string& title) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title == title) {
                books.erase(books.begin() + i);
                cout << "Your book was removed!\n";
                return;
            }
        }
        cout << "Your book was not found!\n";
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "No books were found in the system.\n";
            return;
        }
        cout << "The books in the system:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
        }
    }
};

int main() {
    BookManagementSystem bms;

    while (true) {
        cout << "\nEnter a command (add, remove, list, exit):\n";

        string command;
        if (!(getline(cin, command) && !command.empty())) {
            cerr << "Error reading input. Exiting...\n";
            return 1;
        }

        if (command == "add") {
            string title, author;
            int year;

            cout << "Enter title:";
            if (!(getline(cin, title) && !title.empty())) {
                cerr << "Error reading input. Exiting...\n";
                return 1;
            }

            cout << "Enter author: ";
            if (!(getline(cin, author) && !author.empty())) {
                cerr << "Error reading input. Exiting...\n";
                return 1;
            }

            cout << "Enter year: ";
            if (!(cin >> year)) {
                cerr << "Error reading input. Exiting...\n";
                return 1;
            }
            cin.ignore();

            bms.addBook({ title, author, year });
        }
        else if (command == "remove") {
            string title;
            cout << "Enter title of the book you want to remove: ";
            if (!(getline(cin, title) && !title.empty())) {
                cerr << "Error reading input. Exiting...\n";
                return 1;
            }
            bms.removeBook(title);
        }
        else if (command == "list") {
            bms.listBooks();
        }
        else if (command == "exit") {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid command!\n";
        }
    }

    return 0;
}