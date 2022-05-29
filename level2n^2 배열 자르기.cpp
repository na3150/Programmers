#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int>answer;
	long index = left;
	while ( index <= right)
	{
		int a = index / n;
		int b = index % n;
		if ( a >= b) answer.push_back(a + 1);
		else answer.push_back(b +1);
		index++;
	}
	return answer;
}