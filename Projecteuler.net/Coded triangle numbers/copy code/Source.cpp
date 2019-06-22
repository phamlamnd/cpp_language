#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

map<char, int> mapAlphabet();
vector<string> getWords(string filename);
int getNumber(string word, map<char, int> &ab);

int main() {
	clock_t t;
	t = clock();
	map<char, int> alphabet = mapAlphabet();
	string filename = "words.txt";
	vector<string> words = getWords(filename);
	vector<int> triNumbers;
	int highestTri = 1;
	triNumbers.push_back(highestTri);
	int nextIncrement = highestTri + 1;
	int nTri = 0;
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
		int number = getNumber(*it, alphabet);
		while (number > highestTri) {
			highestTri += nextIncrement;
			nextIncrement++;
			triNumbers.push_back(highestTri);
		}
		if (find(triNumbers.begin(), triNumbers.end(), number) != triNumbers.end()) {
			nTri++;
		}
	}
	cout << nTri << endl;
	t = clock() - t;
	cout << "Time elapsed is " << (double)t / CLOCKS_PER_SEC << " seconds." << endl;
	return 0;
}