#ifndef TEAM_LEADER_H
#define TEAM_LEADER_H

#include "ProductionWorker.h"

class TeamLeader:public ProductionWorker
{
private:
	double monthlyBonus;
	int reqTrainingHours;
	int attendedTrainingHours;
public:
	TeamLeader();
	TeamLeader(char *, int, int ,double, double, int, int);
	~TeamLeader();
	void setMonthlyBonus(double);
	void setReqTrainingHours(int);
	void setAttendedTrainingHours(int);
	double getMonthlyBonus();
	int	getReqTrainingHours();
	int getAttendedTrainingHours();
	void display();
};

#endif // !TEAM_LEADER_H