#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    string category;
    string brand;
    string model;
    double price;
    int stock;

    // Constructor
    Product(const string& productCategory, const string& productBrand, const string& productModel,
            double productPrice, int productStock)
        : category(productCategory), brand(productBrand), model(productModel),
          price(productPrice), stock(productStock) {}

    // Display product information
    void displayInfo() const {
        cout << setw(10) << category << setw(15) << brand << setw(20) << model
             << setw(10) << price << setw(10) << stock << endl;
    }
};

class Customer {
public:
    string userName;
    string encryptedPwd;
    string name;
    string mobile;

    // Constructor
    Customer(const string& customerUserName, const string& customerEncryptedPwd,
             const string& customerName, const string& customerMobile)
        : userName(customerUserName), encryptedPwd(customerEncryptedPwd),
          name(customerName), mobile(customerMobile) {}
};

class ShoppingCart {
private:
    vector<Customer> customers;
    vector<Product> inventory;
    vector<Product> cart;
    double total;

public:
    void run() {
        loadCustomers();
        loadInventory();

        string username, password;
        int choice;

        while (true) {
            cout << "Welcome to Z-Kart\n";
            cout << "1. Customer Login\n";
            cout << "2. View Inventory\n";
            cout << "3. Add to Cart\n";
            cout << "4. View Cart\n";
            cout << "5. Checkout\n";
            cout << "6. Quit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Customer Login\n";
                    cout << "Username: ";
                    cin >> username;
                    cout << "Password: ";
                    cin >> password;
                    customerLogin(username, password);
                    break;
                case 2:
                    displayInventory();
                    break;
                case 3:
                    addToCart();
                    break;
                case 4:
                    viewCart();
                    break;
                case 5:
                    checkout();
                    break;
                case 6:
                    cout << "Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice. Please select a valid option.\n";
            }
        }
    }

private:
    void loadCustomers() {
        customers.emplace_back("abc@zoho.com", "ApipNbjm", "Rahul", "9922992299");
        customers.emplace_back("123@zoho.com", "Cboljoh", "Anitha", "8564119904");
        customers.emplace_back("user@zoho.com", "kbwb22", "Arpan", "9872345693");
    }

    void loadInventory() {
        inventory.emplace_back("Mobile", "Apple", "6S", 60000, 10);
        inventory.emplace_back("Mobile", "Motorola", "G", 12000, 5);
        inventory.emplace_back("Laptop", "HP", "Elite", 56000, 20);
        inventory.emplace_back("Tablet", "Google", "ChromeBook", 8000, 12);
        // Add more products as needed
    }

    void customerLogin(const string& username, const string& password) {
        auto it = find_if(customers.begin(), customers.end(),
                          [&](const Customer& customer) {
                              return customer.userName == username && customer.encryptedPwd == password;
                          });

        if (it != customers.end()) {
            cout << "Customer Login Successful. Welcome, " << it->name << "!\n";
        } else {
            cout << "Invalid customer credentials. Please try again or sign up.\n";
        }
    }

    void displayInventory() const {
        cout << "Inventory:\n";
        displayInventoryHeader();
        for (const Product& product : inventory) {
            product.displayInfo();
        }
    }

    void displayInventoryHeader() const {
        cout << setw(10) << "Category" << setw(15) << "Brand" << setw(20) << "Model"
             << setw(10) << "Price" << setw(10) << "Stock" << endl;
    }

    void addToCart() {
        string category, brand, model;
        int quantity;

        cout << "Enter product details to add to the cart:\n";
        cout << "Category: ";
        cin >> category;
        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Quantity: ";
        cin >> quantity;

        auto it = find_if(inventory.begin(), inventory.end(),
                          [&](const Product& product) {
                              return product.category == category &&
                                     product.brand == brand &&
                                     product.model == model;
                          });

        if (it != inventory.end() && it->stock >= quantity) {
            cart.push_back(*it);
            total += it->price * quantity;
            it->stock -= quantity;
            cout << "Added to cart: " << category << " " << brand << " " << model << " x" << quantity << "\n";
        } else {
            cout << "Product not found or insufficient stock.\n";
        }
    }

    void viewCart() const {
        if (cart.empty()) {
            cout << "Your cart is empty.\n";
        } else {
            cout << "Your Cart:\n";
            displayInventoryHeader();
            for (const Product& product : cart) {
                product.displayInfo();
            }
            cout << "Total: $" << total << "\n";
        }
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Your cart is empty. Cannot proceed with checkout.\n";
            return;
        }

        cout << "Checkout Summary:\n";
        viewCart();
        cout << "Proceed with checkout? (1 for Yes, 0 for No): ";
        int proceed;
        cin >> proceed;

        if (proceed == 1) {
            // Implement your checkout logic here
            // For example, generate an invoice, update order history, etc.
            cout << "Checkout completed.\n";
            cart.clear();
            total = 0.0;
        } else {
            cout << "Checkout canceled.\n";
        }
    }
};

int main() {
    ShoppingCart shoppingCart;
    shoppingCart.run();

    return 0;
}
