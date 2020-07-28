#include <iostream>
#include <fstream>
using namespace std;



char retCharacter(int digit, int no);


int main()
{
	ofstream fout("numbers.txt");
	int phoneNo,divisor=1000000;
	char digits[8];
	int count = 0;
	
	digits[7] = '\0';
	int number[7];
	bool isTrue = false;
	while (!isTrue)
	{
		cout << "Enter phone no : ";
		cin >> phoneNo;
		isTrue = true;
		for (int i = 0; i < 7 && isTrue; i++)
		{

			number[i] = phoneNo / divisor;
			if (number[i] == 0 || number[i] == 1 || phoneNo>9999999)
			{
				cout << "Wrong no, Enter again:\n";
				isTrue = false;
				divisor = 10000000;
			}
			phoneNo = phoneNo % divisor;
			divisor = divisor / 10;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		digits[0] = retCharacter(number[0], i);
		for (int j = 0; j < 3; j++)
		{

			digits[1] = retCharacter(number[1], j);
			for (int k = 0; k < 3; k++)
			{

				digits[2] = retCharacter(number[2], k);
				for (int l = 0; l < 3; l++)
				{

					digits[3] = retCharacter(number[3], l);
					for (int m = 0; m < 3; m++)
					{
						
						digits[4] = retCharacter(number[4], m);
						for (int n = 0; n < 3; n++)
						{
							digits[5] = retCharacter(number[5], n);
							for (int p = 0; p < 3; p++)
							{
								count++;
								digits[6] = retCharacter(number[6], p);
								//fout << count << " ";
								fout << digits << "\n";
							}
						}
					}
				}
			}
		}
	}







	cout << "\n";
	system("pause");
	return 0;
}





char retCharacter(int digit, int no)
{
	if (digit==2)
	{
		if (no==0)
		{
			return 'A';
		}
		else if(no==1)
		{
			return 'B';
		}
		else
		{
			return 'C';
		}
	}
	if (digit == 3)
	{
		if (no == 0)
		{
			return 'D';
		}
		else if (no == 1)
		{
			return 'E';
		}
		else
		{
			return 'F';
		}
	}
	if (digit == 4)
	{
		if (no == 0)
		{
			return 'G';
		}
		else if (no == 1)
		{
			return 'H';
		}
		else
		{
			return 'I';
		}
	}
	if (digit == 5)
	{
		if (no == 0)
		{
			return 'J';
		}
		else if (no == 1)
		{
			return 'K';
		}
		else
		{
			return 'L';
		}
	}
	if (digit == 6)
	{
		if (no == 0)
		{
			return 'M';
		}
		else if (no == 1)
		{
			return 'N';
		}
		else
		{
			return 'O';
		}
	}
	if (digit == 7)
	{
		if (no == 0)
		{
			return 'P';
		}
		else if (no == 1)
		{
			return 'R';
		}
		else
		{
			return 'S';
		}
	}
	if (digit == 8)
	{
		if (no == 0)
		{
			return 'T';
		}
		else if (no == 1)
		{
			return 'U';
		}
		else
		{
			return 'V';
		}
	}
	if (digit == 9)
	{
		if (no == 0)
		{
			return 'W';
		}
		else if (no == 1)
		{
			return 'X';
		}
		else
		{
			return 'Y';
		}
	}
}


