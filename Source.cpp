// Lab7test.cpp : This file contains the 'main' function. Program execution begins and ends there. 
// 
#include <iostream> 
#include <iomanip> 
#include <string> 
#include <fstream> 
using namespace std;
string user_receipt();

//prompt user receipt
string user_receipt() {
    string name = " ";
    string order = " ";
    double discount;
    double atax;
    double ftax;
    double ctax;
    double ast = 0.0;
    double subtotal = 0;
    atax = subtotal * 0.065;
    ftax = subtotal * 0.005;
    ctax = subtotal * 0.02125;
    double total3;
    double total2;
    total3 = total2 + atax + ftax + ctax;
    total2 = subtotal - discount;
    ofstream receipt;
    receipt.open("Receipt.txt");
    receipt << "Receipt for " << name << endl;
    receipt << order << endl;
    receipt << "arkansas state tax: 6.5% " << atax << endl;
    receipt << "Faulkner County Tax: 0.5% " << ftax << endl;
    receipt << "Conway Municipal Tax: 2.125% " << ctax << endl;
    receipt << "Your total is: " << total3 << endl;
    receipt << "Loyalty Points: " << ast << endl;
    receipt.close();
}

//print loyal 
void printloyalPoints(double total) {
    double total3;
    double loyalty = total3 / 3;
    string order = " ";
    string ast(loyalty, '*');
    cout << order << endl;
    cout << "Loyalty Points" << ast << endl;
}

void takeOrder(char &foodChoice, char &sizeChoice, int &quantity) {
    
    cout << "Please choose an item: " << endl;
    cin >> foodChoice;
    cout << "Please select a size (s/m/l): " << endl;
    cin >> sizeChoice;
    cout << "How many would you like? " << endl;
    cin >> quantity;
}

void readMenuItem(ifstream &input, string &foodName, double &smPrice,
double &medPrice, double &lgPrice){
    input >> foodName;
    input >> smPrice;
    input >> medPrice;
    input >> lgPrice;
}
void printMenuItem(char selectionItem, string foodName, 
    double smPrice, double medPrice, double lgPrice) {
        cout << std::setw(30) << selectionItem << ": "
        << foodName << setw(10) << smPrice 
        << setw(10) << medPrice
        << setw(10) << lgPrice << endl;
}


int main()
{
    //variables 
    string name;
    char itemcode;
    int quantity;
    double price;
    char member;
    double discount;
    char choice;
    char sizechoice;
    char tip;
    bool checkout = false;
    string order;
    string foodname;
    bool day = false;
    double totalsale = 0;
    int customer = 0;
    double subtotal = 0;
    //file 
    string Wine;
    string Tequila;
    string Burger;
    string Moose;

    double sm1;
    double m1;
    double l1;

    double sm2;
    double m2;
    double l2;

    double sm3;
    double m3;
    double l3;

    double sm4;
    double m4;
    double l4;
    //read 
    ifstream inputFile;
    ofstream output;
    output.open("where_am_i.txt");
    inputFile.open("Menu.txt");
    if (!inputFile)
        cout << "File didnt open";
    inputFile >> Wine;
    inputFile >> sm1;
    inputFile >> m1;
    inputFile >> l1;
        //readMenuItem(inputFile, Wine, sm1, m1, l1);    
    readMenuItem(inputFile, Tequila, sm2, m2, l2);    
    readMenuItem(inputFile, Burger, sm3, m3, l3);    
    readMenuItem(inputFile, Moose, sm4, m4, l4);    

    // Menu 

    do {
        do {
        cout << setw(22) << "Menu" << endl;
        cout << setw(35) << "Drinks     Small (s)       Medium (m)       Large(l)" << endl;
        printMenuItem('A', Wine, sm1, m1, l1);
        printMenuItem('B', Tequila, sm2, m2, l2);
        //cout << setw(30) << "A: Wine       3.50            6.00             9.50   " << endl;
        //cout << setw(30) << "B: Tequila    0.99            2.50             5.00" << endl;
        cout << " Entrees" << endl;
        printMenuItem('C', Burger, sm3, m3, l3);
        printMenuItem('D', Moose, sm4, m4, l4);
        //cout << setw(30) << "C: Burger    5.00             7.50            12.50" << endl;
        //cout << setw(30) << "D: Moose     10.00            17.50           32.50" << endl;
        cout << "E: Check out" << endl;

        //menu 

        takeOrder(choice, sizechoice, quantity);
        switch (choice) {
        case 'A':
        case 'a':
            foodname = "Wine";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm1;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m1;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l1;
                subtotal += price * quantity;
                break;
            default: 
            std::cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'B':
        case 'b':
            foodname = "tequila";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm2;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m2;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l2;
                subtotal += price * quantity;
                break;
            default: std::cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'C':
        case 'c':
            foodname = "burger";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm3;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m3;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l3;
                subtotal += price * quantity;
                break;
            default: std::cout << " You messed up try again" << endl;
            }
            break;
        case 'D':
        case 'd':
            foodname = "Moose";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm4;
                subtotal += price * quantity;
            case 'M':
            case 'm':
                price = m4;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l4;
                subtotal += price * quantity;
                break;
            default: cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'E':
        case 'e':
            checkout = true;
            break;
        default: std::cout << "Error" << endl;
        }
        order += foodname + "\t\t" + to_string(quantity) + "\t\t" + to_string(price) + "\t\t" +
            to_string(subtotal) + "\n";

    } while (checkout == false);

        //ask for user's name. 

        std::cout << "What is your name ? " << endl;
        std::cin >> name;

        std::cout << "Are you a member? y/n";
        std::cin >> member;
        //  cashier notes 
        string note;
        cout << " Cashier Notes";
        cin.ignore();
        getline(cin, note);
        //math 

        double total2;
        double total3;
        double atax;
        double ftax;
        double ctax;
        atax = subtotal * 0.065;
        ftax = subtotal * 0.005;
        ctax = subtotal * 0.02125;
        discount = subtotal * 0.10;
        total2 = subtotal - discount;
        total3 = total2 + atax + ftax + ctax;


        double tip1 = 0.15;
        double tip2 = 0.2;
        double tip3 = 0.25;


        double tipamt1 = tip1 * subtotal;
        double tipamt2 = tip2 * subtotal;
        double tipamt3 = tip3 * subtotal;

        double tiptotal1 = tipamt1 + total3;
        double tiptotal2 = tipamt2 + total3;
        double tiptotal3 = tipamt3 + total3;

        // display 
        //cout << left << setw(24) << "Item:" << name << endl; 
        //cout << left << setw(25) << "Item Code:" << itemcode << endl; 

        // cout << left << setw(25) << "Amount:" << quantity << endl; 
        cout << left << setw(25) << "Name: " << name << endl;
        cout << left << setw(25) << fixed << setprecision(2) << "Total:" << subtotal << endl;
        cout << "arkansas state tax: 6.5% " << atax << endl;
        cout << "Faulkner County Tax: 0.5% " << ftax << endl;
        cout << "Conway Municipal Tax: 2.125% " << ctax << endl;
        cout << left << setw(25) << "Membership:" << member << endl;
        if (member == 'y' || member == 'Y') {
            cout << left << setw(25) << "With Membership Discount:" << total2 << endl;

        }
        cout << "Final Total:" << total3 << endl;
        cout << right << setw(25) << "Cashier Notes:" << note << endl;


        cout << setw(30) << "Tip Selection" << "Amount" << endl;
        cout << setw(30) << "A. 15%" << setw(30) << "$" << tipamt1 << endl;
        cout << setw(30) << "B. 20%" << setw(30) << "$" << tipamt2 << endl;
        cout << setw(30) << "C. 25%" << setw(30) << "$" << tipamt3 << endl;
        cout << setw(30) << "D. other " << endl;
        cin >> tip;
        switch (tip) {
        case 'A':
        case 'a':
            cout << " You have chosen a 15% tip" << endl;
            cout << " Your new total is" << tiptotal1 << endl;
            break;
        case 'B':
        case 'b':
            cout << "You have chosen a 20% tip" << endl;
            cout << " Your new total is" << tiptotal2 << endl;
            break;
        case 'C':
        case 'c':
            cout << "You have chosen a 25% tip" << endl;
            cout << " Your new total is" << tiptotal3 << endl;
            break;
        case 'D':
        case 'd':


            double tipc;
            cout << "Please enter the percentage amount you'd like to tip" << endl;
            cin >> tipc;

            double tip4 = tipc / 100;
            double tipamt4 = tip4 * subtotal;
            double tiptotal4 = tipamt4 + total3;
            cout << "you have tipped" << setw(1) << tipamt4 << endl;

            cout << " Your new total is" << setw(1) << tiptotal4 << endl;
            break;
            //default: cout << " No tip" << endl; 

        }

        printloyalPoints(total3);

        customer++;
        totalsale += total3;

        //writing receipt to file 

        user_receipt();
        // day check 
        char cus;
        cout << "Is there another customer?? Y/N" << endl;
        cin >> cus;
        if (cus == 'N' || cus == 'n')
            day = true;

    } while (day == false);
    cout << "There were  " << customer << " Customers" << endl;
    cout << "There was a total of " << totalsale << " Dollars in sales today" << endl;

}
/*
double takeOrder(string& order) {

    // Declare Variables

    cout << setw(22) << "Menu" << endl;
    cout << setw(35) << "Drinks     Small (s)       Medium (m)       Large(l)" << endl;
    cout << setw(30) << "A: Wine       3.50            6.00             9.50   " << endl;
    cout << setw(30) << "B: Tequila    0.99            2.50             5.00" << endl;
    cout << " Entrees" << endl;
    cout << setw(30) << "C: Burger    5.00             7.50            12.50" << endl;
    cout << setw(30) << "D: Moose     10.00            17.50           32.50" << endl;
    cout << "E: Check out" << endl;




    do {
        string name;
        char itemcode;
        int quantity;
        double price;
        char member;
        double discount;
        char choice;
        char sizechoice;
        char tip;
        char checkout;
        bool checkout = false;
        string order;
        string foodname;
        bool day = false;
        double totalsale = 0;
        int customer = 0;
        double subtotal = 0;
        string Wine;
        string Tequila;
        string Burger;
        string Moose;

        double sm1;
        double m1;
        double l1;

        double sm2;
        double m2;
        double l2;

        double sm3;
        double m3;
        double l3;

        double sm4;
        double m4;
        double l4;
        cout << "Please Select Either Drink or Entree: " << endl;
        cin >> choice;
        switch (choice) {
        case 'A':
        case 'a':
            foodname = "Wine";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm1;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m1;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l1;
                subtotal += price * quantity;
                break;
            default: cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'B':
        case 'b':
            foodname = "tequila";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm2;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m2;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l2;
                subtotal += price * quantity;
                break;
            default: cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'C':
        case 'c':
            foodname = "burger";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm3;
                subtotal += price * quantity;
                break;
            case 'M':
            case 'm':
                price = m3;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l3;
                subtotal += price * quantity;
                break;
            default: cout << " You messed up try again" << endl;
            }
            break;
        case 'D':
        case 'd':
            foodname = "Moose";
            switch (sizechoice) {
            case 'S':
            case 's':
                price = sm4;
                subtotal += price * quantity;
            case 'M':
            case 'm':
                price = m4;
                subtotal += price * quantity;
                break;
            case 'L':
            case 'l':
                price = l4;
                subtotal += price * quantity;
                break;
            default: cout << " You messed up try again" << endl;
                break;
            }
            break;
        case 'E':
        case 'e':
            checkout = true;
            break;
        default: cout << "Error" << endl;
        }
        order += foodname + "\t\t" + to_string(quantity) + "\t\t" + to_string(price) + "\t\t" +
            to_string(subtotal) + "\n";

    } while (checkout == false);

    return 0;
}
*/
