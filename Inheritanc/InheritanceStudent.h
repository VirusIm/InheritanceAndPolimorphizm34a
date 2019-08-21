#pragma once
#include "InheritanceHuman.h"


class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;   //год обучения
	unsigned int rating;    //успеваемость

public:
	//передача по ссылке, что бы не делать копию.
	const std::string& get_specialty() const;
	const std::string& get_group() const;
	unsigned int get_year() const;
	unsigned int get_rating() const;

	void set_specialty(const std::string& specialty);
	void set_group(const std::string& group);
	void set_year(unsigned int year);
	void set_rating(unsigned int rating);

	//		Constructors:
	Student(const std::string& firstName, const std::string& lastName, unsigned age,
		const std::string& specialty, const std::string& group,
		unsigned year, unsigned rating);
	~Student();

	//		Methods:
	void some_method();
	void info();

};
std::ostream& operator<<(std::ostream& os, const Student& obj);