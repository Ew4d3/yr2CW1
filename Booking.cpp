#include "Booking.h" //inc header file

//blank constr not needed like flights

Booking::Booking(const std::string& passengerId, const std::string& flightCode, const std::string& date, const std::string& seatClass) //main constr

    : passengerId_(passengerId), flightCode_(flightCode), date_(date), seatClass_(seatClass) { //empty body just init list to assign val to priv 

    }

const std::string& Booking::getPassengerId() const {   
    return passengerId_; 
}

const std::string& Booking::getFlightCode() const {  
    return flightCode_; 
}

const std::string& Booking::getDate() const {  
    return date_; 
}

const std::string& Booking::getSeatClass() const {  
    return seatClass_; 
}





