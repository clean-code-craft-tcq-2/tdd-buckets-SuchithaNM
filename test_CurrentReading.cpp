#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReading.h"

TEST_CASE("Case for checking the given array is invalid with Negative numbers") {
  int ChargingCurrentReadings[] = {3, 3 ,5, -1, -3, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}

TEST_CASE("Case for checking the given array is continuous and arraged in the ascending oder") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4, 11, 10, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}

TEST_CASE("Case for detecting number of continuous range in the given reading:Failing") {
  int ChargingCurrentReadings[] = {4,5};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}

