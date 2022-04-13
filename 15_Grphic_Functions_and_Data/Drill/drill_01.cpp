#include <iostream>
#include <string>

using namespace std;

class B1{
public:

    virtual void vf(){
        cout << "B1::vf()" << endl;
    }

    void f(){
        cout << "B1::f()" << endl;
    }

    // pure virtual function - has to be overwritten by subclasses 
    virtual void pvf() = 0;
};



class D1 : public  B1{
public:
  virtual void vf(){
        cout << "D1::vf()" << endl;
  }

    void f(){
        cout << "D1::f()" << endl;
    }

}; 


class D2 : public  D1{
public:
  virtual void vf(){
        cout << "D2::vf()" << endl;
  }

    void f(){
        cout << "D2::f()" << endl;
    }

    void pvf() override{
        cout << "D2::pvf()" << endl;
    }

}; 


class B2{
public:
  virtual void pvf() = 0;
}; 


class D21: public B2{
public:
  void pvf() override{
    cout << s << endl;
  }
private:
  string s = "pvf";
}; 

class D22: public B2{
public:
  void pvf() override{
    cout << s << endl;
  }

  void f(B2& b){
    b.pvf();
  }
private:
  int s = 1337;
}; 





int main(){
//    B1 b1;
//    b1.f();
//    b1.vf();
//
//    D1 d1;
//    d1.f();
//    d1.vf();
//
//    // Notice how this prints B1::f() - this is because we are looking for function table at B1 - however since this is
//    // not virtrual it doesnt say look at virtual function table and therefore just uses default 
//    B1& bref = d1;
//    bref.f();
//    bref.vf();


//      D2 d2;
//      d2.f();
//      d2.vf();
//      d2.pvf();
//  
//
// 
    
   D21 d;
   D22 d2;

   d.pvf();

   d2.f(d); 
   d2.f(d2); 
      
     
    



}
