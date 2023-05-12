/*
 * This code defines two functions to calculate the total distance traveled by a device using GPS data.
 *
 * The first function, setLatLongPosPrev(), updates the previous latitude and longitude position with the current latitude and longitude position.
 *
 * The second function, distance_total_calculator(), calculates the total distance traveled by the device using the Haversine formula to calculate the distance between two latitude and longitude positions. It takes two double arrays as input, one for the previous latitude and longitude position and one for the current latitude and longitude position. The function calculates the distance between the two positions and adds it to a static double variable that stores the total distance traveled. If the previous latitude and longitude position is NULL, the function sets it to the current latitude and longitude position and returns 0. The function then updates the previous latitude and longitude position with the current latitude and longitude position and returns the total distance traveled.
 */
#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "./displacement_calculator.h" // custom function to calculate displacement

 // Function to update the previous latitude and longitude position with the current latitude and longitude position
void setLatLongPosPrev(double* prev_lat_long, double* now_lat_long) {
  prev_lat_long[0] = now_lat_long[0];
  prev_lat_long[1] = now_lat_long[1];
  prev_lat_long[2] = now_lat_long[2];
  prev_lat_long[3] = now_lat_long[3];
}

// Function to calculate the total distance traveled by the device using Haversine formula
double distance_total_calculator(double* prev_lat_long, double* now_lat_long) {
  static double total_distance = 0;

  // If there is no previous latitude and longitude position, set it to the current position and return 0
  if (prev_lat_long[0] == 0) {
    setLatLongPosPrev(prev_lat_long, now_lat_long);
    return 0;
  }

  // Calculate the distance between the two positions and add it to the total distance traveled
  total_distance += calculateDisplacement(prev_lat_long, now_lat_long);

  // Update the previous latitude and longitude position with the current position
  setLatLongPosPrev(prev_lat_long, now_lat_long);

  // Return the total distance traveled
  return total_distance;
}
