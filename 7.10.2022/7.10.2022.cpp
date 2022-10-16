#include <iostream>
#include <windows.h>
#include "Habitat.h"

using namespace std;
using namespace hbtt;

int main()
{
	srand(time(NULL));

	Habitat preserve(12, 5);

	for (int i = 0; i < 100; i++) preserve.spawn_plant(new Grass);
	for (int i = 0; i < 5; i++) preserve.do_teek();

	while (true)
	{
		preserve.do_teek();

		//Изначально планировалось, чтобы животные размножались 
		//(для этого есть цепочка класов gender), но я не успевл 
		//это реализовать. Поэтому пока просто их создаю, а позже 
		//доделаю как хотел.
		preserve.spawn_carn(new Fox(true));
		for (int i = 0; i < 5; i++) if (rand() % 2 == NULL) preserve.spawn_herb(new Rabbit(true));

		system("cls");
		cout << "Fox: " << preserve.get_carn() << endl;
		cout << "Rabbits: " << preserve.get_herb() << endl;
		cout << "Grass: " << preserve.get_plants() << endl;

		cout << "\nYear: " << preserve.get_year();

		Sleep(100);
	}
}