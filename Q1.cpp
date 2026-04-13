0
#include <iostream>
using namespace std;

class BicycleSpeedometer
{
public:
    // Default constructor initializes all values to 0
    BicycleSpeedometer()
    {
        distance = 0;
        time = 0;
        avg_speed = 0;
    }

    // Set the distance in miles
    void set_distance(double distance1)
    {
        distance = distance1;
    }

    // Set the time in minutes
    void set_time(double time1)
    {
        time = time1;
    }

    // Return distance value
    double get_distance()
    {
        return distance;
    }

    // Return time value
    double get_time()
    {
        return time;
    }

    // Calculate average speed (miles per hour)
    double average_speed()
    {
        // Check to avoid division by zero
        if (time != 0)
        {
            // Convert minutes to hours before dividing
            avg_speed = distance / (time / 60.0);
        }
        else
        {
            avg_speed = 0;
        }

        return avg_speed;
    }

    // Display all results neatly
    void display()
    {
        cout << "Distance traveled = " << distance << " miles" << endl;
        cout << "Time taken = " << time << " minutes" << endl;
        cout << "Average speed = " << avg_speed << " mph" << endl;
    }

private:
    double distance;   // stores distance
    double time;       // stores time
    double avg_speed;  // stores calculated speed
};

int main()
{
    BicycleSpeedometer B1;  // create object
    char choice = 'y';      // used to repeat program

    // Loop so user can test multiple inputs
    while (choice == 'y' || choice == 'Y')
    {
        double d, t;  // variables for user input

        cout << "Enter distance traveled in miles: ";
        cin >> d;

        cout << "Enter time taken in minutes: ";
        cin >> t;

        // Set values into the object
        B1.set_distance(d);
        B1.set_time(t);

        // Calculate and display results
        B1.average_speed();
        B1.display();

        // Ask user if they want to continue
        cout << "\nDo you want to try again? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    return 0;  // end of program
}
