#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

class Flight{ //same as booking.h
    public:
        Flight();  //needed coz std::map::operator[] default-constructs values
        Flight(const std::string& code, const std::string& destination, int durationMins );

        const std::string& getCode() const; 
        const std::string& getDestination() const; //underscores kep eg New_York
        int getDuration() const; //mins


    private:  //priv vars
    std::string code_;
    std::string destination_;
    int durationMins_;


};


#endif








