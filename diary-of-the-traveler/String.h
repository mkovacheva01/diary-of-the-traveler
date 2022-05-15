#pragma once
#include<iostream>
class String {
	char* str;
	size_t size;

	void copyFrom(const String& other);
	void free();
public:
	String();
	String(const char* data);
	String(const String&);
	String& operator=(const String& other);
	~String();

	size_t getSize() const;
	void concat(const String& other);
	const char* getStr() const;
	char operator[] (int index) const;
	friend std::ostream& operator<<(std::ostream& s, const String& str);
	friend std::istream& operator>>(std::istream& s, const String& str);
};
