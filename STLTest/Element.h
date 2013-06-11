///////////////////////////////////////
// Workfile    : Element.h
// Author      : Matthias Schett
// Date        : 16-05-2013
// Description : Stl algorithm tests
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "RandomGen.h"
#include <ostream>

class Element{

private:
    int mRandNum;
    int mIndex;

public:

    Element(int randNum, int index);
    
    // Access Methods
    int getRandNum() const;
    int getIndex() const;

    bool operator<(Element const &e2);    
};

inline std::ostream &operator << (std::ostream &out, const Element & elem){
    out << elem.getRandNum() << "-" << elem.getIndex() << "  ";
    return out;
}

inline bool operator<(Element const &e1, Element const &e2){
    return ( e1.getRandNum() < e2.getRandNum() );
}
