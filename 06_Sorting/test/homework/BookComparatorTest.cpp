#include "Book.h"
#include "BookComparator.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

const std::vector<Book> algoBooks{

        {"Jane Eyre", "Charlotte Bronte", 1989, 350 },

        {"Gulliver’s Travels", "Jonathan Swift", 1967, 698 },

        {"Romeo and Juliet", "William Shakespeare", 1968, 1035 },

        {"The Adventures of Sherlock Holmes ", "Arthur Conan Doyle", 2012, 840 },

        {"Robinson Crusoe", "Daniel Defoe", 1889, 731 },

        {"Frankenstein", "Mary Shelley", 1947, 703},

        {"Treasure Island", "Robert Stevenson", 1856, 780 }

};


void compareBooksByPriceTest() {
  std::cout << "Sort books by price" << std::endl;
  std::vector<Book> sortedBooks(algoBooks);
  std::vector<Book> expectedList(algoBooks);
  std::sort(sortedBooks.begin(), sortedBooks.end(),
            [](const Book &a, const Book &b) {
              return BookComparator::compareBooksByPrice(a, b) < 0;
            });
  std::sort(
      expectedList.begin(), expectedList.end(),
      [](const Book &a, const Book &b) { return a.getPrice() < b.getPrice(); });
  for (size_t i = 0; i < expectedList.size(); ++i) {
      assert(expectedList[i] == sortedBooks[i]);
  }
}

void compareBooksByAuthorAndYearAndPriceTest() {
  std::cout << "Sort books by author, title, year" << std::endl;
  auto sortedBooks(algoBooks);
  auto expectedList(algoBooks);
  std::sort(
      sortedBooks.begin(), sortedBooks.end(), [](const Book &a, const Book &b) {
        return BookComparator::compareBooksByAuthorAndTitleAndYear(a, b) < 0;
      });

  std::sort(expectedList.begin(), expectedList.end(),
            [](const Book &a, const Book &b) {
              return a.getAuthor() != b.getAuthor()
                         ? a.getAuthor() < b.getAuthor()
                         : (a.getTitle() != b.getTitle()
                                ? a.getTitle() < b.getTitle()
                                : a.getYear() < b.getYear());
            });
  for (size_t i = 0; i < expectedList.size(); ++i) {
      assert(expectedList[i] == sortedBooks[i]);
  }
}

void bookCompareToTest() {
  std::cout << "Sort books by price" << std::endl;
  auto sortedBooks(algoBooks);
  auto expectedList(algoBooks);
  std::vector<Book> sortSet;
  for (auto b : algoBooks) {
      if (std::find(sortSet.begin(), sortSet.end(), b) == sortSet.end()) {
         sortSet.push_back(b);
      }      
  }
  auto sortedBooksCount = sortSet.size();
  auto expectedCount = algoBooks.size();
  assert(expectedCount == sortedBooksCount);
}


int main() {
    compareBooksByPriceTest();
    compareBooksByAuthorAndYearAndPriceTest();
    bookCompareToTest();
    std::cout << "All tests for BookComparator passed successfully! Congrats";
    return 0;
}
