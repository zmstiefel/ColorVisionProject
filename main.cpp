#include <iostream>
#include <string>
using namespace std;
int main (){
    char testAgain = 'y';

    //loop: keeps running while user types 'y'
    while (testAgain == 'y'){
        //variables: 2 strings and 1 integer
        string color1 = "";
        string color2 = "";
        int option = 0;

        //standard I/O input color names
        cout << "Enter color 1: ";
        cin >> color1;

        cout << "Enter color 2: ";
        cin >> color2;

        cout << "\n1. Check for red-green color issue\n";
        cout << "2. Check for same color\n";
        cout << "Enter choice (1 or 2): ";
        cin >> option;

        //decision 1 switch statement

        switch (option){
            case 1:
            //decisions 2 and 3 if else if and else
                if (color1 == "red" && color2 == "green"){
                cout << "Warning: Red and green are hard to tell apart!\n";
            }   else if (color1 == "green" && color2 == "red"){
                cout << "Warning: Green and red are hard to tell apart!\n";
            } else {
                cout << "This pair looks okay for red-green colorblindness.\n";
            }
            break;
            case 2:
                if (color1 == color2){
                    cout << "Warning: Both colors have the exact same name!\n";
                }
                    break;
            default:
            cout << "Invalid choice.\n";
            break;
        }
        cout << "\nTest another pair? (y/n): ";
        cin >> testAgain;
        cout << "\n";
    }
        cout << "Done!\n";
        return 0;
    }



