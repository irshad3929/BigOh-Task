#include <bits/stdc++.h>

using namespace std;

// farword class to avoid error in future
class Hotel;
class User;
class UserManagement;
class Admin;
class AdminManagement;
class HotelAgent;
class HotelAgentManagement;
class HotelManagementSystem;

enum RoomStatus
{
    AVAILABLE,
    RESERVED,
    BOOKED
};

enum HotelRating
{
    BAD,
    GOOD,
    BEST
};

class Location
{
    int pin;
    string area;
    string city;
    string country;

public:
    Location(int pin, string area, string city, string country)
        : pin(pin), area(area), city(city), country(country) {}

    // getter function
    int getPin()
    {
        return pin;
    }
    string getArea()
    {
        return area;
    }
    string getCity()
    {
        return city;
    }
    string getCountry()
    {
        return country;
    }

    // setter function
    void setPin(int pin)
    {
        pin = pin;
    }
    void setArea(string area)
    {
        area = area;
    }
    void setCity(string city)
    {
        city = city;
    }
    void setCountry(string country)
    {
        country = country;
    }
};

class Hotel
{
    string hotelName;
    int hotelId;
    Location *location;
    RoomStatus roomStatus;
    HotelRating roomRating;

public:
    // constructor
    Hotel(string hotelName, int hotelId, Location *location, RoomStatus roomStatus, HotelRating roomRating)
        : hotelName(hotelName), hotelId(hotelId), location(location), roomStatus(roomStatus), roomRating(roomRating) {}

    // getter
    string getHotelName()
    {
        return hotelName;
    }
    int getHotelId()
    {
        return hotelId;
    }

    Location *getLocation()
    {
        return location;
    }
    RoomStatus getRoomStatus()
    {
        return roomStatus;
    }
    HotelRating getRoomRating()
    {
        return roomRating;
    }

    // setter
    void setHotelName(string hotelName)
    {
        hotelName = hotelName;
    }
    void setHotelId(int hotelId)
    {
        hotelId = hotelId;
    }
    void setLocation(Location *location)
    {
        location = location;
    }
    void setRoomStatus(RoomStatus roomStatus)
    {
        roomStatus = roomStatus;
    }
    void setRoomRating(HotelRating roomRating)
    {
        roomRating = roomRating;
    }

    // Printing function
    void printDetails() {
        cout << "Hotel Name: " << hotelName << ", ID: " << hotelId << ", Location: " << location->getCity()
             << ", Status: " << roomStatus << ", Rating: " << roomRating << endl;
    }
};
// class for normal user
class User
{
    int userId;
    string name;
    string password;

public:
    User(int userId, string name, string password)
        : userId(userId), name(name), password(password) {}

    // getter function
    int getUserId()
    {
        return userId;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }

    // setter
    void setUserId(int userId)
    {
        userId = userId;
    }
    void setName(string name)
    {
        name = name;
    }
    void setPassword(string password)
    {
        password = password;
    }

    // Printing function
    void printDetails(){
        cout << "User ID: " << userId << ", Name: " << name << endl;
    }
};

// Admin class
class Admin
{
    int adminId;
    string name;
    string password;

public:
    Admin(int userId, string name, string password)
        : adminId(userId), name(name), password(password) {}

    // getter
    int getAdminId()
    {
        return adminId;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }

    // setter
    void setAdminId(int adminId)
    {
        adminId = adminId;
    }
    void setName(string name)
    {
        name = name;
    }
    void setPassword(string password)
    {
        password = password;
    }

    void printDetails(){
        cout << "Admin ID: " << adminId << ", Name: " << name << endl;
    }
};

class HotelAgent
{
    int hotelAgentId;
    string name;
    string password;

public:
    HotelAgent(int hotelAgentId, string name, string password) : hotelAgentId(hotelAgentId), name(name), password(password) {}

    // getter
    int getHotelAgentId()
    {
        return hotelAgentId;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }

    // setter
    void setHotelAgentId(int hotelAgentId)
    {
        hotelAgentId = hotelAgentId;
    }
    void setName(string name)
    {
        name = name;
    }
    void setPassword(string password)
    {
        password = password;
    }

     void printDetails() {
        cout << "Agent ID: " << hotelAgentId << ", Name: " << name << endl;
    }
};

// create a middleware for communication between each other
class HotelManagementSystem
{
    vector<Hotel *> hotels;
    vector<User *> users;
    vector<Admin *> admins;
    vector<HotelAgent *> hotelAgents;

public:
    void addHotel(Hotel *hotel)
    {
        hotels.push_back(hotel);
    }
    void addUser(User *user)
    {
        users.push_back(user);
    }
    void addAdmin(Admin *admin)
    {
        admins.push_back(admin);
    }
    void addHotelAgent(HotelAgent *hotelAgent)
    {
        hotelAgents.push_back(hotelAgent);
    }

    void removeHotel(int hotelId)
    {
        for (auto it = hotels.begin(); it != hotels.end(); ++it)
        {
            if ((*it)->getHotelId() == hotelId)
            {
                hotels.erase(it);
                break;
            }
        }
    }

    void removeUser(int userId)
    {
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            if ((*it)->getUserId() == userId)
            {
                users.erase(it);
                break;
            }
        }
    }

     // Printing function
    void printHotelDetails() {
        cout << "--- Hotels ---" << endl;
        for (auto hotel : hotels) {
            hotel->printDetails();
        }
    }
};

// Class for the admin management
class AdminManagement
{
    HotelManagementSystem *middleWare;
    vector<Admin *> admins;
public:
    AdminManagement(HotelManagementSystem *middleWare) : middleWare(middleWare) {}

    // Methods for admin management
    void addAdmin(Admin *admin)
    {
        middleWare->addAdmin(admin);
    }

     void addUser(User *user)
    {
        middleWare->addUser(user);
    }

    void addHotel(Hotel *hotel)
    {
        middleWare->addHotel(hotel);
    }

    void removeUser(int userId)
    {
        middleWare->removeUser(userId);
    }

    void removeHotel(int hotelId)
    {
        middleWare->removeHotel(hotelId);
    }

    // Printing function
    void printAdminDetails() {
        cout << "---- Admins ----" << endl;
        for (auto admin : admins) {
            admin->printDetails();
        }
    }
};

// Class for the hotel agent management
class HotelAgentManagement
{
    HotelManagementSystem *middleWare;
    vector<HotelAgent *> hotelAgents;

public:
    HotelAgentManagement(HotelManagementSystem *middleWare) : middleWare(middleWare) {}

    // Methods for hotel agent management
    void addHotelAgent(HotelAgent *hotelAgent)
    {
        hotelAgents.push_back(hotelAgent);
    }

    // User registration
    void registerAgent(int hotelAgentId, string name, string password) {
        HotelAgent *agent = new HotelAgent(hotelAgentId, name, password);
        hotelAgents.push_back(agent);
        cout << "Hotel agent registered successfully!\n";
    }

     //Printing function
    void printHotelAgentDetails() {
        cout << "---- Hotel Agents ----" << endl;
        for (auto agent : hotelAgents) {
            agent->printDetails();
        }
    }

    
};

// user management class
class UserManagement {
    HotelManagementSystem *middleWare;
    vector<Hotel *> hotels;
    vector<User *> users;

public:
    UserManagement(HotelManagementSystem *middleWare) : middleWare(middleWare) {}
     
   //add user
    void addUser(User *user){
        users.push_back(user);
    }

    // User registration
    void registerUser(int userId, string name, string password) {
        User *user = new User(userId, name, password);
        users.push_back(user);
        cout << "User registered successfully!\n";
    }

    // Search hotels
    void searchHotel(string location) {
        for (auto hotel : hotels) {
            if (hotel->getLocation()->getCity() == location) {
                cout << "Hotel Name: " << hotel->getHotelName() << ", Rating: " << hotel->getRoomRating() << endl;
            }
        }
    }

    // Book a hotel
    void bookHotel(int userId, int hotelId) {
        cout << "Hotel booked successfully!\n";
    }

    // Modify user details
    void modifyUserDetails(int userId, string newName, string newPassword) {
        for (auto user : users) {
            if (user->getUserId() == userId) {
                user->setName(newName);
                user->setPassword(newPassword);
                cout << "User details modified successfully!\n";
                return;
            }
        }
        cout << "User not found!\n";
    }

    void printUserDetails() const {
        cout << "---- Users ----" << endl;
        for (auto user : users) {
            user->printDetails();
        }
    }
};

int main()
{
    // Sample usage
    // HotelManagementSystem middleware;
    // AdminManagement adminManagement(&middleware);
    // UserManagement userManagement(&middleware);
    // HotelAgentManagement hotelAgentManagement(&middleware);

    // // Adding some hotels
    // Location *location1 = new Location(1234, "ashoknagar", "delhi", "India");
    // Location *location2 = new Location(5678, "sector 2", "Noida", "India");
    // Hotel *hotel1 = new Hotel("Hotel A", 1, location1, AVAILABLE, GOOD);
    // Hotel *hotel2 = new Hotel("Hotel B", 2, location2, RESERVED, BEST);
    // middleware.addHotel(hotel1);
    // middleware.addHotel(hotel2);

    // // Adding users and admins
    // adminManagement.addAdmin(new Admin(1, "Admin 1", "adminpass"));
    // adminManagement.addAdmin(new Admin(2, "Admin 2", "adminpass"));



    // // Adding a user
    // userManagement.registerUser(1, "irshad", "password123");

    // // Adding hotel agents
    // hotelAgentManagement.registerAgent(1, "Agent 1", "agentpass");
    // hotelAgentManagement.registerAgent(2, "Agent 2", "agentpass");

    //  // Printing details
    // middleware.printHotelDetails();
    // adminManagement.printAdminDetails();
    // userManagement.printUserDetails();
    // hotelAgentManagement.printHotelAgentDetails();

    // // Searching hotels
    // userManagement.searchHotel("India");

    // // Modifying user details
    // userManagement.modifyUserDetails(1, "sahil", "newpassword456");


    return 0;
}