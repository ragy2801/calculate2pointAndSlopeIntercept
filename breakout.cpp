/**
 * file: breakout.cpp
 * lab: Slope- Intercept
 * by: Ragy costa de jesus
 * org: COP2001, 202104, 10410
 * desc: main application file that permits user to convert either two-point form or point-slope from into intercept form.
 * --------------------------------------------------------
 */

#include <iostream>     //library for keyboard input

#include "fgcugl.h"     //fgcu library for OpenGl

#include <string>       //window title

#include <math.h>       //calculating formulas

#include <iomanip>      //set precision functions

#define _USE_MATH_DEFINES  //PI

//global constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string WINDOW_TITLE = "Slope - Intercept Project";


//enum
enum Mode {TWO_POINT = 1 , POINT_SLOPE, EXIT};

//structures
struct Point {          //structure property for X and Y coordinates.
    float coordinateX;
    float coordinateY;
};

struct Line {           //structure to graph the line
    Point firstCoordinate;
    Point secondCoordinate;
    float slope;
    float interceptY;
    float length;
    float angle;
};

//functions prototypes
Mode getProblem();     //get user input and return
Point getPoint();
void  get2Point(Line &line);
void getPointSlope(Line &line);
void calcLine (Mode mode, Line &line);


//methods
float slopeFrom2Point (Line &line);
float slopeIntercept(Line slope);
float lineLenght (Line line);
float lineAngle (Line line);

//display methods
void displayLine (Line line);
void display2pt (Line line);
void displayPointSlope (Line line);
void displaySlopeIntercept (Line line);
void drawLine (Line line);


int main() {

    Line line;
    Mode form;


        bool check = false;

    while (!check){
        //calling the functions to get the user input
        form = getProblem();

        if(form == TWO_POINT)
        {
            get2Point(line);
            calcLine(form, line);
            displayLine(line);
            display2pt(line);
            displaySlopeIntercept(line);
            drawLine(line);
        }
        else if (form == POINT_SLOPE) {
            getPointSlope(line);
            calcLine(form, line);
            displayLine(line);
            displayPointSlope(line);
            displaySlopeIntercept(line);
            drawLine(line);
        }
        else  {
            check = true;
            }
        }



    return 0;
}   //end of main


/**
 Get user keyboard input

 Parameters:

 return:
    Mode        enum variable to for the user choice

*/
Mode getProblem()
{
    int userInput;

    // outputs directions for user
    std:: cout << "Select the form you would like to convert to slope- intercept form: \n";
    std:: cout << "\t 1) Two - point form (you know the two points of the line\n";
    std:: cout << "\t 2) Point - slope form (you know the line's slope and one point)\n";
    std:: cout << "\t 3) exit" << std::endl;

    //input of user to decide which form will be used
    std:: cin >>  userInput;

    if(userInput == TWO_POINT)
    {
        return TWO_POINT;
    }
    else if (userInput == POINT_SLOPE)
    {
        return POINT_SLOPE;
    }
    else
    {
        return EXIT;
    }


}       //end of the getProblem function

/**
 Get user input from coordinates X and Y and return as Point Structure

 Parameters:

 Return;
    Point      //variable Point Structure
*/
Point getPoint()
{
    Point point;

    float firstCoordinateX, firstCoordinateY;

    //first coordinates outputs
    std:: cout << "\nEnter the first points:" << std:: endl;
    std:: cout << "Enter X and Y coordinates separated by spaces: ";

    //first coordinates inputs
    std:: cin >> firstCoordinateX >> firstCoordinateY;

    point.coordinateX = firstCoordinateX;
    point.coordinateY = firstCoordinateY;

    return point;
}       //end of getPoint function

/**
 Populate the two points of the line

 Parameters:
    Line        //Line structure

 Return;

*/

void  get2Point(Line &line)
{
    line.firstCoordinate = getPoint();
    line.secondCoordinate = getPoint();

    return;
}       // end of get2Point function

/**
 Populate the point and slope of the line

 Parameters:
    Line        //Line structure

 Return;

*/
void getPointSlope(Line &line)
{
    float slope;

    line.firstCoordinate = getPoint();

    //output for user to input the slope
    std:: cout << "Enter slope value: ";
    std:: cin >> slope;

    line.slope = slope;

    return;
}


/**
  Calculate the line

  Parameters:

  Return:

*/
void calcLine (Mode mode, Line &line)
{


    //TWO-POINT
    if(mode == TWO_POINT)
    {
        line.slope = slopeFrom2Point(line);
        line.interceptY = slopeIntercept(line);
    }

    //POINT-SLOPE
    else if(mode == POINT_SLOPE)
    {
        line.secondCoordinate.coordinateX = 0.0;
        line.interceptY = slopeIntercept(line);
        line.secondCoordinate.coordinateY = line.interceptY;
    }

    line.length = lineLenght(line);     //insert the float variable into the Line structure property length
    line.angle = lineAngle(line);       //insert float variable into Line structure property angle.

    return;
}       //end of calcLine function

/**
 Calculate slope from two points

 Parameters:

 returns:
    float       slope of the line with two points
 */
float slopeFrom2Point (Line &line)
{


    float slope = (line.secondCoordinate.coordinateY - line.firstCoordinate.coordinateY) / (line.secondCoordinate.coordinateX - line.firstCoordinate.coordinateX);

    return slope;
}       //end of slopeFrom2Point method

/**
 Calculate y-intercept

 Parameters:
    Point p      structure Point coordinates x and y
    Line slope   structure Line slope

 returns:
    float        slope of the line with two points
 */
float slopeIntercept(Line slope)
{
     float interceptY;
     interceptY = slope.firstCoordinate.coordinateY - (slope.slope * slope.firstCoordinate.coordinateX);

     return interceptY;
}       //end of the slopeIntercept method

/**
 Takes the line and return the distance between two points.

 Parameters:

 returns:
    float        distance between two points.
 */
 float lineLenght (Line line)
{
     float distance;

     distance = sqrt( pow((line.secondCoordinate.coordinateX - line.firstCoordinate.coordinateX),2) + pow((line.secondCoordinate.coordinateY - line.firstCoordinate.coordinateY),2) );

    return distance;
}       //end of lineLength method

/**
 Takes the line and returns the line angle from the top Y axis or zero degrees as a float.

 Parameters:

 returns:
    float        distance between two points.
 */
 float lineAngle (Line line)
{
     float angle;

     angle = fmod((90.0 - (atan((line.secondCoordinate.coordinateY - line.firstCoordinate.coordinateY) / (line.secondCoordinate.coordinateX - line.firstCoordinate.coordinateX))* (180.0 / M_PI)) ), 360.0);
                        //fmod function has the numerator and the denominator as param-list and returns the answer of the divisor.
     return angle;
}       //end of lineAngle method

/**
 Display the line on the screen

 Parameters:

 returns:

 */
 void displayLine(Line line)
{

     //display of the line numbers
     std:: cout <<std::fixed << std::setprecision(0) <<  "Line:" << std:: endl;
     std:: cout << "\tPoint 1  (" << line.firstCoordinate.coordinateX << ", " << line.firstCoordinate.coordinateY << ")" << std::endl;
     std:: cout << "\tPoint 2  (" << line.secondCoordinate.coordinateX << ", " << line.secondCoordinate.coordinateY << ")" << std::endl;
     std:: cout << "\t  Slope = " << std::setprecision(1) << line.slope << std::endl;
     std:: cout << "\tY-Intcpt = " << std::setprecision(0) << line.interceptY << std::endl;
     std:: cout << "\t Length = " << line.length << std::endl;
     std:: cout << "\t  Angle = " << line.angle << std:: endl;

     return ;
}       // end of the displayLine numbers method

/**
 Display the numbers of a two point slope

 Parameters:

 returns:

 */
void display2pt (Line line)
{


    //display of the 2 point slope numbers
    std:: cout << std::fixed << std::setprecision(0) <<"Two-Point form:" << std:: endl;
    std:: cout << "\t\t(" << line.secondCoordinate.coordinateY << " - " << line.firstCoordinate.coordinateY << ")" << std:: endl;
    std:: cout << "\tm = ---------------" << std:: endl;
    std:: cout << "\t\t(" << line.secondCoordinate.coordinateX << " - " << line.firstCoordinate.coordinateX << ")" << std:: endl;


    return;
}       //end of display2pt method


/**
 Display the coordinate and slope for a point slope form

 Parameters:

 returns:

 */
 void displayPointSlope (Line line)
{

     //display the the point slope form
     std:: cout <<"Point - Slope form:" << std:: endl;
     std:: cout << "\ty - " << line.firstCoordinate.coordinateY << " = " << std::setprecision(1) << line.slope << std::setprecision(0) << "(x - " << line.firstCoordinate.coordinateX << ")\n" ;

     return ;
}       //end of the displayPointSlope method


/**
 Display the slope intercept

 Parameters:

 returns:

 */
 void displaySlopeIntercept (Line line)
{

     //out the the slope intercept form
     std:: cout << "Slope-intercept form:" << std:: endl;
     std:: cout << "\ty = " << std::setprecision(1) << line.slope << "x + " << std::setprecision(1) << line.interceptY << std:: endl;

     return;
}       //end of the displaySLopeIntercept method


/**
 Draw the line in a graph

 Parameters:

 returns:

 */
void drawLine (Line line)
{

    //open the window
    fgcugl:: openWindow(WINDOW_WIDTH,WINDOW_HEIGHT, WINDOW_TITLE, false);

    while (!fgcugl::windowClosing())
    {
        //draw x and y axis
        fgcugl::drawLine(0 , WINDOW_HEIGHT/2 , WINDOW_WIDTH, WINDOW_HEIGHT/2);
        fgcugl::drawLine(WINDOW_HEIGHT/2 , 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);


        //draw the slope intercept form line
        fgcugl:: drawLine(line.firstCoordinate.coordinateX + (WINDOW_WIDTH / 2), line.firstCoordinate.coordinateY + (WINDOW_HEIGHT /2), line.secondCoordinate.coordinateX + (WINDOW_WIDTH /2), line.secondCoordinate.coordinateY + (WINDOW_HEIGHT /2));

        fgcugl:: windowPaint();

        fgcugl:: getEvents();
    }

    fgcugl:: cleanup();
}