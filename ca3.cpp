#include<stdio.h>
#include<stdlib.h>

int convertMinToHours(int result);
char printDestinationMenu(void);
char printHomeCityMenu(void);
int calculateTime(int,int);
int getNum(void);

int main()
{
	int homeCity = 0;
	int destinationCity = 0;
	do {
		printHomeCityMenu();

		homeCity = getNum();

		printDestinationMenu();

		destinationCity = getNum();

		if (homeCity < destinationCity)
		{
			printf("error\n");

		}
		else if (homeCity == destinationCity)
		{
			printf("error\n");
		}
		else
		{
			int result = 0;


			result = calculateTime(homeCity, destinationCity);
			int time = convertMinToHours(result);
		}
	} while (homeCity != 0 && destinationCity != 0);
	
}

int calculateTime(int home,int destination)
{
	const int flytime[5] = { 255,238,355,134,207 };
	const int Layover[5] = { 80,46,689,53,0 };
	int result = 0;
	home--;
	destination -= 2;

	for (int i = home; i <= destination; i++) 
	{

		result += flytime[i];
		result += Layover[i];

		if (i == destination)
		{
			result -= Layover[i];
		}
	}
	return result;
}

int convertMinToHours(int result)
{
	int hours = result / 60;
	int minutes = result % 60;
	printf("the total time is %d:%d\n",hours,minutes);
	return result;
}

char printHomeCityMenu(void)
{
	printf("Hello! Please select your Home City:\n");
	printf("(1)Toronto\n(2)Atlanta\n(3)Austin\n(4)Denver\n(5)Chicago\n");

	return 0;
}

char printDestinationMenu(void)
{
	printf("Now select your Destination City:\n");
	printf("(2)Atlanta\n(3)Austin\n(4)Denver\n(5)Chicago\n(6)Buffalo\n");
	return 0;
}

#pragma warning(disable: 4996)
int getNum(void)
{
	char record[121] = { 0 };
	int number = 0;

	fgets(record, 121, stdin);

	if (sscanf(record, "%d", &number) != 1)
	{
		number = -1;
	}
	return number;
}