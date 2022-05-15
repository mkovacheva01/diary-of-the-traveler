#pragma once
#include "Journey.h"
class Destination {
	String name;
	Journey* journeys;
	int countJourney;
	int capacity;
	double averageG = 0;
	double sumAllG = 0;
	void copyFrom(const Destination& other);
	void free();
	void resize();
	bool isEmpty()const;

public:
	Destination();
	Destination(const String& name);
	Destination(const Destination&);
	Destination& operator=(const Destination& other);
	~Destination();

	const String& getName()const;
	const Journey* getJourney()const;
	const int getCountJourney() const;
	void add(const Journey& journey);
	void print()const;
	void saveJtoFile(const Journey& journey)const;
};

