#include "InheritanceGraduate.h"
const std::string& Graduate::get_diplomaTheme() const
{
	return diplomaTheme;
}
void Graduate::set_diplomaTheme(const std::string& diplomaTheme)
{
	this->diplomaTheme = diplomaTheme;
}


//			Constructors:
Graduate::Graduate(const std::string& firstName, const std::string& lastName, unsigned age,
	const std::string& specialty, const std::string& group,
	unsigned year, unsigned rating, const std::string& diplomaTheme)
	:Student(firstName, lastName, age,
		specialty, group, year, rating), diplomaTheme(diplomaTheme)
{
	std::cout << "GConstructor:\t" << this << std::endl;
}
Graduate::~Graduate()
{
	std::cout << "GDestructor:\t" << this << std::endl;
}

//			Methods:
void Graduate::info()
{
	Student::info();
	std::cout << "Тема дипломного проекта: " << diplomaTheme << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	os << (Student&)obj;
	return os << "Тема дипломного проекта: " << obj.get_diplomaTheme();
}