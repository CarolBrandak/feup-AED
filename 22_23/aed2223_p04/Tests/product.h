<<<<<<< HEAD
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <system_error>

using namespace std;

class Product : public error_code {
    string id;
    float price;
    float weight;
public:
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
    bool operator<(const Product &p) const;
};
#endif
=======
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <system_error>

using namespace std;

class Product : public error_code {
    string id;
    float price;
    float weight;
public:
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
    bool operator<(const Product &p) const;
};
#endif
>>>>>>> 15d654b9bf7aaeb31a544467ffce6ac33cb65a9b