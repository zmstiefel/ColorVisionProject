
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // Found in cplusplus.com.
#include <cctype>  // Found in cplusplus.com.
#include <cmath>
#include <limits>  // Found in cplusplus.com.

using namespace std;

// Function prototypes: tell main() which functions are available.
bool isValidHex(string hexCode);
void getColors(vector<string>& colors, int count);
double getLuminance(string hexCode);
double getContrastRatio(string firstColor, string secondColor);
void displayResults(const vector<string>& colors, ostream& output);
void saveResults(const vector<string>& colors);

int main() {
    char testAgain = 'y';

    //while loop: keeps running while user types 'y' or 'Y'.

    //Intro (work in progress).
    cout << "Welcome to the Color Compatibility Checker 2.0!\n";
    cout << "Compare hex colors for text/background contrast.\n";
    cout << "Note: Contrast does not guarantee colorblind accessibility.\n";

    while (testAgain == 'y' || testAgain == 'Y') {

        //variables: store the number of colors and menu choice.
        int colorCount = 0;

        // New: user chooses how many colors to enter.
        cout << "\nHow many colors would you like to test (2-20)? ";

        while (true) {
            if (!(cin >> colorCount)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (colorCount >= 2 && colorCount <= 20) {
                break;
            }

            cout << "Please enter a whole number from 2 to 20: ";
        }

        // New: vector stores as many hex colors as the user selects.
        vector<string> colors;
        getColors(colors, colorCount);

        // New: allow the user to quit early without losing entered colors.
        if (colors.size() < 2) {
            cout << "At least two colors are needed for comparison.\n";
        }
        else {

            //standard I/O input color names (now hex codes).
            int option = 0;

            while (option != 4) {
                cout << "\n1. Compare all color pairs\n";
                cout << "2. Check for duplicate colors\n";
                cout << "3. Save results to a file\n";
                cout << "4. Finish this set\n";
                cout << "Enter choice (1-4): ";

                if (!(cin >> option)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    option = 0;
                }

                //decision 1 switch statement.
                switch (option) {

                    case 1:
                        displayResults(colors, cout);
                        break;

                    case 2: {
                        //decisions 2 and 3 if else if and else.
                        // New: nested loops check each unique pair for duplicates.
                        bool foundDuplicate = false;

                        for (int i = 0; i < static_cast<int>(colors.size()); i++) {
                            for (int j = i + 1; j < static_cast<int>(colors.size()); j++) {

                                if (colors[i] == colors[j]) {
                                    cout << "Duplicate: color " << i + 1
                                         << " and color " << j + 1
                                         << " (" << colors[i] << ")\n";

                                    foundDuplicate = true;
                                }
                            }
                        }

                        if (!foundDuplicate) {
                            cout << "No duplicate colors found.\n";
                        }

                        break;
                    }

                    case 3:
                        saveResults(colors);
                        break;

                    case 4:
                        break;

                    default:
                        cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                        break;
                }
            }
        }

        //do while for invalid input (implemented here with while).
        cout << "\nWould you like to test another set? (y/n): ";
        cin >> testAgain;

        while (testAgain != 'y' && testAgain != 'Y' &&
               testAgain != 'n' && testAgain != 'N') {

            cout << "Please enter y or n: ";
            cin >> testAgain;
        }

        cout << "\n";
    }

    //at the end, always prints Done!
    cout << "Done!\n";

    return 0;
}

// New function: pass-by-value receives a copy of the hex code.
// Returns true only when the code is # followed by six hex digits.
bool isValidHex(string hexCode) {
    if (hexCode.length() != 7 || hexCode[0] != '#') {
        return false;
    }

    for (int i = 1; i < 7; i++) {
        if (!isxdigit(static_cast<unsigned char>(hexCode[i]))) {
            return false;
        }
    }

    return true;
}

// New function: pass-by-reference adds entries to the original vector.
// A loop asks for each color and repeats the prompt for invalid input.
// New: the user can enter Q or q to stop entering colors early.
void getColors(vector<string>& colors, int count) {
    for (int i = 0; i < count; i++) {
        string hexCode;

        do {
            cout << "Enter hex code for color " << i + 1
                 << " (example #FF0000, or Q to quit): ";
            cin >> hexCode;

            // New: quit color entry without losing previous colors.
            if (hexCode == "Q" || hexCode == "q") {
                cout << "Color entry finished. "
                     << colors.size() << " colors saved.\n";
                return;
            }

            if (!isValidHex(hexCode)) {
                cout << "Invalid hex code! Use # followed by six hex digits.\n";
            }

        } while (!isValidHex(hexCode));

        // New: convert lowercase hex letters to uppercase.
        for (char& letter : hexCode) {
            letter = static_cast<char>(
                toupper(static_cast<unsigned char>(letter))
            );
        }

        colors.push_back(hexCode);
    }
}

// New function: convert each hex color channel to a number.
// Calculate WCAG relative luminance from a six-digit sRGB hex code.
double getLuminance(string hexCode) {
    double channels[3];

    for (int i = 0; i < 3; i++) {
        int channel = stoi(hexCode.substr(1 + i * 2, 2), nullptr, 16);
        double value = channel / 255.0;

        channels[i] = (value <= 0.04045)
                      ? value / 12.92
                      : pow((value + 0.055) / 1.055, 2.4);
    }

    return 0.2126 * channels[0]
         + 0.7152 * channels[1]
         + 0.0722 * channels[2];
}

// New function: calculate contrast between two colors.
// The lighter color is divided by the darker color using the WCAG formula.
double getContrastRatio(string firstColor, string secondColor) {
    double first = getLuminance(firstColor);
    double second = getLuminance(secondColor);

    double lighter = (first > second) ? first : second;
    double darker = (first > second) ? second : first;

    return (lighter + 0.05) / (darker + 0.05);
}

// New function: nested loops compare every unique pair of colors.
// ostream lets the same report go to the console or an output file.
void displayResults(const vector<string>& colors, ostream& output) {
    output << "\nColor contrast results:\n";
    output << fixed << setprecision(2);

    for (int i = 0; i < static_cast<int>(colors.size()); i++) {
        for (int j = i + 1; j < static_cast<int>(colors.size()); j++) {

            double ratio = getContrastRatio(colors[i], colors[j]);

            output << colors[i] << " and " << colors[j]
                   << ": " << ratio << ":1 - ";

            if (ratio >= 4.5) {
                output << "Passes WCAG AA for normal-sized text";
            }
            else if (ratio >= 3.0) {
                output << "Passes WCAG AA for large text only";
            }
            else {
                output << "Does not meet WCAG AA text contrast minimums";
            }

            if (colors[i] == colors[j]) {
                output << " (duplicate colors)";
            }

            output << "\n";
        }
    }

    output << "Contrast measures readability, not colorblind distinguishability.\n";
}

// New function: file output saves the colors and comparison results.
// ofstream creates or replaces the report file.
void saveResults(const vector<string>& colors) {
    ofstream outputFile("color_results.txt");

    if (!outputFile.is_open()) {
        cout << "Error: Could not open color_results.txt for writing.\n";
        return;
    }

    outputFile << "Color Compatibility Checker 2.0\n";
    outputFile << "Entered colors:\n";

    for (int i = 0; i < static_cast<int>(colors.size()); i++) {
        outputFile << i + 1 << ". " << colors[i] << "\n";
    }

    displayResults(colors, outputFile);

    outputFile.close();

    cout << "Results saved to color_results.txt\n";
    cout << "Note: Saving again will replace the previous report.\n";
}
