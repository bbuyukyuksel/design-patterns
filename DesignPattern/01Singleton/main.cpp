#include "singleton.h"
#include <cstdlib>

void func() {
	std::cout << "Inside Func\n";
	std::cout << Manager::Instance() << '\n';
}

int main() {
	auto& manager = Manager::Instance();

	manager->Add(Tea{ 1,1,1 });
	manager->Add(Tea{ 2,2,2 });
	std::cout << *manager << '\n';

	manager->Remove(Tea{ 1,1,1 });

	std::cout << *manager << '\n';
	manager->Add(Tea{ 3,3,3 });

	func();

	std::cout << "Platform Name:" << manager->GetPlatformName() << '\n';
}