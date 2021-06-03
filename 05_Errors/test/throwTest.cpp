#include <iostream>


int method1(){
    throw "Division by zero condition!";
    return 1;
}
int method2(){
    method1();
    return 1;
}

int main(){

    try{
        method2();
    }catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    return 1;
}

