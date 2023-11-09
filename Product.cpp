#include "Product.h"
#include <iostream>
#include <iomanip>

Product::Product(const std::string& productCategory, const std::string& productBrand, const std::string& productModel,
                 double productPrice, int productStock)
    : category(productCategory), brand(productBrand), model(productModel),
      price(productPrice), stock(productStock) {}

void Product::displayInfo() const {
    std::cout << std::setw(10) << category << std::setw(15) << brand << std::setw(20) << model
              << std::setw(10) << price << std::setw(10) << stock << std::endl;
}