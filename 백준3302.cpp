#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;
	vector<int>imos(H+1);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (i % 2 == 0) {
			imos[0]++; //�������� ����
			imos[a]--; //�������� ����
		}
		else {
			imos[H - a]++; //�������� ����
			imos[H]--; //�������� ����
		}
	}
	int now = 0;
	for (int i = 0; i < H; i++) { //������ ���
		now += imos[i];
		imos[i] = now;
	}
	int Min = *min_element(imos.begin(), imos.end()-1);
	int cnt = 0;
	for (int i = 0; i < H; i++)
		if (Min == imos[i]) cnt++;
	cout << Min << " " << cnt;

	return 0;
}