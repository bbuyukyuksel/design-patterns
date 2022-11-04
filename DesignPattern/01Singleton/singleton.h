#define WIN32

#include "tea.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <memory>



class Manager {
	friend std::ostream& operator<<(std::ostream& os, const Manager& m);
public:
	static std::unique_ptr<Manager>& Instance() {
#if defined(UNIX)
		static std::unique_ptr<Manager> instance{ new Manager{"unix"} };
#elif defined(WIN32)
		static std::unique_ptr<Manager> instance{ new Manager{"win32"} };
#endif
		return instance;
	}


	void Add(Tea tea) {
		teas.push_back(tea);
	}

	void Remove(Tea tea) {
		auto iter = std::find(teas.cbegin(), teas.cend(), tea);
		if (iter != teas.cend()) {
			teas.erase(iter);
		}
	}

	[[nodiscard]] const std::vector<Tea>& GetTeaList() {
		return teas;
	}

	const std::string& GetPlatformName() {
		return platform;
	}


private:

	std::vector<Tea> teas;
	std::string platform;
	Manager() = default;
	Manager(std::string platform) : platform{ std::move(platform) } {}
};

std::ostream& operator<<(std::ostream& os, const Tea& t) {
	return os << '(' << t.cost << ',' << t.quantity << ',' << t.strength << ')';
}

std::ostream& operator<<(std::ostream& os, const Manager& m) {
	
	os << '[';
	for (const auto& v : m.teas) {
		os << v << ", ";
	}
	return os << ']';
}