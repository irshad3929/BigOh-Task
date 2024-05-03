#include<bits/stdc++.h>
using namespace std;


/*
DESC:- Here City class define 
*/
class City{
private:
    int cityId;
    string name;
    int countryId;
    
public:
    //constructor
    City(int cityId, string &cityName, int countryId) : cityId(cityId), name(cityName), countryId(countryId) {}
    //getter function
    int getCityId() const {return cityId;}
    string getName() const {return name;}
    int getCountryId() const {return countryId;}
    City(){
      //default constructure
    }

};

/*
DESC:- Here Country class define 
*/

class Country{
private:
    int countryId;
    string name;
public:
    
    City city;  //Country has a city
    //make a constructor
    Country(int cid, string& countryName) : countryId(cid), name(countryName){}

    //getter function
    int getCountryId() const {return countryId;}
    string getName() const  {return name;}
};

/*
DESC:- Here Brick class define which show all property
*/


class Brick {
private:
    string owner;
    string caption;
    string message;
    string dedicateTo;
    bool visible;
    int flagCount;
    vector<Brick> noOfBricks;
public:
    Brick(string own, string capt, string mess, string dedicate) : owner(own),caption(capt),message(mess),dedicateTo(dedicate),visible(true),flagCount(0){}  
       
    // Getters and setters
    string getOwner() const { return owner; }
    string getCaption() const { return caption; }
    string getMessage() const { return message; }
    string getDedicateTo() const { return dedicateTo; }
    bool isVisible() const { return visible; }
    int getFlagCount() const { return flagCount; }

    void setVisible(bool visible) { visible = visible; }
    void increaseFlagCount() { flagCount++; }

    void addBrick(const Brick& brick) {
        noOfBricks.push_back(brick);       //function that add bricks
    }
};

/*
DESC:- Here Wall class define which show bricks on wall
*/

class Wall {
private:
    vector<Brick> bricks;
    int wallNumber;

public:
    Wall(int wallNum) : wallNumber(wallNum) {}
    
    void addBrick(const Brick& brick) {
        bricks.push_back(brick);      
    }
    

    // Getters
    int getWallNumber() const { return wallNumber; }
    int getNumBricks() const { return bricks.size(); }
    vector<Brick>& getBricks() { return bricks; }
};

/*
DESC:- Here User class define
Operation:-  user can edit own bricks only
*/

class User {
private:
    string name;
    vector<Brick*> ownedBricks;

public:
    User(string name) : name(name) {}

    string getName() const { return name; }

    void addBrick(Brick* brick) {
        ownedBricks.push_back(brick);
    }

   vector<Brick*>& getOwnedBricks() { return ownedBricks; }
};

/*
DESC:- Here Admin class define
Operation:-  Admin can edit any bricks
*/

class Admin {
public:
    static void editBrick(Brick& brick, string newCaption, string newMessage, string newDedicateTo) {
        brick.setVisible(true);
        brick.increaseFlagCount(); // Reset flag count after editing
       
    }
};

/*
DESC:- Here Wallmanagher class define
Operation:-  WallManager can define the hottest guy and lonelyGuy
*/

class WallManager {
private:
    vector<Wall> walls;

public:
   
};

int main(){

    return 0;
}