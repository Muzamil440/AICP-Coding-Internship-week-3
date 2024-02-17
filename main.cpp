#include <iostream>

using namespace std;

const int MAX_COWS = 100; // Maximum number of cows
const int DAYS_IN_WEEK = 7; // Number of days in a week

// Function to calculate total weekly volume of milk for the herd
double calculateTotalVolume(const double milkYields[][DAYS_IN_WEEK], int totalCows) {
    double totalVolume = 0;
    for (int cow = 0; cow < totalCows; ++cow) {
        for (int day = 0; day < DAYS_IN_WEEK; ++day) {
            totalVolume += milkYields[cow][day];
        }
    }
    return totalVolume;
}

// Function to calculate average yield per cow in a week
double calculateAverageYield(const double milkYields[][DAYS_IN_WEEK], int totalCows) {
    double totalVolume = calculateTotalVolume(milkYields, totalCows);
    return totalVolume / (totalCows * DAYS_IN_WEEK);
}

// Function to identify the most productive cow
int identifyMostProductiveCow(const double milkYields[][DAYS_IN_WEEK], int totalCows) {
    int mostProductiveCowId = -1;
    double maxTotalYield = 0;
    for (int cow = 0; cow < totalCows; ++cow) {
        double totalYield = 0;
        for (int day = 0; day < DAYS_IN_WEEK; ++day) {
            totalYield += milkYields[cow][day];
        }
        if (totalYield > maxTotalYield) {
            maxTotalYield = totalYield;
            mostProductiveCowId = cow;
        }
    }
    return mostProductiveCowId;
}

// Function to identify cows producing less than 12 litres on four or more days
void identifyLowYieldCows(const double milkYields[][DAYS_IN_WEEK], int totalCows, bool lowYieldCows[]) {
    for (int cow = 0; cow < totalCows; ++cow) {
        int daysBelowThreshold = 0;
        for (int day = 0; day < DAYS_IN_WEEK; ++day) {
            if (milkYields[cow][day] < 12.0) {
                daysBelowThreshold++;
            }
        }
        if (daysBelowThreshold >= 4) {
            lowYieldCows[cow] = true;
        }
    }
}

int main() {
    double milkYields[MAX_COWS][DAYS_IN_WEEK] = {0}; // Array to store milk yields for each cow
    bool lowYieldCows[MAX_COWS] = {false}; // Array to track low yield cows

    int totalCows;
    cout << "Enter the total number of cows in the herd: ";
    cin >> totalCows;

    // Task 1: Record the milk yields for a week
    for (int day = 0; day < DAYS_IN_WEEK; ++day) {
        cout << "Day " << day + 1 << ":" << endl;
        for (int cow = 0; cow < totalCows; ++cow) {
            int cowId;
            double yield;

            cout << "Enter cow's 3-digit identity code number: ";
            cin >> cowId;
            cout << "Enter yield for cow " << cowId << " on day " << day + 1 << ": ";
            cin >> yield;

            milkYields[cow][day] = yield; // Record the milk yield for the cow
        }
    }

    // Task 2: Calculate and display total weekly volume of milk for the herd
    double totalVolume = calculateTotalVolume(milkYields, totalCows);
    cout << "Total weekly volume of milk for the herd: " << totalVolume << " litres" << endl;

    // Task 2: Calculate and display average yield per cow in a week
    double averageYield = calculateAverageYield(milkYields, totalCows);
    cout << "Average yield per cow in a week: " << averageYield << " litres" << endl;

    // Task 3: Identify the most productive cow
    int mostProductiveCowId = identifyMostProductiveCow(milkYields, totalCows);
    cout << "Most productive cow (ID): " << mostProductiveCowId + 1 << endl;

    // Task 3: Identify cows producing less than 12 litres on four or more days
    identifyLowYieldCows(milkYields, totalCows, lowYieldCows);
    cout << "Cows producing less than 12 litres on four or more days: ";
    bool noLowYieldCows = true;
    for (int cow = 0; cow < totalCows; ++cow) {
        if (lowYieldCows[cow]) {
            cout << cow + 1 << " ";
            noLowYieldCows = false;
        }
    }
    if (noLowYieldCows) {
        cout << "None";
    }
    cout << endl;

    return 0;
}
