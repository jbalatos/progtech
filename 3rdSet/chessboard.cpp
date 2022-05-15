#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ChessBoardArray {
	protected:
		class Row {
			public:
				Row(ChessBoardArray &a, int i);
				int & operator [] (int i);
		};
		class ConstRow {
			public:
				ConstRow(const ChessBoardArray &a, int i);
				int operator [] (int i) const;
		};
	public:
		ChessBoardArray(unsigned size = 0, unsigned base = 0);
		ChessBoardArray(const ChessBoardArray &a);
		~ChessBoardArray();
		ChessBoardArray & operator = (const ChessBoardArray &a) noexcept;
		int & select(int i, int j);
		int select(int i, int j) const;
		const Row operator [] (int i);
		const ConstRow operator [] (int i) const;

		friend ostream & operator << (ostream &out, const ChessBoardArray &a) noexcept;

	private:
		unsigned int loc (int i, int j) const; // throws std::out_of_range
};


#ifndef CONTEST
int main() {
	ChessBoardArray a(4, 1); // size 4x4, rows and columns numbered from 1
	a[3][1] = 42;
	a[4][4] = 17;
	try { a[2][1] = 7; }
	catch(out_of_range &e) { cout << "a[2][1] is black" << endl; }
	try { cout << a[1][2] << endl; }
	catch(out_of_range &e) { cout << "and so is a[1][2]" << endl; }
	cout << a;
}
/* EXPECTED OUTPUT
a[2][1] is black
and so is a[1][2]
   0    0    0    0
   0    0    0    0
  42    0    0    0
   0    0    0   17
*/
#endif //CONTEST
