//============================================================================
// Name        : menu.cpp
// Author      : Freddy Hurkmans
// Version     :
// Copyright   : copyright Freddy Hurkmans
// Description : Assignment 1 example
//============================================================================

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "RentalAdministration.h"
#include "Limousine.h"
#include "Sedan.h"

void addTestDataToAdministration(RentalAdministration *administration)
{
    string licencePlates[] = {"SD-001", "SD-002", "SD-003", "SD-004", "LM-001", "LM-002"};

    for (int i = 0; i < 4; i++)
    {
        Car *sedan = new Sedan("BMW", "535d", 2012 + i, licencePlates[i], false);
        administration->Add(sedan);
        delete sedan;
    }
    for (int i = 4; i < 6; i++)
    {
        Car *limousine = new Limousine("Rolls Roys", "Phantom Extended Wheelbase", 2015, licencePlates[i], true);
        administration->Add(limousine);
        delete limousine;
    }
}

static const Car *GetCurrentCar(const RentalAdministration *administration, size_t carNumber)
{
    if (carNumber > administration->GetCars().size())
    {
        cout << "\nError: car with car number " << carNumber << " does not exist!\n";
        return NULL;
    }

    Car *car = administration->GetCars()[carNumber - 1];

    return car; // return the correct car here
}

static void printCars(const RentalAdministration *administration)
{
    int i = 1;
    for (Car *car : administration->GetCars())
    {
        cout << "\n"
             << i << ": " << car->ToString();
        i++;
    }
}

static size_t selectCar(const RentalAdministration *administration)
{
    size_t carNumber = 0;
    cout << "These cars are currently listed:";
    printCars(administration);
    cout << "\nPlease enter a car number: ";
    std::cin >> carNumber;
    std::cin.ignore();
    return carNumber;
}

static void rentCar(RentalAdministration *administration, size_t carNumber)
{
    const Car *curr = GetCurrentCar(administration, carNumber);
    // rent this car, functionality comparable to btnRent_Click
    if (administration->RentCar(curr->GetLicensePlate()))
    {
        cout << "Car " << curr->ToString() << " has been rented" << endl;
    }
    else{
        cout << "ERROR: " << curr->ToString() << " is not available!" << endl;
    }
    delete curr;
}

static void returnCar(RentalAdministration *administration, size_t carNumber)
{
    const Car *curr = GetCurrentCar(administration, carNumber);
    // return this car, do handle exceptions
    try{
        int kilometers = 10;
        double costs = administration->ReturnCar(curr->GetLicensePlate(), kilometers);
        cout << "Car " << curr->ToString() << " returned, price: " << costs << endl; 
    }
    catch(const domain_error error){
        cout << "ERROR: Car " << curr->ToString() << " - " << error.what() << endl;
    }
    delete curr;
}

static void printIfCarNeedsCleaning(const RentalAdministration *administration, size_t carNumber)
{
    const Car *curr = GetCurrentCar(administration, carNumber);
    // print if this car needs cleaning
    if (curr->GetNeedsCleaning()){
        cout << "Car " << curr->ToString() << " needs cleaning";
    }
    else{
        cout << "Car " << curr->ToString() << " doesn't need cleaning";
    }
    delete curr;
}

static void cleanCar(RentalAdministration *administration, size_t carNumber)
{
    const Car *curr = GetCurrentCar(administration, carNumber);
    // clean this car, see: btnClean_Click
    administration->CleanCar(curr->GetLicensePlate());
    cout << "Car " << curr->ToString() << " has been cleaned";
    delete curr;
}

static void showMenu(void)
{
    cout << ("\n\nCar Rental menu\n");
    cout << ("===============\n");
    cout << ("(1) Show all cars\n");
    cout << ("(2) Select car\n");
    cout << ("(3) Rent selected car\n");
    cout << ("(4) Return selected car\n");
    cout << ("(5) Check if car needs cleaning\n");
    cout << ("(6) Clean car\n");
    cout << ("-----------------------\n");
    cout << ("(9) QUIT\n\n");
    cout << ("Choice : ");
}

int main(void)
{
    bool quit = false;
    size_t carNumber = 0;

    RentalAdministration administration;
    addTestDataToAdministration(&administration);

    while (!quit)
    {
        char choice = '\0';
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            printCars(&administration);
            break;
        case '2':
            carNumber = selectCar(&administration);
            cout << "Selected car: " << carNumber << endl;
            break;
        case '3':
            rentCar(&administration, carNumber);
            break;
        case '4':
            returnCar(&administration, carNumber);
            break;
        case '5':
            printIfCarNeedsCleaning(&administration, carNumber);
            break;
        case '6':
            cleanCar(&administration, carNumber);
            break;

        case '9':
            quit = true;
            break;
        default:
            cout << "\n\nI did not understand your choice (" << choice << ")" << endl;
            break;
        }
    }

    return 0;
}
