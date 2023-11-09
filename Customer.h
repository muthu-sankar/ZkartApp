#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    std::string userName;
    std::string encryptedPwd;
    std::string name;
    std::string mobile;

    Customer(const std::string& customerUserName, const std::string& customerEncryptedPwd,
             const std::string& customerName, const std::string& customerMobile);
};

#endif // CUSTOMER_H