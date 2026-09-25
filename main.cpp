#include <iostream>
#include <string>
using namespace std;
int main (){

    char testAgain = 'y';

    //loop: keeps running while user types 'y'
    while (testAgain == 'y'){
        //variables: 2 strings and 1 integer
        int color1 = 0;
        int color2 = 0;
        int option = 0;

        //Intro (work in progress)
        cout << "Welcome! This is the Color Compatibility Checker specifically geared for detecting a color pair's compatibility with red-green color blindness." << endl;
        cout << "Here are the colors you may choose from:\n";
        cout << "1.Red\n2.Orange\n3.Yellow\n4.Green\n5.Blue\n6.Indigo\n7.Violet\n8.Pink\n\n";

        //standard I/O input color names
       do{
        cout << "Enter color 1 (1-8): ";
        cin >> color1;
        if (color1 < 1 || color1 > 8){
            cout << "Invalid selection! Please choose a number between 1 and 7.\n";
        }
       } while (color1 < 1 || color1 > 8);
       
        do{
            cout << "Enter color 2 (1-8): ";
            cin >> color2;
            if (color2 < 1 || color2 > 8){
            cout << "Invalid selection! Please choose a number between 1 and 8.\n";
        }
       } while (color2 < 1 || color2 > 8);

        do{
        cout << "\n1. Check for compatibility of color pair for red-green color blindness\n";
        cout << "2. Check for same color\n";
        cout << "Enter choice (1 or 2): ";
        cin >> option;
        if (option != 1 && option != 2){
            cout << "Invalid choice! Please enter 1 or 2.\n";
        }
            } while (option != 1 && option !=2);

        
        //decision 1 switch statement

        switch (option){
            case 1:
            //decisions 2 and 3 if else if and else
                if (color1 == 1 && color2 == 4){
                cout << "Warning: Red and green are hard to tell apart for red-green type color blindness!\n";
            }   else if (color1 == 4 && color2 == 1){
                cout << "Warning: Green and red are hard to tell apart for red-green type color blindness!\n";
            } else {
                cout << "This pair looks okay for red-green colorblindness.\n";
            }
            break;
            case 2:
                if (color1 == color2){
                    cout << "Warning: Both colors have the exact same name!\n";
                }
                if (color1 != color2){
                    cout << "These colors are not the same.\n";
                }
                    break;
            default:
            cout << "Invalid choice.\n";
            break;
        }
        do{
        cout << "\nWould you like to test another pair? (y/n): ";
        cin >> testAgain;
        
        if (testAgain != 'y' && testAgain != 'Y' && testAgain != 'n' && testAgain != 'N'){
            cout << "Invalid choice! Please enter 'y' for yes or 'n' for no.\n";
        }
    } while (testAgain != 'y' && testAgain != 'Y' && testAgain != 'n' && testAgain  != 'N');
        cout << "\n";
    }
        cout << "Done!\n";
        return 0;
    }



