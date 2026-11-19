#include "ItineraryGenerator.h"

#include <fstream> //read from file
#include <sstream> //read from string

using namespace std;

    //req num 1-5
    //1 - Passenger ID starts at the beginning of the line 
    //2 - Date lines start with two spaces 
    //3 - Flight details start with four spaces
    //4 - Totals start with two spaces
    //5 - mins enclosed in brackets + end w colon

//print all flights on date
void ItineraryGenerator::printFlightsOnDate(const string& date, const vector<Booking>& bookings, ostream& out) 
    const {out << "  Date " << date << ":\n"; //req 2 - print date w 2 spaces 

    for (size_t i = 0; i < bookings.size(); ++i) { //loop through bookings vector
        const Booking& booking = bookings[i]; 
        auto flight = flights_.find(booking.getFlightCode()); //find flight in flights_ map using flight code from booking

        //following adheres to formatting reqs , prints w propa formatting 4 spaces, mins in brace etc
        out << "    " << flight->second.getCode() << " " 
            << flight->second.getDestination() << " (" << flight->second.getDuration() << " mins): " //req 5
            << booking.getSeatClass() << "\n"; 

    }
    
    out << "  Total Flights: " << bookings.size() << "\n" << "\n"; //req 4 - print total no of flights 


}


bool ItineraryGenerator::loadFlights(const std::string& filename) { //func returns true if file loaded successfully, false if not - func line 3
    std::ifstream file(filename.c_str()); //open file assigned to file for reading
    if (!file) return false; //if file not opened ret false

    std::string code, destination; 
    int duration;
    while (file >> code >> destination >> duration) { //read each line of the file in+assign to vars
        flights_[code] = Flight(code, destination, duration); //create flight obj w values, assign to map flights_ with code as key
   

    }

    return true;

}


bool ItineraryGenerator::loadBookings(const std::string& filename) {
    std::ifstream file(filename.c_str());  //same as above but for bookings
    if (!file) return false; 

    std::string passenger, flightCode, date, seatClass; 
    while (file >> passenger >> flightCode >> date >> seatClass) { //same as above
        bookings_[passenger][date].push_back(Booking(passenger, flightCode, date, seatClass));    


    }


    return true;
}



//If only a passenger ID is given, print the full itinerary
//If a date is provided, print only flights for that date
bool ItineraryGenerator::processRequests(const string& filename, ostream& out) const { 
    ifstream file(filename.c_str());
    if (!file) return false;


    string line; 
    while (getline(file, line)) { //read each line of file in , assign to line
        istringstream iss(line); //new string stream iss to read from line
        string passengerId, date; 
        if (!(iss >> passengerId)) continue; //if no pId next line
        iss >> date; 

        out << "Passenger ID: " << passengerId << "\n"; //req 1 - print pId 



        if (!date.empty()) { //if date specified
            auto pId = bookings_.find(passengerId); 
            if (pId != bookings_.end()) { //find pId in map
                auto flyDate = pId->second.find(date); //find date in map of dates for pId
                if (flyDate != pId->second.end()) { //if date found print flights on date
                    printFlightsOnDate(date, flyDate->second, out);
                }

            }


        }



        else { //no date, print full itinerary
            size_t overall = 0;  //if date empty 
            auto pId = bookings_.find(passengerId); //rest is same as above
            if (pId != bookings_.end()) { 
                for (auto flyDate = pId->second.begin(); flyDate != pId->second.end(); ++flyDate) { //loop through as print all flights 
                    printFlightsOnDate(flyDate->first, flyDate->second, out); 
                    overall += flyDate->second.size(); //add to overall total no flights
                }
            }

            //req 4 part 2 - only print overall flights for no date provided. otherwise total as per line IG func last line
            out << "  Overall Flights: " << overall << "\n\n";  //added double newline for easier to read formatting 

        }



    }

    return true;




}








