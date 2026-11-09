# Color Compatibility Checker

## Description

**version 1.0**

This program serves as an interactive color vision checking tool designed to evaluate accessibility between color pairs. It allows users to input two color names and choose a specific test to run. The program can analyze whether the chosen pair represents a contrast issue or creates potential readability challenges for individuals with red-green color blindness. By running in a continuous loop, it enables designers and users to quickly evaluate multiple color combinations in a single session.

**version 2.0**

Version 2.0 improves the Color Compatibility Checker by allowing users to enter custom hexadecimal color codes instead of selecting from eight predetermined colors. Users can now enter between 2 and 20 colors, and the program automatically compares every possible pair.

New Features

Hex Codes: Users enter colors using hex codes such as #FF0000. Invalid codes are rejected.

Multiple Colors: Users choose how many colors to enter. Typing Q allows them to stop early without losing previously entered colors.

Contrast Checking: The program calculates contrast ratios and evaluates whether combinations meet WCAG AA text contrast requirements.

Duplicate Detection: Checks whether the same color was entered multiple times.

Saving Results: Users can save their colors and comparison results to color_results.txt, which the program creates automatically.

New C++ Concepts

Vectors: A vector<string> stores the user's hex codes.

Functions: Six functions handle input validation, collecting colors, calculating luminance and contrast, displaying results, and saving results.

Parameters: Pass-by-value is used to examine individual hex codes, while pass-by-reference allows functions to access or modify the original vector.

Return Types: Functions use bool, double, and void.

File I/O: ofstream writes the results to a text file.

Loops and Decisions: Loops collect and compare colors, while conditional statements validate input and evaluate results.

Improvements

Version 1.0 only warned users about red-green combinations. Version 2.0 replaces this limited check with numerical contrast calculations and improves input validation. However, contrast calculations do not directly determine whether colors are distinguishable to people with colorblindness.

## Developer

Zoë Stiefel

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
**version 1.0**
Welcome! This is the Color Compatibility Checker specifically geared for detecting a color pair's compatibility with red-green color blindness.
Here are the colors you may choose from:
1.Red
2.Orange
3.Yellow
4.Green
5.Blue
6.Indigo
7.Violet
8.Pink

Enter color 1 (1-8):
1
Enter color 2 (1-8):
4

1. Check for compatibility of color pair for red-green color blindness
2. Check for same color

Enter choice (1 or 2):
1
**version 2.0**
How many colors would you like to test (2-20)? 5

Enter hex code for color 1: #FF0000
Enter hex code for color 2: #00FF00
Enter hex code for color 3: #0000FF
Enter hex code for color 4: q

Color entry finished. 3 colors saved.

1. Compare all color pairs
2. Check for duplicate colors
3. Save results to a file
4. Finish this set

Enter choice (1-4): 1

Color contrast results:
#FF0000 and #00FF00: 2.91:1
#FF0000 and #0000FF: 2.15:1
#00FF00 and #0000FF: 6.26:1

Warning: Red and green are hard to tell apart for red-green type color blindness!

Test another pair? (y/n): n

Done!
```
