#include "Bookstore.h"

Bookstore::Bookstore() : catalog(BookCatalogItem("", "", 0)) {}

void Bookstore::generateCatalog(vector<Book *> inventory) {
    catalog.makeEmpty();
    for (auto & b : inventory) {
        catalog.insert(b);
    }
}

BST<BookCatalogItem> Bookstore::getCatalog() const {
    return catalog;
}


//=============================================================================
//TODO:
vector<Book *> Bookstore::getBooksBy(string a) const {
    vector<Book *> result;
    //for (auto it=catalog.begin();it!=catalog.end();it++) {
    /*for (int i = 0; i < catalog.; ++i) {
        if(){

        }
    }

*/

    return result;
}

//TODO:
vector<Book *> Bookstore::getBooksBetween(unsigned y1, unsigned y2) const {
    vector<Book *> result;
    return result;
}
