#pragma once
#include "Book.h"

class BookComparator {
public:
    BookComparator(){};
    virtual ~BookComparator(){};
    //Реализовать сравнение книг только по цене, вначале самые дешевые
	static int compareBooksByPrice(const Book &first, const Book &second) {
        if(first.getPrice() > second.getPrice()) return 1;
        else if(first.getPrice() < second.getPrice()) return -1;
        else return 0;
    }

    //Реализовать сравнение книг вначале по автору, потом по названию, затем по году публикации
    static int compareBooksByAuthorAndTitleAndYear(const Book &first, const Book &second) {
        if(first.getAuthor() > second.getAuthor() ) return 1;
        else if(first.getAuthor() < second.getAuthor()) return -1;
        if(first.getTitle() > second.getTitle()) return 1;
        else if(first.getTitle() < second.getTitle()) return -1;
        if(first.getYear() > second.getYear()) return 1;
        else if(first.getYear() < second.getYear()) return -1;
        return 0;
    }
};
