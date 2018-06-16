/*Created by Ryan J. Wilson
Date of last Modification: 6-4-18
For CS115
Colorado Technical University
Unit 1 Individual Project*/
#include <iostream>

using namespace std;
class Customer
{
private:
    string custName;
    string custAddress1;
    string custAddress2;
    string custCity;
    string custState;
    string custZip;
public:
		void setcustName(string);
		string getcustName();
        void setcustAddress1(string);
		string getcustAddress1();
		void setcustAddress2(string);
		string getcustAddress2();
		void setcustCity(string);
		string getcustCity();
		void setcustState(string);
		string getcustState();
		void setcustZip(string);
		string getcustZip();
		//constructor
		Customer();
};
void Customer:: setcustName(string name)
{custName=name;
}
void Customer:: setcustAddress1(string address1)
{custAddress1=address1;}
void Customer:: setcustAddress2(string address2)
{custAddress2=address2;
}

void Customer:: setcustCity(string city)
{custCity=city;
}
void Customer:: setcustState(string state)
{custState=state;
}
void Customer:: setcustZip(string zip)
{custZip= zip;
}
string Customer::getcustName(){return custName;}
string Customer::getcustAddress1(){return custAddress1;}
string Customer::getcustAddress2(){return custAddress2;}
string Customer::getcustCity(){return custCity;}
string Customer::getcustState(){return custState;}
string Customer::getcustZip(){return custZip;}
Customer::Customer()
{
    custName= "";
    custAddress1 = "";
    custAddress2 = "";
    custCity = "";
    custState = "";
    custZip = "";

}

// create function for products selected
void productsSelected(int, int, int, int);

//create function prototype to show cost of products
void productCost(int, int, int, int);
//create function prototype to add costs, find tax, and add tax to total price
void totalCost(float,float,float,float);
void displayMenu(Customer *cust);

int main(void)
{
    //declare variables
    const int size = 80;
    int virusRemoval = 0;
    int product2 = 0;
    int product3 = 0;
    int product4 = 0;
    char menuSelection = ' ';

    //used later to create seperation during menu. need to find a better way to do this
    char useless = ' ';
    string uName = " ";
    string uAddress = " ";
    string uAddress2 = " ";
    string uCity = " ";
    string uState = " ";
    string uZipCode = " ";
    // Ask the user for his or her name
    cout << "Please enter your name:  "<<endl;
    //save name to variable
    getline(cin, uName);
    if (uName == "test"){
        uName = "test test";
        uAddress = "test";
        uAddress2 = "test";
        uCity = "test";
        uState= "TT";
        uZipCode = "123456";}
    else{
        uName[0] = toupper(uName[0]);
        //capitalize first letter of each word for user name
        for (int i = 1; i < size; i++)
   {
        if ( uName[i - 1] == ' ' )
            uName[i] = toupper( uName[i] );}

    //use test to reduce typing during testing of code
    //ask for address line 1, save to variable
        cout << "Please enter your street address: ";
        getline(cin, uAddress);
    //ask for line 2, save to variable
        cout << " Adress Line 2: ";
        getline(cin, uAddress2);
        uAddress2[0] = toupper(uAddress2[0]);
        //capitalize first letter of each word for apartment/suite number/letter
        for (int i = 1; i < size; i++)
   {
        if ( uAddress[i - 1] == ' ' )
            uAddress[i] = toupper( uAddress[i] );}
        for (int i = 1; i < size; i++)
   {
        if ( uAddress2[i - 1] == ' ' )
            uAddress2[i] = toupper( uAddress2[i] );}

    //ask and save city
        cout << "City: ";
        getline(cin, uCity);
        uCity[0]= toupper(uCity[0]);
        //capitalize first letter of each word for city
        for (int i = 1; i < size; i++)
   {
        if ( uCity[i - 1] == ' ' )
            uCity[i] = toupper( uCity[i] );}
    //ask and save state
        cout << "State(use state abbreviation, i.e. NC): ";
        getline(cin, uState);
    //ask and save zip code
        cout << "Zip code: ";
        getline(cin, uZipCode);
    //capitalize first and second letter of state for uniformity
        uState[0] = toupper(uState[0]);
        uState[1] = toupper(uState[1]);}
        Customer customer1;
        customer1.setcustName(uName);
        customer1.setcustAddress1(uAddress);
        customer1.setcustAddress2(uAddress2);
        customer1.setcustCity(uCity);
        customer1.setcustState(uState);
        customer1.setcustZip(uZipCode);

    //open menu for user selection
    // use do while loop to allow multilple products to be selected until user exits
    do {
        displayMenu(&customer1);

        cin >> menuSelection;
        switch (menuSelection){
            case '1':
            cout << "You selected 1 virus removal" << endl;
            virusRemoval += 1;
            cout << "Y: To Continue"<< endl;
            cin >> useless;
                break;
            case '2':
            cout << "You selected 1 Operating system install" << endl;
            product2 += 1;
            cout << "Y: To Continue"<< endl;
            cin >> useless;
                break;
            case '3':
            cout << "You selected 1 Hardware install" << endl;
            product3 += 1;
            cout << "Y: To Continue"<< endl;
            cin >> useless;
                break;
            case '4':
            cout<< "You selected 1 Computer maintenance" << endl;
            product4 += 1;
            cout << "Y: To Continue"<< endl;
            cin >> useless;
                break;
            case 'X':
            case 'x':
            cout << "Thank you, have a great day"<<endl;
                break;
            //default case to prevent program crash :(
            default:
            cout << "Please enter a number 1-4 or X"<<endl;
            cout << "Y: To Continue"<< endl;
            cin >> useless;

                }
        }
        while (menuSelection!= 'X' && menuSelection!='x');

    productsSelected(virusRemoval, product2, product3, product4);
    productCost(virusRemoval, product2, product3, product4);
    totalCost(virusRemoval, product2, product3, product4);
    return 0;

}
//define function for products
void productsSelected(int product1, int product2, int product3, int product4){
int quantitySelected [4] = {product1, product2, product3, product4};
if (product1 != 1){
        cout << "You have chosen " << quantitySelected[0]<< " virus removals" << endl;}
    else{
        cout << "You have chosen "<< quantitySelected[0] << " virus removal"<< endl;}
    if (product2 != 1){
        cout << "You have chosen " << quantitySelected[1]<< " OS installations" << endl;}
    else{
        cout << "You have chosen " << quantitySelected[1] << " OS installation" << endl;}
    if (product3 != 1){
        cout << "You have chosen " << quantitySelected[2] << " Hardware installations" << endl;}
    else{
        cout << "You have chosen " << quantitySelected[2] << " Hardware installation" << endl;}
    if (product4 != 1){
        cout << "You have chosen " << quantitySelected[3] << " computer maintenances " << endl;}
    else{
        cout << "You have chosen " << quantitySelected[3] << " computer maintenance" << endl;}
}
//define function for product cost
void productCost(int cost1, int cost2, int cost3, int cost4){
    cost1 = cost1*75;
    cost2 = cost2*100;
    cost3 = cost3*55;
    cost4 = cost4*100;
    cout << " Your cost for Virus removals is : $" << cost1 << endl;
    cout << " Your cost for OS installations is: $" << cost2 << endl;
    cout << " Your cost for Hardware installation is: $" << cost3 << endl;
    cout << " Your cost for Computer maintenances is: $" << cost4 << endl;}
//define function for total cost
void totalCost(float cost1, float cost2,float cost3,float cost4){
    cost1 = cost1*75;
    cost2 = cost2*100;
    cost3 = cost3*55;
    cost4 = cost4*100;
    float totalBeforeTax = cost1+cost2+cost3+cost4;
    float tax = totalBeforeTax * .07;
    float totalAfterTax = totalBeforeTax *1.07;
    cout << "Your total Before tax is: $" << totalBeforeTax << endl;
    cout << "Taxes = $"<< tax << endl;
    cout << "Your total including tax is: $" << totalAfterTax<< endl;
    }
void displayMenu(Customer *cust)
{
string productsForMenu[5] = {"Virus Removal","OS Installation","Hardware Installation","Computer Maintenance","X to Exit"};
string costForMenu[5] = {"$75.00", "$100.00 + Cost of License", "$55.00 + Cost of Hardware", "$100.00"};

    //hello message to customer
    cout << "Hello, " << cust->getcustName() << ", welcome to our store." << endl;
        //verify address saved(for testing purposes and to use address)
    cout << "We will come to this address to provide service if needed:  " << endl;
    cout << "   "+ cust->getcustAddress1() << endl;
    cout << "   "+ cust->getcustAddress2() << endl;
    cout << "   "+ cust->getcustCity() << ", " << cust->getcustState() << " " << cust->getcustZip() <<  endl;

    cout << "What service can we offer you today?" << endl;
    cout <<"-----------------------------------------"<< endl;

        for (int i = 0; i < 5; i++){
            if (i <4){
                cout<< i + 1 << ". "<< productsForMenu[i] << ". Cost:  "<<costForMenu[i]<<endl;}
            else{
                cout<< i + 1 << ". "<< productsForMenu[i]<<endl;
            };};
}
