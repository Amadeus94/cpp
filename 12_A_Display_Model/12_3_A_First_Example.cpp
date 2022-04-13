#include "Simple_window.h"
#include "Graph.h"
#include "FL/fl_draw.H"

int main3() {
	using namespace Graph_lib; // appearantly not that useful for polygon

	Point tl{ 100,100 };	// the point we put our graphic  screen in relation to monitor screen NOT CMD window 
	Simple_window win{ tl, 600,400,"Canvas" };

	Graph_lib::Polygon poly; // Is unambigous .--- so use the namespace 

	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });

	poly.set_color(Color::red);

	win.attach(poly);
	// Notice nothing drawn yet ----> we give control to display engine via the following command 
	win.wait_for_button();	// Allows you to click before it is finished ie -- like a cin at the end .. so it doesnt just flash and finishes the program
	
}