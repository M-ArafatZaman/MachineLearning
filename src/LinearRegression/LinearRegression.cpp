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

int main() {

    // This dataset is has a positive correlation with the y-intersect being close to the origin (0,0)
    vector<int> x = {1, 2, 4, 6,  8, 10, 15, 17};
    vector<int> y = {1, 3, 2, 6, 11, 10, 13, 20};
    
    pair<float, float> equation = linearRegression(x, y);

    cout << "m = " << equation.first << endl;
    cout << "b = " << equation.second << endl;

    return 0;
}