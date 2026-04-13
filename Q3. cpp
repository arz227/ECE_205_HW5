#include <iostream>
#include <vector>
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

    // Constructor with values
    Pizza(int t, int s, int top)
    {
        type = t;
        size = s;
        toppings = top;
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

    // Set toppings
    void set_toppings(int toppings1)
    {
        toppings = toppings1;
    }

    // Return pizza type
    int get_type() const
    {
        return type;
    }

    // Return pizza size
    int get_size() const
    {
        return size;
    }

    // Return number of toppings
    int get_toppings() const
    {
        return toppings;
    }

    // Compute pizza price
    double computePrice() const
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

    // Display pizza information
    void outputDescription() const
    {
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

class Order
{
private:
    vector<Pizza> pizzas;   // store all pizzas in the order

public:
    // Add pizza object to order
    void addPizza(const Pizza& p)
    {
        pizzas.push_back(p);
    }

    // Create pizza and add to order
    void addPizza(int type, int size, int toppings)
    {
        Pizza p(type, size, toppings);
        pizzas.push_back(p);
    }

    // Show all pizzas and total price
    void outputOrder() const
    {
        double totalPrice = 0;

        if (pizzas.empty())
        {
            cout << "No pizzas in the order." << endl;
            return;
        }

        cout << "\n------ Order Details ------" << endl;

        for (int i = 0; i < pizzas.size(); i++)
        {
            cout << "\nPizza #" << i + 1 << endl;
            pizzas[i].outputDescription();
            cout << "Price = $" << pizzas[i].computePrice() << endl;

            totalPrice = totalPrice + pizzas[i].computePrice();
        }

        cout << "\nTotal Order Price = $" << totalPrice << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    char choice = 'y';   // used to repeat program

    // Loop to allow multiple orders
    while (choice == 'y' || choice == 'Y')
    {
        Order order1;
        int numberOfPizzas;

        cout << "Enter number of pizzas in the order: ";
        cin >> numberOfPizzas;

        // Check number of pizzas
        while (numberOfPizzas <= 0)
        {
            cout << "Invalid input. Enter again: ";
            cin >> numberOfPizzas;
        }

        int i = 0;

        // Enter each pizza
        while (i < numberOfPizzas)
        {
            int type, size, toppings;

            cout << "\nEnter information for Pizza #" << i + 1 << endl;

            cout << "Enter pizza type (1=Deep Dish, 2=Hand Tossed, 3=Pan): ";
            cin >> type;

            while (type < 1 || type > 3)
            {
                cout << "Invalid input. Enter pizza type again (1, 2, or 3): ";
                cin >> type;
            }

            cout << "Enter pizza size (1=Small, 2=Medium, 3=Large): ";
            cin >> size;

            while (size < 1 || size > 3)
            {
                cout << "Invalid input. Enter pizza size again (1, 2, or 3): ";
                cin >> size;
            }

            cout << "Enter number of toppings: ";
            cin >> toppings;

            while (toppings < 0)
            {
                cout << "Invalid input. This is not realistic. Enter again: ";
                cin >> toppings;
            }

            // Add pizza to the order
            order1.addPizza(type, size, toppings);
            i++;
        }

        // Print the full order
        order1.outputOrder();

        cout << "\nDo you want to create another order? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    return 0;
}
