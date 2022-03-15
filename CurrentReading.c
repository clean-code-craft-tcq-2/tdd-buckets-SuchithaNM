#include "CurrentReading.h"
int NumberofContRange = 0;

int count = 0;

bool validateCurrentReadingInputSequence(int *InputSequence , int length)
{
	int i;
	for(i= 0; i < length; i++)
	{
		if(InputSequence[i] >= 0)
		{
			sortInputSeq(InputSequence, length);			
			return true;
		}	
		else
		{
			return false;
		}
	}

}
void sortInputSeq(int *InputSequence , int length)
{
	int i , j , temp ;
	for(i=0; i< length; i++)
	{
		for(j=i+1; j< length; j++)
		{
			if(InputSequence[i] > InputSequence[j])
			{
				temp = InputSequence[i];
				InputSequence[i] = InputSequence[j];
				InputSequence[j] = temp; 
			}
		}	
	}
}

int NumberofContinuousRange(int *ChargingCurrentReadings, int numOfCCReadings)
{
    int i, j, curRead;
    if(validateCurrentReadingInputSequence(ChargingCurrentReadings, numOfCCReadings) == true)
    {
	    for(i = 0; i < numOfCCReadings; i++)
	    {
		curRead = (ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]);
		if((curRead == 0) || (curRead == 1))
		{
			count++;
		}
		
	    }
	   return count;
    }
}

RangeReading detectCurrentReadingAndPrintCSVFormat( int min, int max, int numberInRange)
{
	RangeReading rangeReading;
	rangeReading.StartIndex=min;
	rangeReading.EndIndex= max;
	rangeReading.NumOfReadingsInRange= numberInRange;
	printf("The number of readings in the range %d - %d is %d",  min, max , numberInRange);
	 
	return rangeReading;
}

