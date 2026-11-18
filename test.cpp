#include <iostream>
#include "ItineraryGenerator.h"
using namespace std;

int main() {
    ItineraryGenerator g;
    g.loadFlights("flights.txt.txt");
    g.loadBookings("bookings.txt.txt");
    if (!g.processRequests("requests.txt.txt", cout)) {
        cout << "Could not open requests\n";
    }
    return 0;
}