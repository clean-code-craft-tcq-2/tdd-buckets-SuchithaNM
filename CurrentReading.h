#pragma once

#include <stdio.h>

typedef struct{
	int StartIndex;
	int EndIndex;
	int NumOfReadingsInRange;
}RangeReading;

extern int NumberofContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings);
RangeReading *DetectContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings);
