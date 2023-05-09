/*
 * This code defines two functions to calculate the displacement between two GPS latitude and longitude positions using the Haversine formula.
 *
 * The first function, to_rad(), takes a double value as input, which represents an angle in degrees, and returns the angle in radians.
 *
 * The second function, calculateDisplacement(), takes two double arrays as input, one for the current latitude and longitude position (location) and one for the target latitude and longitude position (target). The function calculates the displacement between the two positions using the Haversine formula, which takes into account the curvature of the Earth. The function returns the displacement in meters.
 */

#pragma once

#include <math.h>

# define PI 3.14159265359
# define radius_of_Earth 6371000 // Earth's mean radius in meters

 // Function to convert an angle in degrees to an angle in radians
double to_rad(double y) {
    return y * PI / 180;
}

// Function to calculate the displacement between two GPS latitude and longitude positions using the Haversine formula
double calculateDisplacement(double* location, double* target) {
    double dlat = to_rad(location[0] - target[0]); // Latitude difference in radians
    double dlon = to_rad(location[2] - target[2]); // Longitude difference in radians
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(to_rad(location[0])) * cos(to_rad(target[0])) * sin(dlon / 2) * sin(dlon / 2);
    // Haversine formula
    double c = 2 * atan2(sqrt(a), sqrt(1 - a)); // Angular distance in radians
    double d = radius_of_Earth * c; // Displacement in meters
    return d;
}
