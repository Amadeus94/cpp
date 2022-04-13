#include <FL/FL.h>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Window.h>

int main4() {
	Fl_Window window(200, 200, "Window Title");
	Fl_Box box(0, 0, 200, 200, "Hey, I mean, Hello, World");
	window.show();
	return Fl::run();
}