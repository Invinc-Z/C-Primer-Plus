#include "pe12-2a.h"
#include <stdio.h>

static int mode = 0; // 0 = metric, 1 = US
static double distance = 0.0; // Distance in meters or feet
static double power = 0.0; // Power in watts or horsepower

void set_mode(int new_mode)
{
	if (new_mode == 0 || new_mode == 1)
		mode = new_mode;
	else
		printf("Invalid mode specified. Mode %d%s used.\n", mode, mode ? "(US)" : "metric");
}


void get_info()
{
	if (mode == 0)
		printf("Enter distance traveled in kilometers: ");
	else if (mode == 1)
		printf("Enter distance traveled in miles: ");
	scanf("%lf", &distance);
	if (mode == 0)
		printf("Enter fuel consumed in liters: ");
	else if (mode == 1)
		printf("Enter fuel consumed in miles: ");
	scanf("%lf", &power);
}

void show_info()
{
	if (mode == 0)
		printf("Fuel consumption is %.2lf liters per 100km.\n",  power / distance * 100);
	else if (mode == 1)
		printf("Fuel consumption is %.2lf miles per gallon.\n", distance / power);
}
