#ifndef NL_VERSION_H
#define NL_VERSION_H

#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int x1, int y1):x(x1), y(y1)
    {
        std::cout << "Point(int x1, int y1) Ctor." << std::endl;
    }
};

struct Line{
    Point start;
    Point end;
    Line():Line(Point(0,0), Point(100,100)){}
    Line(Point s, Point e):start(s), end(e){
        std::cout << "Line Ctor." << std::endl;
    }
};

struct Rect{
    Point start;
    int width;
    int height;
    Rect():Rect(Point(0, 0), 100, 100){}
    Rect(Point s, int w, int h):start(s),width(w),height(h) {
        std::cout << "Rect Ctor." << std::endl;
    }
};

// Consider we need add a new Circle class
// Change.01
struct Circle{
    Point center;
    int radius;
    Circle():Circle(Point(0, 0), 100){}
    Circle(Point o, int r):center(o), radius(r){
        std::cout << "Circle Ctor." << std::endl;
    }
};

class NLWindow
{
private:
    vector<Line*> lineVector;
    vector<Rect*> rectVector;
    vector<Circle*> circleVececor; // Add 02
public:
    void addShape()
    {
        lineVector.push_back(new Line);
        rectVector.push_back(new Rect);
        circleVececor.push_back(new Circle); // Add 03
    }
    void paintShape()
    {
        for(int i = 0; i < lineVector.size(); i++)
        {
            std::cout <<"call system api to draw lines" << std::endl;
        }
        for(int i = 0; i < rectVector.size(); i++)
        {
             std::cout <<"call system api to draw rects" << std::endl;
        }
        // Change & Add 04.
        for(int i = 0; i < circleVececor.size(); i++)
        {
            std::cout <<"call system api to draw circles" << std::endl;
        }
    }
};


#endif // NL_VERSION_H
