#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <random>

#define TEST 10*1000*1000 // number of tests
#define MAX 1000

#define ld long double
#define ll long long int
#define db(x) cout << #x << "=" << x << endl

using namespace std;

int main() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-MAX,MAX); //doubles from -1 to 1
    for (int i=0; i<TEST; i++) {
        // Generate random number between -MAX and +MAX
        double x=0, y=0, z;
        while (x == 0) x = distribution(generator);
        while (y == 0) y = distribution(generator);
        z = 3-x-y;
        double r = (x*x)/(y*y) + (y*y)/(z*z) + (z*z)/(x*x);
        if (r <= 3) printf("%lf\n", r);
    }
}