//
// Created by adzer on 29/09/2022.
//

#ifndef CODAGETP_LONGUEURMAXIMAL_H
#define CODAGETP_LONGUEURMAXIMAL_H

#include <vector>

class LongueurMaximal {
private:
    int len;
    std::vector<int> codeur;
    std::vector<int> vecteurInitial;
    std::vector<int> polynome;
public:
    LongueurMaximal(int newlen,std::vector<int> newVecteurInitial ){
        len = newlen;
        codeur;
        vecteurInitial = newVecteurInitial;
        std::vector<int> polynome;
    }
};


#endif //CODAGETP_LONGUEURMAXIMAL_H