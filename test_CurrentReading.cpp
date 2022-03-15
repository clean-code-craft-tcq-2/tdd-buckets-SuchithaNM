#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReading.h"

TEST_CASE("Case for detecting number of continuous range in the given reading:Failing") {
  int ChargingCurrentReadings[] = {4,5};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == true);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
}

TEST_CASE("Case for checking the given array is invalid with Negative numbers") {
  int ChargingCurrentReadings[] = {-3, 3 ,-5, -4, -3, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == false);
}

TEST_CASE("Case for checking the given array in the ascending order") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == true);

}

TEST_CASE("Case for checking the given array to print on console") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  int expectedStartIndex = 3, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 4;
  RangeReading rangeReading;
  rangeReading = detectCurrentReadingAndPrintCSVFormat(expectedStartIndex,expectedEndIndex,expectedNumOfReadingsInRange );
  REQUIRE(rangeReading.StartIndex == expectedStartIndex);
  REQUIRE(rangeReading.EndIndex == expectedEndIndex);
  REQUIRE(rangeReading.NumOfReadingsInRange == expectedNumOfReadingsInRange);
}


