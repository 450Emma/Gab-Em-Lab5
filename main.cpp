#include <iostream>
#include <vector>
#include "StringData.h"

using namespace std;
// search through the list individually comparing each element
int linear_search(vector<string> container, string element){
    for(int i = 0; i < container.size() ; i++){
        if (container[i] == element){
            return i;
        }
    }
    return -1;
}

// divides list in half and checks for the placement of the element
// (either higher or lower) and repeats process
int binary_search(vector<string> container, string element){
    int low = 0;
    int high = container.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (container[mid] > element){
            high = mid - 1;
        }
        else if(container[mid] < element){
            low = mid + 1;
        }
        else{
            return mid ;
        }
    }
    return -1;
}



int main() {
    // intialized list that is searched through plus the specific phrases
    vector<string> string_list = getStringData();
    string s1 = "not_here";
    string s2 = "aaaaa";
    string s3 = "mzzzz";

    // creates and sets variable for start and end
    chrono::time_point<chrono::system_clock> start, end;

    for (int i = 0; i < 6; i++) {
        string fiveString;
        // checks the iteration and accordingly changes it after every two
        if (i == 0) {
            fiveString = s1;
            cout << fiveString << " search:" << endl;
        }
        if (i == 2) {
            fiveString = s2;
            cout << fiveString << " search:" << endl;
        }
        if (i == 4) {
            fiveString = s3;
            cout << fiveString << " search:" << endl;
        }
        // checks whether the given iteration is odd or even so that for every term
        // binary search as well as linear search is called,
        // checks current time performs operation and subtracts time it took to complete the operation

        if (i % 2 == 0) {
            start = chrono::system_clock::now();
            int ind = linear_search(string_list, fiveString);
            chrono::duration<double> operation_time = chrono::system_clock::now() - start;
            cout << "Linear Index: " << ind << endl;
            cout << "Linear Time: " << operation_time.count() << endl;
        }

        if (i % 2 == 1) {
            start = chrono::system_clock::now();
            int ind = binary_search(string_list, fiveString);
            chrono::duration<double> operation_time = chrono::system_clock::now() - start;
            cout << "Binary Index: " << ind << endl;
            cout << "Binary Time: " << operation_time.count() << endl;
        }


    }

}