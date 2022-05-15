#include "String.h"
#include <cstring>
#pragma warning (disable : 4996)
void String::copyFrom(const String& other) {
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void String::free() { delete[] str; }

String::String() {
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

String::String(const char* data) {
	if (data == nullptr) {
		str = new char[1];
		str[0] = '\0';
		size = 0;
	}
	else {
		size = strlen(data);
		str = new char[size + 1];
		strcpy(str, data);
	}
}

String::String(const String& other) {
	copyFrom(other);
}
String& String::operator=(const String& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
String::~String() {
	free();
}


size_t String::getSize() const {
	return size;
}

void String::concat(const String& other) {
	char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	size = size + other.getSize();
}

const char* String::getStr() const {
	return str;
}

char String::operator[] (int index) const {
	return str[index];
}

std::ostream& operator<<(std::ostream& s, const String& str) {
	s << str.str;
	return s;
}
std::istream& operator>>(std::istream& s, const String& str) {
	s >> str.str;
	return s;
}
