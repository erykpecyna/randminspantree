#include "helpers.h"
#include <cmath>
#include <tuple>

using namespace std;

double euclid_distance(tuple<int,int,int,int> p1, tuple<int,int,int,int> p2, int d) {
    double dist_sum = 0;
    for (int i = 0; i < d; n++) {
        dist_sum += (get<i>(p1) - get<i>(p2))^2
    }
    return sqrt(dist_sum)
}
