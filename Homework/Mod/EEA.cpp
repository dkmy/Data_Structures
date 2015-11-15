#include <iostream>

using namespace std;


long EEA(long a, long b){
//	function extended_gcd(a, b)
//	s := 0 coef_1_2;    old_s := 1 coef_1_1
//	t := 1 coef_2_2;    old_t := 0 coef_2_1
//	r := b val_2;    old_r := a val_1
//	while r ≠ 0
//		quotient := old_r div r
//		(old_r, r) := (r, old_r - quotient * r)
//		(old_s, s) := (s, old_s - quotient * s)
//		(old_t, t) := (t, old_t - quotient * t)
//	output "Bézout coefficients:", (old_s, old_t)
//	output "greatest common divisor:", old_r
//	output "quotients by the gcd:", (t, s)

	long val_1 = a;
	long val_2 = b;
	long coef_1_1 = 1;
	long coef_1_2 = 0;
	long coef_2_1 = 0;
	long coef_2_2 = 1;
	long q;
	long temp1;
	
	while (val_2 != 0){
		q = val_1 / val_2;
		temp1 = val_1;
		val_1 = val_2;
		val_2 = temp1 - q * val_2;
		
		temp1 = coef_1_1; 
		coef_1_1 = coef_1_2;
		coef_1_2 = temp1 - q * coef_1_2;
		
		temp1 = coef_2_1;
		coef_2_1 = coef_2_2;
		coef_2_2 = temp1 - q * coef_2_2;
	}
	if (val_1 != 1){
		cout << "Integer must be coprime with modulus" << "\n";
		exit(-1);
	}
	if (coef_2_1 < 0){
		coef_2_1 = (coef_2_1 % a + a) % a;
		return coef_2_1;
	}
	return coef_2_1;
}


int main(int argc, char *argv[]) {
	
	cout << EEA(135, 135) << "\n";
	
}