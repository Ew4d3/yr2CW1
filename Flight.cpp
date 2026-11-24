#include "Flight.h" 

// Default constr required by std::map::operator[], which default-constructs
//a Flight before it is assigned in loadFlights().
Flight::Flight() : code_(""), destination_(""), durationMins_(0) {} 

Flight::Flight(const std::string& code, const std::string& destination, int durationMins) //main constr
    : code_(code), destination_(destination), durationMins_(durationMins) { //same empty body as booking

    }

const std::string& Flight::getCode() const { 
    return code_; 
}

const std::string& Flight::getDestination() const { 
    return destination_; 
}

int Flight::getDuration() const { 
    return durationMins_; 
}










