#include <iostream>
#include "LongueurMaximal/LongueurMaximal.h"

int main() {
    std::cout << "Hello World!\n";
    std::vector<int> polynome = {1,5};
    LongueurMaximal *lm = new LongueurMaximal(polynome);
    std::cout << *lm;

    std::cout << lm->generate(20);

    return 0;
}
