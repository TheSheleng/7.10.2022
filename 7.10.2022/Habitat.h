#pragma once

#include <iostream>
#include <vector>
#include "Entities.h"

using namespace std;
using namespace ntts;

namespace hbtt
{
	class Habitat
	{
		vector<Carnivores*> _carn;
		vector<Herbivores*> _herb;
		vector<Plant*> _plants;

		const int TEEKS_PER_YEAR;
		const int GRASS_PER_TEEK;

		const int TRY_EAT;

		int year = 0;
		int teek = 0;

	public:
		Habitat(const int tpy, const int gpt, const int _te = 10) : TEEKS_PER_YEAR(tpy), GRASS_PER_TEEK(gpt), TRY_EAT(_te) {}

		void do_teek();
		void pass_year();

		void spawn_carn(Carnivores* _ca);
		void spawn_herb(Herbivores* _he);
		void spawn_plant(Plant* _pl);

		void dell_carn(int index);
		void dell_herb(int index);
		void dell_plant(int index);

		int get_carn();
		int get_herb();
		int get_plants();

		int rand_carn();
		int rand_herb();
		int rand_plants();

		int get_year();
	};
}

