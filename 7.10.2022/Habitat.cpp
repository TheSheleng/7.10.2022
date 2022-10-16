#include "Habitat.h"

void hbtt::Habitat::do_teek()
{
	//Плотоядные
	for (int i = 0; i < _carn.size(); i++)
	{
		for (int y = 0, r = rand_herb(); y < TRY_EAT; y++, r = rand_herb())
			if (r == -1) break;
			else
			{
				Animal* prey = _herb[r];
				if (_carn[i]->eat(&prey)) { dell_herb(r); break; }
			}

		_carn[i]->starve();
		if (_carn[i]->die()) dell_carn(i--);
	}

	//Травоядные
	for (int i = 0; i < _herb.size(); i++)
	{
		for (int y = 0, r = rand_plants(); y < TRY_EAT; y++, r = rand_plants())
			if (r == -1) break;
			else if (_herb[i]->eat(&_plants[r])) { dell_plant(r); break; }
			
		_herb[i]->starve();
		if (_herb[i]->die()) dell_herb(i--);
	}

	//Растения
	for (int i = 0; i < _plants.size(); i++)
	{
		//Рост
		_plants[i]->grow_up();

		//Смерть
		if (_plants[i]->die()) dell_plant(i--);
	}

	//Спавн растений
	for (int i = 0; i < GRASS_PER_TEEK; i++)
		spawn_plant(new Grass);

	if(teek++ % TEEKS_PER_YEAR == NULL) pass_year();

}

void hbtt::Habitat::pass_year()
{
	for (int i = 0; i < _carn.size(); i++) _carn[i]->grow_up();
	for (int i = 0; i < _herb.size(); i++) _herb[i]->grow_up();

	year++;
}

void hbtt::Habitat::spawn_carn(Carnivores* _ca)
{
	_carn.push_back(_ca);
}

void hbtt::Habitat::spawn_herb(Herbivores* _he)
{ 
	_herb.push_back(_he);
}

void hbtt::Habitat::spawn_plant(Plant* _pl)
{
	_plants.push_back(_pl);
}

void hbtt::Habitat::dell_carn(int index)
{
	delete _carn[index];
	_carn.erase(_carn.begin() + index);
}

void hbtt::Habitat::dell_herb(int index)
{
	delete _herb[index];
	_herb.erase(_herb.begin() + index);
}

void hbtt::Habitat::dell_plant( int index)
{
	delete _plants[index];
	_plants.erase(_plants.begin() + index);
}

int hbtt::Habitat::get_carn()
{
	return _carn.size();
}

int hbtt::Habitat::get_herb()
{
	return _herb.size();
}

int hbtt::Habitat::get_plants()
{
	return _plants.size();
}

int hbtt::Habitat::get_year()
{
	return year;
}

int hbtt::Habitat::rand_carn()
{
	if (_carn.size() != 0) return rand() % _carn.size();
	else return -1;
}

int hbtt::Habitat::rand_herb()
{
	if (_herb.size() != 0) return rand() % _herb.size();
	else return -1;
}

int hbtt::Habitat::rand_plants()
{
	if (_plants.size() != 0) return rand() % _plants.size();
	else return -1;
}