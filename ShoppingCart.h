#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Product.h"
#include "Customer.h"

class ShoppingCart {
private:
    std::vector<Customer> customers;
    std::vector<Product> inventory;
    std::vector<Product> cart;
    double total;

public:
    void run();

private:
    void loadCustomers();
    void loadInventory();
    void customerLogin(const std::string& username, const std::string& password);
    void displayInventory() const;
    void displayInventoryHeader() const;
    void addToCart();
    void viewCart() const;
    void checkout();
};

#endif // SHOPPINGCART_H