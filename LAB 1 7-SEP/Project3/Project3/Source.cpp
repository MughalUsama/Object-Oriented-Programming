#include <iostream>
using namespace std;

struct Weather
{
	double totalRain;
	double highTemp;
	double lowTemp;
	double averageTemp;
};

int main()
{
	Weather month[12];
	int highestTempMonth = 0, lowestTempMonth = 0;
	double totalRainfall=0, totalTemprature=0;

	for (int i = 0; i < 12; i++)
	{
		cout << "\nEnter the data for month " << i + 1 << ":\n";
		cout << "Enter the total rainfall: ";
		cin >> month[i].totalRain;
		totalRainfall = totalRainfall + month[i].totalRain;
		do
		{	//input validation
			cout << "Enter the highest temprature in range of -100 and 140: ";
			cin >> month[i].highTemp;
		} while ((month[i].highTemp < -100 || month[i].highTemp>140));

		if (month[i].highTemp>month[highestTempMonth].highTemp)
		{
			highestTempMonth = i;
		}
		do
		{	//input validation
			cout << "Enter the lowest temprature in range of -100 and 140: ";
			cin >> month[i].lowTemp;
		} while ((month[i].lowTemp < -100 || month[i].lowTemp>140));

		if (month[i].lowTemp<-100 || month[i].lowTemp>140)
		{
			cout << "Enter the temprature in range of -100 and 140: ";
			cin >> month[i].lowTemp;
		}
		if (month[i].lowTemp<month[lowestTempMonth].lowTemp)
		{
			lowestTempMonth = i;
		}
		cout << "Enter the average temprature: ";
		cin >> month[i].averageTemp;
		totalTemprature=totalTemprature+ month[i].averageTemp;
	}
	//displaying record
	cout << "\n\n\t\t\t\t\tYearly Record\n";
	cout << "\n Average monthly rainfall : "<< totalRainfall/12;
	cout << "\n Total Rainfall: " << totalRainfall;
	cout << "\n\n Highest temp was in month " << highestTempMonth+1;
	cout << "\n Highest temp was " << month[highestTempMonth].highTemp;
	cout << "\n\n Lowest temp was in month " << lowestTempMonth+1;
	cout << "\n Lowest temp was " << month[lowestTempMonth].lowTemp;
	cout << "\n Average temp of year is "<< totalTemprature/12;
	
	
	cout << "\n";
	system("pause");
	return 0;
}
