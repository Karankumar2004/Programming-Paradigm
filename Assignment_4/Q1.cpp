#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    float price;
    string Manufacturer;

public:
    // Default Constructor
    Vehicle()
    {
        price = 0.0;
        Manufacturer = "";
    }

    // Parametrized Constructor
    Vehicle(float price, string &Manufacturer)
    {
        this->price = price;
        this->Manufacturer = Manufacturer;
    }

    // Assignment operator
    Vehicle operator=(const Vehicle &other)
    {
        if (this != &other)
        {
            price = other.price;
            Manufacturer = other.Manufacturer;
        }
        return *this;
    }

    // Read Data
    void readData()
    {
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter manufacturer: ";
        cin >> Manufacturer;
    }

    // Display Data
    void displayData()
    {
        cout << "price: " << price << endl;
        cout << "Manufacturer: " << Manufacturer << endl;
    }
};

class Car : public Vehicle
{
private:
    string color;
    int NumberOfSeats;
    string Model;

public:
    // Default Constructor
    Car()
    {
        Vehicle();
        color = "";
        NumberOfSeats = 0;
        Model = "";
    }

    // Parametrized Constructor
    Car(float price, string &Manufacturer, string color, int NumberOfSeats, string Model)
    {
        Vehicle(price, Manufacturer);
        this->color = color;
        this->NumberOfSeats = NumberOfSeats;
        this->Model = Model;
    }

    // Copy Construtor
    Car(const Car &other)
        : Vehicle(other) // Used to initialize the sub-object of baseclass
    {
        color = other.color;
        NumberOfSeats = other.NumberOfSeats;
        Model = other.Model;
    }

    // Assignment operator
    Car operator=(const Car &other)
    {
        if (this != &other)
        {
            if (this != &other)
            {
                Vehicle::operator=(other); // Explicitly assigning value
                color = other.color;
                NumberOfSeats = other.NumberOfSeats;
                Model = other.Model;
            }
            return *this;
        }
    }

    // Read Data
    void readData()
    {
        Vehicle::readData(); // Explicitly calling the function from parent fn
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter number of seats: ";
        cin >> NumberOfSeats;
        cout << "Enter model: ";
        cin >> Model;
    }

    // Display Data
    void displayData()
    {
        Vehicle::displayData();
        cout << "Color: " << color << endl;
        cout << "Number of seats: " << NumberOfSeats << endl;
        cout << "Model: " << Model << endl;
    }
};
int main()
{
    cout << "Creating a Vehicle object..." << endl;
    Vehicle vehicle1;
    cout << "Reading data for Vehicle object..." << endl;
    vehicle1.readData();
    cout << "Displaying data for Vehicle object..." << endl;
    vehicle1.displayData();

    cout << "\nCreating a Car object..." << endl;
    Car car1;
    cout << "Reading data for Car object..." << endl;
    car1.readData();
    cout << "Displaying data for Car object..." << endl;
    car1.displayData();

    return 0;
}