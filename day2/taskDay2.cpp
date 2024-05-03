#include <bits/stdc++.h>
using namespace std;

/*
 DESC:- Here create a Enum(user defined data type)
 enum class:- ParkingSpotType,PaymentType
 forward class:- ParkingFloor,ParkingSpot, ParkingAttendant
*/
enum class ParkingSpotType {
    COMPACT,
    LARGE,
    HANDICAPPED,
    MOTORCYCLE,
    ELECTRIC
};

enum class PaymentType {
    CASH,
    CREDIT_CARD
};

// Forward declarations
class ParkingFloor;
class ParkingSpot;
class ParkingAttendant;

// Class Address for storing address details
class Address {
public:
    string country;
    string state;
    string city;
    string street;
    string zipCode;
};

// Class for representing a Parking Ticket
class ParkingTicket {
public:
    int ticketNumber;
    time_t entryTime;
    ParkingSpot* parkingSpot;
    bool paid;

    ParkingTicket(int ticketNumber, time_t entryTime, ParkingSpot* parkingSpot)
        : ticketNumber(ticketNumber), entryTime(entryTime), parkingSpot(parkingSpot), paid(false) {}
};

// Class for Payment Information
class PaymentInfo {
public:

    int transactionId;
    time_t paymentTime;
    double amount;
    PaymentType paymentType;

    PaymentInfo(int transactionId, time_t paymentTime, double amount, PaymentType paymentType)
        : transactionId(transactionId), paymentTime(paymentTime), amount(amount), paymentType(paymentType) {}
};

// Class for Parking Spot
class ParkingSpot {
public:
    int spotNumber;
    bool occupied;
    ParkingSpotType type;

    ParkingSpot(int spotNumber, ParkingSpotType type) : spotNumber(spotNumber), type(type), occupied(false) {}
};

/*
 DESC:- Here create a ParkingFloor clasa
 Method:- here two function addParkingSpot and updateFreeSpotsAvailable that shoud be manager by Admin

*/
class ParkingFloor {
public:
    int floorNumber;
    vector<ParkingSpot*> spots;
    unordered_map<ParkingSpotType, int> freeSpots; // Stores number of free spots for each spot type

    ParkingFloor(int floorNumber) : floorNumber(floorNumber) {}

    void addParkingSpot(ParkingSpot* spot) {
        spots.push_back(spot);
        freeSpots[spot->type]++;
    }

    void updateFreeSpotsAvailable() {
        for (auto spot : spots) {
            if (!spot->occupied) {
                freeSpots[spot->type]++;
            }
        }
    }
};

/*
 DESC:- Here create a ParkingLot clasa
 Method:- here a function addParkingFloor that shoud be manager by Admin
 Relation:- A ParkingLot has many ParkingFloor
*/

class ParkingLot {
public:
    vector<ParkingFloor*> floors;
    Address address;
    string name;

    ParkingLot(Address address, string name) : address(address), name(name) {}

    void addParkingFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }
};

//class ParkingAttendant
class ParkingAttendant {
public:
    bool processVehicleEntry(ParkingTicket* ticket) {
        // Logic for processing vehicle entry
        if (ticket) {
            return true;
        }
        return false;
    }
};

/*
 DESC:- Here create a Admin class
 Method:- here Admin perform CRUD operation like addParkingFloor,addParkingSpot,removeParkingSpot,updateParkingSpotType
*/

class Admin {
public:
    bool addParkingFloor(ParkingLot* parkingLot, ParkingFloor* floor) {
        if (parkingLot && floor) {
            parkingLot->addParkingFloor(floor);
            return true;
        }
        return false;
    }

    bool addParkingSpot(ParkingFloor* floor, ParkingSpot* spot) {
        if (floor && spot) {
            floor->addParkingSpot(spot);
            return true;
        }
        return false;
    }

    bool removeParkingSpot(ParkingFloor* floor, ParkingSpot* spot) {
        if (floor && spot) {
            auto it = find(floor->spots.begin(), floor->spots.end(), spot);
            if (it != floor->spots.end()) {
                floor->spots.erase(it);
                delete spot;
                return true;
            }
        }
        return false;
    }

    bool updateParkingSpotType(ParkingSpot* spot, ParkingSpotType newType) {
        if (spot) {
            spot->type = newType;
            return true;
        }
        return false;
    }
};


int main() {
    // Create Parking Lot
    //  Address lotAddress{"india", "up", "lucknow", "Main Street", "15201"};
  

    // // Create Parking Floors
    //  ParkingFloor* groundFloor = new ParkingFloor(0);
    //  ParkingFloor* firstFloor = new ParkingFloor(1);
    //  ParkingFloor* secondFloor = new ParkingFloor(2);

    // // Create Admin
    // Admin admin;


    return 0;
}
