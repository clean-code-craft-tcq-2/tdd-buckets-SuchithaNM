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
			return TRUE;
		}	
		else
			return FALSE;
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
    int i,curRead;
    if(validateInputSequence(ChargingCurrentReadings, numOfCCReadings) == TRUE)
    for(i=0;i<numOfCCReadings;i++)
    {
        curRead = (ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]);
        if((curRead == 0) || (curRead == 1))
        {
            count++;
        }
    }
    return count;
}
