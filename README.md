# Color Compatibility Checker

## Description

**version 1.0**

This program serves as an interactive color vision checking tool designed to evaluate accessibility between color pairs. It allows users to input two color names and choose a specific test to run. The program can analyze whether the chosen pair represents a contrast issue or creates potential readibility challenges for indiviuals with red-green color blindness. By running in a continuous loop, it enables designers and users to quickly evaluate multiple color combinations in a single session.

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
Enter color 1: red
Enter color 2: green

1. Check for red-green color issue
2. Check for same color

Enter choice (1 or 2): 1
Warning: Red and green are hard to tell apart!

Test another pair? (y/n): n

Done!
```