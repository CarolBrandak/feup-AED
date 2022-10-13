<<<<<<< HEAD
#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator < (const Product &p) const{
    if(this->getPrice()==p.getPrice()){
        return this->getWeight()<p.getWeight();
    }
    return this->getPrice()<p.getPrice();
}
=======
#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator < (const Product &p) const{
    if(this->getPrice()==p.getPrice()){
        return this->getWeight()<p.getWeight();
    }
    return this->getPrice()<p.getPrice();
}
>>>>>>> 15d654b9bf7aaeb31a544467ffce6ac33cb65a9b
