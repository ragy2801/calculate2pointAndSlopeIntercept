/**
* file: Line.h
* lab: Slope - Intercept Project
* by: Ragy costa de jesus
* org: COP2001, 202102, 10410
* desc: declaration of a Line class object
* --------------------------------------------------------
*/

#include <math.h>      //math library for angle and length member methods

#include "Line.h"

#include "Point.h"

#define _USE_MATH_DEFINES  //PI


//Constructor
/**
 * Default constructor - initialize empty Point
 */
Line::Line()
{
    firstCoordinate ;
    secondCoordinate ;
    slopePoint = 0.0;
}

/**
 * Default constructor - initialize value to Point
 */
Line::Line(Point firstCoor, Point secondCoor, float slope )
{
    firstCoordinate = firstCoor;
    secondCoordinate = secondCoor;
    slopePoint= slope;
}


//Accessor
//--------------------------------------------------------
//Getters
Point Line::getFirstCoordinate(){ return firstCoordinate;}
Point Line::getSecondCoordinate(){ return secondCoordinate;}
float Line::getSlopePoint(){ return slopePoint;}

//Setters
void Line::setFirstCoordinate( Point value ){ firstCoordinate = value;}
void Line::setSecondCoordinate(Point value) {secondCoordinate = value;}
void Line::setSlopePoint( float value ){ slopePoint = value;}

//Member Methods
//--------------------------------------------------------

/**
 * calculate the difference between two X coordinate
 */
float Line::calcDiffX()
// subtract the second X coordinate from the first X coordinate to get the difference
{ return secondCoordinate.getXCoordinate() - firstCoordinate.getXCoordinate() ;}

/**
 * calculate the difference between two Y coordinate
 */
float Line::calcDiffY()
// subtract the second Y coordinate from the first Y coordinate to get the difference
{ return secondCoordinate.getYCoordinate() - firstCoordinate.getYCoordinate();}

/**
 * calculate the slope with diffX() and diffY()
 */
float Line::calcSlope()
{ slopePoint = calcDiffY() / calcDiffX();
    return slopePoint;
}

/**
 * calculate the Y-intercept with diffX() and diffY()
 */
float Line::calcYInt()
//calculate the y intercept
{
        return firstCoordinate.getYCoordinate() -
        (slopePoint * firstCoordinate.getXCoordinate());
}

/**
 * calculate the length of the line with diffX() and diffY()
 */
float Line::calcLength()
{return sqrt(pow(calcDiffX(),2) + pow(calcDiffY(), 2));}

/**
 * calculate the angle
 */
float Line::calcAngle()
{
    float radians = std::atan2(calcDiffY(),calcDiffX() );
    float angle = radians * 180.0 / M_PI;	// relative to X-axis
    float degrees = 90.0 - angle;				// rotate angle to left 90 degrees
    float cardinal =  (degrees > 0.0 ? degrees : degrees + 360.0);	// fix negative cardinal degrees

    return cardinal;
}