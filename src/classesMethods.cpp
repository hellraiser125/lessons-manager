#include"includesXdefines.h"

void student::token_generation() {
	std::mt19937 mersenne;
	mersenne.seed(std::time(nullptr));
	bool flag = false;
	while (flag != true) {
		user_token = mersenne();
		if (user_token > 0) flag = true;
	}
}


std::pair<int, int> lessons::getSystemtime() {

	SYSTEMTIME sys_tm;
	GetLocalTime(&sys_tm);
	int hour = sys_tm.wHour;
	int minute = sys_tm.wMinute;
	return std::pair<int, int>(hour, minute);

}