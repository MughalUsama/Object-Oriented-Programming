#include "TeamLeader.h"



TeamLeader::TeamLeader()
{
	this->monthlyBonus = 0;
	this->reqTrainingHours = 0;
	this->attendedTrainingHours = 0;
}

TeamLeader::TeamLeader(char * workerName, int workerNo, int shiftNo, double payRate, double bonus, int reqHours, int attendedHours):ProductionWorker(workerName,workerNo,shiftNo,payRate)
{
	if (bonus>=0)
	{
		this->monthlyBonus = bonus;
	}
	else
	{
		this->monthlyBonus = -bonus;
	}

	if (reqHours>=0)
	{
		this->reqTrainingHours = reqHours;
	}
	else
	{
		this->reqTrainingHours = -reqHours;
	}

	if (attendedHours>=0)
	{
		this->attendedTrainingHours = attendedHours;
	}
	else
	{
		this->attendedTrainingHours = -attendedHours;
	}

}


TeamLeader::~TeamLeader()
{
	this->monthlyBonus = 0;
	this->reqTrainingHours = 0;
	this->attendedTrainingHours = 0;
}

void TeamLeader::setMonthlyBonus(double bonus)
{
	if (bonus >= 0)
	{
		this->monthlyBonus = bonus;
	}
	else
	{
		this->monthlyBonus = -bonus;
	}
}

void TeamLeader::setReqTrainingHours(int hours)
{
	if (hours>= 0)
	{
		this->reqTrainingHours = hours;
	}
	else
	{
		this->reqTrainingHours = -hours;
	}
}

void TeamLeader::setAttendedTrainingHours(int hours)
{
	if (hours >= 0)
	{
		this->attendedTrainingHours = hours;
	}
	else
	{
		this->attendedTrainingHours = -hours;
	}
}

double TeamLeader::getMonthlyBonus()
{
	return monthlyBonus;
}

int TeamLeader::getReqTrainingHours()
{
	return reqTrainingHours;
}

int TeamLeader::getAttendedTrainingHours()
{
	return attendedTrainingHours;
}

void TeamLeader::display()
{
	displayWorker();
	cout << "Monthly Bonus : "<<monthlyBonus << "\n";
	cout << "Required training hours : " << reqTrainingHours << "\n";
	cout << "Attended training hours : " << attendedTrainingHours << "\n";
}

