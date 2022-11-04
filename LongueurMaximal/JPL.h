//
// Created by adzer on 07/10/2022.
//

#ifndef CODAGETP_JPL_H
#define CODAGETP_JPL_H

#include <vector>
#include <ostream>
#include "LongueurMaximal.h"

class JPL {
private:
    std::vector<LongueurMaximal> LMgenerateurs;

public:

    // Constructors
    JPL(const std::vector<std::vector<int>>& listPoly);

    JPL(const std::vector<std::vector<int>>& listPoly, bool init);

    friend std::ostream &operator<<(std::ostream &os, const JPL &jpl) {
        os << "LMgenerateurs: ";
        for (int i = 0; i < jpl.LMgenerateurs.size(); ++i) {
            os << jpl.LMgenerateurs[i];
        }
        return os;
    }

    // Utilities

     std::vector<bool> generate(int n);
};

#endif //CODAGETP_JPL_H
