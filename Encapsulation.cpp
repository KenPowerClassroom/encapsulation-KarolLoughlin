#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;  // Withdrawal successful
        }
        return false;  // Insufficient funds
    }
};

class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    void regulate(HeatingSystem& hs, double targetTemperature) {
        if (currentTemperature < targetTemperature) {
            hs.turnOn();
        }
        else {
            hs.turnOff();
        }
    }
};

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        isAvailable = false;
    }

    void returnBook() {
        isAvailable = true;
    }

    // New Function
    void tryBorrowBook() {
        if (checkAvailability()) {
            borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }
};

class Library {
public:
    //void processBookBorrowing(Book& book) {
    //    // Violates Tell, Don't Ask
    //    if (book.checkAvailability()) {
    //        book.borrowBook();
    //        std::cout << "Book borrowed successfully." << std::endl;
    //    }
    //    else {
    //        std::cout << "Book is not available for borrowing." << std::endl;
    //    }
    //}

    void processBookBorrowing(Book& book) {
        book.tryBorrowBook();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.getHealth() > 0 && player.getAmmo() > 0) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);

    // Violation of Tell, Don't Ask
    
    bool successfulTransaction = account.withdraw(500);

    if (successfulTransaction) {
        std::cout << "Withdrawal successful. New balance: $" << account.getBalance() << std::endl;
    }
    else {
        std::cout << "Insufficient funds for withdrawal." << std::endl;
    }

    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    HeatingSystem heating;

    thermostat.regulate(heating, 20.0);
 
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////


    Book myBook("1984");
    Library library;

    // Don't change client if possible - keep library
    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////

    Player player;
    Game game;

    while (player.getHealth() > 0 && player.getAmmo() > 0) {
        game.enemyAttack(player); // Player responds to attack until unable
    }

    return 0;
    

}