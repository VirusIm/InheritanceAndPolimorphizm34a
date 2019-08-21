#include "InheritanceHuman.h"

std::string Human::get_firstName() const
{
	return this->firstName;
}
const std::string Human::get_lastName() const
{
	return this->lastName;
}
unsigned int Human::get_age() const
{
	return this->age;
}
void Human::set_firstName(const std::string firstName)
{
	this->firstName = firstName;
}
void Human::set_lastName(const std::string lastName)
{
	this->lastName = lastName;
}
void Human::set_age(const unsigned int age)
{
	this->age = age;
}

//				Constrictors:
Human::Human(const std::string& firstName, const std::string& lastName, const unsigned int age)
{
	set_firstName(firstName);
	set_lastName(lastName);
	set_age(age);
	std::cout << "HConstructor:\t" << this << std::endl;
}
Human::Human(Human& other)
{
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->age = other.age;
	std::cout << "HCopyConstructor:\t" << this << std::endl;

}


Human::~Human()
{
	std::cout << "HDestructor:\t" << this << std::endl;
}

//				Methods:
void Human::info()
{
	std::cout << lastName << " " << firstName << " " << age << " year." << std::endl;
}




std::ostream& operator<< (std::ostream& os, const Human& obj)
{
	return os << obj.get_lastName() << " " << obj.get_firstName() << " " << obj.get_age() << " year " << std::endl;
}