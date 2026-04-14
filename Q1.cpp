#include <iostream>
using namespace std;

// Class to store bicycle trip information
class BicycleSpeedometer
{
public:
    // Default constructor sets all values to 0
    BicycleSpeedometer()
    {
        distance = 0;
        time = 0;
        avg_speed = 0;
    }

    // Set distance in miles
    void set_distance(double distance1)
    {
        distance = distance1;
    }

    // Set time in minutes
    void set_time(double time1)
    {
        time = time1;
    }

    // Return distance
    double get_distance()
    {
        return distance;
    }

    // Return time
    double get_time()
    {
        return time;
    }

    // Compute average speed in miles per hour
    double average_speed()
    {
        avg_speed = distance / (time / 60.0);
        return avg_speed;
    }

    // Display trip details
    void display()
    {
        cout << "Distance traveled = " << distance << " miles" << endl;
        cout << "Time taken = " << time << " minutes" << endl;
        cout << "Average speed = " << avg_speed << " mph" << endl;
    }

private:
    double distance;   // stores distance in miles
    double time;       // stores time in minutes
    double avg_speed;  // stores average speed
};

int main()
{
    BicycleSpeedometer B1;   // create object
    char choice = 'y';       // used to repeat the program

    while (choice == 'y' || choice == 'Y')
    {
        double d, t;

        // Ask for distance until user enters a valid value
        do
        {
            cout << "Enter distance traveled in miles: ";
            cin >> d;

            if (d < 0)
                cout << "Distance cannot be negative. Please try again." << endl;

        } while (d < 0);

        // Ask for time until user enters a value greater than 0
        do
        {
            cout << "Enter time taken in minutes: ";
            cin >> t;

            if (t <= 0)
                cout << "Time must be greater than 0. Please try again." << endl;

        } while (t <= 0);

        // Store values in the object
        B1.set_distance(d);
        B1.set_time(t);

        // Calculate and display average speed
        B1.average_speed();
        B1.display();

        // Ask if user wants to run the program again
        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    return 0;
}
