#include "Main.h"
#include "Complex.h"

Complex::Complex() {
	real = 0.0;
	imaginary = 0.0;
}

Complex::Complex(Complex &copy) {
	real = copy.getReal();
	imaginary = copy.getImaginary();
}

Complex::Complex(double r, double i) {
	real = r;
	imaginary = i;
}

Complex::~Complex() {}

double Complex::getReal() const {
	return real;
}

double Complex::getImaginary() const {
	return imaginary;
}

void Complex::setReal(double r) {
	real = r;
}

void Complex::setImaginary(double i) {
	imaginary = i;
}

void Complex::read() {
	char full_input[50] = "";
	cout << "Input Complex number in format <real> +/- <imaginary>i";
	cin >> full_input;
	
}

void Complex::print() {

}

Complex Complex::add(Complex rhs) {
	Complex n(rhs.getReal() + real, rhs.getImaginary() + imaginary);
	return n;
}

Complex Complex::sub(Complex rhs) {
	Complex n(rhs.getReal() - real, rhs.getImaginary() - imaginary);
	return n;
}

//==NON CLASS FUNCTIONS==//

Complex add(Complex lhs, Complex rhs) {
	Complex n(rhs.getReal() + lhs.getReal(), rhs.getImaginary() + lhs.getImaginary());
	return n;
}

Complex operator+ (const Complex &lhs, const Complex &rhs) {
	Complex n(rhs.getReal() + lhs.getReal(), rhs.getImaginary() + lhs.getImaginary());
	return n;
}

Complex operator- (const Complex &lhs, const Complex &rhs) {
	Complex n(rhs.getReal() - lhs.getReal(), rhs.getImaginary() - lhs.getImaginary());
	return n;
}


