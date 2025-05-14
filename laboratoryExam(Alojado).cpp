#include <iostream>
using namespace std;

// Function Prototypes
void inputTemperatures(float temps[], int size);
float calculateAverage(float temps[], int size);
float findMax(float temps[], int size);
float findMin(float temps[], int size);
int countAbove40(float temps[], int size);
void sortAscending(float temps[], int size);
void displayResults(float temps[], int size, float avg, float max, float min, int above40);

int main() {
    const int MAX_SIZE = 100;
    float temperatures[MAX_SIZE];
    int numTemps;
    char anotherDay;

    do {
        // Input with validation
        do {
            cout << "Enter the number of temperature readings for the day: ";
            cin >> numTemps;
            if (numTemps < 1 || numTemps > MAX_SIZE) {
                cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            }
        } while (numTemps < 1 || numTemps > MAX_SIZE);

        // Capture temperatures
        inputTemperatures(temperatures, numTemps);

        // Calculations
        float avg = calculateAverage(temperatures, numTemps);
        float max = findMax(temperatures, numTemps);
        float min = findMin(temperatures, numTemps);
        int above40 = countAbove40(temperatures, numTemps);
        sortAscending(temperatures, numTemps);

        // Display Results
        displayResults(temperatures, numTemps, avg, max, min, above40);

        // Ask if user wants to enter data for another day
        cout << endl << "Do you want to enter data for another day? (Y/N): ";
        cin >> anotherDay;
    } while (anotherDay == 'Y' || anotherDay == 'y');

    cout << "Program ended." << endl;
    return 0;
}

// Function Definitions

void inputTemperatures(float temps[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter temperature reading " << i + 1 << ": ";
        cin >> temps[i];
    }
}

float calculateAverage(float temps[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += temps[i];
    }
    return sum / size;
}

float findMax(float temps[], int size) {
    float max = temps[0];
    for (int i = 1; i < size; i++) {
        if (temps[i] > max) {
            max = temps[i];
        }
    }
    return max;
}

float findMin(float temps[], int size) {
    float min = temps[0];
    for (int i = 1; i < size; i++) {
        if (temps[i] < min) {
            min = temps[i];
        }
    }
    return min;
}

int countAbove40(float temps[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (temps[i] > 40.0) {
            count++;
        }
    }
    return count;
}

void sortAscending(float temps[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temps[j] > temps[j + 1]) {
                float temp = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = temp;
            }
        }
    }
}

void displayResults(float temps[], int size, float avg, float max, float min, int above40) {
    cout << endl << "--- Results for the Day ---" << endl;
    cout << "Temperatures (Ascending): ";
    for (int i = 0; i < size; i++) {
        cout << temps[i] << " ";
    }
    cout << endl;
    cout << "Average Temperature: " << avg << endl;
    cout << "Highest Temperature: " << max << endl;
    cout << "Lowest Temperature: " << min << endl;
    cout << "Number of readings above 40°C: " << above40 << endl;
}