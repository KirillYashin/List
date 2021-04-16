#include "List.h"
#include <iostream>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		List<int> list;
		int position, data;
		std::cout << "Проверим работу функций PushBegin и PushEnd" << std::endl;
		std::cout << "Введите количество элементов, которые вы хотели бы поместить в начало списка:" << std::endl;
		int begin, end;
		std::cin >> begin;
		for (int i = 0; i < begin; i++)
			list.PushBegin(std::rand() % 100);
		std::cout << "Введите количество элементов, которые вы хотели бы поместить в конец списка:" << std::endl;
		std::cin >> end;
		for (int i = 0; i < end; i++)
			list.PushEnd(std::rand() % 100);
		std::cout << "Список:" << std::endl;;
		list.Print();
		std::cout << std::endl;
		std::cout << "Первый элемент в списке:" << list.GetBegin() << std::endl;
		std::cout << "Последний элемент в списке: " << list.GetEnd() << std::endl;
		std::cout << std::endl;
		std::cout << "Список без этих элементов:" << std::endl;
		list.Print();
		std::cout << std::endl;
		std::cout << "Введите номер позиции, отличный от начала и конца, куда вы хотите поместить новый элемент:" << std::endl;
		std::cin >> position;
		std::cout << "Введите сам элемент:" << std::endl;
		std::cin >> data;
		list.Push(position, data);
		std::cout << "Обновленный список:";
		list.Print();
		std::cout << std::endl;
		std::cout << "Введите 1, если хотите проверить исключение для Print." << std::endl;
		std::cout << "Введите 2, если хотите проверить исключение для неправильного индекса в Get." << std::endl;
		std::cout << "Введите 3, если хотите проверить исключение для Get." << std::endl;
		std::cout << "Введите 4, если хотите проверить обработку неправильного индекса в Push." << std::endl;
		int mode;
		std::cin >> mode;
		std::cout << std::endl;
		List<int> tmp;
		switch (mode)
		{
		case 1:
			tmp.Print();
			break;
		case 2:
			list.Get(-1);
			break;
		case 3:
			tmp.GetBegin();
			break;
		case 4:
			list.Push(-1, 0);
			break;
		default:
			break;
		}
	}
	catch (Exception exc)
	{
		exc.Print();
	}

	return 0;
}
