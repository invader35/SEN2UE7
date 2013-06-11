///////////////////////////////////////
// Workfile    : WeatherStations.h
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "WeatherStation.h"
#include <iostream>
#include <exception>
#include <list>

class WeatherException : public std::exception
{
public:
    WeatherException(const char* errMessage):errMessage_(errMessage){}
    // overriden what() method from exception class
    const char* what() const throw() { return errMessage_; }

private:
    const char* errMessage_;
};

class WeatherStations {

private:

    // member variables
    std::list<WeatherStation> mWeatherStations;

    // private helper methods
    // Search for the coldes station
    WeatherStation searchForColdest() const;
    // Search for the warnest station
    WeatherStation searchForWarmest() const;

public:
    
    //************************************
    // Method:    Add
    // FullName:  WeatherStations::Add
    // Access:    public 
    // Returns:   bool
    // Qualifier:
    // Parameter: WeatherStation const & ws
    // Adds a weather station
    //************************************
    void Add(WeatherStation const &ws);
    
    //************************************
    // Method:    Remove
    // FullName:  WeatherStations::Remove
    // Access:    public 
    // Returns:   bool
    // Qualifier:
    // Parameter: WeatherStation const & ws
    // Removes a weather station
    //************************************
    bool Remove(WeatherStation const& ws);

    // Returns the number of weather stations
    size_t GetNrStations() const;

    
    //************************************
    // Method:    PrintAll
    // FullName:  WeatherStations::PrintAll
    // Access:    public 
    // Returns:   void
    // Qualifier: const
    // Parameter: std::ostream & out
    // Prints all weather stations
    //************************************
    void PrintAll(std::ostream &out) const;

    
    //************************************
    // Method:    PrintColdest
    // FullName:  WeatherStations::PrintColdest
    // Access:    public 
    // Returns:   void
    // Qualifier: const
    // Parameter: std::ostream & out
    // Prints the coldest weather station
    //************************************
    void PrintColdest(std::ostream &out) const;

    //************************************
    // Method:    PrintWarmest
    // FullName:  WeatherStations::PrintWarmest
    // Access:    public 
    // Returns:   void
    // Qualifier: const
    // Parameter: std::ostream & out
    // Prints the warmest weather station
    //************************************
    void PrintWarmest(std::ostream &out) const;

};