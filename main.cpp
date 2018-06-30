#include"Sequence.h"
#include<iostream>
using namespace std;

int main()
{
	Sequence f("dna.txt");
	int l;
	l = f.length();
	cout << l << endl;
	cout << "Please tell me which nucleotide you want to find:" << endl;
	char k;
	cin >> k;
	cout << f.numberOf(k) << endl;
	cout << "The longest base sequence of the same base:" << endl;
	cout << f.longestConsecutive() << endl;
	cout << "The longest repetitive sequence :" << endl;
	cout << f.longestRepeated() << endl;
	return 0;
}
