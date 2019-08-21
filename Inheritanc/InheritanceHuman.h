#pragma once
#include <iostream>
#include <string>

#define tab "\t"
#define delimiter "\n-------------------------------------------------------------------\n"

class Human
{
	std::string firstName;
	std::string lastName;
	unsigned int age;
public:
	std::string get_firstName() const;
	const std::string get_lastName() const;
	unsigned int get_age() const;
	void set_firstName(const std::string firstName);
	void set_lastName(const std::string lastName);
	void set_age(const unsigned int age);

	//				Constrictors:
	Human(const std::string& firstName, const std::string& lastName, const unsigned int age);
	Human(Human& other);


	virtual~Human();

	//				Methods:
	virtual void info();
	virtual void some_method() = 0;
};

std::ostream& operator<< (std::ostream& os, const Human& obj);
