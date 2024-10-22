#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Library {
private:
    vector<string> authors;
    vector<string> titles;
    vector<int> ids;
    vector<bool> status;
    int currentBookCount;

public:
    Library() : currentBookCount(0) {}

    void showMenu() {
        cout << "Welcome to ALEX Library \n";
        cout << "___________________________________________________________\n";
        cout << "Choose an option:" << endl;
        cout << "1- Add a book" << endl;
        cout << "2- List all books" << endl;
        cout << "3- Update a book" << endl;
        cout << "4- Borrow a book" << endl;
        cout << "5- Delete a book" << endl;
        cout << "6- Return a book" << endl;
        cout << "7- Exit" << endl;
        cout << "___________________________________________________________\n\n";

        cout << "Enter Your Choice: ";
    }

    void addBook(const string& author, const string& title) {
        ids.push_back(currentBookCount + 1);
        authors.push_back(author);
        titles.push_back(title);
        status.push_back(true);
        currentBookCount++;
        cout << "Book added successfully.\n";
    }

    int findBook(int id) {
        for (size_t i = 0; i < ids.size(); i++) {
            if (ids[i] == id) {
                return i;
            }
        }
        return -1;
    }

    void deleteBook(int id) {
        int position = findBook(id);
        if (position == -1) {
            cout << "Book doesn't exist.\n";
            return;
        }
        titles[position] = "Empty";
        authors[position] = "Empty";
        status[position] = false;
        cout << "Book removed successfully.\n";
    }

    void updateBook(int id) {
        int position = findBook(id);
        if (position == -1) {
            cout << "Book doesn't exist.\n";
            return;
        }

        int choice;
        bool running = true;
        while (running) {
            cout << "What do you want to update?\n";
            cout << "1- Book title\n";
            cout << "2- Book Author\n";
            cout << "3- Availability\n";
            cout << "4- Exit\n";
            cout << "Your Choice: ";
            cin >> choice;

            string input;
            switch (choice) {
            case 1:
                cout << "Enter new title: ";
                cin.ignore();
                getline(cin, input);
                titles[position] = input;
                cout << "Title updated.\n";
                break;
            case 2:
                cout << "Enter new author: ";
                cin.ignore();
                getline(cin, input);
                authors[position] = input;
                cout << "Author updated.\n";
                break;
            case 3:
                cout << "Available (yes/no)? ";
                cin >> input;
                status[position] = (input == "yes");
                cout << "Availability updated.\n";
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        cout << "Book updated successfully.\n";
    }

    void borrowBook(int id) {
        int position = findBook(id);
        if (position == -1) {
            cout << "Book doesn't exist.\n";
            return;
        }
        if (status[position]) {
            status[position] = false;
            cout << "Book borrowed successfully.\n";
        }
        else {
            cout << "Book is already borrowed.\n";
        }
    }

    void returnBook(int id) {
        int position = findBook(id);
        if (position == -1) {
            cout << "Book doesn't exist.\n";
            return;
        }
        if (!status[position]) {
            status[position] = true;
            cout << "Book returned successfully.\n";
        }
        else {
            cout << "Book is already available.\n";
        }
    }

    void displayBookInfo(int id) {
        int position = findBook(id);
        if (position == -1) {
            cout << "Book doesn't exist.\n";
            return;
        }
        cout << "Author: " << authors[position] << "\n";
        cout << "Title: " << titles[position] << "\n";
        cout << "Status: " << (status[position] ? "Available" : "Not Available") << "\n";
        cout << "ID: " << ids[position] << "\n";
    }

    void displayAllBooks() {
        for (size_t i = 0; i < ids.size(); i++) {
            displayBookInfo(ids[i]);
            cout << "****************************************\n";
        }
    }
};

int main() {
    Library library;
    library.addBook("Taha Hussein", "The Days");
    library.addBook("Naguib Mahfouz", "Children of the Alley");

    int choice, id;
    string title, author;
    bool running = true;

    while (running) {
        system("cls");
        library.showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Book Author: ";
            getline(cin, author);
            library.addBook(author, title);
            system("pause");
            break;
        case 2:
            library.displayAllBooks();
            system("pause");
            break;
    
        case 3:
            cout << "Book ID: ";
            cin >> id;
            library.updateBook(id);
            system("pause");
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            library.borrowBook(id);
            system("pause");
            break;

        case 5:
            cout << "Enter the ID of the book to return: ";
            cin >> id;
            library.returnBook(id);
            system("pause");
            break;
      
        case 6:
            cout << "Book ID: ";
            cin >> id;
            library.deleteBook(id);
            system("pause");
            break;

        case 7:
            running = false;
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        system("cls");
    }
    cout << "Thanks for your visit!\n";
    return 0;
}
