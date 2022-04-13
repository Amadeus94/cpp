// -----------------------------------------------------------------------------
// https://lptcp.blogspot.com
// Chapter 12 - Drill 1
/*
   Get an empty Simple_window with the size 600 by 400 and a label My Window 
   compiled, linked, and run. Note that you have to link the FLTK library as 
   described in Appendix D; #include Graph.h and Simple_window.h in your code; 
   and include Graph.cpp and Window.cpp in your project.
*/
//	https://github.com/l-paz91/principles-practice
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Simple_window.h"

// -----------------------------------------------------------------------------

int main2()
{
	using namespace Graph_lib;
	Simple_window win{ Point{100,100}, 600, 400, "My Window" };
	
	win.wait_for_button();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------