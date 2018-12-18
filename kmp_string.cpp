#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void next(string &pattern, vector<int> &next_table)
{
	int index = 1;
	int last_match = -1;
	next_table[0] = -1;
	while (index<pattern.length())
	{
		while (last_match > -1 && pattern[last_match + 1] != pattern[index])
			last_match = next_table[last_match];

		if (pattern[index] == pattern[last_match + 1])
			last_match++;

		next_table[index] = last_match;
		index++;
	}
}

int main()
{
	string t = "cababababababcadcababaababababcajkjkababababcaj";
	string pattern = "ababababca";
	vector<int> next_table(pattern.length());
	next(pattern, next_table);
	int last_match = -1;
	for (int i = 0; i<t.length(); i++)
	{
		while (last_match>-1 && t[i] != pattern[last_match + 1])
			last_match = next_table[last_match];
		if (t[i] == pattern[last_match + 1])
			last_match++;
		if (last_match == pattern.length() - 1)
			cout << "match:" <<i<< endl;
	}

	return 0;
}