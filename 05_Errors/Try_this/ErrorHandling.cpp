#include <iostream>
#include "..\..\Bjarnes_Standard_Header\std_lib_facilities.h"

class Bad_area{};

int area(int length, int width){
    if(length<=0||width <=0) throw Bad_area{}; // Changed .. return -1;
                                                // Terminated after throwing an instance of 'Bad_area' 
    return length*width;
}


int framed_area(int x,int y){
    constexpr int frame_width=2;
    if(x-frame_width<=0||y-frame_width<=0)
        error("non-positive area() argumented called by framed_area()");
    return area(x-frame_width, y-frame_width);
}

int f(int x, int y, int z)
{
    int area1= area(x,y);
    if(area1<=0) error("non-positive area");
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;
    return -1;
}

int main(){
    area(-1,-2);
  // f(-1,3,3); 
   
}
