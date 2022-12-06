#include <iostream>

double GCD(double a, double b) {
	while(a != b) {
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int main() {
	double p = 1, k = 0;
	double up_border   = 3. / 7.;
	double down_border = 2. / 5.;
	double p_result;
	double k_result;

	while(p <= 1000000) {
		double current = k / p;
		if(current <= down_border)
			k += 1;
		else if(current >= up_border)
			p += 1;
		else {
			p_result = p;
			k_result = k;
			down_border = current;
		}
	}
	double gcd = GCD(k_result, p_result);
	while(gcd != 1) {
		p_result /= gcd;
		k_result /= gcd;
		gcd = GCD(k_result, p_result);
	}

	std::cout << "ANSWER:" << std::endl;
	std::cout << "\tNumerator   = " << k_result << std::endl;
	std::cout << "\tDenominator = " << p_result << std::endl;

	return 0;
}