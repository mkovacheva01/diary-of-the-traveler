#include "Destination.h"
#include <fstream>

void Destination::copyFrom(const Destination& other) {
	name = other.name;
	countJourney = other.countJourney;
	capacity = other.capacity;
	journeys = new Journey[capacity];
	for (size_t i = 0; i < countJourney; i++) {
		journeys[i] = other.journeys[i];
	}
}
void Destination::free() {
	delete[] journeys;
}

void Destination::resize() {
	capacity = 2 * capacity;
	Journey* newMemory = new Journey[capacity];

	for (int i = 0; i < countJourney; i++)
		newMemory[i] = journeys[i];

	delete[] journeys;
	journeys = newMemory;
}

bool Destination::isEmpty()const {
	return countJourney == 0;
}


Destination::Destination() {
	capacity = 8;
	journeys = new Journey[capacity];
	countJourney = 0;
}
Destination::Destination(const String& name) {
	this->name = name;
	capacity = 8;
	journeys = new Journey[capacity];
	countJourney = 0;
}
Destination::Destination(const Destination& other) {
	copyFrom(other);
}
Destination& Destination::operator=(const Destination& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Destination::~Destination() {
	free();
}

const String& Destination::getName()const { return name; }
const Journey* Destination::getJourney()const { return journeys; }
const int Destination::getCountJourney() const { return countJourney; }

void Destination::add(const Journey& journey) {
	if (countJourney == capacity)
		resize();
	sumAllG += journey.getGrade();
	countJourney++;
	journeys[countJourney] = journey;
	averageG = sumAllG / countJourney;
}

void Destination::print()const {
	std::cout << name << ": \n";
	for (size_t i = 0; i < countJourney; i++) {
		journeys[i].print();
	}
	std::cout << "\n  Average grade: " << averageG << std::endl;
}

void Destination::saveJtoFile(const Journey& journey)const {
	String file = journey.getPerson().getUsername();
	file.concat(".txt");
	std::ofstream f(file.getStr(), std::ios::app);
	if (!f.is_open()) {
		std::cout << "File is not open";
		return;
	}
	char line1 = ' / ';
	char line2 = '|';
	f << name << line1 << journey.getTime().getDate1() << line2 << journey.getTime().getDate2() << line1
		<< journey.getGrade() << line1 << journey.getComment() << line1;
	for (size_t i = 0; i < journey.getPhotosCount(); i++) {
		f << journey.getPhotos()[i] << line2;
	}
}