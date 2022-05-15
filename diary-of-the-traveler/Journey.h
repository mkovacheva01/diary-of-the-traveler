#pragma once
#include"Person.h"
#include"TimePeriod.h"
#include"String.h"

class Journey {
	Person person;
	TimePeriod time;
	String comment;
	int grade;
	String* photos;
	int photosCount;

	void copyFrom(const Journey& other);
	void free();
	const bool isValidNameOfPhoto(const String& photo);

public:
	Journey();
	Journey(const Person& person, const TimePeriod& time, const String& comment, const int grade, const String* photos, const int photosCount);
	Journey(const Journey&);
	Journey& operator=(const Journey& other);
	~Journey();

	const Person& getPerson() const;
	const TimePeriod& getTime() const;
	const String& getComment() const;
	const int getGrade() const;
	const String* getPhotos() const;
	const int getPhotosCount()const;

	void setGrade(int grade);
	void setPhotos(const String* photos, int photosCount);
	void print()const;
};

