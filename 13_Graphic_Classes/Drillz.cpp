 #include "Graph.h"
#include "Simple_window.h"
#include <exception>

using namespace Graph_lib;
void drillz2() {
	// 1. Make an 800x100 Simple_Window
	int screenWidth = 800;
	int screenHeight = 1000;
	Point startOfAxis = Point{ 0,0 };
	Simple_window win{ startOfAxis, screenWidth,screenHeight,"My Window" };

	//2,. Put an 8x8 grid on the leftmost 800 by 800 part of that window 
	//	So that each square is 100x100

	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x < screenWidth; x += x_grid)
		grid.add(Point{ x,0 }, Point(x, screenHeight)); // Vertical Line
	for (int y = y_grid; y < screenHeight; y += y_grid)
		grid.add(Point{ 0,y }, Point(screenWidth, y)); // Vertical Line

	grid.set_color(Color::black);
	win.attach(grid);


	// 3 Make the eight squares on the diagonal start Starting from the top left corner 
	//		Use Rectangle 
	//	ie make the top left corner red

	Graph_lib::Rectangle rect{ Point{0,0}, 200,200 };
	rect.set_color(Color::red);
	rect.set_fill_color(Color::red);
	win.attach(rect);

	// 3. Place three copies of it on the grid - each image covering four squares ( Ie  200x200) 
	// Don't obsquare the red lines ie don't place it on top of the top left corner 
	//	200x200 pixel image JPEG OR GIF

	Image i1{ Point{ 200,200 }, "img3.jpeg" };
	win.attach(i1);
	Image i2{ Point{ 400,400 }, "img3.jpeg" };
	win.attach(i2);
	Image i3{ Point{ 600,600 }, "img3.jpeg" };
	win.attach(i3);

	Image i4{ Point{ 0,0 }, "img3.jpeg" };
	win.attach(i4);
	
	int dx = 0;
	int dy = 0;
	int mx = 100;
	int my = 0;
	for (int i = 0; i < 80; i++)
	{
		win.wait_for_button();
		dx += 1;
		if (dx>7){
			my=100;
			mx = -700;
			dx = 0;
		}
		
		i4.move(mx, my);
		my = 0;
		mx = 100;
	}



	//delete obj;
	//win.wait_for_button();
	//win.attach(*obj);
	//win.wait_for_button();
	//obj = new Image(Point{ 100,100 }, "img3.jpeg");
	//win.attach(*obj);
	//win.wait_for_button();

	//{
	//	int j = -1;
	//for (int i = 0; i < 36; i++)
	//{
	//	if (i % 8 ==0)
	//		j++;
	////	delete obj;
	////	obj = new Image { Point{ 100,100}, "img3.jpeg" };
	////	win.attach(*obj);


}





