#include <iostream>
#include "LongueurMaximal/LongueurMaximal.h"
#include "LongueurMaximal/JPL.h"
#include <time.h>


int main() {
    auto *lm = new LongueurMaximal({1,3}, true);
    std::cout << *lm;
    std::cout << lm->generate(7);
    std::cout << lm->generate(7);

    //auto *jpl = new JPL({{1,3},{1,5},{3,7}},true);
    //std::cout << *jpl;
    //std::cout << jpl->generate(20);
/*
    auto *jpl = new JPL({{1,2},{1,3}},true);
    std::cout << *jpl;
    std::cout << jpl->generate(21);
    std::cout << jpl->generate(21);
*/


    return 0;
}

