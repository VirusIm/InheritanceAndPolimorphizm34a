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
	std::string get_firstName() const
	{
		return this->firstName;
	}
	const std::string get_lastName() const
	{
		return this->lastName;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_firstName(const std::string firstName)
	{
		this->firstName = firstName;
	}
	void set_lastName(const std::string lastName)
	{
		this->lastName = lastName;
	}
	void set_age(const unsigned int age)
	{
		this->age = age;
	}

	//Constrictors:
	Human(const std::string& firstName, const std::string& lastName, const unsigned int age)
	{
		set_firstName(firstName);
		set_lastName(lastName);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}

	virtual~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

	//Methods:
	virtual void info()
	{
		std::cout << lastName << " " << firstName << " " << age << " year." << std::endl;
	}

};
class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;   //��� ��������
	unsigned int rating;    //������������

public:
	//�������� �� ������, ��� �� �� ������ �����.
	const std::string& get_specialty() const
	{
		return this->specialty;
	}
	const std::string& get_group() const
	{
		return this->group;
	}
	unsigned int get_year() const
	{
		return this->year;
	}
	unsigned int get_rating() const
	{
		return this->rating;
	}

	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating;
	}

	//		CONSTRUCTURS:
	Student(const std::string& firstName, const std::string& lastName, unsigned age,
		const std::string& specialty, const std::string& group,
		unsigned year, unsigned rating) :Human(firstName, lastName, age)
	{
		this->specialty = specialty;
		this->group = group;
		this->year = year;
		this->rating = rating;
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	//		FUNCTIONS
	void info()
	{
		Human::info();
		std::cout << "�������������: " << specialty << ", group: " << group << ", "
			<< year << " " << "����, ������������: " << rating << std::endl;
	}

};

class Teacher :public Human
{
	std::string subject;	//�������
	unsigned int experience;	//���� ������
	unsigned int salary;	//��������
public:
	const std::string& get_subject() const
	{
		return this->subject;
	}
	unsigned int get_experience() const
	{
		return this->experience;
	}
	unsigned int get_salary() const
	{
		return this->salary;
	}

	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	void set_salary(unsigned int salary)
	{
		this->salary = salary;
	}

	//			Construcnors:
	Teacher(const std::string& firstName, const std::string& lastName, unsigned int age,
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
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	//			Function
	void info()
	{
		Human::info();
		std::cout << "�������: " << subject << ", ���� ������: " << experience <<" ���"
					<< ", ��������: " << salary << std::endl;
	}

};
class Graduate :public Student		//���������
{
	std::string diplomaTheme;
public:
	const std::string& get_diplomaTheme() const
	{
		return diplomaTheme;
	}
	void set_diplomaTheme(const std::string& diplomaTheme)
	{
		this->diplomaTheme = diplomaTheme;
	}

	Graduate(const std::string& firstName, const std::string& lastName, unsigned age,
		const std::string& specialty, const std::string& group,
		unsigned year, unsigned rating, const std::string& diplomaTheme)
		:Student(firstName, lastName, age,
			specialty, group, year, rating), diplomaTheme(diplomaTheme)
	{
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void info()
	{
		Student::info();
		std::cout << "���� ����������� �������: " << diplomaTheme << std::endl;
	}


};
void main()
{
	setlocale(0, "");
	///*Human h("�������", "�����", 21);
	//h.info();*/

	//Teacher Gordon("�������", "������", 37, "�������", 11, 3800);

	///*Student s("����", "�������", 18, "����������", "�� �� 34�", 1, 0);
	//s.info();*/
	//Graduate Become("Detroit", "Become", 21, "����������", "�� �� 344", 4, 99,
	//	"��� ����������� ���� ����, ��� �� ���� ���� ���-�� �������?");
	//Human* pA = &Gordon;
	//Human* pM = &Become;
	//Human(*pA).info();
	//pA->info();// �������������� � �������� ��������
	//Human(*pM).info();	//���������� �� ��� ����������
	//pM->info();
	Human* group[] =
	{
		new Graduate("�������","������", 20, "���", "C� �� 34�", 1, 100, "������������ ��, +� � -�"),
		new Student("����", "��������", 18, "���", "�� �� 34�", 1, 70),
		new Teacher("������", "�����������", 40, "HardwarePC", 18, 1000),
		new Student("�������", "������", 18, "���", "�� �� 34�", 1, 70),
		new Graduate("��������", "����������", 17, "���", "�� �� 34�",1 , 80,
		"��� ����������� ���� ����, ����� ���� ���� ���-�� �������?"),
		new Teacher("�����", "�������", 33, "WebDev", 5, 1000)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		std::cout << delimiter << std::endl;
		// * ��������� ��� ��������
		std::cout << typeid(*group[i]).name() << std::endl;
		//group[i]->info();
		std::cout << *group[i] << std::endl;
		//����������� 
	}

	std::cout << delimiter << std::endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}



}









