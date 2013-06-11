///////////////////////////////////////
// Workfile    : StlTest.h
// Author      : Matthias Schett
// Date        : 16-05-2013
// Description : Stl algorithm tests
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "RandomGen.h"
#include "Element.h"
#include <vector>
#include <ostream>
#include <list>

int const minVal = 0;
int const maxVal = 10;

//************************************
// Method:    startStlTest
// FullName:  startStlTest
// Access:    public 
// Returns:   void
// Qualifier:
// Starts the stl test specified in the task
//************************************
void startStlTestOK();

//************************************
// Method:    startStlTest
// FullName:  startStlTest
// Access:    public 
// Returns:   void
// Qualifier:
// Starts the stl test specified in the task with empty vectors
//************************************
void startStlTestNOK();

//************************************
// Method:    printVector
// FullName:  printVector
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: ostream & os
// Parameter: vector<Element>
// Prints the given vector
//************************************
void printVector(std::ostream &os, std::vector<Element> elemVec);


//************************************
// Method:    printList
// FullName:  printList
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: std::ostream & os
// Parameter: std::list<Element> elemVec
// Prints the given list
//************************************
void printList(std::ostream &os, std::list<Element> elemVec);

//************************************
// Method:    countFrequencyOfNumbers
// FullName:  countFrequencyOfNumbers
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: std::vector<Element> elemVec
// Counts how often a specific number occurs inside the container
//************************************
void countFrequencyOfNumbers(std::vector<Element> elemVec);

//************************************
// Method:    createRandomNumbers
// FullName:  createRandomNumbers
// Access:    public 
// Returns:   std::vector<Element>
// Qualifier:
// Parameter: int numOfRandomNum
// Creates a vector with filled with random numbers
//************************************
std::vector<Element> createRandomNumbers(int numOfRandomNum);