#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentReading.h"
#include "ADCSensorReading.h"

TEST_CASE("Case for validate current reading input sequence and find the continuous range") {
  int ChargingCurrentReadings[] = {4,5};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(validateCurrentReadingInputSequence(ChargingCurrentReadings,numOfCCReadings) == true);
  REQUIRE(numberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
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

TEST_CASE("Case checks the given current reading for csv format construction") {
  int ChargingCurrentReadings[] = {3, 3 ,5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  int expectedStartIndex = 3, expectedEndIndex = 5 , expectedNumOfReadingsInRange = 4;
  RangeReading rangeReading;
  rangeReading = detectCurrentReadingAndPrintCSVFormat(expectedStartIndex,expectedEndIndex,expectedNumOfReadingsInRange );
  REQUIRE(rangeReading.StartIndex == expectedStartIndex);
  REQUIRE(rangeReading.EndIndex == expectedEndIndex);
  REQUIRE(rangeReading.NumOfReadingsInRange == expectedNumOfReadingsInRange);
}

TEST_CASE("Checks for the current values for given ADC values from the array") {
	
	int ADCValues[] = {64, 512, 1140, 1220, 1560, 2048,4094};

	int numberOfSamples = sizeof(ADCValues) / sizeof(ADCValues[0]);

	int expectedCurrentSenseValues[] = {0, 1, 2, 3, 4, 5, 10};
	
	int ADC_Resolution = 12;
	int maxCurrentValue = 10;
	
	int currentSenseValues[numberOfSamples];
	
	ChargingCurrentSenseValue(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue, currentSenseValues);
	/*for(int i=0; i < numberOfSamples; i++)
	{
		 REQUIRE(currentSenseValues[i] == expectedCurrentSenseValues[i]);
	}*/
}

