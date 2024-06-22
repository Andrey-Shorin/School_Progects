#include <map>
#include "map.hpp"
// #include <stdio.h>      /* printf, scanf, puts, NULL */
// #include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */
#include <iostream>
#define TEST ft
int main(){
    TEST::map<int,int> a;
    a.insert(TEST::pair<int,int>(5,15));
    a.insert(TEST::pair<int,int>(4,8));
    a.insert(TEST::pair<int,int>(3,3));
    a.insert(TEST::pair<int,int>(14,14));
    a.insert(TEST::pair<int,int>(6,0));

    // ft::map<int,int>::iterator i = a.begin();
    // while (i != a.end()){
    //     std::cout << (*i).first << "  " << (*i).second << " \n" ;
    //     i++;
    // }
    TEST::map<int,int> ::const_iterator i = a.begin();
        (void) i;
    TEST::map<int,int> ::iterator   h = a.begin();
         (void) h;


    //  void* u =i._M_node;
     return 0;
    // std::cout << "\n";
    // std::cout << (a.at).second << "\n";
    // std::map<int,int> j;
}