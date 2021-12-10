/**
* file: Line.h
* lab: Slope - Intercept Project
* by: Ragy costa de jesus
* org: COP2001, 202102, 10410
* desc: declaration of a Line class object
* --------------------------------------------------------
*/

#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line{
    public:
    //Constructor
    Line();
    Line(Point firstCoor, Point secondCoor, float slopeP );


    //Accessor
    //Getters
    Point getFirstCoordinate();
    Point getSecondCoordinate();
    float getSlopePoint();

    //Setters
    void setFirstCoordinate( Point value);
    void setSecondCoordinate(Point value);
    void setSlopePoint(float value);

    //Member Methods
    float calcDiffX();
    float calcDiffY();
    float calcSlope();
    float calcYInt();
    float calcLength();
    float calcAngle();


    private:
    Point firstCoordinate;
    Point secondCoordinate;
    float slopePoint;
};

#endif //LINE_H
