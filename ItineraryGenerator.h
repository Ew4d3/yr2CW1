#ifndef ITINERARY_GENERATOR_H //guard
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
    bool loadBookings(const std::string& filename); 
    bool processRequests(const std::string& filename, std::ostream& out) const; //reads requests.txt + writes one itinerary per request to out


    //test
    //std::size_t countBookings(const std::string& passengerId) const;


private:
    // Prints one date block- the flights then total flights
    void printFlightsOnDate(const std::string& date, const std::vector<Booking>& bookings, std::ostream& out) const; 

    std::map<std::string, Flight> flights_; //map called flights_that maps str flight code to Flight val
    std::map<std::string, std::map<std::string, std::vector<Booking>>> bookings_; //passengerId -> bookings by date
};

#endif










