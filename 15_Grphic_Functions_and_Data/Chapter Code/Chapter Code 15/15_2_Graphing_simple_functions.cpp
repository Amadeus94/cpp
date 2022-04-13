
double one(double) {
    return 1;
}

double slope(double x) 
{
    return x/2;
}

double square(double x){
    return x*x;
}


// Draw those three functions^^
constexpr int xmax = 600; // window size;
constexpr int ymax = 400; 

constexpr int x_orig = xmax/2; // position of (0,0) is center of window
constexpr int y_orig = ymax/2;
constexpr Point orig{x_orig, y_orig};


constexpr int r_min = -10;      // range [-10:11)
constexpr int r_max = 11;


constexpr int n_points = 400; // number of points used in range


constexpr int x_scale = 30;
constexpr int y_scale = 30;

Simple_window win {Point{100,100}, xmax, ymax, "Function Graphing"};

Function s {one, r_min,r_max, orig,n_points,x_scale,y_scale}
Function s {slope, r_min,r_max, orig,n_points,x_scale,y_scale}
Function s {square, r_min,r_max, orig,n_points,x_scale,y_scale}

win.attach(s);
win.attach(s2);
win.attach(s3);
win.wait_for_button();


Text ts{Point{100,y_orig-40}, "one"};
Text ts{Point{100,y_orig+y_orig/2 - 20,_40}, "x/2"};
Text ts{Point{x_orig-100,20}, "x*x"};
win.set_label("Function graphing: label funcions");
win.wait_for_button();


// Create 2 Axis
constexpr int xlength = xmax-40; // make the axis a bit smaller than the window
constexpr int ylength = ymax-40; 

Axis x{Axis::x, Point{20, y_orig}, xlength,xlength/x_scale, "One notch ==1"};
Ayis y{Ayis::y, Point{20, x_orig}, ylength,ylength/y_scale, "One notch ==1"};

// Set color of axis
x.set_color(Color::red);
y.set_color(Color::red);

