#include "Simple_window.h"
#include "Graph.h"
#include "FL/fl_draw.H"

int main5() {
	using namespace Graph_lib; // appearantly not that useful for polygon

	Point tl{ 100,100 };	// the point we put our graphic  screen in relation to monitor screen NOT CMD window 
	Simple_window win{ tl, 600,400,"Canvas" };

	Graph_lib::Axis xa{ 
		Axis::x, //horizontal
		Point{20,300},  // starting at (20,300)
		280,			//280 pixels long
		10,				//10 "notches"
		"x axis"		// lbael the axis "x-axis"
	};


	Graph_lib::Axis ya{
			Axis::y, //horizontal
			Point{20,300},  // starting at (20,300)
			280,			//280 pixels long
			10,				//10 "notches"
			"y axis"		// lbael the axis "x-axis"
	};

	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas#3");






	win.attach(xa);
	win.set_label("Canvas#2");



	//Plot isn() in the range [0:100) with (0,0) at (20,150)
	/// using 1000 points; sclae x values *50, scale y values *50
	Function sine{ 
		sin,
		0,
		100,
		Point{20,150},
		1000,50,50 };

	win.attach(sine);
	win.set_label("canvas#4");



	sine.set_color(Color::blue);

	Graph_lib::Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	Graph_lib::Rectangle r{ Point{200,200},100,50 }; // startpos, width, height .. Height grows down 
	win.attach(r);

	// make a rectangle with opolygons
	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100});

	// destroy the rect by making it a pentagon
	poly_rect.add(Point{ 50,75 });

	//although polyline looks like a rectangle but in memory it really isn't 



	win.attach(poly_rect);



	//fill
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 5));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	
	//text
	Text t{
		Point{150,150},
		"Hello, graphical world!"};
	win.attach(t);
	win.set_label("canvas#8");

	t.set_font(Font::times_bold);
	t.set_font_size(20);
	
	// Images
	Image ii{ Point{100,50}, "img.jpg" };
	win.attach(ii);

	ii.move(100, 200);
	

	Graph_lib::Circle c{ Point{100,200},50};

	Graph_lib::Ellipse e{Point{100,200},75,25};
	e.set_color(Color::dark_red);
	
	Graph_lib::Mark m{ Point{100,200},'x'};
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Graph_lib::Text sizes{Point{100,20}, oss.str()};

	Graph_lib::Image cal{ Point{225,225}, "nyan_cat.gif" };
	cal.set_mask(Point{ 40,40 }, 200, 150);

	
	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);



	win.wait_for_button();	// Allows you to click before it is finished ie -- like a cin at the end .. so it doesnt just flash and finishes the program

}