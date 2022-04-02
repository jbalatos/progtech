#include <iostream>
#include "babyratio.hpp"

using namespace std;

int main() {
	rational a(1, 3);
	rational b(1, 4);
	rational c(5, 6);
	a.add(b).print();
	cout << endl;
	a.print();
	cout << " should still be 1/2" << endl;
}
