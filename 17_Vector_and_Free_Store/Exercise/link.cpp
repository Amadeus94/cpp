#include <string>

#include<iostream>

using namespace std;


struct  God{
    string name, mythology, vehicle, weapon;
};
class Link{
public:
    string value;  // this member is public because why not... it is only data 
    
    Link(const string& v, Link* p = nullptr, Link* s= nullptr)
        :value{v}, prev{p},  succ{s}{}

    Link* insert(Link* n);                    // insert n before this object
    Link* add(Link* n);                       // insert n after this object
    Link* erase();                            // remove this object from list

    Link* find(const string& s);              // find s in list
    const Link* find(const string& s) const;  // find s in const list 
    Link* erase(Link* p);


    Link* find(Link* p, const string& s);  // added
    Link* advance(Link* p, int n);   // added 

    Link* advance(int n) const;               // Move n positions in list

    Link* next() const {return succ;}
    Link* previous() const {return prev;}

private:
    Link* prev;
    Link* succ;

};



    Link* find(const string& s) {

        cout << "find(const string& s  -  method()";
        return nullptr;
        //added
    }

// TODO: Draw it to understand it
Link* Link::insert(Link* n)
{
    if(n==nullptr) 
        return this;
    if(this==nullptr) 
        return n;
    
    n->succ = this; // this object comes after n;
    
    // reason that we can call on prev here is because we are calling this->prev implicitly  
    // Personally I think this only confuses the code as prev is not shown anywhere else in the code 
    if(prev)  // error if write only prev
        prev->succ=n; // this object's predecessor
                            // becomes n's predecessor

                // error if change to prev
    n->prev=prev;     // n becomes this object's predecessor

    return n;
}

Link* Link::find(Link* p, const string& s) // find s in list;  - if not found return nullptr
{
    while(p){
        if(p-> value==s) 
            return p;
        p=p->succ;
    }
    return nullptr;
}

Link* Link::advance(Link* p, int n){ // move n positions in list - return nullptr if not found 
                              //positive n moves forward
                              //negative n moved backward
    if(p==nullptr)
        return nullptr;
    if(0<n){
        while(n--) {
            if(p->succ ==nullptr) 
                return nullptr;
            p = p->prev;
        }
    }else if(n<0) {
        while(n++){ // very smart -- until not 0  ....  when hits 0 it is false and jumps out of loops 
            if(p-> prev ==nullptr)
                return nullptr;
            p= p->prev;
        }
    }
    return p;
}

Link* Link::erase(Link* p){
    if(p==nullptr) 
        return nullptr;
    // If the about to deleted node contains a successor
    //     set that successors prev to this p->prev
    if(p->succ)
        p->succ->prev = p->prev;
    if(p->prev)
        p->prev->succ=p->succ;
    return p->succ;
}




void print_all(Link* p){
    cout << "{";
    while(p) {
        cout << p->value;
        if(p=p->next())
            cout << ",";
    }
    cout << "}";
}



int main(){
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    print_all(norse_gods);

    

    // todo find mistake with find 
//    Link* p = greek_gods->find("Mars");
//    if(p)
//        p->value = "Ares";
//
//    // move Zeus into his correct Pantheon
//    Link* p2 = norse_gods->find("Zeus");
//    if(p2){
//        if(p2==norse_gods)
//            norse_gods=p2->next();
//
//    }
//

    // Exercise 12 - Why did we define two versions of find()?
//    Link* find(const string& s);              // find s in list
//    const Link* find(const string& s);  // find s in const list 
    // The reason is that the first one could potentially change a const 
    // and the second one  is added for overloading 
    

}
