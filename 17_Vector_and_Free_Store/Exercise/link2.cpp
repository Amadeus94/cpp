#include <string>

#include<iostream>

using namespace std;


struct  God{
    string name, mythology, vehicle, weapon;
};
class Link{
public:
    God god;
    //string value;  // this member is public because why not... it is only data 
  
    Link(God v, Link* p = nullptr, Link* s= nullptr)
        :god{v}, prev{p},  succ{s}{}

    

    Link* insert(Link* n);                    // insert n before this object
    Link* add(Link* n);                       // insert n after this object
    Link* erase();                            // remove this object from list
    Link* addOrdered(Link* n); //Ex13  -- Places its new element in its correct lexigraphically  position 

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


Link* Link::addOrdered(Link* n)
{
   this->insert(n);

   while(n->succ->god.name > n->god.name && n->succ != nullptr) 
       this->advance(n, 1);
       

   return n;
}



Link* Link::find(Link* p, const string& s) // find s in list;  - if not found return nullptr
{
    while(p){
        if(p->god.name==s) 
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
    cout << endl <<  p->god.mythology << endl << endl;
    cout << "{" << endl;
    while(p) {
        cout << "{";
        //print god stats
        //string name, mythology, vehicle, weapon;
        cout<< p->god.name <<  ',';
        cout<< p->god.mythology << ',';
        cout<< p->god.vehicle << ',';
        cout<< p->god.weapon;
 //       cout << p->value;
        if(p=p->next())
            cout << "}" << endl << ",";
    }
    cout << endl << "}";
}



int main(){
    // Uncomment after print is fixed 
    Link* norse_gods = new Link{God{"Thor", "Norse","chariot pulled by two goats, Tanngrisnir and tanngnjóstr","Mjølnir"}};
    norse_gods = norse_gods->insert(new Link{God{"Odin", "Norse","Eight-legged flying horse called Sleipner","Gungnir"}});
    norse_gods = norse_gods->insert(new Link{God{"Freia", "Norse","Hildisvíni (battle swine)","Dainsleif"}});

    //ex13 - addordered
    norse_gods = norse_gods->addOrdered(new Link{God{"Jens", "Norse","Hildisvíni (battle swine)","Dainsleif"}});

    norse_gods->advance(norse_gods->find(norse_gods, "jens") , 2);

    


    //Todo - Add weapons etc.. everything functiosn now 
    Link* greek_gods = new Link{God{"Hera", "Greek","","Sharp Tongue"}};
    greek_gods = greek_gods->insert(new Link{God{"Athena", "Greek","","2 swords"}});
    greek_gods = greek_gods->insert(new Link{God{"Mars", "Greek","","Spear"}});
    greek_gods = greek_gods->insert(new Link{God{"Poseidon", "Greek","","trident"}});
    greek_gods = greek_gods->insert(new Link{God{"Zeus", "Greek","","Lightning"}});
//
    print_all(norse_gods);
    cout << endl<< endl;
    print_all(greek_gods);
//


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
