/*
19.12.31 해결
#고찰
기존에 mod를 써서 설탕 전체를 3, 5로 나눔으로써 문제를 해결해려 했다.
예) 11의 경우 5로 나눈 나머지는 1, 남은 설탕 1을 3으로 나눈 나머지는 1로 탈락이라 판단하는 실수를 했다.
예) 24의 경우 5로 나눈 나머지는 4, 남은 설탕 4를 3으로 나눈 나머지는 1 다만, 24를 3로 나눈 나머지는 0으로 답을 8로 처리하는 문제가 있었다.
즉, 봉지의 갯수를 줄이는 방법이 "5kg 봉지 < 3, 5kg 봉지 < 3kg봉지"로 판단 후 단순히 3, 5로만 나눠버리자 위 예제처럼 실제론 나눌 수 있거나 더 줄일 수 있는 방법이 있음을 판단하지 못하였다.

#해결
전체가 5로 한번에 나눠지지 않는다면 설탕의 무게가 음수가 될때까지 3씩 빼면서 5로 나누는 방식으로 접근해야 3kg 봉지를 최소화 할 수 있다.
만약 설탕의 무게가 음수가 된다면 -1로 처리하면 된다.	
*/

////////////////////////////////////////Wrong Answer//////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {
	int sugar;
	int p_3, p_5;	// 3kg, 5kg plastic bag
	int leftover;	// leftover sugar

	cin >> sugar;

	if ((sugar % 5) == 0) {
		cout << sugar / 5;
	}
	else {
		p_5 = sugar / 5;			// Share of whole divided by five.
		leftover = sugar % 5;		// Remainer of whole divided by five.
		p_3 = leftover / 3;			// Share of remainer divided by three.
		leftover = leftover % 3;	// Remainer of remainer divided by three.
		if (leftover == 0) {		// If sugar's weight suit multiple of three and five
			cout << p_5 + p_3;
		}
		else {
			if ((sugar % 3) == 0) {	// if sugar's weight doesn't suit multiple of three and five but suit multiple of three.
				cout << sugar / 3;
			}
			else {					// No one suits multiple three and five.
				cout << -1;
			}
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////Righr Answer//////////////////////////////////////////////////

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

