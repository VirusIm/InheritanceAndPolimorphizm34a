#pragma once
#include "InheritanceTeacher.h"

class Graduate :public Student		//Дипломник
{
	std::string diplomaTheme;
public:
	const std::string& get_diplomaTheme() const;
	void set_diplomaTheme(const std::string& diplomaTheme);


	//			Constructors:
	Graduate(const std::string& firstName, const std::string& lastName, unsigned age,
		const std::string& specialty, const std::string& group,
		unsigned year, unsigned rating, const std::string& diplomaTheme);
	~Graduate();

	//			Methods:
	void info();
};
std::ostream& operator<<(std::ostream& os, const Graduate& obj);
