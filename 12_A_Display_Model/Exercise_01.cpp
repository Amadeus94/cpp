#include "Graph.h"
#include "Simple_window.h"
#include "Exercise_01.h"
#include <math.h>

using namespace Graph_lib;


// Exercise 01 - Draw a rectangle as Rectangle and as a  Polygon
	// Make the lines of the Polygon Red 
	// and the lines of the Rectangle blue
void Exercise01(Graph_lib::Simple_window& win)
{
	// Rectangle
	Graph_lib::Rectangle r1{ Point{ 200,200 }, 100,100 };
	r1.set_color(Color::blue);
	win.attach(r1);
	//Polygon
	Graph_lib::Polygon poly;
	poly.add(Point{ 250,250 });
	poly.add(Point{ 350,250 });
	poly.add(Point{ 350,350 });
	poly.add(Point{ 250,350 });
	poly.set_color(Color::red);
	win.attach(poly);

}

//Exercise 02 - Draw a 100x30 Rectangle and place the text "Howdy" Inside it
void Exercise02(Graph_lib::Simple_window& win)
{
	//Ex 2
// Rectangle
	int length = 100;
	int width = 30;

	Graph_lib::Rectangle r1{ Point{ 200,200 }, length,width };
	r1.set_color(Color::blue);
	win.attach(r1);

	//Text
	Graph_lib::Text t1{ Point{200 + (length / 2),200 + (width / 2)}, "Howdy" };
	win.attach(t1);
}



void Exercise03(Graph_lib::Simple_window& win)
{
	//Exercise 03
	// Draw your initials 150 pixels high
	//	Use a a thick line
	//	Draw Each Initials with a diff color

	//K
	Graph_lib::Polygon k;
	k.add(Point{ 100,100 });
	k.add(Point{ 120,100 });

	k.add(Point{ 120,175 });
	k.add(Point{ 200,100 });

	k.add(Point{ 220,100 });
	k.add(Point{ 140,175 });

	k.add(Point{ 220,250 });
	k.add(Point{ 200,250 });

	k.add(Point{ 120,195 });

	k.add(Point{ 120,250 });
	k.add(Point{ 100,250 });

	//H
	Graph_lib::Polygon h;
	h.add(Point{ 300,100 });
	h.add(Point{ 320,100 });

	h.add(Point{ 320,165 });
	h.add(Point{ 400,165 });

	h.add(Point{ 400,100 });
	h.add(Point{ 420,100 });

	h.add(Point{ 420,250 });
	h.add(Point{ 400,250 });

	h.add(Point{ 400,185 });

	h.add(Point{ 320,185 });

	h.add(Point{ 320,250 });
	h.add(Point{ 300,250 });

	k.set_color(Color::blue);
	h.set_color(Color::red);
	

	win.attach(k);
	win.attach(h);
}

void Exercise04(Graph_lib::Simple_window& win)
{
	//Exercise 04
	// Draw a 3x3 Tic-tac-toe board of alternating color


	Graph_lib::Rectangle r1c1{ Graph_lib::Point{ 200,200 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r1c2{ Graph_lib::Point{ 230,200 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r1c3{ Graph_lib::Point{ 260,200 },30,30 }; // startpos, width, height .. Height grows down 

	Graph_lib::Rectangle r2c1{ Graph_lib::Point{ 200,230 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r2c2{ Graph_lib::Point{ 230,230 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r2c3{ Graph_lib::Point{ 260,230 },30,30 }; // startpos, width, height .. Height grows down 

	Graph_lib::Rectangle r3c1{ Graph_lib::Point{ 200,260 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r3c2{ Graph_lib::Point{ 230,260 },30,30 }; // startpos, width, height .. Height grows down 
	Graph_lib::Rectangle r3c3{ Graph_lib::Point{ 260,260 },30,30 }; // startpos, width, height .. Height grows down 



	r1c1.set_color(Color::black);
	r1c2.set_color(Color::red);
	r1c3.set_color(Color::black);
	r2c1.set_color(Color::red);
	r2c2.set_color(Color::black);
	r2c3.set_color(Color::red);
	r3c1.set_color(Color::black);
	r3c2.set_color(Color::red);
	r3c3.set_color(Color::black);

	win.attach(r1c1);
	win.attach(r1c2);
	win.attach(r1c3);
	win.attach(r2c1);
	win.attach(r2c2);
	win.attach(r2c3);
	win.attach(r3c1);
	win.attach(r3c2);
	win.attach(r3c2);
	win.attach(r3c3);
}

void Exercise05(const Graph_lib::Point& t2)
{

	//Exercise05
	// Draw a red 1/4 inch frame around a 
	// rectangle that is three-quarters the height of your screen and two-thirds the width

	cout << Fl::h() << " " << Fl::w();

	int screenWidth = Fl::w();
	int screenHeight = Fl::h();
	Simple_window win{ t2, screenWidth,screenHeight,"My Window" };

	//frame
	//Graph_lib::Rectangle rectOuter{ Graph_lib::Point{0,0},screenWidth,screenHeight };
	//rectOuter.set_color(Color::white);
	//rectOuter.set_fill_color(Color::white);

	//Rectangle 
	int innerHeight = (screenHeight / 8); // Three quarters the height
	int innerWidth = (screenWidth / 6.5);   // 2 thirds the width 
	Graph_lib::Rectangle rectInner{ Graph_lib::Point{ innerWidth,innerHeight },(screenWidth / 3) * 2,(screenHeight / 4) * 3 };
	rectInner.set_color(Color::red);
	//rectInner.set_fill_color(Color::red);
	rectInner.set_style(Line_style(Line_style::solid, 22));


	//Frame 
	////	int innerHeight = (screenHeight / 4) * 3; // Three quarters the height
	//	int innerWidth = (screenWidth / 3) * 2;   // 2 thirds the width 
	//	Graph_lib::Rectangle rectInner{ Graph_lib::Point{(screenWidth / 3),(screenHeight / 4)},innerHeight,innerWidth };
	//	rectInner.set_color(Color::white);
	//	rectInner.set_fill_color(Color::white);


	win.attach(rectInner);


	//	win.attach(rectOuter);


}

void Exercise06(Graph_lib::Simple_window& win, const Graph_lib::Point& t2)
{
	//Exercise06
	// What happens when you draw a shape that doesn't fit nsde its window?
	Graph_lib::Rectangle rect{ Graph_lib::Point{ 100,100 },800,800 };
	win.attach(rect);
	// It overflows ie it is there but ust isnt shown
	// 
	// What happens when you deraw a window that is too large for the monitor?
	Simple_window win2{ t2, 2000,2000,"My Window" };
	// Same as above - it still is there but you only see a part of it 

}

void Exercise08(Graph_lib::Simple_window& win)
{
	//Exercise08
	//	Draw Olympic Rings
	//	with color //blue,yellow,black,green,red
	Graph_lib::Circle circle1{ Point{ 100,100 }, 55 };
	Graph_lib::Circle circle2{ Point{ 160,165 }, 55 };
	Graph_lib::Circle circle3{ Point{ 220,100 }, 55 };
	Graph_lib::Circle circle4{ Point{ 280,165 }, 55 };
	Graph_lib::Circle circle5{ Point{ 340,100 }, 55 };

	circle1.set_color(Color::blue);
	circle2.set_color(Color::yellow);
	circle3.set_color(Color::black);
	circle4.set_color(Color::green);
	circle5.set_color(Color::red);

	circle1.set_style(Line_style(Line_style::solid, 10));
	circle2.set_style(Line_style(Line_style::solid, 10));
	circle3.set_style(Line_style(Line_style::solid, 10));
	circle4.set_style(Line_style(Line_style::solid, 10));
	circle5.set_style(Line_style(Line_style::solid, 10));




	win.attach(circle1);
	win.attach(circle2);
	win.attach(circle3);
	win.attach(circle4);
	win.attach(circle5);
}

void Exercise09(Graph_lib::Simple_window& win)
{
	// Create an image with a caption and the window 

	Image ii{ Point{ 100,50 }, "img3.jpg" };
	win.attach(ii);

	Graph_lib::Text sizes{ Point{ 100,180 }, "Figure 1 - X-Fi Fear Factory Icon" };

	win.attach(ii);
	win.attach(sizes);
}

void Exercise10()
{
	// Exercise10
	//	Draw the file diagram at $12.8

	Point start = Point{ 0,0 };
	Simple_window win{ start, Fl::w(),Fl::h(),"My Window" };

	Graph_lib::Rectangle r1{ Graph_lib::Point{ 200,200 },120,25 }; // startpos, width, height .. Height grows down

	Text t1_1{
		Point{ 200,190 },
		"Point.h:" };

	Text t1_2{
		Point{ 210,215 },
		"struct Point{...];" };
	r1.set_fill_color(Color::yellow);
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Graph_lib::Rectangle r2{ Graph_lib::Point{ 200,300 }, 150, 50 }; // startpos, width, height .. Height grows down
	Text t2_1{
		Point{ 200,300 },
		"Graph.h:" };
	Text t2_2{
		Point{ 210,315 },
		"//Graphing interrface:" };
	Text t2_3{
		Point{ 210,330 },
		"struct Shape{ ... };" };
	Text t2_4{
		Point{ 210,345 },
		"..." };
	r2.set_fill_color(Color::yellow);
	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle r3{ Graph_lib::Point{ 300,400 }, 150, 25 }; // startpos, width, height .. Height grows down
	Text t3_1{
		Point{ 300,395 },
		"window.cpp:" };
	Text t3_2{
		Point{ 310,415 },
		"Window code" };
	r3.set_fill_color(Color::yellow);


	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle r4{ Graph_lib::Point{ 100,400 }, 150, 25 }; // startpos, width, height .. Height grows down
	Text t4_1{
		Point{ 100,395 },
		"Graph.cpp:" };
	Text t4_2{
		Point{ 110,415 },
		"Window code" };
	r4.set_fill_color(Color::yellow);



	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle r5{ Graph_lib::Point{ 150,600 }, 175, 50 }; // startpos, width, height .. Height grows down
	Text t5_1{
		Point{ 150,600 },
		"chapter12.cpp:" };
	Text t5_2{
		Point{ 160,615 },
		"#include \"graph.h\"" };
	Text t5_3{
		Point{ 160,630 },
		"#include \"Simple_window.h\"" };
	Text t5_4{
		Point{ 160,645 },
		"int main() {...}" };
	r5.set_fill_color(Color::yellow);

	//////////////////////////Column 2/////////////////////////////////////////////
	Graph_lib::Rectangle r6_1{ Graph_lib::Point{ 600,100 },120,35 }; // startpos, width, height .. Height grows down
	Graph_lib::Rectangle r6_2{ Graph_lib::Point{ 610,110 },120,35 }; // startpos, width, height .. Height grows down
	Graph_lib::Rectangle r6_3{ Graph_lib::Point{ 620,120 },120,35 }; // startpos, width, height .. Height grows down

	Text t6_1{
		Point{ 630,135 },
		"FTLTK headers" };
	r6_1.set_fill_color(Color::yellow);
	r6_2.set_fill_color(Color::yellow);
	r6_3.set_fill_color(Color::yellow);


	//////////////////////////Column 3/////////////////////////////////////////////
	Graph_lib::Rectangle r7_1{ Graph_lib::Point{ 900,200 },120,35 }; // startpos, width, height .. Height grows down
	Graph_lib::Rectangle r7_2{ Graph_lib::Point{ 910,210 },120,35 }; // startpos, width, height .. Height grows down
	Graph_lib::Rectangle r7_3{ Graph_lib::Point{ 920,220 },120,35 }; // startpos, width, height .. Height grows down

	Text t7_1{
		Point{ 930,235 },
		"FLTK code" };
	r7_1.set_fill_color(Color::yellow);
	r7_2.set_fill_color(Color::yellow);
	r7_3.set_fill_color(Color::yellow);


	//////////////////////////Column 2/////////////////////////////////////////////
	Graph_lib::Rectangle r8{ Graph_lib::Point{ 600,300 },175,50 }; // startpos, width, height .. Height grows down

	Text t8_1{
		Point{ 600,300 },
		"Window.h:" };
	Text t8_2{
		Point{ 610,315 },
		"//window interface:" };
	Text t8_3{
		Point{ 610,330 },
		"class Window{...};" };
	Text t8_4{
		Point{ 600,345 },
		"..." };


	r8.set_fill_color(Color::yellow);

	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle r9{ Graph_lib::Point{ 900,400 }, 175, 50 }; // startpos, width, height .. Height grows down
	Text t9_1{
		Point{ 900,400 },
		"GUI.h" };
	Text t9_2{
		Point{ 910,415 },
		"//GUI Interface" };
	Text t9_3{
		Point{ 910,430 },
		"struct In_box{...};" };
	Text t9_4{
		Point{ 910,445 },
		"..." };
	r9.set_fill_color(Color::yellow);

	/////////////////////////////////////////////////////////////////

	Graph_lib::Rectangle r10{ Graph_lib::Point{ 900,500 }, 120, 25 }; // startpos, width, height .. Height grows down
	Text t10_1{
		Point{ 900,500 },
		"GUI.cpp" };
	Text t10_2{
		Point{ 910,515 },
		"GUI code" };
	r10.set_fill_color(Color::yellow);


	//////////////////////////Column 2/////////////////////////////////////////////
	Graph_lib::Rectangle r11{ Graph_lib::Point{ 600,500 },175,50 }; // startpos, width, height .. Height grows down

	Text t11_1{
		Point{ 600,500 },
		"Simple_window.h:" };
	Text t11_2{
		Point{ 610,515 },
		"//window interface:" };
	Text t11_3{
		Point{ 610,530 },
		"class Simple_window{...};" };
	Text t11_4{
		Point{ 600,545 },
		"..." };


	r11.set_fill_color(Color::yellow);

	//////////////////////////////////////////////////////////////////
	//FLTK Headers
	Line l1{ Point{ 260,300 }, Point{ 680,155 } };
	Line l3{ Point{ 680,300 }, Point{ 680,155 } };
	Line l4{ Point{ 980,400 }, Point{ 680,155 } };
	Line l5{ Point{ 680,155 }, Point{ 900,220 } };
	//Point.h
	Line l2{ Point{ 260,300 },Point{ 260,225 } };
	Line l6{ Point{ 600,300 }, Point{ 260,225 } };

	//window.h
	Line l7{ Point{ 380,400 }, Point{ 680,350 } };
	Line l8{ Point{ 990,400 }, Point{ 680,350 } };
	Line l9{ Point{ 680,500 }, Point{ 680,350 } };

	//GUI.j
	Line l10{ Point{ 960,500 }, Point{ 980,450 } };
	Line l11{ Point{ 680,500 }, Point{ 980,450 } };

	//Graph.h
	Line l12{ Point{ 175,400 }, Point{ 275,350 } };
	Line l13{ Point{ 230,600 }, Point{ 275,350 } };

	//Simple Window
	Line l14{ Point{ 230,600 }, Point{ 680,550 } };

	win.attach(r1);
	win.attach(t1_1);
	win.attach(t1_2);



	win.attach(r2);
	win.attach(t2_1);
	win.attach(t2_2);
	win.attach(t2_3);
	win.attach(t2_4);

	win.attach(r3);
	win.attach(t3_1);
	win.attach(t3_2);

	win.attach(r4);
	win.attach(t4_1);
	win.attach(t4_2);

	win.attach(r5);
	win.attach(t5_1);
	win.attach(t5_2);
	win.attach(t5_3);
	win.attach(t5_4);

	win.attach(r6_1);
	win.attach(r6_2);
	win.attach(r6_3);
	win.attach(t6_1);

	win.attach(r7_1);
	win.attach(r7_2);
	win.attach(r7_3);
	win.attach(t7_1);


	win.attach(r8);
	win.attach(t8_1);
	win.attach(t8_2);
	win.attach(t8_3);
	win.attach(t8_4);

	win.attach(r9);
	win.attach(t9_1);
	win.attach(t9_2);
	win.attach(t9_3);
	win.attach(t9_4);

	win.attach(r10);
	win.attach(t10_1);
	win.attach(t10_2);

	win.attach(r11);
	win.attach(t11_1);
	win.attach(t11_2);
	win.attach(t11_3);
	win.attach(t11_4);

	win.attach(l1);
	win.attach(l2);
	win.attach(l3);
	win.attach(l4);
	win.attach(l5);
	win.attach(l6);
	win.attach(l7);
	win.attach(l8);
	win.attach(l9);
	win.attach(l10);
	win.attach(l11);
	win.attach(l12);
	win.attach(l13);
	win.attach(l14);


	win.wait_for_button();
}

void Exercise11(Graph_lib::Simple_window& win)
{

	//Exercise 11 
	// Draw a series of regular polyugons inside each other
	//	The innermost should be an quiliateral triangle, Enclosed by a square
	// Enclosed by a pentagon etc. 

	
	Graph_lib::Polygon triangle;

	triangle.add(Point{ 400,350 });
	triangle.add(Point{ 350,400 });
	triangle.add(Point{ 450,400 });

	Graph_lib::Polygon rect;
	rect.add(Point{ 300,300 });
	rect.add(Point{ 300,500 });
	rect.add(Point{ 500,500 });
	rect.add(Point{ 500,300 });

	Graph_lib::Polygon pent;
	pent.add(Point{ 400,200 });
	pent.add(Point{ 200,400 });
	pent.add(Point{ 200,600 });
	pent.add(Point{ 600, 600 });
	pent.add(Point{ 600, 400 });



	win.attach(triangle);
	win.attach(rect);
	win.attach(pent);
}

double sgn(double d)
{
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

Closed_polyline createSuperEllipse(double a, double b) {
	const double pi = (22.0 / 7.0);
	int a = 100;
	int b = 100;
	double n = 4;

	double n = 0; // dno what n repesents 
	double t = 0; // Dunno what t represents
	double x = a * pow(cos(t), (2 / n));	// n is r here
	double y = b * pow(sin(t), (2 / n));	// n is r here

	// r ie n must be > 2 
}



int main1232() {
	Point t2 = Point{ 100,100 };
	Simple_window win{ t2, Fl::w(), Fl::h(),"My Window" };

	//Exercise01(win);
	//Exercise02(win);
	//Exercise03(win);
	//Exercise04(win);
	//Exercise05(t2);
	//Exercise06(win, t2);
	//Exercise07();
	//Exercise08(win);
	//Exercise09
	//Exercise09(win);
	//Exercise10();
	//Exercise11(win);
	//Exercise12 

	cout << pow(10, 1);
	
	win.wait_for_button();
}




void Exercise07()
{

	//Exercise07
	// Create a House from the front
	//	Door 
	// Two windows
	// Roof 
	//	with a chimney
	//	optional: Create smoke from chimney

	int screenWidth = Fl::w();
	int screenHeight = Fl::h();
	Point t2 = Point{ 100,100 };
	Simple_window win{ t2, screenWidth,screenHeight,"My Window" };


	Graph_lib::Rectangle house{ Point{ 250,250 }, 400,400 };

	Graph_lib::Rectangle window1{ Point{ 300,350 }, 100,100 };
	Graph_lib::Rectangle window2{ Point{ 500,350 }, 100,100 };

	Graph_lib::Rectangle door{ Point{ 400,500 }, 100,150 };

	Graph_lib::Polygon roof;
	roof.add(Point{ 250 - 50,250 });
	roof.add(Point{ 250 + 450,250 });
	roof.add(Point{ ((250 + 450) / 2) + 100,150 });

	Graph_lib::Rectangle chimney{ Point{ 600,175 }, 40,60 };

	//Graph_lib::Lines smoke;
	//	smoke.add(Point{ 600,195 }, Point{ 600,175 });
	//	Graph_lib::Line smokes{ Point{ 600,195 }, Point{ 600,175 } };

	//fl_line(int x, int y, int x1, int y1)

	Graph_lib::Function smoke{
		sin,
		0,
		100,
		Graph_lib::Point{ 620,175 },
		1000,50,50 };

	win.attach(smoke);


	win.attach(house);
	win.attach(window1);
	win.attach(window2);
	win.attach(door);
	win.attach(roof);
	win.attach(chimney);
	//	win.attach(smoke);
	//	win.attach(smokes);

	win.wait_for_button();
}
