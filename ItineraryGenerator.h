#ifndef ITINERARY_GENERATOR_H //guards
#define ITINERARY_GENERATOR_H

#include <map>
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include "Flight.h"
#include "Booking.h"


class ItineraryGenerator {
public:
    bool loadFlights(const std::string& filename); //true if file loaded successfully, false if not
    bool loadBookings(const std::string& filename); //same 
    bool processRequests(const std::string& filename, std::ostream& out) const; 

    //test
    //std::size_t countBookings(const std::string& passengerId) const;


private:
    void printFlightsOnDate(const std::string& date, const std::vector<Booking>& bookings, std::ostream& out) const; //helper func to print all flights on a given date for a given passenger

    std::map<std::string, Flight> flights_; //map called flights_that maps str flight code to Flight val
    std::map<std::string, std::map<std::string, std::vector<Booking>>> bookings_; //map called bookings_ that maps str passengerId to map that maps str flightCode to vector of Booking vals
};

#endif










