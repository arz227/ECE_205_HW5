#include <iostream>
using namespace std;

class Pizza
{
public:
    // Constants for pizza type
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;

    // Constants for pizza size
    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    // Default constructor
    Pizza()
    {
        type = HAND_TOSSED;
        size = SMALL;
        toppings = 0;
    }

    // Set pizza type
    void set_type(int type1)
    {
        type = type1;
    }

    // Set pizza size
    void set_size(int size1)
    {
        size = size1;
    }

    // Set number of toppings
    void set_toppings(int toppings1)
    {
        toppings = toppings1;
    }

    // Compute pizza price
    double computePrice()
    {
        double price = 0;

        if (size == SMALL)
        {
            price = 10 + 2 * toppings;
        }
        else if (size == MEDIUM)
        {
            price = 14 + 2 * toppings;
        }
        else if (size == LARGE)
        {
            price = 17 + 2 * toppings;
        }

        return price;
    }

    // Display pizza details
    void outputDescription()
    {
        cout << "Pizza description:" << endl;

        if (type == DEEP_DISH)
            cout << "Type: Deep Dish" << endl;
        else if (type == HAND_TOSSED)
            cout << "Type: Hand Tossed" << endl;
        else if (type == PAN)
            cout << "Type: Pan" << endl;

        if (size == SMALL)
            cout << "Size: Small" << endl;
        else if (size == MEDIUM)
            cout << "Size: Medium" << endl;
        else if (size == LARGE)
            cout << "Size: Large" << endl;

        cout << "Number of toppings: " << toppings << endl;
    }

private:
    int type;       // pizza type
    int size;       // pizza size
    int toppings;   // toppings count
};

int main()
{
    Pizza p1;          // create pizza object
    char choice = 'y'; // used to repeat program

    // Loop to allow multiple runs
    while (choice == 'y' || choice == 'Y')
    {
        int type, size, toppings;

        // Input and validate type
        cout << "Enter pizza type (1=Deep Dish, 2=Hand Tossed, 3=Pan): ";
        cin >> type;

        while (type < 1 || type > 3)
        {
            cout << "Invalid input. Enter pizza type again (1, 2, or 3): ";
            cin >> type;
        }

        // Input and validate size
        cout << "Enter pizza size (1=Small, 2=Medium, 3=Large): ";
        cin >> size;

        while (size < 1 || size > 3)
        {
            cout << "Invalid input. Enter pizza size again (1, 2, or 3): ";
            cin >> size;
        }

        // Input and validate toppings
        cout << "Enter number of toppings: ";
        cin >> toppings;

        while (toppings < 0)
        {
            cout << "Invalid input. This is not realistic. Enter again: ";
            cin >> toppings;
        }

        // Store values in object
        p1.set_type(type);
        p1.set_size(size);
        p1.set_toppings(toppings);

        // Display output
        p1.outputDescription();
        cout << "Pizza price = $" << p1.computePrice() << endl;

        // Ask user to continue
        cout << "\nDo you want to enter another pizza? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    return 0;
}
