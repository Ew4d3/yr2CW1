#include "Booking.h" //inc header file

//blank constr not needed like flights

Booking::Booking(const std::string& passengerId, const std::string& flightCode, const std::string& date, const std::string& seatClass) //main constr
    : passengerId_(passengerId), flightCode_(flightCode), date_(date), seatClass_(seatClass) {}

const std::string& Booking::getPassengerId() const {  //getter meths 
    return passengerId_; 
}

const std::string& Booking::getFlightCode() const {  //getter meths 
    return flightCode_; 
}

const std::string& Booking::getDate() const {  //getter meths 
    return date_; 
}

const std::string& Booking::getSeatClass() const {  //getter meths 
    return seatClass_; 
}

