///////////////////////////////////////
// Workfile    : WeatherStations.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////
#include "WeatherStations.h"
#include <algorithm>

bool findColdest(WeatherStation const &ws1, WeatherStation const &ws2){
    return ws1.GetCelsius() < ws2.GetCelsius();
}

bool findWarmest(WeatherStation const &ws1, WeatherStation const &ws2){
    return ws1.GetCelsius() > ws2.GetCelsius();
}

bool sortByName(WeatherStation const &ws1, WeatherStation const &ws2){
    return ws1.GetName() < ws2.GetName();
}

class RemoveWithName{
private:

    WeatherStation wsIntern;

public:
    RemoveWithName(WeatherStation const & ws) : wsIntern(ws){
    }

    bool operator () (WeatherStation const &ws1){
        return ws1.GetName() == wsIntern.GetName();
    }

};

void WeatherStations::Add(WeatherStation const &ws){
    if(mWeatherStations.empty()){
        mWeatherStations.push_front(ws);
    } else{
        // using standard functions just push it to the back then sort and remove duplicates
        mWeatherStations.remove_if(RemoveWithName(ws));
        mWeatherStations.push_back(ws);
        mWeatherStations.sort(sortByName);
    }
}

// Returns the number of weather stations
size_t WeatherStations::GetNrStations() const{
    return mWeatherStations.size();
}

// Prints all weather stations
void WeatherStations::PrintAll(std::ostream &out) const{
    if(!mWeatherStations.empty()){
        for (std::list<WeatherStation>::const_iterator it = mWeatherStations.begin(); it != mWeatherStations.end(); ++it) {
            it->Print(out);
        }
    } else{
        out << "The list is empty" << std::endl;
    }
}

// Prints coldest/warmest weather station
void WeatherStations::PrintColdest(std::ostream &out) const {
    try{
        searchForColdest().Print(out);
    } catch(WeatherException& e){
        std::cout << e.what() << std::endl;
    }
}
void WeatherStations::PrintWarmest(std::ostream &out) const{
    try{
        searchForWarmest().Print(out);
    } catch(WeatherException& e){
        std::cout << e.what() << std::endl;
    }
}

WeatherStation WeatherStations::searchForColdest() const{
    if(!mWeatherStations.empty()){
        std::list<WeatherStation>::const_iterator it = std::min_element(mWeatherStations.begin(), mWeatherStations.end(), findColdest);
        return *it;
    } else {
        throw WeatherException("No stations are defined");
    }
}

WeatherStation WeatherStations::searchForWarmest() const{
    if(!mWeatherStations.empty()){
        std::list<WeatherStation>::const_iterator it = std::max_element(mWeatherStations.begin(), mWeatherStations.end(), findWarmest);
        return *it;
    } else {
        throw WeatherException("No stations are defined");
    }
}