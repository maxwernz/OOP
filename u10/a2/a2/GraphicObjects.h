//
//  GraphicObjects.hpp
//  a2
//
//  Created by Maximilian Wernz on 20.09.22.
//

#ifndef GraphicObjects_h
#define GraphicObjects_h

#include <cmath>

class GraphicObject {
public:
    virtual ~GraphicObject() {}
    virtual void paint() = 0;
    virtual bool is_in(int x, int y) const = 0;
};

class Square : public GraphicObject {
    int m_x, m_y, m_width; //top left for x and y
public:
    Square(int x, int y, int width);
    void paint() override {};
    bool is_in(int x, int y) const override;
};

class Circle : public GraphicObject {
    int m_centerX, m_centerY, m_radius;
public:
    Circle(int x, int y, int r);
    void paint() override {};
    bool is_in(int x, int y) const override;
};

class Rectangle : public GraphicObject {
    int m_x, m_y, m_width, m_height;
public:
    Rectangle(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) {}
    void paint() override {};
    bool is_in(int x, int y) const override;
};

#endif /* GraphicObjects_h */
