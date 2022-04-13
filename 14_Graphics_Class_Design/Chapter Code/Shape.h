class Shape{
public:
    void draw() const;
    virtual void move(int dx, int dy);

    void set_color(Color col);  // Setter
    Color color() const;        // Getter

    void set_style(Line_style sty);
    Line_style line_style() const;

    void set_fill_color(Color col);
    Color fill_color() const; 

    Point point(int i) const;   // Read-only access to points
    int number_of_points() const;

    Shape(const Shape&) = delete;   // Prevent copying
    Shape& operator=(const Shape&) = delete;


    virtual ~Shape(){}

protected:      
    //abstract constructor 
    Shape(){} // Since this consteructor is protected 
                // It can only be used as as a base for classes, such as Line and Open-_polyline.... 
                // ie we cannot instantiate Shape ... Shape ss ... gives error... 
                // In other words, this makes the Shape class ABSTRACT
    Shape(Initializer_list<Point> lst); // add() the Points to this Shape

    virtual void draw_lines() const; 
    void add(Point p);
    void set_point(int i, Point p);
private:
    vector<Point> points;
    Color IColor{fl_color()};   // Color for lines and characters(with default);
    Line_style ls{0};   // I guess this is the default
    Color fcolor{Color::invisible};     // fill color
}