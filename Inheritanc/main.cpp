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
	unsigned int year;   //год обучения
	unsigned int rating;    //успеваемость

public:
	//передача по ссылке, что бы не делать копию.
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
		std::cout << "Специальность: " << specialty << ", group: " << group << ", "
			<< year << " " << "курс, успеваемость: " << rating << std::endl;
	}

};

class Teacher :public Human
{
	std::string subject;	//Предмет
	unsigned int experience;	//Стаж работы
	unsigned int salary;	//Зарплата
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
		std::cout << "Предмет: " << subject << ", стаж работы: " << experience <<" лет"
					<< ", зарплата: " << salary << std::endl;
	}

};
class Graduate :public Student		//Дипломник
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
		std::cout << "Тема диспломного проекта: " << diplomaTheme << std::endl;
	}


};
void main()
{
	setlocale(0, "");
	///*Human h("Василий", "Дурко", 21);
	//h.info();*/

	//Teacher Gordon("Дмитрий", "Гордон", 37, "История", 11, 3800);

	///*Student s("Иван", "Тупэнко", 18, "Девелоупер", "СТ ПУ 34а", 1, 0);
	//s.info();*/
	//Graduate Become("Detroit", "Become", 21, "Программер", "СТ ПП 344", 4, 99,
	//	"Как разработать свою игру, что бы тебя хоть кто-то заметил?");
	//Human* pA = &Gordon;
	//Human* pM = &Become;
	//Human(*pA).info();
	//pA->info();// преобразование в обычного человека
	//Human(*pM).info();	//показывает на всю информацию
	//pM->info();
	Human* group[] =
	{
		new Graduate("Виталий","Гавриш", 20, "РПО", "CТ ПУ 34а", 1, 100, "Самообучение ИИ, +ы и -ы"),
		new Student("Юлия", "Рыбакова", 18, "РПО", "СТ ПУ 34а", 1, 70),
		new Teacher("Андрей", "Кобылинский", 40, "HardwarePC", 18, 1000),
		new Student("Евгений", "Ковтун", 18, "РПО", "СТ ПУ 34а", 1, 70),
		new Graduate("Марианна", "Забрянская", 17, "РПО", "СТ ПУ 34а",1 , 80,
		"Как разработать свою игру, чтобы тебя хоть кто-то заметил?"),
		new Teacher("Роман", "Шерстюк", 33, "WebDev", 5, 1000)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		std::cout << delimiter << std::endl;
		// * указывает тип значения
		std::cout << typeid(*group[i]).name() << std::endl;
		//group[i]->info();
		std::cout << *group[i] << std::endl;
		//Перегрузить 
	}

	std::cout << delimiter << std::endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}



}









