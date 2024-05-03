#include<bits/stdc++.h>
using namespace std;

class ATM {
private:
    vector<int> denominations;
    vector<int> countingOfNotes;

public:
    // Constructor to initialize ATM with denominations and notes count
    ATM(vector<int> denomimations, vector<int> counts) {
        denominations = denomimations;
        countingOfNotes = counts;
    }

   /*
   DESC:- Here create a function that top-up ATM machine with specific note and thier count
   Input:- Take denomination like(2000,500,200,100) and there count
   
   */

    void topUp(int denomimation, int count) {
        // finding the denominationPosition
        auto denominationPosition = find(denominations.begin(), denominations.end(), denomimation);
        if (denominationPosition != denominations.end()) {
            int index = denominationPosition - denominations.begin();   //find index of particular denomination
            countingOfNotes[index] += count;
        } else {
            // if domination not found then add new the domination if modi ji add new note like 5000
            denominations.push_back(denomimation);
            countingOfNotes.push_back(count);
        }
    }
     
    /*
     DESC:- Here create a function to withdraw an amount from atm
     Input:- Amount that you want to withdraw
     Output:- if there is available balace in your account it gives the specific currecy 
    */ 
    
    void withdraw(int amount) {
        vector<int> result;
        for (int i = denominations.size() - 1; i >= 0; i--) {
            int denomination = denominations[i];
            // count is calculated 
            int count = amount / denomination;
            // amount left to be calculated
            amount = amount - (count * denomination);

            // insert funtion insert the denomination and count that how many copies of denomination be inserted
            // like if amount is 5700 then 2000 note should be 2 times inserted 
            result.insert(result.end(), count, denomination);
        }
        if (amount != 0) {
            cout << "Insufficient balance or invalid denomination\n";
        } else {
            cout << "Total money that has been withdraw: ";
            for (int note : result) {
                cout << note << " ";    //it print the remaining balance with has less than 100
            }
            cout << "\n";
        }
    }
};

int main() {

    /*
     DESC:- Initialize ATM with initial denominations and notes count
     Notes:-This task design for if in future any new denomination present by gov.
             than out system easily add those currency with minimal changes.
     Future:-If any new note comes than we add in simply denominations vector and
              simply topup the atm and withdraw the new note easily        
    */

    vector<int> denominations = {100, 200, 500, 2000}; // create vector so it dynamically accpet if any onter denomination add in future
    vector<int> countingOfNotes = {10, 5, 3, 2};
    ATM atm(denominations, countingOfNotes);

    // Top-up ATM with additional denominations and counts
    atm.topUp(2000, 20);   // Add 20 more notes of 2000 INR
    atm.topUp(500, 2);     // Add 2 more notes of 500 INR (we add 5000 note here if any change in future occur by modi ji)

    // Withdraw cash
    atm.withdraw(8300);  // Expected output: 2000 2000 2000 2000 200 100
    atm.withdraw(2100);  // Expected output: 2000 100

    return 0;
}




