#include <QCoreApplication>
#include <iostream>
using namespace std;
class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Point{
public:
    Point(){}
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
public:
    int x;
    int y;
};

class Line: public Shape{
public:
    Point start;
    Point end;

    Line(const Point& start, const Point& end){
        this->start = start;
        this->end = end;
    }

    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Line: I am drawing..." << std::endl;
    }

};

class Rect: public Shape{
public:
    Point leftUp;
    int width;
    int height;

    Rect(const Point& leftUp, int width, int height){
        this->leftUp = leftUp;
        this->width = width;
        this->height = height;
    }

    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Rect draw start." << std::endl;
    }
};

//增加
class Circle : public Shape{
public:
    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Circle: I am drawing..." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Shape *s = new Circle();
    Point p1(2,3);
    Point p2(3,4);
    Shape *r = new Line(p1, p2);
    r->draw();
    s->draw();
    return a.exec();
}
