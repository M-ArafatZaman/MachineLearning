#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <cmath>
using namespace std;


// Function to perform linear regression analyisis
template <class T>
pair<float, float> linearRegression(vector<T>& xs, vector<T>& ys) {
    /* 
        This function takes in 2 vectors of ints or floats representing x and y respectively.
        And returns a pair containing the gradient (m) in the first and y-intercept (b) in the second
        
        The formula used is from Khan Academy - https://www.youtube.com/watch?v=GAmzwIkGFgE
     */
    
    // Size of xs and ys
    int N_x = xs.size();
    int N_y = ys.size();

    // Calculate average of x and y
    float avg_x = accumulate(xs.begin(), xs.end(), 0) / N_x; 
    float avg_y = accumulate(ys.begin(), ys.end(), 0) / N_y;

    // Average of xy's
    vector<float> xys;

    for (int i = 0; i < N_x; ++i) {
        xys.push_back( xs[i] * ys[i] );
    }

    float avg_xy = accumulate(xys.begin(), xys.end(), 0) / N_x;

    // Calculate the square of average x
    float squared_avg_x = pow(avg_x, 2);

    // Calculate the average of square of xs
    vector<float> xs_squared;

    for (int j = 0; j < N_x; ++j) {
        xs_squared.push_back( pow(xs[j], 2) );
    }

    float avg_xs_squared = accumulate(xs_squared.begin(), xs_squared.end(), 0) / N_x;

    // Calculate the gradient
    float m = ((avg_x * avg_y) - avg_xy) / (squared_avg_x - avg_xs_squared);
    float b = avg_y - (m * avg_x);

    // Return {gradient, y-intersect}
    return {m, b};
};


// Test runner exception
class FailedTest: public exception {
    public:
        FailedTest(string err) {
            cout << err << endl;
        }
};

void test_runner() {
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> y = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair<float, float> equation = linearRegression(x, y);
    float m = 1, b = 0;

    if (equation.first != m) throw FailedTest("Failed to calculate gradient 'm' properly.");
    if (equation.second != b) throw FailedTest("Failed to calculate y-intersect 'b' properly.");

    cout << "All tests passed!" << endl;
}


int main() {

    test_runner();

    return 0;
}