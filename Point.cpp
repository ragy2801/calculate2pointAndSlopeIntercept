/**
* file: Homwork_3
* by: Ragy costa de jesus
* org: COP3003
* desc: main source file to compute a line and with coordinates
* --------------------------------------------------------
*/

#include "Point.h"

#include "Line.h"

//constructor
/**
 * Default constructor - initialize empty Point to zero
 */
Point::Point()
{
    coorX = 0.0;
    coorY = 0.0;
}

/**
 * Default constructor - set values to Point
 */
Point::Point(float x, float y)
{
    coorX = x;
    coorY = y;
}

//accessors
//--------------------------------------------------------
//getters
float Point::getXCoordinate(){ return coorX;}
float Point::getYCoordinate(){ return coorY;}


//setters
void Point::setXCoordinate( float value){ coorX = value;}
void Point::setYcoordinate( float value){ coorY = value;}



//member methods
//--------------------------------------------------------
