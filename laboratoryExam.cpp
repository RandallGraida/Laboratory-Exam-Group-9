#include <iostream>
#include <string>
#include <vector>
#include <limits>     
#include <algorithm>  

// Used class for more efficient code structure
class TemperatureDay {
public:
    // Input of the user and read a given number of temperatures
    void inputTemperatures() {
        std::cout << "\nEnter number of temperature readings (Enter '0' to exit the program): ";
        std::size_t numberOfReadings;
        while (!(std::cin >> numberOfReadings) || numberOfReadings < 0) {
            std::cout << "  Invalid number. Please enter a non-negative integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (numberOfReadings == 0) {
            noMoreDataEntered_ = true;
            return;
        }

        dailyTemperatures_.clear();
        dailyTemperatures_.reserve(numberOfReadings);

        for (std::size_t temperatureCount = 0; temperatureCount < numberOfReadings; ++temperatureCount) {
            double temperatureInput;
            std::cout << "  Enter temperature #" << (temperatureCount + 1) << ": ";
            while (!(std::cin >> temperatureInput)) {
                std::cout << "    Invalid. Enter a numeric temperature: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            dailyTemperatures_.push_back(temperatureInput);
        }
    }

    // Calculate the average of the daily temperature
    double calculateAverageTemperature() const {
        double sumOfTemperatures = 0.0;
        for (double temp : dailyTemperatures_) {
            sumOfTemperatures += temp;
        }
        return dailyTemperatures_.empty() ? 0.0 : (sumOfTemperatures / dailyTemperatures_.size());
    }

    // Find the highest temperature recorded
    double findMaximumTemperature() const {
        double maxTemperature = std::numeric_limits<double>::lowest();
        for (double temp : dailyTemperatures_) {
            if (temp > maxTemperature) {
                maxTemperature = temp;
            }
        }
        return maxTemperature;
    }

    // Find the lowest temperature recorded
    double findMinimumTemperature() const {
        double minTemperature = std::numeric_limits<double>::max();
        for (double temp : dailyTemperatures_) {
            if (temp < minTemperature) {
                minTemperature = temp;
            }
        }
        return minTemperature;
    }

    // Count how many readings exceed the given highTemperatureThreshold
    std::size_t countReadingsAboveThreshold(double highTemperatureThreshold = 40.0) const {
        std::size_t countAboveThreshold = 0;
        for (double temp : dailyTemperatures_) {
            if (temp > highTemperatureThreshold) {
                ++countAboveThreshold;
            }
        }
        return countAboveThreshold;
    }

    // Sort the dailyTemperatures_ in ascending order
    void sortTemperaturesAscending() {
        // Replace with custom sort if <algorithm> is disallowed
        std::sort(dailyTemperatures_.begin(), dailyTemperatures_.end());
    }

    // Display a full report of the day's temperature statistics
    void displayTemperatureReport() const {
        if (dailyTemperatures_.empty()) {
            std::cout << "No temperature data for this day.\n";
            return;
        }

        std::cout << "\nDaily Temperature Report:\n";
        std::cout << "Average temperature: "
                  << calculateAverageTemperature() << "\u00B0C\n";
        std::cout << "Highest temperature:  "
                  << findMaximumTemperature()     << "\u00B0C\n";
        std::cout << "Lowest temperature:   "
                  << findMinimumTemperature()     << "\u00B0C\n";
        std::cout << "Readings > 40\u00B0C:    "
                  << countReadingsAboveThreshold() << "\n";

        std::cout << "Sorted temperatures: ";
        for (double temp : dailyTemperatures_) {
            std::cout << temp << " ";
        }
        std::cout << "\n";
    }

    // Check if user entered 0 readings to finish input loop
    bool isNoMoreDataEntered() const {
        return noMoreDataEntered_;
    }

private:
    // Stores all temperature readings for a day
    std::vector<double> dailyTemperatures_;    

    // Indicates if user wants to finish
    bool noMoreDataEntered_ = false;           
};

// Main program: processes consecutive days until user signals to finish 
int main() {
    std::cout << "C++ Group 9 temperature identifier\n";

    while (true) {
        TemperatureDay currentDayTemperatures;
        currentDayTemperatures.inputTemperatures();

        if (currentDayTemperatures.isNoMoreDataEntered()) {
            std::cout << "\nNo more temperature data entered. Exiting program.\n";
            break;
        }

        currentDayTemperatures.sortTemperaturesAscending();
        currentDayTemperatures.displayTemperatureReport();
    }

    return 0;
}

