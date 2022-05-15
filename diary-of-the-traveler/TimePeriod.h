#pragma once
#include"String.h"
class TimePeriod {
	String sTime;
	String eTime;
public:
	TimePeriod() {
		sTime = nullptr;
		eTime = nullptr;
	}
	TimePeriod(const String& sTime, const String& eTime) {
		if (checkPeriod(sTime, eTime)) {
			this->sTime = sTime;
			this->eTime = eTime;
		}
	}
	const String getDate1() const { return sTime; }
	const String getDate2() const { return eTime; }

	int takeDay(const String& date)const;
	int takeMonth(const String& date)const;
	int takeYear(const String& date)const;

	bool checkDate(const String& date)const;
	bool checkPeriod(const String& sTime, const String& eTime)const;
};

