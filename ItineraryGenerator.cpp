#include "ItineraryGenerator.h"

#include <fstream> //read from file
#include <sstream> //read from string

using namespace std;

bool ItineraryGenerator::loadFlights(const std::string& filename) { //func returns true if file loaded successfully, false if not - lines 9+18
    std::ifstream in(filename.c_str()); //open file assigned to in , for reading
    if (!in) return false; //if file not opened successfully, return false

    std::string code, destination;
    int duration;
    while (in >> code >> destination >> duration) { //read each line of file in , assign to vars
        flights_[code] = Flight(code, destination, duration); //create flight obj w values, assign to map flights_ with code as key
   
    }

      return true;

}



bool ItineraryGenerator::loadBookings(const std::string& filename) {
    std::ifstream in(filename.c_str());  //same as above but for bookings
    if (!in) return false; 

    std::string passenger, flightCode, date, seatClass; 
    while (in >> passenger >> flightCode >> date >> seatClass) { //same as above
        bookings_[passenger][date].push_back(Booking(passenger, flightCode, date, seatClass));    


    }


    return true;
}


bool ItineraryGenerator::processRequests(const string& filename, ostream& out) const {
    ifstream in(filename.c_str());
    if (!in) return false;

    string line;
    while (getline(in, line)) { 
        istringstream iss(line); //read line into iss
        string passengerId, date; //read into these vars
        if (!(iss >> passengerId)) continue; //blank line = skip
        iss >> date; //else date = empty

        out << "Passenger ID: " << passengerId << "\n";
        if (!date.empty()) {
            out << "  (date requested: " << date << ")\n";   // temporary, for testing
        }
    }
    return true;
}

