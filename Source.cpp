#include <iostream>
using namespace std;
class Product {
public:
    string productId;
    string productName;
    double price;

    Product(string id, std::string name, double p) : productId(id), productName(name), price(p) {}

    void displayDetails() {
        cout << "Product ID: " << productId << ", Name: " << productName << ", Price: $" << price << endl;
    }
};

class ShoppingCart {
private:
    static const int MAX_PRODUCTS = 10;
    Product* products[MAX_PRODUCTS];
    int numProducts;

public:
    ShoppingCart() : numProducts(0) {}

    void addProduct(Product* product) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts++] = product;
        }
        else {
            std::cout << "Shopping Cart is full. Cannot add more products." << endl;
        }
    }

    void displayProducts() {
        cout << "Products in Cart:" << endl;
        for (int i = 0; i < numProducts; ++i) {
            products[i]->displayDetails();
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (int i = 0; i < numProducts; ++i) {
            total += products[i]->price;
        }
        return total;
    }
};

class User {
public:
    string userId;
    string userName;
    ShoppingCart* shoppingCart;

    User(std::string id, std::string name) : userId(id), userName(name), shoppingCart(nullptr) {}

    void displayDetails() {
        cout << "User ID: " << userId << ", Name: " << userName << endl;
    }

    void setShoppingCart(ShoppingCart* cart) {
        shoppingCart = cart;
    }
};

int main() {
 
    Product* product1 = new Product("001", "Item1", 10.0);
    Product* product2 = new Product("002", "Item2", 15.0);

    
    ShoppingCart* cart = new ShoppingCart();

    
    cart->addProduct(product1);
    cart->addProduct(product2);

  
    User* user = new User("123", "John");

   
    user->setShoppingCart(cart);

   
    user->displayDetails();

    
    cart->displayProducts();

  
    double totalCost = cart->calculateTotal();

    cout << "Total Cost: $" << totalCost << endl;

   
    delete product1;
    delete product2;
    delete cart;
    delete user;

    return 0;
}