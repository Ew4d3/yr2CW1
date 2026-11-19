#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

class Flight{ //same as booking.h but different params
    public:
        Flight(); //blank constr for if no code found for map
        Flight(const std::string& code, const std::string& destination, int durationMins );

        const std::string& getCode() const; //getter meths
        const std::string& getDestination() const;
        int getDuration() const;


    private:  //priv vars
    std::string code_;
    std::string destination_;
    int durationMins_;


};


#endif








