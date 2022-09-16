#include <iostream> 
using namespace std;

class Employee 
{ 
    string e_name, e_id;
    double e_hourwork, e_rateperhour, netsal, grossPay, otrate; 
    public:

    void getEmployee(string &ename, string &eid, double &hourWork, double &ratePerHour)
    {
        e_name = ename;
        e_id = eid;
        e_hourwork = hourWork;
        e_rateperhour = ratePerHour;
    }

    void calculateGrossPay()
    {
        double ot, sal;
        if(e_hourwork <= 40)
        {
            grossPay = e_hourwork*e_rateperhour;
        }
        else
        {
            sal = 40 * e_rateperhour;
            ot = e_hourwork - 40;
            otrate = e_rateperhour * 1.5;
            grossPay = ((ot * otrate)+sal);
        }
    }

    void calculateNetPay(int taxRate)
    {
        double tax = ((double)taxRate/100)*grossPay;
        netsal = grossPay-tax;
    }

    void printEmolyeePayment()
    {
        cout << "nn Name of Employee : "<<e_name<<"n Employee ID : "<<e_id<<"n Net Pay of Empoloyee : "<<netsal;
    }
};

int main()
{
    string ename, eid;
    double hourwork, rateperhour;
    char flag='y';

    double grosspay, netpay;
    double tax = 5;
    int i=0;
    Employee e[10];

    while(flag=='y')
    {
        cout << "nEnter employee detailsn";
        cout << "Name Of Employee : ";
        cin >> ename;
        cout << "ID Of Employee : ";
        cin >> eid;
        cout << "Work Hour Of Employee : ";
        cin >> hourwork;
        cout << "Rate Per Hour Of Employee : ";
        cin >> rateperhour;
        e[i].getEmployee(ename, eid, hourwork, rateperhour);
        i++;
        cout<<"Do you want to enter details of another employee ? y/n :";
        cin>>flag;
    }

    for(int j=0; j<i; j++)
    { 
        e[j].calculateGrossPay();
        e[j].calculateNetPay(tax);
        e[j].printEmolyeePayment();
    }

    return 0;
}
