/**
* file: Point.h
* lab: Slope - Intercept Project
* by: Ragy costa de jesus
* org: COP2001, 202102, 10410
* desc: declaration of a Line class object
* --------------------------------------------------------
*/

#ifndef POINT_H
#define POINT_H


class Point {
public:
    //constructor
    Point();
    Point(float x, float y);

    //accessors
    //getters
    float getXCoordinate();
    float getYCoordinate();

    //setters
    void setXCoordinate( float value);
    void setYcoordinate( float value);

    //member methods

private:
    float coorX;
    float coorY;

};


#endif //POINT_H
