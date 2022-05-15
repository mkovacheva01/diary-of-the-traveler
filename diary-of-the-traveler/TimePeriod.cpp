#include "TimePeriod.h"

const int MAX_VALID_YR = 2022;
const int MIN_VALID_YR = 1800;

int TimePeriod::takeDay(const String& date)const {
	int length = date.getSize();
	return (date[length - 2] - '0') * 10 + date[length - 1] - '0';
}

int TimePeriod::takeMonth(const String& date) const {
	int length = date.getSize();
	return (date[length - 5] - '0') * 10 + (date[length - 4] - '0');
}

int TimePeriod::takeYear(const String& date)const {
	int length = date.getSize();
	return (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
}

bool TimePeriod::checkDate(const String& date) const {
	int d = takeDay(date);
	int m = takeMonth(date);
	int y = takeYear(date);

	bool isLeap = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));

	if (y > MAX_VALID_YR || y < MIN_VALID_YR) return false;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > 31) return false;

	if (m == 2) {
		if (isLeap) return (d <= 29);
		else return (d <= 28);
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) return (d <= 30);
	return true;
}

bool TimePeriod::checkPeriod(const String& sTime, const String& eTime)const {
	if (checkDate(sTime) && checkDate(eTime)) {
		if (takeYear(sTime) == takeYear(eTime)) {
			if (takeMonth(sTime) == takeMonth(eTime)) {
				if (takeDay(sTime) < takeDay(eTime)) return true;
			}
			else if (takeMonth(sTime) < takeMonth(eTime)) return true;
		}
		else if (takeYear(sTime) < takeYear(eTime)) return true;
	}
	return false;
}