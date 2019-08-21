#include "InheritanceStudent.h"

const std::string& Student::get_specialty() const
{
	return this->specialty;
}
const std::string& Student::get_group() const
{
	return this->group;
}
unsigned int Student::get_year() const
{
	return this->year;
}
unsigned int Student::get_rating() const
{
	return this->rating;
}

void Student::set_specialty(const std::string& specialty)
{
	this->specialty = specialty;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_year(unsigned int year)
{
	this->year = year;
}
void Student::set_rating(unsigned int rating)
{
	this->rating = rating;
}

//		Constructors:
Student::Student(const std::string& firstName, const std::string& lastName, unsigned age,
	const std::string& specialty, const std::string& group,
	unsigned year, unsigned rating) :Human(firstName, lastName, age)
{
	this->specialty = specialty;
	this->group = group;
	this->year = year;
	this->rating = rating;
	std::cout << "SConstructor:\t" << this << std::endl;
}
Student::~Student()
{
	std::cout << "SDestructor:\t" << this << std::endl;
}

//		Methods:
void Student::some_method()
{
	std::cout << "Превед, я стутенд" << std::endl;
}
void Student::info()
{
	Human::info();
	std::cout << "Специальность: " << specialty << ", group: " << group << ", "
		<< year << " " << "курс, успеваемость: " << rating << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << (Human&)obj;
	return os << "Спациальность: " << obj.get_specialty() << ", группа: " << obj.get_group()
		<< ", курс: " << obj.get_year() << ", успеваемость: " << obj.get_rating() << "%" << std::endl;
}