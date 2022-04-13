// Axis is an example of an object composed of several semi-independent objects
struct Axis: Shape{
    enum Orientation{x,y,z};
    Axis(Orientation d, Point xy, int length, int number_of_notches=0, string label="");

    void draw_lines() const override;
    void move(int dx, int dy) override;
    void set_color(Color c);

   
    // Notice these are left public so that a user can manipulate them 
    //      ie you can give the notches a different color from the line and move() the label to a more convenient
    //      location 
    Text label;
    Lines notches;

};

// The axis constructor places the lines and adds the "notches" if number_of_notches" is greater than zero

Axis::Axis(
        Orientation d, 
        Point xy, 
        int length, 
        int number_of_notches=0, 
        string lab):label(Point{0,0}, lab){
    if(length<0) 
        error("Bad axis length");
    switch(d){
        :w

}
