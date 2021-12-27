/*
 * GraphicObject.h
 *
 *  Created on: Dec 4, 2021
 *      Author: max
 */

#ifndef GRAPHICOBJECT_H_
#define GRAPHICOBJECT_H_


class GraphicObject {
public:
	virtual ~GraphicObject() { }
	virtual void paint() = 0;
	virtual bool is_in(int x, int y) const = 0;
};

class Square : public GraphicObject {
public:
	Square(int x, int y, int width) : _x(x), _y(y), _width(width) {};
	void paint() override;
	bool is_in(int x, int y) const override;
protected:
	int _x, _y, _width;
};

class Circle : public GraphicObject {
public:
	Circle(int x, int y, int r): center_x(x), center_y(y), radius(r) {}
	void paint() override;
	bool is_in(int x, int y) const override;
protected:
	int center_x, center_y, radius;
};

class Rectangle : public GraphicObject {
public:
	Rectangle (int x, int y, int heigth, int length) : _x(x), _y(y), _heigth(heigth), _length(length) {}
	void paint() override;
	bool is_in(int x, int y) const override;
private:
	int _x;
	int _y;
	int _heigth;
	int _length;
};


#endif /* GRAPHICOBJECT_H_ */
