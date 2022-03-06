//**********************************************************************
//*                                                                    *
//* Program Name: PROG01 - Draw a picture and print the specifications *
//*                        of a rectangele.                            *
//* Author:       Alex Feng                                            *
//* Installation: Pensacola Christian College, Pensacola               *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: January 31, 2020                                     *
//*                                                                    *
//**********************************************************************

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy any work from the Internet. */
/* I pledge the only person I asked for help from was my teacher.     */
/* I pledge I did not attempt to help any student on this assignment. */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

//**********************************************************************
//*                                                                    *
//* This program ask for length and width of the rectangle, draw a     *
//* picture of it, and print the specifications of the rectangle.      *
//* and the inclusive sum of all integers in the range.                *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER   "CS246" // PCC assigned course number
#define COURSE_NAME     "Object-Oriented Programming and Design"
                                // PCC assigned course name
#define MIN_RECT_LENGTH 1       // Minimum rectangle length
#define MIN_RECT_WIDTH  1       // Minimum rectangle width
#define PROGRAM_NUMBER  1       // Teacher assigned program number
#define RECT_BORDER     "*"     // Rectangle's border symbol
#define RECT_CENTER     " "     // Rectangle's center filling
#define SCALE_FACTOR    1.5     // Scale factor for the specifications

//**********************************************************************
//*                         Program Structure                          *
//**********************************************************************
// Contains the specifications of the rectangle
struct rectangle
{
   float area,      // Area of the rectangle
         length,    // Length of the rectangle
         perimeter, // Perimeter of the rectangle
         width;     // Width of the rectangle
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_rectangle(rectangle *rectangle);
   // Get the rectangle's specifications
void draw_rectangle(float length, float width);
   // Draw the rectangle with the given specifications
void print_rectangle_specs(float length, float width,
                           float area, float perimeter);
   // Print the rectangle specifications

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   rectangle rectangle; // Create a rectangle structure

   // Print the program heading
   print_heading();
   
   // Get rectangle's length and width
   get_rectangle(&rectangle);

   // Draw the rectangle and print the specifications of the rectangle
   draw_rectangle(rectangle.length, rectangle.width);
   print_rectangle_specs(rectangle.length, rectangle.width,
                         rectangle.area,   rectangle.perimeter);

   // Print goodbye message and exit the program
   cout << "\n\nThanks for drawing a rectangle today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                       Print program heading                        *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n        " << COURSE_NUMBER << " "
        << COURSE_NAME " - Program " << PROGRAM_NUMBER;
   cout << "\n\n                     This program draws a rectangle";
   cout <<   "\n                     ==============================";
   cout << "\n\n\n";
   return;
}

//**********************************************************************
//*             Get the length and with of the rectangle               *
//**********************************************************************
void get_rectangle(rectangle *rectangle)
{
   cout << "Enter the rectangle length now: ";
   cin  >> rectangle->length;
   cout << "Enter the rectangle width here: ";
   cin  >> rectangle->width;
   rectangle->area      = rectangle->length * rectangle->width;
   rectangle->perimeter = 2 * (rectangle->length + rectangle->width);
   return;
}

//**********************************************************************
//*         Draw the rectangle with the given specifications           *
//**********************************************************************
void draw_rectangle(float length, float width)
{
   int   column,              // Column for the rectangle's border
         row,                 // Row for the rectangle's border
         int_length, // Length as an integer value
         int_width;  // Width as an integer value

   // Check if length or width is less than the minimum requirement
   if (length < MIN_RECT_LENGTH || width < MIN_RECT_WIDTH)
   {
      cout << "\nA " << length << " by " << width << " rectangle"
           << " is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_LENGTH << " by "
           << MIN_RECT_WIDTH << " (length by width)";
   }
   else
   {
      // Convert length from a float type to integer type
      int_length = (int) (length * SCALE_FACTOR);
      int_width  = (int) width;

      // Print the title
      cout << "\n\nHere is a picture of your rectangle:";
      cout << "\n";

      // Print the top row of the rectangle
      for (column = 0; column < int_length; column++)
         cout << RECT_BORDER;
      
      // Print the middle rows of the rectangle
      for (row = 0; row < int_width - 2; row++)
      {
         cout << "\n" << RECT_BORDER;
         
         for (column = 0; column < int_length - 2; column++)
            cout << RECT_CENTER;
         
         cout << RECT_BORDER;
      }

      // Print the bottom row of the rectangle
      if (int_width > 1)
      {
         cout << "\n";
         for (column = 0; column < int_length; column++)
            cout << RECT_BORDER;
      }
   }
   return;
}

//**********************************************************************
//*              Print the rectangle's specifications                  *
//**********************************************************************
void print_rectangle_specs(float length, float width,
                           float area,   float perimeter)
{
   cout << "\n\nThe rectangle specifications are:";
   cout <<   "\n        Length = " << length    << " units";
   cout <<   "\n         Width = " << width     << " units";
   cout <<   "\n          Area = " << area      << " sq. units";
   cout <<   "\n     Perimeter = " << perimeter << " units";
   return;
}