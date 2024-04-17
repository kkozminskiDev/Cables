#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of test cases
    int D;
    cin >> D;
    // Declare an array to store the results for each test case
    double* results = new double[D];

    // Loop through each test case
    for (int i = 0; i < D; ++i) {
        // Read the number of spools (N) and the required number of pieces (K)
        int N, K;
        cin >> N >> K;

        // Create a vector to store the diameters of spools
        vector<double> spools(N);
        // Read the diameters of spools
        for (int j = 0; j < N; ++j) {
            cin >> spools[j];
        }

        // Sort the diameters of spools in descending order
        sort(spools.begin(), spools.end(), greater<double>());

        // Initialize variables for binary search
        double maxLength = 0.0;
        double left = 0.0, right = spools[0];
        // Binary search loop to find the maximum length of thread
        while (right - left > 0.005) {
            double mid = (left + right) / 2.0;
            int count = 0;
            // Count how many pieces can be obtained from each spool with length 'mid'
            for (int k = 0; k < N; ++k) {
                count += static_cast<int>(spools[k] / mid);
            }
            // Adjust the search range based on the count of pieces
            if (count >= K) {
                maxLength = max(maxLength, mid);
                left = mid;
            }
            else {
                right = mid;
            }
        }

        // Store the maximum length of thread for the current test case
        if (maxLength >= 0.01) {
            results[i] = maxLength;
        }
        else {
            results[i] = 0.00;
        }
    }

    // Output the results
    cout << "Wyniki:" << endl << endl;
    for (int i = 0; i < D; i++) {
        cout << fixed;
        cout.precision(2);
        cout << results[i] << endl;
    }

    // Free the dynamically allocated memory
    delete[] results;

    return 0;
}
