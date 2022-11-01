#include "spawner.h"
#include <algorithm>
#include <random>

int main() {
	DogSpawner ds;
	CatSpawner cs;
	MouseSpawner ms;

	std::vector<Creature*> creatures;

	ds.spawnerPack(creatures);
	cs.spawnerPack(creatures);
	ms.spawnerPack(creatures);
	
	std::random_device rnd{};
	std::mt19937 eng{ rnd() };
	std::shuffle(creatures.begin(), creatures.end(), eng);

	for (const auto& v : creatures) {
		std::cout << *v << '\n';
		if (Dog* c = dynamic_cast<Dog*>(v) ) {
			c->Bark();
			std::cout << "Clonning Dog:" << '\n';
			Creature* clone{ c->clone() };
			std::cout << "Clone: " << *clone << '\n';
		}
		else if (Cat* c = dynamic_cast<Cat*>(v)) {
			c->Meow();
		}
		else if (Mouse* c = dynamic_cast<Mouse*>(v)) {
			c->Squeak();
		}
	}

}