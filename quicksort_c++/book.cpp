#include <iostream>
#include "book.h"
#include <string>
#include <cstdlib>

//Book Object Implementation
//Constructor
Book::Book() {
   bookID = 0;
   bookName = "";
   ISBN = "";
}

//Destructor
Book::~Book() {
  // std::cout << "Book has been destroyed!" << std::endl;
}

int Book::GetBookID() {
    return bookID;
}

std::string Book::GetBookName() {
    return bookName;
}

std::string Book::GetISBN() {
    return ISBN;
}

void Book::SetBookID(int i) {
    bookID = i;
}

void Book::SetBookName(std::string s) {
    bookName = s;
}

void Book::SetBookISBN(std::string s) {
    ISBN = s;
}

void Book::PrintBook() {
    std::cout << " " << bookName << "_" << bookID << "_" << ISBN << " "<< std::endl;
}