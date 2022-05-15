#pragma once
#include "String.h"
class Person {
	String username;
	String password;
	String email;

public:
	Person() {};
	Person(const String& username, const String& password, const String& email);
	const String getUsername() const { return username; }
	const String getEmail() const { return email; }
};

