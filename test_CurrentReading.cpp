#include "catch.hpp"
#include "CurrentRead.h"

TEST_CASE("Case for detecting number of continuous range in the given reading:Failing") {
  int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 3);
}
