#include <iostream>
#include <iomanip>
#include <tuple>
#include <ios>
using namespace std;


class Calculator {
public:

    static double  Addition (double  num1, double  num2) {
        double  result = num1 + num2;
        return result;
    }
    static double  Subtraction (double  num1, double  num2) {
        double  result = num1 - num2;
        return result;
    }
    static double  Multiplication (double  num1, double  num2) {
        double  result = num1 * num2;
        return result;
    }
    static double  Division (double  num1, double  num2) {
        double  result = num1 / num2;
        return result;
    }
    static void Results (int operation, double num1, double num2){

        static const int addition = 1;
        static const int subtraction = 2;
        static const int multiplication = 3;
        static const int division = 4;
        double results;

        switch (operation) {
            case addition:
                results = Calculator :: Addition(num1, num2);
                cout << num1 << " + " << num2 << " = " << results;
                break;
            case subtraction:
                results = Calculator :: Subtraction(num1, num2);
                cout << num1 << " - " << num2 << " = " << results;
                break;
            case multiplication:
                results = Calculator :: Multiplication(num1, num2);
                cout << num1 << " * " << num2 << " = " << results;
                break;
            case division:
                results = Calculator :: Division(num1, num2);
                cout << num1 << " / " << num2 << " = " << results;
                break;
            default:
                break;
        }
        cout << "\n****************************************\n";
    }

};

class Interaction{
public:

    static void GreetUser () {
        cout << "Greetings, User!\n";
        cin.clear();
    }
    static int GetOperation (){
#pragma region reads user operation with error checking
        static const int ADD = 1;
        static const int SUB = 2;
        static const int MUL = 3;
        static const int DIV = 4;
        int operation;
        //User input
        cout <<
             "****************************************\n"
             "What operation would you like to use?\n"
             "[1] : + addition\n"
             "[2] : - subtraction\n"
             "[3] : * multiplication\n"
             "[4] : / division\n"
             "****************************************\n"
             "Enter operation :  ";
        cin >> operation;
        // user input with error checking
        while (true) {
            if (!(operation >= 1 && operation <= 4)) {
                cin.clear();
                cin.ignore(50, '\n');
                cout << "\t\t*** Invalid Input, Try Again! ***" << endl;
                cout << "Enter operation :  ";
                cin >> operation;
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(50, '\n');
                cout << "\t*** Invalid Input, Try Again! ***" << endl;
                cout << "Enter operation :  ";
                cin >> operation;
            } else if (!cin.fail()) {
                cout << "\nThe Operation will be ";
                switch (operation) {
                    case ADD:
                        cout << "addition";
                        break;
                    case SUB:
                        cout << "subtraction";
                        break;
                    case MUL:
                        cout << "multiplication";
                        break;
                    case DIV:
                        cout << "division";
                        break;
                    default:
                        break;
                }
                cout << "\n****************************************\n";
                break;
            }
        }
#pragma endregion
        return operation;
    }
    static tuple<double , double > GetNum1and2(int operation){

        static const int ADD = 1;
        static const int SUB = 2;
        static const int MUL = 3;
        static const int DIV = 4;

        double num1;
        double num2;

#pragma region User input two numbers
        cout << "Enter TWO variables to be ";
        switch (operation) {
            case ADD:
                cout << "added\n"
                        "\nNum1 + Num2 = Result";
                break;
            case SUB:
                cout << "subtracted\n"
                        "\nNum1 - Num2 = Result";
                break;
            case MUL:
                cout << "multiplied\n"
                        "\nNum1 * Num2 = Result";
                break;
            case DIV:
                cout << "divided\n"
                        "\nNum1 / Num2 = Result";
                break;
            default:
                break;
        }

//input num1
        cout << "\nEnter Num1 : ";
        cin.clear();
        cin.ignore(50, '\n');
        cin >> num1;
//error checking for num1
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cout << "\t\t*** Invalid Input, Try Again! ***" << endl;
                cin.ignore();
                cout << "\nEnter Num1 : ";
                cin >> num1;
            } else if (!cin.fail()) {
                switch (operation) {
                    case ADD:
                        cout <<"\n"<< num1 << " + Num2 = Result\n";
                        break;
                    case SUB:
                        cout <<"\n"<< num1 << " - Num2 = Result\n";
                        break;
                    case MUL:
                        cout <<"\n"<< num1 << " * Num2 = Result\n";
                        break;
                    case DIV:
                        cout <<"\n"<< num1 << " / Num2 = Result\n";
                        break;
                    default:
                        break;
                }
                break;
            }
        }

//input num2
        cout << "Enter Num2 : ";
        cin.clear();
        cin.ignore(50, '\n');
        cin >> num2;
//error checking for num2
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cout << "\t\t*** Invalid Input, Try Again! ***" << endl;
                cin.ignore();
                cout << "\nEnter Num2 : ";
                cin >> num2;
            } else if (!cin.fail()) {
                switch (operation) {
                    case ADD:
                        cout <<"\n"<< num1 << " + " << num2 << " = Result\n";
                        break;
                    case SUB:
                        cout <<"\n"<< num1 << " - " << num2 << " = Result\n";
                        break;
                    case MUL:
                        cout <<"\n"<< num1 << " * " << num2 << " = Result\n";
                        break;
                    case DIV:
                        cout <<"\n"<< num1 << " / " << num2 << " = Result\n";
                        break;
                    default:
                        break;
                }
                cout << "****************************************\n";
                break;
            }
        }

#pragma endregion
        return make_tuple( num1, num2);
    }
};

int main() {
//variables
    int operation;
    double  num1;
    double  num2;
    char yesOrNo;
    bool isRepeat = true;
//deci format
    cout << fixed << showpoint << setprecision(2);

    //Greet User
    Interaction :: GreetUser();

    while(isRepeat){
//Get Operation to be use
        operation = Interaction :: GetOperation();
//Get Variables to be use
        tie(num1, num2) = Interaction :: GetNum1and2(operation);
//Operation Checking and displaying results
        Calculator::Results(operation, num1, num2);
//Repeating Logic
        cout<< "Do you want to repeat?\n"
               "Enter [Y] or [N] :";
        cin.clear();
        cin.ignore(50, '\n');
        cin >>  yesOrNo;
        yesOrNo = (char)toupper(yesOrNo);
        if (yesOrNo == 'Y') isRepeat = true;
        else if (yesOrNo == 'N') isRepeat = false;
        while (yesOrNo != 'Y' && yesOrNo != 'N')
        {
            cout << "\t\t*** Invalid Input, Try Again! ***" << endl;
            cout << "\nEnter [Y] or [N] :";
            cin.clear();
            cin.ignore(50, '\n');
            cin >>  yesOrNo;
            yesOrNo = (char)toupper(yesOrNo);
        }

    }

    return 0;
}
