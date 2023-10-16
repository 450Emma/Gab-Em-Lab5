// lab partner: Gabriel Munoz

#include <iostream>
#include <vector>
#include "StringData.h"
using namespace std;

// function prototypes
int linear_search(vector<string> container, string element);
int binary_search(vector<string> container, string element);
int run_searches(string input);

int main() {

    // runs binary and linear search for each string and displays resulting time and index
    run_searches("not_here");
    run_searches("mzzzz");
    run_searches("aaaaa");

    return 0;
}

// runs binary and linear search for imputed string and displays resulting time and index
int run_searches(string input){
    vector<string> dataset = getStringData();
    cout << "Searches for "<< input << endl;

    // creates and sets variable type for start_time and end_time
    chrono::time_point<std::chrono::system_clock> start_time, end_time;

    // runs, times, and displays info for linear search
    start_time = chrono::system_clock::now();
    int index = linear_search(dataset, input);
    chrono::duration<double> elapsed_time = chrono::system_clock::now() - start_time;
    cout << "Linear time: " << elapsed_time.count() << endl;
    cout << "Linear index: " << index << endl;

    // runs, times, and displays info for binary search
    start_time = chrono::system_clock::now();
    index = binary_search(dataset, input);
    elapsed_time = chrono::system_clock::now() - start_time;
    cout << "Binary time: " << elapsed_time.count() << endl;
    cout << "Binary index: " << index << endl;

    cout << endl;
    return 0;

}

// compares element to each value in container and returns index when found
int linear_search(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++){
        if (container.at(i) == element) return i;
    }

    return -1;
}


int binary_search(vector<string> container, string element) {
    // initiate bounds for the portion of the container being considered
    int low_val = 0;
    int high_val = container.size();

    // runs until element is found or found to not be in container
    while (true){
        int mid_val = (high_val + low_val)/2;  // sets variable equal to the index between low_val and high_val

        // changes bounds or returns index if found according to element's relation to mid_val
        if (element.compare(container.at(mid_val)) > 0) low_val = mid_val + 1;
        else if (element.compare(container.at(mid_val)) < 0) high_val = mid_val - 1;
        else if (element == container.at(mid_val)) return mid_val;

        // runs when element is not in container
        if (mid_val == high_val) break;
    }

    return -1;
}
