#include "CurrentReading.h"
int NumberofContRange=0;

RangeReading ArrayofContRange[]={};
int NumberofContinuousRange(int *ChargingCurrentReadings, int numOfCCReadings)
{
	int l_NumberofContRange=NumberofContRange;
	NumberofContRange=0;
	return l_NumberofContRange;
}
	
void swap(int *xp, int *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

RangeReading printFunction( int a_StartIndex, int a_EndIndex, int a_NumberinRange)
{
	RangeReading l_RangeReading;
	l_RangeReading.StartIndex=a_StartIndex;
	l_RangeReading.EndIndex= a_EndIndex;
	l_RangeReading.NumOfReadingsInRange= a_NumberinRange;
	 printf("The number of readings in the range %d - %d is %d",  a_StartIndex, a_EndIndex , a_NumberinRange);
	 
	 return l_RangeReading;
}

void SortArray(int *ChargingCurrentReadings, int numOfCCReadings)
{
	int next_index=0;
	for (int i=0;i<numOfCCReadings-1;i++)
    {
        next_index=i;
        for (int j=i+1;j<numOfCCReadings;j++)
        {
            if (ChargingCurrentReadings[j]<ChargingCurrentReadings[next_index])
            {
                next_index=j;
            }
        }

        swap(&ChargingCurrentReadings[next_index],&ChargingCurrentReadings[i]);
    }
}

RangeReading *DetectContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings)
{
	int StartIndex=0;
	int RangeCounter=1;
	RangeReading l_RangeReading;
	int ArrayIndex=0;
	NumberofContRange=0;
	StartIndex=ChargingCurrentReadings[0];
	SortArray(ChargingCurrentReadings, numOfCCReadings);
	for (int i=0; i<numOfCCReadings; i++)
	{		
		int j=i+1;
		int tempdiff =ChargingCurrentReadings[j]- ChargingCurrentReadings[i];
		if (tempdiff== 0 ||tempdiff== 1)
		{
			RangeCounter++;
		}
		else
		{
		   NumberofContRange++;
		   l_RangeReading=printFunction(StartIndex,ChargingCurrentReadings[i], RangeCounter);
		   ArrayofContRange[ArrayIndex]= l_RangeReading;
		   ArrayIndex++;
		   StartIndex= ChargingCurrentReadings[j];
		   RangeCounter=1;
		}
	}
	return ArrayofContRange;
}
