
//Dangerously ugly code - Last example of 8.4
// Indent it properly
// Explain the meaning of each construct


// Struct X has 4 methods
    // void f(int x)
        // Defines a struct Y with a method  f() that returns 1 that the void f method uses 
    // void g(int m)
    // void m3()
    // void main()
struct X
{
    void f(int x)
    {
        struct Y
        {
            int f() { return 1; }
            int m;
        };
        int m;
        m = x;
        Y m2;
        return f(m2.f());
    }
    int m;
    void g(int m)
    {
        if (m)
            f(m + 2);
        else
        {
            g(m + 2);
        }
    }
    X() {}
    void m3() {}

    void main()
    {
        X a;
        a.f(2);
    }
};
