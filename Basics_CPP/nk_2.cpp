#include <cstdint>
#include <iostream>
using namespace std;

int main() {

	// write your code here......
	int i = 1;
	uint32_t num = 9, sum = 0;
	while (i < 11) {
		sum = sum + num;
		cout << sum << "," << num << endl;
		num = num * 10 + 9;
		++i;
	}
	cout << sum << endl;
	cout << 999999999 * 10 + 9;

	return 0;
}