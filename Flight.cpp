#include "Flight.h" //inc header file

Flight::Flight() : code_(""), destination_(""), durationMins_(0) {} //constr for if no code found for map

Flight::Flight(const std::string& code, const std::string& destination, int durationMins) //main constr
    : code_(code), destination_(destination), durationMins_(durationMins) { //same empty body as booking

    }

const std::string& Flight::getCode() const {  //getter meths 
    return code_; 
}

const std::string& Flight::getDestination() const { 
    return destination_; 
}

int Flight::getDuration() const { 
    return durationMins_; 
}










