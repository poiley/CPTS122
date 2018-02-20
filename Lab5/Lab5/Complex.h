#include "Main.h"

class Complex {
public:
	Complex();
	Complex(Complex &copy);
	Complex(double r, double i);

	~Complex();

	double getReal() const;
	double getImaginary() const;

	void setReal(double r);
	void setImaginary(double i);

	void read();
	void print();
	Complex add(Complex rhs);
	Complex sub(Complex rhs);

private:
	double real, imaginary;
};

Complex add(Complex lhs, Complex rhs);

Complex operator+ (const Complex &lhs, const Complex &rhs);
Complex operator- (const Complex &lhs, const Complex &rhs);