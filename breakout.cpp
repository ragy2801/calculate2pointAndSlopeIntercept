/**
 * file: breakout.cpp
 * lab: Slope- Intercept
 * by: Ragy costa de jesus
 * org: COP2001, 202104, 10410
 * desc: main application file that permits user to convert either two-point form or point-slope from into intercept form.
 * --------------------------------------------------------
 */

#include <string>       //window title

#include <iostream>     //library for keyboard input

#include <math.h>       //calculating formulas

#include <iomanip>      //set precision functions

#define _USE_MATH_DEFINES  //PI

#include "fgcugl.h"     //fgcu library for OpenGl

#include "Line.h"       // Line class

#include "Point.h"      //Point class

//global constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string WINDOW_TITLE = "Slope - Intercept Project";


//enum
enum Mode {TWO_POINT = 1 , POINT_SLOPE, EXIT};


//functions prototypes
Mode getProblem();     //get user input and return
Point getPoint();
void  get2Point(Line& line);
void getPointSlope(Line& line);
void calcLine (Mode mode, Line &line);

//display methods
void displayLine (Line line);
void display2pt (Line line);
void displayPointSlope (Line line);
void displaySlopeIntercept (Line line);
void drawLine (Line line);


int main() {

    Mode form;


    //creat a Line object
    Point firstCoor;
    Point secondCoor;
    float slope;
    Line line = Line( firstCoor, secondCoor, slope);


    bool check = false;

    while (!check){
        //calling the functions to get the user input
        form = getProblem();

        if(form == TWO_POINT)
        {
            //display user input for two point
            get2Point(line);

            calcLine(form, line);

            //display Line and outputs
            displayLine(line);
            display2pt(line);
            displaySlopeIntercept(line);
            drawLine(line);
        }
        else if (form == POINT_SLOPE) {

            //display user input for two point

            getPointSlope(line);

            calcLine(form, line);


            //display Line and outputs
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
    //crete point object
    float coordinateX;
    float coordinateY;
    Point point = Point(coordinateX, coordinateY);

    //first coordinates outputs
    std:: cout << "\nEnter the first points:" << std:: endl;
    std:: cout << "Enter X and Y coordinates separated by spaces: ";

    //first coordinates inputs
    std:: cin >> coordinateX  >> coordinateY;

    point.setXCoordinate(coordinateX);
    point.setYcoordinate(coordinateY);


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
    line.setFirstCoordinate(getPoint()) ;

    line.setSecondCoordinate(getPoint());

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

    line.setFirstCoordinate(getPoint());


    //output for user to input the slope
    std:: cout << "Enter slope value: ";
    std:: cin >> slope;



    line.setSlopePoint(slope);

    return;
}


/**
 Display the line on the screen

 Parameters:

 returns:

 */

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
        line.calcSlope();
        line.calcYInt();
    }

        //POINT-SLOPE
    else if(mode == POINT_SLOPE)
    {
        //set thee Y second coordinate to the Y-intercept
        line.calcYInt();
        line.setSecondCoordinate(Point(0.0, line.calcYInt()));
    }


    return;
}       //end of calcLine function
void displayLine(Line line)
{

    //display of the line numbers
    std:: cout <<std::fixed << std::setprecision(0) <<  "Line:" << std:: endl;

    std:: cout << "\tPoint 1  (" << line.getFirstCoordinate().getXCoordinate()
    << ", " << line.getFirstCoordinate().getYCoordinate() << ")" << std::endl;

    std:: cout << "\tPoint 2  (" << line.getSecondCoordinate().getXCoordinate() << ", "
    << line.getSecondCoordinate().getYCoordinate() << ")" << std::endl;

    std:: cout << "\t  Slope = " << std::setprecision(1) << line.calcSlope() << std::endl;
    std:: cout << "\tY-Intcpt = " << std::setprecision(0) << line.calcYInt() << std::endl;
    std:: cout << "\t Length = " << line.calcLength() << std::endl;
    std:: cout << "\t  Angle = " << line.calcAngle() << std:: endl;

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
    std:: cout << "\t\t(" << line.getSecondCoordinate().getYCoordinate() << " - " << line.getFirstCoordinate().getYCoordinate() << ")" << std:: endl;
    std:: cout << "\tm = ---------------" << std:: endl;
    std:: cout << "\t\t(" << line.getSecondCoordinate().getXCoordinate() << " - " << line.getFirstCoordinate().getXCoordinate() << ")" << std:: endl;


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
    std:: cout << "\ty - " << line.getFirstCoordinate().getYCoordinate() << " = " << std::setprecision(1) << line.calcSlope() << std::setprecision(0) << "(x - " << line.getFirstCoordinate().getXCoordinate() << ")\n" ;

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
    std:: cout << "\ty = " << std::setprecision(1) << line.calcSlope() << "x + " << std::setprecision(1) << line.calcYInt() << std:: endl;

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
        fgcugl:: drawLine(line.getFirstCoordinate().getXCoordinate() + (WINDOW_WIDTH / 2),
                          line.getFirstCoordinate().getYCoordinate() + (WINDOW_HEIGHT /2),
                          line.getSecondCoordinate().getXCoordinate() + (WINDOW_WIDTH /2),
                          line.getSecondCoordinate().getYCoordinate() + (WINDOW_HEIGHT /2));

        fgcugl:: windowPaint();

        fgcugl:: getEvents();
    }

    fgcugl:: cleanup();
}
