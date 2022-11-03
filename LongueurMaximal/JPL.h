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
    JPL(const std::vector<std::vector<int>>& listPoly) {
        JPL(listPoly, false);
    }

    JPL(const std::vector<std::vector<int>>& listPoly, bool init) {
        // TODO gerer la generation avec le temps
        for (int i = 0; i < listPoly.size(); ++i) {
            LongueurMaximal *lm = new LongueurMaximal(listPoly[i]);
            LMgenerateurs.push_back(*lm);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const JPL &jpl) {
        os << "LMgenerateurs: ";
        for (int i = 0; i < jpl.LMgenerateurs.size(); ++i) {
            os << jpl.LMgenerateurs[i];
        }
        return os;
    }

     std::vector<bool> generate(int n) {
         std::vector<bool> result ;
         for (int i = 0; i < n; ++i) {
             std::vector<bool> lmResults;
             bool tmpResult = false;
             for (LongueurMaximal &lm: LMgenerateurs)
                 lmResults.push_back(lm.generate());
             for (bool b: lmResults)
                 tmpResult = tmpResult xor b;
            result.push_back(tmpResult);
         }
         return result;
    }
};

#endif //CODAGETP_JPL_H
