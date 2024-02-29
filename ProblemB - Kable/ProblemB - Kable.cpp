#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int D;
    cin >> D;
    double* results = new  double[D];

    for (int i = 0; i < D; ++i) {
        int N, K;
        cin >> N >> K;

        vector<double> spools(N);
        for (int j = 0; j < N; ++j) {
            cin >> spools[j];
        }

        sort(spools.begin(), spools.end(), greater<double>());

        double maxLength = 0.0;
        double left = 0.0, right = spools[0];
        while (right - left > 0.005) {
            double mid = (left + right) / 2.0;
            int count = 0;
            for (int k = 0; k < N; ++k) {
                count += static_cast<int>(spools[k] / mid);
            }
            if (count >= K) {
                maxLength = max(maxLength, mid);
                left = mid;
            }
            else {
                right = mid;
            }
        }

        if (maxLength >= 0.01) {
            results[i] = maxLength;
        }
        else {
            results[i] = 0.00;
        }
    }

    for (int i = 0; i < D; i++) {
        cout << fixed;
        cout.precision(2);
        cout << results[i] << endl;     
    }

    return 0;
}
