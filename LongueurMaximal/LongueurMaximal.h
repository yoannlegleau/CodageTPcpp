//
// Created by adzer on 29/09/2022.
//

#ifndef CODAGETP_LONGUEURMAXIMAL_H
#define CODAGETP_LONGUEURMAXIMAL_H

#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

std::ostream &operator<<(std::ostream &os, const std::vector<bool> &list)
{
    for (auto const &i: list) {
        os <<  i;
    }
    os << '\n';
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &list)
{
    for (auto const &i: list) {
        os << ' ' << i;
    }
    return os;
}


class LongueurMaximal {
private:
    std::vector<bool> codeur;
    std::vector<bool> vecteurInitial;
    std::vector<int> polynomeInt;
    std::vector<bool> polynomeBool;
public:

    LongueurMaximal(const std::vector<int>& newPolynom){
        std::vector<bool> newVecteurInitial;
        // TODO generaer avec le temps
        newVecteurInitial = generateVecteurInitial(newPolynom);
        codeur = newVecteurInitial;
        vecteurInitial = newVecteurInitial;
        polynomeInt = newPolynom;
        polynomeBool = generateFromPolynopm(newPolynom);
    }

    LongueurMaximal(const std::vector<int>& newPolynom , bool init): LongueurMaximal(newPolynom){


    }

    const std::vector<bool> &getVecteurInitial() const {
        return vecteurInitial;
    }

    const std::vector<bool> &getPolynome() const {
        return polynomeBool;
    }

    std::vector<bool> generateFromPolynopm(const std::vector<int> &poly) {
        std::vector<bool> listBool ;
        auto max = *max_element(poly.begin(), poly.end());
        for (int i = 0; i < max; ++i) {
            listBool.push_back(0);
        }
        for (auto &item: poly){
            listBool[item-1] = true;
        }
        return listBool ;
    }

    std::vector<bool> generateVecteurInitial(const std::vector<int> &poly) {
        auto max = *max_element(poly.begin(), poly.end());
        std::vector<bool> newVecteurInitial;
        for (int i = 0; i < max; ++i) {
            newVecteurInitial.push_back(true);
        }

        return newVecteurInitial ;
    }

    std::vector<bool> generateVecteurInitialFromTime(const std::vector<int> &poly) {
        time_t seconds = time(NULL)%codeur.size();

        auto max = *max_element(poly.begin(), poly.end());
        std::vector<bool> newVecteurInitial;
        for (int i = 0; i < max; ++i) {
            newVecteurInitial.push_back(true);
        }

        return newVecteurInitial ;
    }

    //time_t seconds;
    //seconds = time(NULL);
    //std::cout << seconds;

    bool generate(){
        bool result = codeur.back();
        bool newbite = 0;
        for (int i = polynomeBool.size(); i >= 0; i--)
            if (polynomeBool[i] == 1)
                newbite = newbite xor codeur[i];
        codeur.pop_back();
        codeur.insert(codeur.begin(),newbite);
        return result;
    }

    std::vector<bool> generate(int n){
        std::vector<bool> result;
        for (int i = 0; i < n; ++i)
            result.push_back(generate());
        return result;
    }


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