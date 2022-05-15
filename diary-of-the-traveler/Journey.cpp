#include "Journey.h"
void Journey::copyFrom(const Journey& other) {
	person = other.person;
	time = other.time;
	comment = other.comment;
	grade = other.grade;
	photosCount = other.photosCount;
	photos = new String[photosCount];
	for (size_t i = 0; i < photosCount; i++) {
		photos[i] = other.photos[i];
	}
}
void Journey::free() {
	delete[] photos;
}

const bool Journey::isValidNameOfPhoto(const String& photo) {
	int count = 0;
	int length = photo.getSize();
	char* tail = new char[4];
	bool b = true;
	for (int i = 0; i < length; i++) {
		if (photo[i] < '0' || (photo[i] > '9' && photo[i] < 'A') || (photo[i] > 'Z' && photo[i] < '_') ||
			(photo[i] > '_' && photo[i] < 'a') || photo[i] > 'z') {
			b = false;
			break;
		}
		if (photo[i] == '.') {
			for (size_t j = 0; j < length - i; j++)
				tail[j] = photo[i + j + 1];
		}
	}
	if (b && (strcmp(tail, "png") == 0) || (strcmp(tail, "jpeg") == 0)) {
		delete[] tail;
		return true;
	}
	delete[] tail;
	return false;
}

Journey::Journey() {
	grade = 0;
	photos = nullptr;
}
Journey::Journey(const Person& person, const TimePeriod& time, const String& comment, const int grade, const String* photos, const int photosCount) {
	this->person = person;
	this->time = time;
	this->comment = comment;
	this->photosCount = photosCount;
	setGrade(grade);
	setPhotos(photos, photosCount);
}
Journey::Journey(const Journey& other) {
	copyFrom(other);
}
Journey& Journey::operator=(const Journey& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Journey::~Journey() { free(); }

const Person& Journey::getPerson() const { return person; }
const TimePeriod& Journey::getTime() const { return time; }
const String& Journey::getComment() const { return comment; }
const int Journey::getGrade() const { return grade; }
const String* Journey::getPhotos() const { return photos; }
const int Journey::getPhotosCount()const { return photosCount; }


void Journey::setGrade(int grade) {
	if (grade < 1) grade = 1;
	if (grade > 5) grade = 5;
	this->grade = grade;
}
void Journey::setPhotos(const String* photos, int photosCount) {
	for (size_t i = 0; i < photosCount; i++) {
		this->photos[i] = photos[i];
	}
	this->photosCount = photosCount;
	return;
}

void Journey::print()const {
	std::cout << person.getUsername() << ": (" << time.getDate1() << " - " << time.getDate2() << "), wrote: " << comment
		<< " Grade: " << grade << " Photos: " << std::endl;
	for (size_t i = 0; i < photosCount; i++) {
		std::cout << photos[i] << std::endl;
	}
}