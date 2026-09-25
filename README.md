# Color Compatibility Checker

## Description

**version 1.0**

This program serves as an interactive color vision checking tool designed to evaluate accessibility between color pairs. It allows users to input two color names and choose a specific test to run. The program can analyze whether the chosen pair represents a contrast issue or creates potential readability challenges for individuals with red-green color blindness. By running in a continuous loop, it enables designers and users to quickly evaluate multiple color combinations in a single session.

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

Warning: Red and green are hard to tell apart for red-green type color blindness!

Test another pair? (y/n): n

Done!
```