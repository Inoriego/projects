//**********************************************************************
//*                                                                    *
//* Program Name: PROG02 - This program calculates geometric area and  *
//*                        volumn                                      *
//* Author:       Alex Feng                                            *
//* Installation: Pensacola Christian College, Pensacola               *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 12, 2020                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge this assignment is my own first time work.                *
//* I pledge I did not copy or try to copy any work from the Internet. *
//* I pledge the only person I asked for help from was my teacher.     *
//* I pledge I did not attempt to help any student on this assignment. *
//* I understand if I violate this pledge I will receive a 0 grade.    *
//*                                                                    *
//*                                                                    *
//*                      Signed: _____________________________________ *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program asks for a diamater, a rectangle length, a rectangle  * 
//* width, a rectangle height, and calculates the geometric shape      *
//* areas and volumn.                                                  *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER   "CS246"   // PCC assigned course number
#define COURSE_NAME     "Object-Oriented Programming and Design"
                                  // PCC assigned course name
#define PI              3.141593f // Mathematical constant PI
#define PROGRAM_NUMBER  2         // Teacher assigned program number

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_dimensions(float *p_diameter, float *p_depth, float *p_length, 
                    float *p_width);
   // Get the geometric shape dimensions
void calculate(float diameter);
   // Calculate the circle's area
void calculate(float length, float width);
   // Calculate the rectangle's area
void calculate(float depth, float length, float width);
   // Calculate the rectangular solid's volumn

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   float diameter, // Diameter of the circle
         depth,    // Depth of the rectangle
         length,   // Length of trhe rectangle
         width;    // Width of the rectangle

   // Print the program heading
   print_heading();

   // Get the dimensions of the geometric shapes
   get_dimensions(&diameter, &depth, &length, &width);

   // Calculate and print the areas and volumn of the geometric shapes
   cout << "\n\nHere are the requested areas and volume:";
   cout <<   "\n----------------------------------------";
   calculate(diameter);
   calculate(length, width);
   calculate(depth, length, width);

   // Print a goodbye message and exit the program
   cout << "\n\n\nThanks for calculating geometric shapes today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                       Print program heading                        *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n";
   cout << COURSE_NUMBER << " " << COURSE_NAME << " - Program "
        << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\n       Calculate geometric shape areas and volume";
   return;
}

//**********************************************************************
//*                Get the geometric shape dimensions                  *
//**********************************************************************
void get_dimensions(float *p_diameter, float *p_depth, float *p_length,
   float* p_width)
{
   cout << "\n\n\nEnter the geometric shape dimensions as follows:";
   cout <<     "\n    Circle diameter: ";
   cin  >> *p_diameter;
   cout <<       "   Rectangle length: ";
   cin  >> *p_length;
   cout <<       "    Rectangle width: ";
   cin  >> *p_width;
   cout <<       "    Rectangle depth: ";
   cin  >> *p_depth;
   return;
}

//**********************************************************************
//*                     Calculate the circle's area                    *
//**********************************************************************
void calculate(float diameter)
{
   cout << "\nArea of a circle with diameter " << diameter;
   cout << "\n   " << (diameter * diameter * PI) * 0.25f
        << " square units";
   return;
}

//**********************************************************************
//*                   Calculate the rectangle's area                   *
//**********************************************************************
void calculate(float length, float width)
{
   cout << "\nArea of a rectangle of length " << length 
        <<                       " by width " << width  
        <<                                ":";
   cout << "\n   " << length * width << " square units";
   return;
}

//**********************************************************************
//*             Calculate the rectangular solid's volumn               *
//**********************************************************************
void calculate(float depth, float length, float width)
{
   cout << "\nVolume of a rectangular solid of length " << length
        <<                                    " width " << width
        <<                                    " depth " << depth
        <<                                          ":";
   cout << "\n   " << length * width * depth
        << " cubic units";
   return;
}