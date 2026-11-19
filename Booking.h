#ifndef BOOKING_H
#define BOOKING_H
#include <string>

class Booking{ //same as flight.h but different params
    public: 
        //Booking(); blank constr not needed
        Booking(const std::string& passengerId, const std::string& flightCode, const std::string& date, const std::string& seatClass );//main constr

        const std::string& getPassengerId() const; //getter meths
        const std::string& getFlightCode() const;
        const std::string& getDate() const;
        const std::string& getSeatClass() const;



    private: //private vars
    std::string passengerId_;
    std::string flightCode_;
    std::string date_;
    std::string seatClass_;


};


#endif







