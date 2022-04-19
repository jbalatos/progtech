#include <iostream>
#include <stdexcept>

using namespace std;

class Polynomial {
	protected:
		class Term {
			protected:
				int exponent;
				int coefficient;
				Term *next;
				Term(int exp, int coeff, Term *n);
				friend class Polynomial;
		};

	public:
		Polynomial();
		Polynomial(const Polynomial &p);
		~Polynomial();

		Polynomial & operator = (const Polynomial &p) noexcept;

		void addTerm(int expon, int coeff) noexcept;
		double evaluate(double x) noexcept;

		friend Polynomial operator+ (const Polynomial &p, const Polynomial &q) noexcept;
		friend Polynomial operator* (const Polynomial &p, const Polynomial &q) noexcept;

		friend ostream & operator << (ostream &out, const Polynomial &p) noexcept;
};

#ifndef CONTEST
int main() {
	Polynomial p; // 0
	p.addTerm(1, 3); // 3x
	p.addTerm(2, 1); // x^2
	p.addTerm(0, -1); // -1

	Polynomial q(p); // x^2 + 3x - 1
	q.addTerm(1, -3); // -3x

	cout << "P(x) = " << p << endl;
	cout << "P(1) = " << p.evaluate(1) << endl;
	cout << "Q(x) = " << q << endl;
	cout << "Q(1) = " << q.evaluate(1) << endl;
	cout << "(P+Q)(x) = " << p+q << endl;
	cout << "(P*Q)(x) = " << p*q << endl;
}
/* EXPECTED OUTPUT
P(x) = x^2 + 3x - 1
P(1) = 3
Q(x) = x^2 - 1
Q(1) = 0
(P+Q)(x) = 2x^2 + 3x - 2
(P*Q)(x) = x^4 + 3x^3 - 2x^2 - 3x + 1
 */
#endif //CONTEST
