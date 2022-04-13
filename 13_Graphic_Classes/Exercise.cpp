#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;
// Not my soltuoin -- Was not sure what he asked us to do 
struct Arc2 : Shape
{
	//angle1 must be less than or equal to angle2
	Arc2(Point p, int ww, int hh, int a1, int a2)
		: w{ ww }, h{ hh }, angle1{ a1 }, angle2{ a2 }
	{
		add(Point{ p.x - ww, p.y - hh });
	}

	void draw_lines() const;
	void change_angle(int a1, int a2);

private:
	int w, h;
	int angle1, angle2;
};


void Arc2::draw_lines() const
{
	if (fill_color().visibility())
	{	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, w, h, angle1, angle2);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility())
	{
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w, h, angle1, angle2);
	}
}

// -----------------------------------------------------------------------------

void Arc2::change_angle(int a1, int a2)
{
	angle1 = a1;
	angle2 = a2;
	Arc2::draw_lines();
}
/// <summary>
/// Exercise 04 
///		Define functions n(),s(),e(),w(),center(),ne(),se(),sw(),nw()
///			Takes a Rectangle arguments
///				returns a point 
///		You return a connection point ie nw  is the top left ocrner of the rectangle
/// </summary>
/// <returns></returns>

Point nw(Graph_lib::Rectangle &r) {
	Point northWest = r.point(0);
	return northWest;
}

Point n(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point north = Point(northWest.x + (r.width() / 2), northWest.y);
	return north;

}

Point ne(Graph_lib::Rectangle& r) {
	Point northWest= r.point(0);
	Point northEast = Point(northWest.x + r.width(), northWest.y);
	return northEast;
}

Point w(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point west= Point(northWest.x, northWest.y+(r.height() / 2));
	return west;
}

Point c(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point center = Point(northWest.x + (r.width() / 2), northWest.y + (r.height() / 2));
	return center;
}

Point e(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point east = Point(northWest.x + r.width(), northWest.y + (r.height() / 2));
	return east;
}

Point sw(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point southWest = Point(northWest.x, northWest.y + r.height());
	return southWest;
}

Point s(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point south= Point(northWest.x+(r.width() / 2), northWest.y + r.height());
	return south;
}

Point se(Graph_lib::Rectangle& r) {
	Point northWest = r.point(0);
	Point southEast = Point(northWest.x + r.width(), northWest.y + r.height());
	return southEast;
}





int main() {
	int screenWidth = Fl::w();
	int screenHeight= Fl::h();

	Simple_window win{ Point{100,100},screenWidth,screenHeight, "Chapter 13 - Exercise 1"};
	// Exercise 01 - Not my solution
	// 
	//Arc2 arc(Point{ 200, 200 }, 100, 100, 0, 180);
	//arc.set_color(Color::black);
	//arc.set_fill_color(Color::cyan);
	//win.attach(arc);
	//win.wait_for_button();

	//arc.change_angle(210, 350);
	//arc.set_color(Color::red);
	//win.wait_for_button();


	//Exercise02 - Draw a box with rounded corners
	//	Define a class Box, consisting of four lines and four arcs



	// Exercise04
	/*Graph_lib::Rectangle r{Point{100,100},100,200};
	Point northWest= nw(r);
	Point north = n(r);
	Point northEast = ne(r);
	
	Point west= w(r);
	Point center= c(r);
	Point east= e(r);

	Point southWest = sw(r);
	Point south = s(r);
	Point southEast = se(r);


	cout << "(" << northWest.x << "," << northWest.y << ")" << endl;
	cout << "(" << north.x << "," << north.y << ")" << endl;
	cout << "(" << northEast.x << "," << northEast.y << ")" << endl;

	cout << "(" << west.x << "," << west.y << ")" << endl;
	cout << "(" << center.x << "," << center.y << ")" << endl;
	cout << "(" << east.x << "," << east.y << ")" << endl;
	

	cout << "(" << southWest.x << "," << southWest.y << ")" << endl;
	cout << "(" << south.x << "," << south.y << ")" << endl;
	cout << "(" << southEast.x << "," << southEast.y << ")" << endl;
*/

//	cout << "(" << topLeft.x << "," << topLeft.y << ")";
//	win.attach(r);

	/// Exercise 7
	//	Make an RGB Color chart of 256 ie 16x16
	//int width = screenWidth / 16;
	//int height = screenHeight / 16;
	//Vector_ref<Graph_lib::Rectangle*> v;
	//

	//int row = -1;
	//for (int i = 0; i < 256; i++)
	//{
	//	int dx = (i * width) % (width * 16);
	//	if (dx == 0)
	//		row++;
	//	Graph_lib::Rectangle* r = new Graph_lib::Rectangle(Point{dx,row*height}, width,height);
	//	r->set_fill_color(i);
	//	win.attach(*r);
	//	v.push_back(r);
	//	cout << dx << endl;
	//}


	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	win.attach(*v[i]);
	//}
	//cout << v.size();


	//Exercise08 -- Fucked
	//Regular_hexagon rh(Point{ 400,500 }, 50);
//	win.attach(rh);

	win.wait_for_button();
}