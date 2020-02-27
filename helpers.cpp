#include "helpers.h"
#include <cmath>
#include <tuple>

using namespace std;

float euclid_distance(std::tuple<float,float,float,float> p1, std::tuple<float,float,float,float> p2) {
    float dist_sum = pow((get<0>(p1) - get<0>(p2)),2) + 
                      pow((get<1>(p1) - get<1>(p2)),2) +
                      pow((get<2>(p1) - get<2>(p2)),2) + 
                      pow((get<3>(p1) - get<3>(p2)),2);
    return(sqrt(dist_sum));
}
