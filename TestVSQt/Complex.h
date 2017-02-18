#ifndef _COMPLEX_H
#define _COMPLEX_H

template <class T>
class Complex {

private:
	T realPart;
	T imaginaryPart;

public:
	Complex(T realPart = 0, T imaginaryPart = 0) {
		this->realPart = realPart;
		this->imaginaryPart = imaginaryPart;
	}
	~Complex() {}

	void setRealPart(T realPart) {
		this->realPart = realPart;
	}
	void setImaginaryPart(T imaginaryPart) {
		this->imaginaryPart = imaginaryPart;
	}

	T getRealPart() {
		return this->realPart;
	}
	T getImaginaryPart() {
		return this->imaginaryPart;
	}

	Complex<T>& computeSquare() {
		T newRealPart = this->realPart * this->realPart - this->imaginaryPart * this->imaginaryPart;
		T newImaginaryPart = 2 * this->realPart * this->imaginaryPart;

		realPart = newRealPart;
		imaginaryPart = newImaginaryPart;

		return *this;
	}

	void addComplex(Complex &number) {
		this->reealPart += number->getRealPart();
		this->imaginaryPart += number->getImaginaryPart();
	}

	double returnMagnitude() {
		return sqrt(this->realPart * this->realPart + this->imaginaryPart * this->imaginaryPart);
	}

	Complex<T>& operator-(const Complex<T>& number) {
		realPart -= number.realPart;
		imaginaryPart -= number.imaginaryPart;
		return *this;
	}

	Complex<T>& operator+(const Complex<T>& number) {
		realPart += number.realPart;
		imaginaryPart += number.imaginaryPart;
		return *this;
	}

	Complex<T>& operator+=(const Complex<T>& number) {
		realPart += number.realPart;
		imaginaryPart += number.imaginaryPart;
		return *this;
	}

	Complex<T>& operator=(const Complex& number) {
		if (this != &number) {
			realPart = number.realPart;
			imaginaryPart = number.imaginaryPart;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Complex<T>& number) {
		out << number.realPart;
		if (number.imaginaryPart >= 0) {
			out << " + ";
		}
		else {
			out << " - ";
		}
		out << abs(number.imaginaryPart) << " * i";
		return out;
	}
};

#endif