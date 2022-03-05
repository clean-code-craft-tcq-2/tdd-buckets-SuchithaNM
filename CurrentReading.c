#include "CurrentReading.h"
int count = 1;

int NumberofContinuousRange(int *ChargingCurrentReadings, int numOfCCReadings)
{
    int i,curRead;
    for(i=0;i<numOfCCReadings;i++)
    {
        curRead = (ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]);
        if((curRead == 0) && (curRead == 1))
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }
    return count;
}
