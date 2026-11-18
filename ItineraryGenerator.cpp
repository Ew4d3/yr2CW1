#include "ItineraryGenerator.h"

#include <fstream> //read from file
#include <sstream> //read from string

using namespace std;

//print all flights on date
void ItineraryGenerator::printFlightsOnDate(const string& date, const vector<Booking>& bookings, ostream& out) 
    const {out << "  Date " << date << ":\n"; //print date

    for (size_t i = 0; i < bookings.size(); ++i) { //loop through bookings vector
        const Booking& b = bookings[i]; 
        auto f = flights_.find(b.getFlightCode()); //find flight in flights_ map using flight code from booking
        out << "    " << f->second.getCode() << " " //following prints w propa formatting 4 spaces etc
            << f->second.getDestination() << " ("  
            << f->second.getDuration() << " mins): " 
            << b.getSeatClass() << "\n";
    }
    out << "  Total Flights: " << bookings.size() << "\n"; //print total no of flights
}


bool ItineraryGenerator::loadFlights(const std::string& filename) { //func returns true if file loaded successfully, false if not - lines 9+18
    std::ifstream in(filename.c_str()); //open file assigned to in , for reading
    if (!in) return false; //if file not opened successfully, return false

    std::string code, destination;
    int duration;
    while (in >> code >> destination >> duration) { //read each line of the file in+assign to vars
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
    while (getline(in, line)) { //read each line of file in , assign to line
        istringstream iss(line); 
        string passengerId, date;
        if (!(iss >> passengerId)) continue; //if no passengerId, skip to next line
        iss >> date;

        out << "Passenger ID: " << passengerId << "\n"; //print passengerId

        if (!date.empty()) { 
            auto p = bookings_.find(passengerId);
            if (p != bookings_.end()) { //find pas in map
                auto d = p->second.find(date); //find date in map of dates for passengerId
                if (d != p->second.end()) { //if date found, print flights on date for passenger
                    printFlightsOnDate(date, d->second, out); 
                }
            }
        }

        else {
            size_t overall = 0;  //if date is empty, print all flights for passenger as per spec
            auto p = bookings_.find(passengerId); //rest is same as above
            if (p != bookings_.end()) { 
                for (auto d = p->second.begin(); d != p->second.end(); ++d) { //loop through as print all flights 
                    printFlightsOnDate(d->first, d->second, out); 
                    overall += d->second.size(); //add to overall total no flights
                }
            }
            out << "  Overall Flights: " << overall << "\n"; 
        }


    }
    return true;
}