//
// Created by adzer on 29/09/2022.
//

#include "LongueurMaximal.h"

// Constructors

LongueurMaximal::LongueurMaximal(const std::vector<int> &newPolynom) {
    std::vector<bool> newVecteurInitial;
    newVecteurInitial = generateVecteurInitial(newPolynom);
    codeur = newVecteurInitial;
    vecteurInitial = newVecteurInitial;
    polynomeInt = newPolynom;
    polynomeBool = generateFromPolynopm(newPolynom);
}

std::vector<bool> LongueurMaximal::generateFromPolynopm(const std::vector<int> &poly) {
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

std::vector<bool> LongueurMaximal::generateVecteurInitial(const std::vector<int> &poly) {
    auto max = *max_element(poly.begin(), poly.end());
    std::vector<bool> newVecteurInitial;
    for (int i = 0; i < max; ++i) {
        newVecteurInitial.push_back(true);
    }

    return newVecteurInitial ;
}

std::vector<bool> LongueurMaximal::generateVecteurInitialFromTime(const std::vector<int> &poly) {
    time_t seconds = time(NULL)%codeur.size();

    auto max = *max_element(poly.begin(), poly.end());
    std::vector<bool> newVecteurInitial;
    for (int i = 0; i < max; ++i) {
        newVecteurInitial.push_back(true);
    }

    return newVecteurInitial ;
}

// Getters

LongueurMaximal::LongueurMaximal(const std::vector<int> &newPolynom, bool init) : LongueurMaximal(newPolynom){
    int i = (int) millisecond() % (int) (pow(2,vecteurInitial.size())-1);
    for (int j = 0; j < i; ++j) {
        generate();
    }
    vecteurInitial = codeur;
}

const std::vector<bool> &LongueurMaximal::getVecteurInitial() const {
    return vecteurInitial;
}

// Utilities


bool LongueurMaximal::generate() {
    bool result = codeur.back();
    bool newbite = 0;
    for (int i = polynomeBool.size(); i >= 0; i--)
        if (polynomeBool[i] == 1)
            newbite = newbite xor codeur[i];
    codeur.pop_back();
    codeur.insert(codeur.begin(),newbite);
    return result;
}

double LongueurMaximal::millisecond() {
    //TODO Tester date sur linux
#ifdef _MSC_VERstatic
    static LARGE_INTEGER frequency;
        if (frequency.QuadPart == 0)
            ::QueryPerformanceFrequency(&frequency);

        LARGE_INTEGER now;
        ::QueryPerformanceCounter(&now);
        return now.QuadPart / double(frequency.QuadPart);
#else
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return now.tv_nsec;
#endif
}
