#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <cstring>

int check(const char *c, int mid);
using namespace std;

int main() {
	const char *tmp;
	string name;
	cout << "Enter stuff\n";
	cin >> name;

	tmp = name.c_str();	

	//Find the middle of the array
	int size = (sizeof(tmp) / sizeof(*tmp));
	int mid = (strlen(tmp)/2);
	//cout << "Mid Character " << tmp[mid] << endl;

	check(tmp, mid);
	system("PAUSE");
	return 0;
}

int check(const char *c, int mid) {
	int max = strlen(c);
	int min = 0;

	char *lefthalf = "";
	for (int i = min; i < mid; i++) {
		lefthalf += c[i];
	}

	char *righthalf = "";
	for (int i = max; i > mid; i--) {
		righthalf  += c[i];
	}

	if (*righthalf == *lefthalf) {
		cout << "It is a palindrome.\n";
		return 0;
	}
	else {
		cout << "Not a palindrome.\n";
		int size = strlen(c);

		int check = mid + 1;
		int needed = 0;

		while (c[mid] == c[check]) {
			needed += 1;
			check = check + 1;
		}
		check = mid - 1;
		while (c[mid] == c[check]) {
			needed += 1;
			check = check - 1;
		}

		cout << "Your need " << (size - 1) - needed << " more letters\n";
		return ((size - 1) - needed);
	}
	
}