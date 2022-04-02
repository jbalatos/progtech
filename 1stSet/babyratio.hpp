#ifndef BABYRATIO_HPP
#define BABYRATIO_HPP

class rational {
	public:
		rational (int n, int d);

		rational add (rational r);
		rational sub (rational r);
		rational mul (rational r);
		rational div (rational r);

		void print ();
	private:
		int nom, den;

		static int gcd (int a, int b);
};

#endif //BABYRATIO_HPP

