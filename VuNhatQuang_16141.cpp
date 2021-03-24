#include<iostream>
#include <string>
#include <math.h>
using namespace std;

class BaseMath
{
private:
    bool isEven(int number)
        {
            if (number % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
public:
    BaseMath()
    {}
    double factorial(int n)
    {
        double sol = 1;
        for (int i = 1; i <= n; i++)
        {
            sol *= i;
        }
        return sol;
    }
};

class AdvancedMath : public BaseMath
{
public:
    AdvancedMath()
    {}
    double EulerNumber(int loops)
    {
        double e = 1.0;
        for (int i = 1; i <= loops; i++)
        {
            e += 1.0/factorial(i);
        }
        return e;
    }
};


class Point
{
private:
    float x;
    float y;
public:
    Point()
    {}
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    int get_x()
    {
        return this->x;
    }
    int get_y()
    {
        return this->y;
    }
};


class Shape : private Point
{
protected:
    Point coordinate;
public:
    Shape()
    {}
    void update(float x, float y)
    {
        Point shapepoint(x,y);
        this->coordinate = shapepoint;
    }
    virtual float ComputeArea() = 0;
    virtual float ComputeCircumference() =0;
};

class Circle : public Shape
{
private:
    float r;
public:
    Circle()
    {}
    Circle(float x, float y, float r)
    {
        this->r = r;
        update(x,y);
    }
    float ComputeArea()
    {
        return 2.0 * 3.14 * this->r * this->r;
    }
    float ComputeCircumference()
    {
        return 2.0 * 3.14 * this->r;
    }
};

class Square : public Shape
{
private:
    float side;
public:
    Square()
    {}
    Square(float x, float y, float side)
    {
        this->side = side;
        update(x,y);
    }
    float ComputeArea()
    {
        return this->side * this->side;
    }
    float ComputeCircumference()
    {
        return this->side * 4.0;
    }
};

class Rectangle : public Shape
{
private:
    float w;
    float h;
public:
    Rectangle()
    {}
    Rectangle(float x, float y, float w, float h)
    {
        this->h = h;
        this->w = w;
        update(x,y);
    }
    float ComputeArea()
    {
        return this->h * this->w;
    }
    float ComputeCircumference()
    {
        return 2 * (this->h + this->w);
    }
};


int main()
{
    Shape* r = new Circle(1.54,1.25,2.5);
    //Shape* s = new Square(2.5,3.4,4.44);
    //Shape* h = new Rectangle(1.2,2.8,3,4.5);
    cout << r->ComputeArea() << endl;
    cout << r->ComputeCircumference() << endl;
    //cout << s->ComputeArea() << endl;
    //cout << h->ComputeArea() << endl;
    //delete s;
    //delete h;
    delete r;
    return 0;
}