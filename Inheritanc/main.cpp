#include "InheritanceGraduate.h"


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

		if (typeid(*group[i]) == typeid(Student))
		{
			std::cout << *dynamic_cast<Student*>(group[i]) << std::endl;
		}
		else if (typeid(*group[i]) == typeid(Teacher))
		{
			std::cout << *dynamic_cast<Teacher*>(group[i]) << std::endl;
		}
		else if (typeid(*group[i]) == typeid(Graduate))
		{
			std::cout << *dynamic_cast<Graduate*>(group[i]) << std::endl;
		}

		/*
			dynamin_cast - позволяет узнать что то про кого-то :D, <   *> указывает про кого мы хотим узнать
		*/


		//std::cout << *group[i] << std::endl;
		//Перегрузить 
	}

	std::cout << delimiter << std::endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}

//virtual type name(parameters) = 0;		//Обявление чисто виртуального метода.

	std::cout << "Have a nice day))" << std::endl;

}