#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <math.h>

using namespace std;
using namespace Graph_lib;

struct Smiley : public Graph_lib::Circle {
	using Circle::Circle; // base constructor 


	void draw_lines() const
	{
		//circle fill color && outline
		Circle::draw_lines();

		const int halfR = radius() / 2;
		//eyes
		if (fill_color().visibility())
		{
			const int eyeR = (radius() / 10) * 2;	//eyes are 20% the size of the radius

			fl_color(Color::black);
			fl_pie(point(0).x + halfR, point(0).y + halfR, eyeR, eyeR, 0, 360);
			fl_pie(point(0).x + radius() + halfR - eyeR, point(0).y + halfR, eyeR, eyeR, 0, 360);
			fl_color(color().as_int());	// reset color
		}

		//mouth
		if (color().visibility())
		{
			const int mouthR = radius();
			fl_color(Color::black);
			fl_arc(point(0).x + halfR, point(0).y + halfR, mouthR, mouthR, 180, 360);
		}
	}


	void draw_lines_Mine() const {
		Circle::draw_lines();

		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, mouthRadius + mouthRadius - 1, mouthRadius + mouthRadius - 1, 0, 360);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x + center().x, point(0).y, mouthRadius + mouthRadius, mouthRadius + mouthRadius, 0, 360);
		}


	}
private:
	int mouthRadius = Circle::radius() / 3;
	int mouthPositionX = Circle::center().x;
	int mouthPositionY = Circle::center().y + Circle::radius() / 3;
};



struct Frowney : public Graph_lib::Circle {
	using Circle::Circle; // base constructor 


	void draw_lines() const
	{
		//circle fill color && outline
		Circle::draw_lines();

		const int halfR = radius() / 2;
		//eyes
		if (fill_color().visibility())
		{
			const int eyeR = (radius() / 10) * 2;	//eyes are 20% the size of the radius

			fl_color(Color::black);
			fl_pie(point(0).x + halfR, point(0).y + halfR, eyeR, eyeR, 0, 360);
			fl_pie(point(0).x + radius() + halfR - eyeR, point(0).y + halfR, eyeR, eyeR, 0, 360);
			fl_color(color().as_int());	// reset color
		}

		//mouth
		if (color().visibility())
		{
			const int mouthR = radius();
			fl_color(Color::black);
			fl_arc(point(0).x + halfR, point(0).y + radius(), mouthR, mouthR, 0, 180);
		}
	}




private:
	int mouthRadius = Circle::radius() / 3;
	int mouthPositionX = Circle::center().x;
	int mouthPositionY = Circle::center().y + Circle::radius() / 3;
};


// Abstract class
class B {
public:
	virtual void f() = 0; // pure virtual function
	virtual void g() = 0;
};


// Exercise 04
//	Define a class Immobile_Circle
//		Which is just like a Circle but can't be moved

class Immobile_Circle : public Graph_lib::Circle {
	using Circle::Circle;  // base constructor 

public:
	void move(int dx, int dy) override {
		cout << "Immobile_Circle are incapable of being moved" << endl;
	}


};

//Exercise05 
//	Define a Striped_rectangle where instead of fill, 
//		the rectangle is "filled" by drawing one-pixel-wide horizontal lines across the inside of the rectangle 
//			(say, draw every second line like that). 
//	You may have to play with the widwidth of lines and the line spacing to get the pattern you like


class Striped_rectangle : public Rectangle {
	using Rectangle::Rectangle; // use base constructor

public:
	void draw_lines() const override {
		int startX = point(0).x;
		int startY = point(0).y;

		int stripePx = 1;

		int numOfLines = (height() / stripePx) / 2;

		for (size_t i = 0; i < numOfLines; i++)
		{
			fl_color(fill_color().as_int());
			fl_line_style(Line_style::solid, stripePx);	//only set the line style for the fill
			fl_line(startX, startY, startX + width(), startY);
			startY += stripePx * 2;
		}

		if (color().visibility()) {	// edge on top of fill
			fl_color(color().as_int());
			fl_rect(point(0).x, point(0).y, Rectangle::width(), Rectangle::height());
		}

	}


};
#define PI 3.14159265

int calcXonCircle(int radius, int angle) {
	int result = radius * std::cos(angle);
	return result;
}

int calcYonCircle(int radius, int angle) {
	int result = radius * std::cos(angle);
	return result;
}

class Striped_circle : public Circle {
	using Circle::Circle; // use base constructor

public:
	void draw_lines() const override {

		int centerX = center().x;
		int centerY = center().y;
		int startX = center().x;
		int Y = center().y - Circle::radius();

		int endX = center().x;


		int stripePx = 1;

		int numOfLines = Circle::radius();

		if (fill_color().visibility()) {	// fill
			size_t j = 0;
			for (size_t i = 0; i < numOfLines; i++)
			{
				fl_color(fill_color().as_int());
				fl_line_style(Line_style::solid, stripePx);	//only set the line style for the fill
				fl_line(startX - j * PI + j * PI / 2, Y, endX + j * PI - j * PI / 2, Y);
				Y += stripePx * 2;
				i < numOfLines / 2 ? j++ : j--;

			}

			if (color().visibility()) {
				fl_color(color().as_int());
				fl_arc(point(0).x, point(0).y, Circle::radius() + Circle::radius(), Circle::radius() + Circle::radius(), 0, 360);
			}





			//for (size_t i = 0; numOfLines > 0; i--)
			//{
			//	fl_color(fill_color().as_int());
			//	fl_line_style(Line_style::solid, stripePx);	//only set the line style for the fill
			//	fl_line(startX - i * PI, Y, endX + i * PI, Y);
			//	Y += stripePx * 2;
			//}

			//fl_color(fill_color().as_int());
			//fl_pie(point(0).x, point(0).y, Circle::radius() + Circle::radius() - 1, Circle::radius() + Circle::radius()  - 1, 0, 360);
			//fl_color(color().as_int());	// reset color
		}






		//Old - non horizontal lines 
		// Find a point
		//	// y = rsin(angle)
		//	// x = rcos(angle)
		//
		//for (size_t i = 0; i < 360; i++)
		//{
		//	fl_color(fill_color().as_int());
		//	fl_line_style(Line_style::solid, stripePx);	//only set the line style for the fill
		////	fl_line(startX, startY, startX+ calcXonxCircle(radius(), i), startY + calcYonCircle(radius(), i));
		//}



		//if (fill_color().visibility()) {	// fill
		//	fl_color(fill_color().as_int());
		//	fl_pie(point(0).x, point(0).y, 
		//		 Circle::radius() + Circle::radius() - 1, Circle::radius() + Circle::radius() - 1, 0, 360);
		//	fl_color(color().as_int());	// reset color
		//}

	/*	if (color().visibility()) {
			fl_color(color().as_int());
			Circle::radius() + Circle::radius() - 1, Circle::radius() + Circle::radius() - 1, 0, 360);
		*/
	}



};


class Striped_closed_polyline : public Closed_polyline {
	using Closed_polyline::Closed_polyline;

	void draw_lines() const override
	{
		if (fill_color().visibility()) {
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			for (int i = 0; i < number_of_points(); ++i) {
				fl_vertex(point(i).x, point(i).y);
			}
			fl_end_complex_polygon();
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility())
			Shape::draw_lines();

		if (color().visibility())	// draw closing line:
			fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
	}

};


int main() {
	int screenWidth = Fl::w();
	int screenHeight = Fl::h();

	Graph_lib::Simple_window win{ Graph_lib::Point{100,100},screenWidth,screenHeight, "Chapter 14 - Exercise 1" };


	//Exercise 01 define a Smiley and a Frowny
	Smiley smiley(Point{ 200,200 }, 100);
	smiley.set_color(Color::black);
	smiley.set_fill_color(Color::yellow);
	win.attach(smiley);


	Frowney frowny(Point{ 500,200 }, 100);
	frowny.set_color(Color::black);
	frowny.set_fill_color(Color::yellow);
	win.attach(frowny);

	//Exercise 02 - Try to copy a Shape
//	Graph_lib::Shape shape{(Graph_lib::Point{100,100}) }; // Initialize a shape 
	// ^^^Error error C2248: 'Graph_lib::Shape::Shape': cannot access protected member declared in class 'Graph_lib::Shape'

	// Copy constructor
//	Shape::Shape(frowny); //  error C2280: 'Graph_lib::Shape::Shape(const Graph_lib::Shape &)': attempting to reference a deleted function
	// ^^					message : 'Graph_lib::Shape::Shape(const Graph_lib::Shape &)': function was explicitly deleted

	// Define an abstract class and try to define an object of that type. What happens?
	//B b; // error C2259: 'B': cannot instantiate abstract class

	Immobile_Circle circle(Point{ 400,100 }, 100);
	circle.set_color(Color::red);
	win.attach(circle);


	Striped_rectangle rect(Point{ 300,300 }, 200, 200);
	rect.set_color(Color::blue);
	rect.set_fill_color(Color::blue);
	win.attach(rect);

	Striped_circle circle2(Point{ 530,530 }, 100);
	circle2.set_color(Color::blue);
	circle2.set_fill_color(Color::blue);
	win.attach(circle2);

	Striped_closed_polyline polys(Point{ 530,530 }, Point{ 530,530 }, Point{ 530,530 }, Point{ 530,530 })
	polys.set_color(Color::blue);
	polys.set_fill_color(Color::blue);
	win.attach(polys);



	win.wait_for_button();
	circle.move(24, 24);
	win.wait_for_button();
}