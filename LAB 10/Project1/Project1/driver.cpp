#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
#include "TeamLeader.h"
using namespace std;



int main()
{

	char name[10] = "Usama";
	char name1[10] = "Shahid";
	ProductionWorker worker(name, 1234, 2, 234.6);
	worker.displayWorker();
	cout << "\n";

	TeamLeader tl(name1, 7369, 1, 1004.6, 23,13, 1223);
    tl.display();
	cout << "\n";
	system("pause");
	return 0;
}