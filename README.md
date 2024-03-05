# library_manage
LIBRARY MANAGEMENT
This C++ code is a simple library management system that allows users to perform various operations such as adding books, searching for books, checking out books, returning books, and displaying all books in the library. Let's break down the code and explain each part:

Libraries Included :
      iostream: Standard Input/Output Library.
      vector: Dynamic Array Library.
      string: String Library.
      algorithm: Algorithms Library (used for searching).
      chrono: Time Library (used for handling time-related operations).
Classes : 
      Book Class:
        Represents individual books with attributes like title, author, ISBN, availability, and due date.
      Library Class: 
            Manages a collection of books and provides functions for various operations on the books.
      Book Class:
Private Attributes: 
        title, author, ISBN, available, and dueDate.
Constructor:
        Initializes the book with the given title, author, and ISBN.
Getter Methods:
        Getters for accessing the attributes of the book.
checkOut():
        Marks the book as checked out and sets the due date.
returnBook():
        Marks the book as returned.
Library Class
Private Attribute:
          books, a vector to store instances of Book class.
Methods:
    addBook(): 
          Adds a new book to the library.
    searchBooks(): 
          Searches for a book by title, author, or ISBN.
    checkOutBook(): 
          Marks a book as checked out if it's available.
    returnBook(): 
          Marks a book as returned and calculates fine if overdue.
    displayBooks():
          Displays all books in the library.
Main Function
Main Menu Loop: 
          Provides a menu-driven interface for users to interact with the library system.
Switch Statement:
          Executes different operations based on user input.
Input/Output: 
          Handles user input and displays output messages accordingly.
Explanation of Operations
Add a Book:  
        Prompts the user to input title, author, and ISBN, then adds the book to the library.
Search for a Book: 
        Prompts the user to enter a search term and displays matching books.
Check Out a Book:
        Prompts the user to enter the ISBN of the book to check out, then marks it as checked out.
Return a Book: 
        Prompts the user to enter the ISBN of the book to return, then marks it as returned and calculates a fine if overdue.
Display All Books:
        Prints information about all the books in the library.
Exit: 
        Terminates the program.

        
Overall, this code provides a basic framework for managing a library's collection of books and allows users to perform common operations related to book management.


