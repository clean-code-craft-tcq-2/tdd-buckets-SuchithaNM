#pragma once

#include <stdio.h>
#include <stdbool.h>
#define formatBool(b) ((b) ? "TRUE" : "FALSE")

typedef struct{
	int StartIndex;
	int EndIndex;
	int NumOfReadingsInRange;
}RangeReading;

extern int NumberofContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings);
extern bool validateCurrentReadingInputSequence(int *InputSequence , int length);
extern void sortInputSeq(int *InputSequence , int length);
RangeReading detectCurrentReadingAndPrintCSVFormat( int min, int max, int numberInRange);

