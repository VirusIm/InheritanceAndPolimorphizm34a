#include "InheritanceGraduate.h"


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
			dynamin_cast - ��������� ������ ��� �� ��� ����-�� :D, <   *> ��������� ��� ���� �� ����� ������
		*/


		//std::cout << *group[i] << std::endl;
		//����������� 
	}

	std::cout << delimiter << std::endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}

//virtual type name(parameters) = 0;		//��������� ����� ������������ ������.

	std::cout << "Have a nice day))" << std::endl;

}