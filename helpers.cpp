#include "helpers.h"
#include <cmath>
#include <tuple>

using namespace std;

double euclid_distance(tuple<int,int,int,int> p1, tuple<int,int,int,int> p2) {
    double dist_sum = pow((get<0>(p1) - get<0>(p2)),2) + 
                      pow((get<1>(p1) - get<1>(p2)),2) +
                      pow((get<2>(p1) - get<2>(p2)),2) + 
                      pow((get<3>(p1) - get<3>(p2)),2);
    return(sqrt(dist_sum));
}
