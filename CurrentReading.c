#include "CurrentReading.h"
int NumberofContRange = 0;

int count = 1;

bool validateInputSequence(int *InputSequence , int length)
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
    if(validateInputSequence(ChargingCurrentReadings, numOfCCReadings) == true)
    {
	    for(i = 0; i < numOfCCReadings; i++)
	    {
		curRead = (ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]);
		if(curRead > 1)
		{
			count++;
		}
		
	    }
	   return count;
    }
}

RangeReading printFunction( int min, int max, int numberInRange)
{
	RangeReading rangeReading;
	rangeReading.StartIndex=min;
	rangeReading.EndIndex= max;
	rangeReading.NumOfReadingsInRange= numberInRange;
	printf("The number of readings in the range %d - %d is %d",  min, max , numberInRange);
	 
	return rangeReading;
}

