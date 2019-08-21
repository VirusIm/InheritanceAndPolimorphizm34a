#include "InheritanceTeacher.h"

const std::string& Teacher::get_subject() const
{
	return this->subject;
}
unsigned int Teacher::get_experience() const
{
	return this->experience;
}
unsigned int Teacher::get_salary() const
{
	return this->salary;
}

void Teacher::set_subject(const std::string& subject)
{
	this->subject = subject;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}
void Teacher::set_salary(unsigned int salary)
{
	this->salary = salary;
}

//			Constructors:
Teacher::Teacher(const std::string& firstName, const std::string& lastName, unsigned int age,
	const std::string& subject, unsigned experience, unsigned salary) :Human(firstName, lastName, age)
{
	/*this->subject = subject;
	this->experience = experience;
	this->salary = salary;*/
	set_subject(subject);
	set_experience(experience);
	set_salary(salary);
	std::cout << "TConstructor:\t" << this << std::endl;
}
Teacher::~Teacher()
{
	std::cout << "TDestructor:\t" << this << std::endl;
}
//			Methods:
void Teacher::some_method()
{
	std::cout << "��� ������!" << std::endl;
}
void Teacher::info()
{
	Human::info();
	std::cout << "�������: " << subject << ", ���� ������: " << experience << " ���"
		<< ", ��������: " << salary << std::endl;
}
std::ostream& operator<< (std::ostream& os, const Teacher& obj)
{
	os << (Human&)obj;
	return os << "�������: " << obj.get_subject() << ", ���� ������: " << obj.get_experience()
		<< " ���, ��������: " << obj.get_salary() << std::endl;
}