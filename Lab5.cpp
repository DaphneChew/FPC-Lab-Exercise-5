#include <iostream> 
#include <iomanip>
using namespace std;

#define SIZE 5
#define COLS 5

void displayLine();
void getData(int [], double [][COLS]);
void calculatePayroll(int [], double [][COLS] );
void printData(int [], double [][COLS]);
void highestOvertime(int [], double[][COLS]);

//USER DEFINED FUNCTION 1
void displayLine()
{
    for(int i=0;i<106;i++)
        cout <<"-";
    cout << endl;
}

//USER DEFINED FUNCTION 2
void getData(int empID[], double empRecord[][COLS])
{
    for(int i=0;i<SIZE;i++)
    {
        cout<<"ID: ";
        cin >>empID[i];
        cout<<"Hours worked: ";
        cin >> empRecord[i][0]; //Hours worked
        cout<<"Rate of Pay (RM per hour): ";
        cin >> empRecord[i][1]; //Rate of Pay
    }
    cout << endl;
}

//USER DEFINED FUNCTION 3
void calculatePayroll(int empID[], double empRecord[][COLS])
{
    for(int i=0; i<SIZE ;i++)
    {
        empRecord[i][2] = empRecord[i][0] * empRecord[i][1]; //Regular Pay calculation
        if( empRecord[i][0] > 40)
        {
            empRecord[i][3] = (empRecord[i][0]-40 )* 1.5 * empRecord[i][1]; //Overtime Pay calculation
        }
        else 
        {
            empRecord[i][3] = 0;
        }
        empRecord[i][4] = empRecord[i][2] + empRecord[i][3]; //Total Pay calculation
    }
}

//USER DEFINED FUNCTION 4
void printData(int empID[], double empRecord[][COLS])
{
    cout<<"Payroll Final Report" << endl;
    displayLine();
    cout<< left << setw(10)<<"ID" <<  setw(10) <<"HOURS"<<  setw(10) <<"RATE (RM)"<<  setw(20) <<"REGULAR DAY(RM)"<<  setw(15) <<"OVERTIME(RM)"<<  setw(10) <<"TOTAL(RM)"<< endl;
    displayLine();
    for(int i=0; i<SIZE; i++)
    {
        cout << left << setw(10) << empID[i];
        cout << left << setw(10) << empRecord[i][0];
        cout << left << setw(10) << empRecord[i][1];
        cout << left << setw(20) << empRecord[i][2];
        cout << left << setw(15) << empRecord[i][3];
        cout << left << setw(10) << empRecord[i][4] << endl;
   
    }
}

//USER DEFINED FUNCTION 5
void highestOvertime(int empID[], double empRecord[][COLS])
{
    double highestOvertime = empRecord[0][3];
    int highestEmp = empID[0];
    for(int i=0; i<SIZE; i++)
    {
        if(empRecord[i][3] > highestOvertime)
        {
            highestOvertime = empRecord[i][3];
            highestEmp = empID[i];
        }
    }
    cout<<"Staff "<< highestEmp <<" has the highest pay overtime of RM" << highestOvertime << endl;
}

//MAIN FUNCTION 
int main()
{
  
    int empID[SIZE];
    double empRecord[SIZE][COLS];

    cout <<"Payroll Program" << endl;
    getData(empID, empRecord);
    calculatePayroll(empID, empRecord);
    printData(empID, empRecord);
    cout << endl;
    highestOvertime(empID, empRecord);
    cout << endl;

    return 0;
}

