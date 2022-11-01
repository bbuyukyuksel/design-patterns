#include "creature.h"
#include <vector>

class Spawner {
public:
	virtual ~Spawner() = default;
	virtual Creature* spawn() = 0;	
	virtual void spawnerPack(std::vector<Creature*>& out_pack) = 0;
};

class DogSpawner : public Spawner {
public:
	Creature* spawn()override {
		return new Dog{};
	}
	void spawnerPack(std::vector<Creature*>& out_pack) override {
		for (int i = 0; i < 5; ++i) {
			out_pack.push_back(new Dog{});
		}
	}
};

class CatSpawner : public Spawner {
public:
	Creature* spawn()override {
		return new Cat{};
	}
	void spawnerPack(std::vector<Creature*>& out_pack) override {
		for (int i = 0; i < 5; ++i) {
			out_pack.push_back(new Cat{});
		}
	}
};

class MouseSpawner : public Spawner{
public:
	Creature* spawn()override {
		return new Mouse{};
	}
	void spawnerPack(std::vector<Creature*>& out_pack) override {
		for (int i = 0; i < 5; ++i) {
			out_pack.push_back(new Mouse{});
		}
	}
};
