#pragma once
#include "InheritanceStudent.h"


class Teacher :public Human
{
	std::string subject;	//Предмет
	unsigned int experience;	//Стаж работы
	unsigned int salary;	//Зарплата
public:
	const std::string& get_subject() const;
	unsigned int get_experience() const;
	unsigned int get_salary() const;

	void set_subject(const std::string& subject);
	void set_experience(unsigned int experience);
	void set_salary(unsigned int salary);

	//			Constructors:
	Teacher(const std::string& firstName, const std::string& lastName, unsigned int age,
		const std::string& subject, unsigned experience, unsigned salary);
	~Teacher();
	//			Methods:
	void some_method();
	void info();
};
std::ostream& operator<< (std::ostream& os, const Teacher& obj);
