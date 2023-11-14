#include <iostream>
using namespace std;

// Class representing a physical book
class Book {
private:
	string title;  
	string isbn;   // ISBN (International Standard Book Number) of the book
	double price;

public:
	// Constructor to initialize the Book object
	Book(string t, string i, double p) : title(t), isbn(i), price(p) {};

	// Member function to display information about the book
	void ShowBookInfo() {
		cout << "Title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Price(USD): " << price << endl;
	}
};

// Class representing an electronic book (eBook), inheriting from Book
class EBook : public Book {
private:
	string drmkey;  // DRM
	string format;  // Format of the eBook (default is "Kindle")

public:
	EBook(string t, string i, double p, string d, string f = "Kindle") : Book(t, i, p), drmkey(d), format(f) {};

	// Member function to display information about the eBook, including Book information
	void ShowEBookInfo() {
		ShowBookInfo();  // Call the ShowBookInfo() function from the base class
		cout << "DRMkey: " << drmkey << endl;
		cout << "Format: " << format << endl;
	}
};

const int MAX_BOOK = 100;
class EBookLibrary {
private:
	EBook* m_books[MAX_BOOK]; // Array to store pointers to EBook objects
	int m_cnt;  // Current count of stored EBook objects
public:
	EBookLibrary() : m_cnt(0) {};

	// Destructor to free dynamically allocated memory
	~EBookLibrary() {
		for (int i = 0; i < m_cnt; ++i) {
			delete m_books[i];
		}
	};

	// Add Ebook to library
	void AddBook(EBook* book) {
		if (m_cnt < MAX_BOOK) {
			m_books[m_cnt++] = book;
		}
		else {
			cout << "EBookLibrary is full. Cannot add more books." << endl;
		}
	}

	// Show all info of ebooks
	void ShowAllBooks(void) {
		for (int i = 0; i < m_cnt; i++) {
			m_books[i]->ShowEBookInfo();
			cout << endl;
		}
	};
};

int main() {
	EBookLibrary elib;
	elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" });
	elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
	elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub" });
	elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });
	elib.ShowAllBooks();
	return 0;
}
