//
// Created by adzer on 29/09/2022.
//

#ifndef CODAGETP_LONGUEURMAXIMAL_H
#define CODAGETP_LONGUEURMAXIMAL_H

#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <math.h>

#ifdef _MSC_VER
// Windows
#include <Windows.h>
#else
// Linux
#include <time.h>
#endif


inline  std::ostream &operator << (std::ostream &os, const std::vector<bool> &list)
{
    for (auto const &i: list)
        os << i;

    os << '\n';
    return os;
}

inline std::ostream &operator << (std::ostream &os, const std::vector<int> &list)
{
    for (auto const &i: list)
        os << ' ' << i;

    return os;
}

class LongueurMaximal {
private:
    std::vector<bool> codeur;
    std::vector<bool> vecteurInitial;
    std::vector<int> polynomeInt;
    std::vector<bool> polynomeBool;
public:

    // Constructors
    LongueurMaximal(const std::vector<int>& newPolynom);

    LongueurMaximal(const std::vector<int>& newPolynom , bool init);

    std::vector<bool> generateFromPolynopm(const std::vector<int> &poly);

    std::vector<bool> generateVecteurInitial(const std::vector<int> &poly);

    std::vector<bool> generateVecteurInitialFromTime(const std::vector<int> &poly);

    // Getters
    const std::vector<bool> &getVecteurInitial() const;

    const std::vector<bool> &getPolynome() const {
        return polynomeBool;
    }

    // Utilities

    bool generate();

    std::vector<bool> generate(int n){
        std::vector<bool> result;
        for (int i = 0; i < n; ++i)
            result.push_back(generate());
        return result;
    }

    double millisecond();

    friend std::ostream &operator<<(std::ostream &os, const LongueurMaximal &maximal) {
        os << "LongueurMaximal:"
           << "\n\tcodeur: " << maximal.codeur
           << "\tvecteurInitial: " << maximal.vecteurInitial
           << "\tpolynome:" << maximal.polynomeInt
           << "\n\t\t" << maximal.polynomeBool
           << "\n";
        return os;
    }

};

#endif //CODAGETP_LONGUEURMAXIMAL_H