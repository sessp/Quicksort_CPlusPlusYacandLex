#include <iostream>
#include "book.cpp"
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <array>

int quicksortType() {
    std::cout << " If you would like to quicksort on name enter 1, else press 2 for ISBN.  \n";
    int m;
    std::cin >> m;
    return m;
}

//Reference ALG https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string getRandomName(size_t l)
{
   auto randomCharacter = []() -> char
   {
     const char charset[] = "abcdefghijklmnopqrstuvwxyz";
     const size_t max_i = (sizeof(charset) - 1);
     return charset[rand() % max_i];
   };
   std::string str(l,0);
   std::generate_n(str.begin(),l,randomCharacter);
   return str;
}

std::string getRandomISBN(size_t l)
{
   auto randomCharNum = []() -> char
   {
     const char charset[] = "123456789";
     const size_t max_i = (sizeof(charset) - 1);
     return charset[rand() % max_i];
   };
   std::string str(l,0);
   std::generate_n(str.begin(),l,randomCharNum);
   return str;
}

int getListNum() {
    std::cout << " Please input the number of books you wish to create  \n";
    int nBook;
    std::cin >> nBook;
    return nBook;
}


struct compare_name{
  bool operator() (Book left, Book right) {return left.GetBookName() < right.GetBookName(); }
};

struct compare_isbn{
  bool operator() (Book left, Book right) {return left.GetISBN() < right.GetISBN(); }
};

void swap(Book a[], int x, int y)
{
     Book temp = a[x];
     a[x] = a[y];
     a[y] = temp;
}

int partName(Book a[],int lowIndex,int highIndex)
{
   Book p = a[highIndex]; //Errors here
   int i = (lowIndex-1);
   for(int j = lowIndex; j <= highIndex-1; j++)
   {
      if(a[j].GetBookName() <= p.GetBookName())
      {
	i++;        
	swap(a,i,j);
      }
   }
   //final swap
   swap(a,(i+1),highIndex);
   return (i+1);
}

int partISBN(Book a[],int lowIndex,int highIndex)
{
   Book p = a[highIndex]; //Errors here
   int i = (lowIndex-1);
   for(int j = lowIndex; j <= highIndex-1; j++)
   {
      if(a[j].GetISBN() <= p.GetISBN())
      {
	i++;        
	swap(a,i,j);
      }
   }
   //final swap
   swap(a,(i+1),highIndex);
   return (i+1);
}

void qsName(Book a[], int lowIndex, int highIndex)
{
  if(lowIndex < highIndex) //if we aren't done yet.
  {
     int partitionIndex = partName(a,lowIndex,highIndex); //partition the array
     qsName(a,lowIndex,partitionIndex-1);  //quicksort the first partition.
     qsName(a,partitionIndex+1,highIndex); //quicksort the second partition.
  }
}

void qsISBN(Book a[], int lowIndex, int highIndex)
{
  if(lowIndex < highIndex) //if we aren't done yet.
  {
     int partitionIndex = partISBN(a,lowIndex,highIndex); //partition the array
     qsISBN(a,lowIndex,partitionIndex-1);  //quicksort the first partition.
     qsISBN(a,partitionIndex+1,highIndex); //quicksort the second partition.
  }
}

void quicksort(Book ab[], int SortOnDT, int aSize)
{

  
  int a = 0;
  std::cout << " \n";
  std::cout << " |Unsorted Array| \n";
  std::cout << " \n";

  Book b;
  for (int index = 0;index < aSize;index++) {
      ab[index].PrintBook();
      a++;
  } 
  
  if(SortOnDT == 1) //If you want to sort by name then use compare_name struct
  {
    qsName(ab,0,(a-1));
  }
  else if(SortOnDT == 2) 
  {
    qsISBN(ab,0,(a-1));
  }

  std::cout << " \n";
  std::cout << " |Sorted Array| \n";
  std::cout << " \n";
  for (int index1 = 0;index1 < aSize;index1++) {
      ab[index1].PrintBook();
  } 
}

void CreateBooks(int numBooks,int option, int nBooks) {
    std::cout << " Randomly Generating books! \n";
    std::cout << " \n";
    Book a[numBooks];
    Book b;
    for(int i = 0;i < numBooks;i++)
    {
       
       b.SetBookName(getRandomName(rand() % 13 + 1));
       b.SetBookISBN(getRandomISBN(13));
       b.SetBookID(i);
       a[i] = b;
       a[i].PrintBook();
    }
    quicksort(a,option,nBooks);
}

int main() {
    srand(time(0));
    std::cout << " Book Quicksorter Program! \n";
    int option = quicksortType();
    if(option != 0)
    {
    	int nBooks = getListNum();
    	std::cout << " Num of books to create " << nBooks << "\n";
        CreateBooks(nBooks,option,nBooks);
    }
    return 0;
}