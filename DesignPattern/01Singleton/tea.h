#include <utility>
#include <tuple>

struct Tea {
	int cost;
	int strength;
	int quantity;
};

bool operator==(const Tea& t1, const Tea& t2) {
	return std::make_tuple(t1.cost, t1.quantity, t1.strength) == std::make_tuple(t2.cost, t2.quantity, t2.strength);
}