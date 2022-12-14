//
// Created by adzer on 07/10/2022.
//

#include "JPL.h"

JPL::JPL(const std::vector<std::vector<int>> &listPoly) {
    JPL(listPoly, false);
}

JPL::JPL(const std::vector<std::vector<int>> &listPoly, bool init) {
    // TODO gerer la generation avec le temps
    for (int i = 0; i < listPoly.size(); ++i) {
        LongueurMaximal *lm = new LongueurMaximal(listPoly[i],init);
        LMgenerateurs.push_back(*lm);
    }
}


std::vector<bool> JPL::generate(int n) {
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
