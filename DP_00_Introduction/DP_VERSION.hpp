#ifndef DP_VERSION_H
#define DP_VERSION_H
#include <iostream>
#include <vector>
namespace DP {
struct Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

struct Point{
    int x; int y;
    Point():x(0),y(0){}
    Point(int x1, int y1):x(x1), y(y1){ std::cout << "Point(int x1, int y1) Ctor." << std::endl;}
};

struct Line : public Shape{
    Point start;
    Point end;
    Line():Line(Point(0,0), Point(100,100)){}
    Line(const Point& start, const Point& end){
        this->start = start;
        this->end = end;
        std::cout << "Line(const Point& start, const Point& end) Ctor." << std::endl;
    }

    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Line: I am drawing..." << std::endl;
    }

};

struct Rect : public Shape{
    Point leftUp;
    int width;
    int height;
    Rect():Rect(Point(0, 0), 100, 100){}
    Rect(const Point& leftUp, int width, int height){
        this->leftUp = leftUp;
        this->width = width;
        this->height = height;
        std::cout << "LRect(const Point& leftUp, int width, int height) Ctor." << std::endl;
    }

    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Rect: I am drawing myself." << std::endl;
    }
};

//增加
struct Circle : public Shape{
    Point center;
    int radius;
    Circle():Circle(Point(0, 0), 100){}
    Circle(Point o, int r):center(o), radius(r){
        std::cout << "Circle Ctor." << std::endl;
    }
    //实现自己的Draw，负责画自己
    virtual void draw(){
        std::cout << "Circle: I am drawing myself." << std::endl;
    }
};

class DPWindow
{
private:
    std::vector<Shape*> m_shapes;
public:
    void addShape()
    {
        m_shapes.push_back(new Line);
        m_shapes.push_back(new Rect);
        m_shapes.push_back(new Circle); // Add 03
    }
    void paintShape()
    {
        for(__SIZE_TYPE__ i = 0; i < m_shapes.size(); i++)
        {
            m_shapes.at(i)->draw();
        }
    }
};
}


#endif // DP_VERSION_H
