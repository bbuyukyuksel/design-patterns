#include <iostream>

class Creature {
public:
	virtual ~Creature() = default;
	Creature() = default;
	virtual Creature* clone() { return nullptr; }
	int get_hp()const { return m_hitPoint; }
	int get_attack()const { return m_attack; }
	int get_speed()const { return m_speed; }

protected:
	int m_hitPoint = 0;
	int m_attack = 0;
	int m_speed = 0;
};

std::ostream& operator<<(std::ostream& os, const Creature& c) {
	return os << c.get_hp() << ',' << c.get_attack() << ',' << c.get_speed();
}

class Dog : public Creature {
public:
	Dog(){
		m_hitPoint = 3;  m_attack = 3; m_speed = 3;
	}
	void Bark()const {
		std::cout << "Wow!\n";
	}
	Creature* clone()const {
		return new Dog(*this);
	}
};

class Cat : public Creature {
public:
	Cat(){
		m_hitPoint = 2;  m_attack = 2; m_speed = 2;
	}
	void Meow()const {
		std::cout << "Meow!\n";
	}
};

class Mouse : public Creature {
public:
	Mouse(){
		m_hitPoint = 1;  m_attack = 1; m_speed = 1;
	}
	void Squeak()const {
		std::cout << "ekeekkee!\n";
	}
};