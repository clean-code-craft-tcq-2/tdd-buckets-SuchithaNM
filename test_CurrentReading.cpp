#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReading.h"

TEST_CASE("Case for detecting number of continuous range in the reading array given:Failing") {
  int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 3);
}

TEST_CASE("Case for detecting continuous range: Failing") {
   int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
   int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
   RangeReading *ArrofRange= DetectContinuousRange( ChargingCurrentReadings, numOfCCReadings);
   REQUIRE(ArrofRange[0].StartIndex == 10);
}


TEST_CASE("Case for detecting number of continuous range in the reading array given") {
  int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  RangeReading *ArrofRange= DetectContinuousRange(ChargingCurrentReadings, numOfCCReadings);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}


TEST_CASE("Case for detecting continuous range: Passing") {
   int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
   int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
   RangeReading *ArrofRange= DetectContinuousRange( ChargingCurrentReadings, numOfCCReadings);
   REQUIRE(ArrofRange[0].StartIndex == 3);
   REQUIRE(ArrofRange[0].EndIndex == 5);
   REQUIRE(ArrofRange[0].NumOfReadingsInRange == 4);
   REQUIRE(ArrofRange[1].StartIndex == 10);
   REQUIRE(ArrofRange[1].EndIndex == 12);
   REQUIRE(ArrofRange[1].NumOfReadingsInRange == 3);
}
