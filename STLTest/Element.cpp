///////////////////////////////////////
// Workfile    : Element.cpp
// Author      : Matthias Schett
// Date        : 16-05-2013
// Description : Stl algorithm tests
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "Element.h"

using namespace std;


Element::Element(int randNum, int index) : mRandNum(randNum), mIndex(index){
}


int Element::getRandNum() const{
    return mRandNum;
}

int Element::getIndex() const{
    return mIndex;
}

bool Element::operator<(Element const &e2){
    return ( getRandNum() < e2.getRandNum() ) ;
}