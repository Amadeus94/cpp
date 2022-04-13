// 15.6.1 Reading a file
// (1960:30 64 6)
// (1930:33 62 1)

struct Distribution  {
    int year, young, middle, old;
};

istream& operator>>(istream is, Distribution& d){
    // assume format (year: young middle old) 
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;

    Distribution dd;
    if(is>>ch1 >> dd.year >>ch2 >>dd.young >> dd.middle >> dd.old
            >> ch3){
        if(ch1!= '(' ||ch2 != ':' || ch3!=')'){
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d=dd;
    return is;




}

//Driver code

string file_name = "Japanese-age-data.txt";
ifstream ifs{file_name};
if(!ifs)
    error("can't open ", file_name);
//....
for(Distribution d; ifs>>d;){
    if(d.year<base_year||end_year<d.year)
        error("Year out of range");
    if(d.young+d.middle+d.old!=100)
        error("Percentages don't add up");
}



//15.6.2 - General Layout

constexpr int xmax = 600;  // window size
constexpr int ymax = 400; 

constexpr int xoffset = 100; //distance from left-hand side of window to y axis
constexpr int yoffset = 60; // distance from bottom of window to x axis

constexpr int xspace = 40;  //space beyound axis
constexpr int yspace = 40; 

constexpr int xlength = xmax-xoffset-xspace;  //length of axis
constexpr int ylength = ymax-yoffset-yspace; 


// 15.6.3 Scaling Data
constexpr int base_year = 1960; 
constexpr int end_year = 2040; 

constexpr double xscale = double(xlength)/(end_year-base_year);
constexpr double yscale = double(ylength)/100;


class Scale{
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s}{}
    int operator()(int v) const{
        return cbase + (v-vbase)*scale;
    }
}




// Final Driver code

Window win{Point{100,100}, xmax, ymax,"Aging japan"};

Axis x{Axis::x, Point{xoffset,ymax-yoffset},xlength, (end_year-base_year)/10,
        "uear   1960    1970    1980    1990    "
        "2000   2010    2020    2030    2040"};
x.label.move(-100,0);
Axis y{Axis::y, Point{xoffset, ymax-yoffset}, ylength, 10, "% of population"};

Line current_year{Point{xs(2008), ys(0)}, Point{xs(2008), ys(100)}};
curret_year.set_style(Line_style::dash);


//The gui code
Open_polyline children;
Open_polyline adults;
Open_polyline aged;

for(Distriution d; ifs>>d;){
    if(d.year<base_yea || end_eyar < d.year)
        error("year out of range");
    if(d.young+d.middle+d.old!=100)
        error("percentages don't add up");
    const int x = xs (d.year);
    children.ad(Point{c

