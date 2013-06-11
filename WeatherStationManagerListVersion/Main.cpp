///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <vld.h>
#include <iostream>
#include "WeatherStations.h"

using namespace std;

int main(){

    WeatherStation ws1 ("WS1", 18.3, 99);
    WeatherStation ws2 ("WS2", 6.3, 12);
    WeatherStation ws3 ("WS3", -17, 14);
    WeatherStation ws4 ("WS1", -19, 22);

    WeatherStations wsManager;

    cout << "Test Add" << endl;

    wsManager.Add(ws1);
    wsManager.Add(ws2);
    wsManager.Add(ws3);
    wsManager.Add(ws1);
    
    cout << endl;
    cout << "Test PrintAll" << endl;
    
    wsManager.PrintAll(cout);
    cout << endl;
    cout << "Test Getter" << endl;

    cout << "Should return 3: " << wsManager.GetNrStations() << endl;
    cout << endl;
    
    cout << "Test Duplicates" << endl;
    cout << ws4 << endl;
    cout << "Add and Print All" << endl;
    wsManager.Add(ws4);
    wsManager.PrintAll(cout);

    cout << endl;
    cout << "Test copy constr" << endl;
    cout << endl;
    WeatherStations wsManager1 (wsManager);

    cout << "Coldest of original: ";
    wsManager.PrintColdest(cout);

    cout << endl << "Coldest of copy: ";
    wsManager1.PrintColdest(cout);
    cout << endl;
    cout << endl << "Test Assignment operator" << endl;

    WeatherStations wsManager2 = wsManager;
    cout << endl;
    cout << "Warmest of original: ";
    wsManager.PrintWarmest(cout);

    cout << endl << "Warmest of copy: ";
    wsManager2.PrintWarmest(cout);

    cin.get();
    return 0;
}