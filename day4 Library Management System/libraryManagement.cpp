#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    DESC:- A farword class BookItem to avoid any error and Book class that hold all
           property of Book
    Method:- addItem()       
*/
class NotificationSystem;
class BookItem;
class Book {
private:
    int id;
    string title;
    string author;
    string subject;
    string publicationDate;
    vector<BookItem*> items;

public:
    Book(int id, const string &title, const string &author, const string &subject, const string &publicationDate)
        : id(id), title(title), author(author), subject(subject), publicationDate(publicationDate) {}

//getter function
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getSubject() const { return subject; }
    string getPublicationDate() const { return publicationDate; }
    vector<BookItem*> getItems() { return items; }

    void addItem(BookItem* item)
    { 
        items.push_back(item); 
    }
};

/*
    DESC:- a class BookItem declare that hold information about book available or not
    Method:- setAvailability()       
*/

class BookItem {
private:
    int barcode;
    Book* book;
    bool available;

public:
    BookItem(int barcode, Book* book) : barcode(barcode), book(book), available(true) {}

    int getBarcode() const { return barcode; }
    Book* getBook() const { return book; }
    bool isAvailable() const { return available; }

    void setAvailability(bool status)
    { 
        available = status;
    }
};

/*
    DESC:- a Member class declare that hold information about Member and books that borrow
    Method:- borrowBook() ,returnBook(), reserveBook(), renewBook()      
*/

class Member {
private:
    int memberId;
    string name;
    vector<BookItem*> borrowedBooks;
public:
    Member(int memberId, const string& name) : memberId(memberId), name(name) {}

    int getMemberId() const { return memberId; }
    string getName() const { return name; }
    vector<BookItem*> getBorrowedBooks() { return borrowedBooks; }
    
    //borrow a book by member
    void borrowBook(BookItem* book) {
        borrowedBooks.push_back(book);
        book->setAvailability(false);
    }
    
    //return book by member
    void returnBook(BookItem* book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            cout<<"Book is returned successfully by "<<name<<endl;
            book->setAvailability(true);
        }
    }
    //reserve book by member
    void reserveBook(BookItem* bookItem) {
        cout << "Book with barcode " << bookItem->getBarcode() << " reserved successfully by " << name << "." << endl;
    }
    // renew our book by member
    void renewBook(BookItem* bookItem) {
        cout << "Book with barcode " << bookItem->getBarcode() << " renewed successfully by " << name << "." << endl;
    }
};

/*
    DESC:- a Library class that hold information about books and members
    Method:- addBook(),addMember(),removeMember(),searchBook(),issueBook(),returnBook()       
*/

class Library {
private:
    vector<Book*> books;
    vector<Member*> members;
   // NotificationSystem notificationSystem; 
public:
    void addBook(Book* book)
    { 
        books.push_back(book); 
    }
    void addMember(Member* member) 
    { 
        members.push_back(member); 
    }

    void removeMember(Member* member) {
        auto it = find(members.begin(), members.end(), member);
        if (it != members.end()) {
            members.erase(it);
            cout << "Member removed successfully." << endl;
        } else {
            cout << "Member not found." << endl;
        }
    }

    // Search books by title, author, subject, or publication date
    vector<Book*> searchBooks(const string& keyword) {
        vector<Book*> results;
        for (Book* book : books) 
        {
            if (book->getTitle().find(keyword) != string::npos ||
                book->getAuthor().find(keyword) != string::npos ||
                book->getSubject().find(keyword) != string::npos ||
                book->getPublicationDate().find(keyword) != string::npos) 
                {
                   results.push_back(book);
                }
        }
        return results;
    }

    // Issue a book to a member
    void issueBook(Member* member, BookItem* bookItem) {
        member->borrowBook(bookItem);
    }

    // Return a book from a member
    void returnBook(Member* member, BookItem* bookItem) {
        member->returnBook(bookItem);
    }
};

class NotificationSystem
{
public:
    void sendNotification(const string &user, const string &message)
    {
        cout << "Sending notification to " << user << ": " << message << endl;
    }
};

/*
    DESC:-  main class for test the program
    Method:-      
*/

int main() {
    
    Library library;

    Book book1(1, "Book Title 1", "Author 1", "Subject 1", "04-05-2024");
    Book book2(2, "Book Title 2", "Author 2", "Subject 2", "05-09-2024");

    BookItem item1(101, &book1);
    BookItem item2(102, &book1);
    BookItem item3(103, &book2);

    book1.addItem(&item1);
    book1.addItem(&item2);
    book2.addItem(&item3);

    library.addBook(&book1);
    library.addBook(&book2);

    Member member1(1001, "Member 1");
    Member member2(1002, "Member 2");

    library.addMember(&member1);
    library.addMember(&member2);

    // Search and display books
    vector<Book*> results = library.searchBooks("Title");
    for (Book* book : results) {
        cout << "ID: " << book->getId() << ", Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Subject: " << book->getSubject() << ", Publication Date: " << book->getPublicationDate() << endl;
    }

    // Issue book to a member
    library.issueBook(&member1, &item1);

    // Return book from a member
    library.returnBook(&member1, &item1);

    //renew book
    member1.renewBook(&item1);
    
    // Remove a member
    cout << "Removing Member 2:" << endl;
    library.removeMember(&member2);


    return 0;
}


/*
 Disclaimer : this code in not run in my vs code
               if you also face this issue please run this code on any online compiler
*/