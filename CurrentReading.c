#include "CurrentReading.h"
int count = 0;

int NumberofContinuousRange(int *ChargingCurrentReadings, int numOfCCReadings)
{
    int i;
    for(i=0;i<numOfCCReadings;i++)
    {
        if(((ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]) == 0) && ((ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]) == 1))
        {
            count++;
        }
    }
    return count;
}
