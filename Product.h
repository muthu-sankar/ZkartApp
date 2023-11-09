#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    std::string category;
    std::string brand;
    std::string model;
    double price;
    int stock;

    Product(const std::string& productCategory, const std::string& productBrand, const std::string& productModel,
            double productPrice, int productStock);

    void displayInfo() const;
};

#endif // PRODUCT_H