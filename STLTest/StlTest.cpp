///////////////////////////////////////
// Workfile    : StlTest.cpp
// Author      : Matthias Schett
// Date        : 16-05-2013
// Description : Stl algorithm tests
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "StlTest.h"
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

struct sortCriteria{
    bool operator() (const Element &a, const Element &b){
        return ( a.getRandNum() < b.getRandNum() ) ;
    }
};

struct equalCriteria{
    bool operator() (const Element &a, const Element &b){
        return ( a.getRandNum() == b.getRandNum() ) ;
    }
};

void printVector(std::ostream &os, std::vector<Element> elemVec){
    std::ostream_iterator<Element> out_it (os);
    std::copy ( elemVec.begin(), elemVec.end(), out_it );

}

void printList(std::ostream &os, std::list<Element> elemList){
    std::ostream_iterator<Element> out_it (os);
    std::copy ( elemList.begin(), elemList.end(), out_it );
}

std::vector<Element> createRandomNumbers(int numOfRandomNum){
    vector<Element> elemVec;

    rgen::Init();

    for(int i = 0; i < numOfRandomNum; i++){
        elemVec.push_back(Element(rgen::GetRandVal(minVal, maxVal), i));
    }

    return elemVec;
}

void countFrequencyOfNumbers(std::vector<Element> elemVec){

    std::pair<std::vector<Element>::iterator,std::vector<Element>::iterator> bounds;
    int freq[11] = {0};

    for(int i = 0; i <= 10; i++){
        bounds = std::equal_range(elemVec.begin(), elemVec.end(), Element(i,0)); 
        freq[i] = (bounds.second - elemVec.begin()) - (bounds.first - elemVec.begin());
    }
    
    for(int i = 0; i < 11; i++){
        cout << "random number(" << i << "): " << freq[i] << endl;
    }
}

void doTask(vector<Element> baseVec){

    cout << "Unsorted values:" << endl;
    printVector(std::cout, baseVec);

    vector<Element> elemVec2(baseVec);

    list<Element> elemList;
    std::copy(baseVec.begin(), baseVec.end(), back_inserter(elemList));

    std::sort(baseVec.begin(), baseVec.end(), sortCriteria());
    std::stable_sort(elemVec2.begin(), elemVec2.end(), sortCriteria());
    elemList.sort(sortCriteria());

    cout << endl << endl;
    cout << "Ascending sorted values:" << endl;
    printVector(cout, baseVec);

    cout << endl << endl;
    cout << "Ascending stable_sorted values:" << endl;
    printVector(cout, elemVec2);

    cout << endl << endl;
    cout << "Ascending list sorted values:" << endl;
    printList(cout, elemList);

    cout << endl << endl;
    cout << "Frequency of random numbers" << endl;
    countFrequencyOfNumbers(baseVec);
}

void startStlTestOK(){
    cout << endl << "Test with filled vector" << endl;
    vector<Element> baseVec = createRandomNumbers(40);
    doTask(baseVec);
}

void startStlTestNOK(){
    cout << endl << "Test with empty vector" << endl;
    vector<Element> baseVec;
    doTask(baseVec);
}