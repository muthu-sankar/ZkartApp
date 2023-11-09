#include "Customer.h"

Customer::Customer(const std::string& customerUserName, const std::string& customerEncryptedPwd,
                   const std::string& customerName, const std::string& customerMobile)
    : userName(customerUserName), encryptedPwd(customerEncryptedPwd),
      name(customerName), mobile(customerMobile) {}