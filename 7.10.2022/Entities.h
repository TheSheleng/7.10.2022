#pragma once

#include <iostream>

using namespace std;

namespace ntts
{
	struct Nature
	{
		virtual void grow_up() = 0;
		virtual bool die() = 0;
	};

	class Plant : public Nature
	{
	protected:
		int how_grown = 0;
		const int EDIBLE;
		const int DRY;
		const int GROW_SPEED; //Может быть больше 0
	public:
		Plant(const int _edi, const int _dry, const int _gs) : EDIBLE(_edi), DRY(_dry), GROW_SPEED(_gs) {}

		int getGrown();
		int getEdible();
		virtual void grow_up();
		virtual bool die();
	};

	class Grass : public Plant
	{
	public:
		Grass() : Plant(5, 15, 3) {}
	};

	class  Gender
	{
		const int PREG_TIME;
		int stage = 0;

	public:
		Gender(const int _pt) : PREG_TIME(_pt) {}
		virtual bool get_ability() = 0;
		virtual void make_offspring() = 0;
	};

	class Male : public Gender
	{
		int occupied = false;

	public:
		Male(const int _pt) : Gender(_pt) {}
		virtual bool get_ability();
		virtual void make_offspring();
	};

	class Female : public Gender
	{
		int pregnancy = false;

	public:
		Female(const int _pt) : Gender(_pt) {}
		virtual bool get_ability();
		virtual void make_offspring();
	};

	class Animal : public Nature
	{
	protected:
		Gender* _gender = nullptr;
		int hunger = 0;
		int age = 0;

		const int SPAN;
		const int STARVATION;

	public:
		Animal(const int _sp, const int _st) : SPAN(_sp), STARVATION(_st) 
		{
			
		}

		virtual void starve();
		virtual void grow_up();
		virtual Animal* create_offspring() = 0;

		bool die();
	};

	class Herbivores : public Animal
	{
	public:
		Herbivores(const bool _m, const int _sp, const int _st) : Animal(_sp, _st) {}
		virtual bool eat(Plant** prey);
	};

	class Rabbit : public Herbivores
	{
	public:
		Rabbit(const bool _m) : Herbivores(_m, 5, 4) {}
		virtual Animal* give_birth();
		virtual bool eat(Plant** prey);
		virtual Animal* create_offspring();
	};

	class Carnivores : public Animal
	{
	public:
		Carnivores(const bool _m, const int _sp, const int _st) : Animal(_sp, _st) {}
		virtual bool eat(Animal** prey) = 0;
	};

	class Fox : public Carnivores
	{
	public:
		Fox(const bool _m) : Carnivores(_m, 15, 8) {}
		virtual Animal* give_birth();
		virtual bool eat(Animal** prey);
		virtual Animal* create_offspring();
	};
}

