#include <iostream>
#include "ItineraryGenerator.h"

using namespace std;

/*
    comp + run line
g++ -o main main.cpp Flight.cpp Booking.cpp ItineraryGenerator.cpp && ./main

*/

int main() {
    ItineraryGenerator generator;


   if (!generator.loadFlights("flights.txt")) { //if file not opened successfully, return false
        cerr << "cant open flights file\n";
        return 1;
    }

    if (!generator.loadBookings("bookings.txt")) {
        cerr << "cant open bookings file\n";
        return 1;
    }

    if (!generator.processRequests("requests.txt", cout)) {
        cerr << "cant open requests file\n";
        return 1;
    }


    return 0;



}







