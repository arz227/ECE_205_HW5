#include <iostream>
using namespace std;

class PrimeNumber {
private:
    int prime;   // stores the current number

    // Function to check if a number is prime
    bool isPrime(int n) const {
        if (n < 2) return false;  // numbers less than 2 are not prime

        // check divisibility from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;     // not prime if divisible
        }
        return true;  // number is prime
    }

    // Function to find next prime number after n
    int nextPrime(int n) const {
        n++;  // move to next number

        // keep checking until a prime is found
        while (!isPrime(n)) {
            n++;
        }

        return n;
    }

    // Function to find previous prime number before n
    int previousPrime(int n) const {
        n--;  // move to previous number

        // keep checking until a prime is found or reach below 2
        while (n >= 2 && !isPrime(n)) {
            n--;
        }

        // if no valid prime found, return 1 (default value)
        if (n < 2) return 1;

        return n;
    }

public:
    // Default constructor (sets value to 1 as required)
    PrimeNumber() {
        prime = 1;
    }

    // Constructor with parameter
    PrimeNumber(int p) {
        prime = p;
    }

    // Getter function
    int getPrime() const {
        return prime;
    }

    // Helper function to check user input from main
    bool checkPrime(int n) const {
        return isPrime(n);
    }

    // Prefix ++ : move to next prime, then return updated object
    PrimeNumber operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // Postfix ++ : return old value, then move to next prime
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;  // store current value
        prime = nextPrime(prime);
        return temp;
    }

    // Prefix -- : move to previous prime, then return updated object
    PrimeNumber operator--() {
        prime = previousPrime(prime);
        return *this;
    }

    // Postfix -- : return old value, then move to previous prime
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;  // store current value
        prime = previousPrime(prime);
        return temp;
    }
};

int main() {
    char choice;  // to repeat program

    do {
        int num;

        // ask user for input
        cout << "Enter 1 or a prime number: ";
        cin >> num;

        PrimeNumber checker;

        // validate input: allow 1 or prime numbers only
        while (num < 1 || (num != 1 && !checker.checkPrime(num))) {
            cout << "Invalid input. Please enter 1 or a prime number: ";
            cin >> num;
        }

        // create object with user input
        PrimeNumber p(num);

        cout << "\nCurrent value: " << p.getPrime() << endl;

        // postfix increment
        p++;
        cout << "After postfix p++: " << p.getPrime() << endl;

        // postfix decrement
        p--;
        cout << "After postfix p--: " << p.getPrime() << endl;

        // prefix increment
        ++p;
        cout << "After prefix ++p: " << p.getPrime() << endl;

        // prefix decrement
        --p;
        cout << "After prefix --p: " << p.getPrime() << endl;

        // ask user to continue
        cout << "\nDo you want to try another number? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended." << endl;

    return 0;
}
