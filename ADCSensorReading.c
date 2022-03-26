#include "ADCSensorReading.h"

int maxAnalogToDigitalConversion(int ADC_Resolution)
{
	return (pow(2,ADC_Resolution) - 2);
}

int stdAnalogToDigitalConvertedValue(int ADC_Resolution)
{
	return (pow(2,ADC_Resolution) - 1);
}

void currentSenseAtoDConversion(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentConversionValues)
{	
	float currentValue, analogToDigitalCoversionValue;
	
	for (int i=0; i<numberOfSamples; i++)
	{
		analogToDigitalCoversionValue = (ADCValues[i]) / (maxAnalogToDigitalConversion(ADC_Resolution));
		currentValue = (maxCurrentValue * analogToDigitalCoversionValue) / (maxAnalogToDigitalConversion(ADC_Resolution));
		currentConversionValues[i] = round(currentValue);
		if(currentConversionValues[i] < 0)
			currentConversionValues[i] = abs(currentConversionValues[i]);
	}	
}

void ignoreError(void)
{
	printf("Ignore the error\n");
}

void ChargingCurrentSenseValue(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentSenseValues)
{
	if((maxAnalogToDigitalConversion(ADC_Resolution)) < (stdAnalogToDigitalConvertedValue(ADC_Resolution)))
	{
		currentSenseAtoDConversion(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue,currentSenseValues);
	}
	else
	{
		ignoreError();	
	}
	
}
