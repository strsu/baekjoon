/*
	19.12.31 해결
	
*/
#include <iostream>
using namespace std;

int main() {
	int sugar;
	int p_3, p_5; // 3kg, 5kg plastic bag

	cin >> sugar;

	p_5 = p_3 = 0;

	while (1) {
		if ((sugar % 5) == 0) {
			cout << p_3 + sugar / 5;
			return 0;
		}
		else if (sugar < 0) {
			cout << -1;
			return 0;
		}
		p_3++;
		sugar -= 3;

	}
	return 0;
}
