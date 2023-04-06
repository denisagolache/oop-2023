#include <stdio.h>
float operator""_Kelvin(unsigned long long int k) {
	float Celsius = k - 273.15;
	return Celsius;
}

float operator""_Fahrenheit(unsigned long long int f) {
	float Celsius = (f - 32) / 1.8;
	return Celsius;
}

int main()
{
	float a = 300_Kelvin;
	printf("Valuarea temperaturii transformata din Kelvin in Celsius este: %f\n", a);
	float b = 120_Fahrenheit;
	printf("Valuarea temperaturii transformata din Fahrenheit in Celsius este: %f\n", a);
}

