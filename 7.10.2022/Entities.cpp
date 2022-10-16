#include "Entities.h"
#include "Habitat.h"

int ntts::Plant::getGrown()
{
	return how_grown;
}

int ntts::Plant::getEdible()
{
	return EDIBLE;
}

void ntts::Plant::grow_up()
{
	switch (rand() % GROW_SPEED)
	{
	case NULL: how_grown++;
	default: break;
	}
}

void ntts::Animal::starve()
{
	hunger++;
}

void ntts::Animal::grow_up()
{
	age++;
}

bool ntts::Plant::die()
{
	return how_grown >= DRY;
}

Animal* ntts::Rabbit::give_birth()
{
	return nullptr;
}

bool ntts::Rabbit::eat(Plant** prey)
{
	if ((*prey)->getGrown() >= (*prey)->getEdible() && hunger > NULL)
		return Herbivores::eat(prey);
	else return false;
}

bool ntts::Animal::die()
{
	return hunger >= STARVATION || age >= SPAN;
}

bool ntts::Herbivores::eat(Plant** prey)
{
	hunger -= 2;
	return true;
}

bool ntts::Carnivores::eat(Animal** prey)
{
	hunger -= 2;
	return true;
}

Animal* ntts::Fox::give_birth()
{
	return nullptr;
}

bool ntts::Fox::eat(Animal** prey)
{
	if (hunger > NULL)
		return Carnivores::eat(prey);
	else return false;
}

bool ntts::Male::get_ability()
{
	return !occupied;
}

bool ntts::Female::get_ability()
{
	return !pregnancy;
}

void ntts::Male::make_offspring()
{

}

void ntts::Female::make_offspring()
{

}

Animal* ntts::Rabbit::create_offspring()
{
	return nullptr;
}

Animal* ntts::Fox::create_offspring()
{
	return nullptr;
}