/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;

void strcpy_slice(char* buf, char* s, int start, int size)
{
	if (strlen(s) > start) {
		s += start;
		while (size-- > 0 && *s != '\0')
			*(buf++) = *(s++);
		*buf = '\0';
	}
}

char* rotate(char* s, int n)
{
	char buf[29];
	buf[0] = s[n - 1];
	for (int i = 1; i < n; i++) {
		buf[i] = s[i - 1];
	}
	buf[n] = '\0';
	return buf;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int k;
		cin >> n >> k;
		char s[29];
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		int q = n / 4;
		vector <string> v;
		for (int i = 0; i < q; i++) {
			char temp[29];
			strcpy_slice(temp, s, 0, q);
			v.push_back(temp);
			char temp1[29];
			strcpy_slice(temp1, s, q, q);
			v.push_back(temp1);
			char temp2[29];
			strcpy_slice(temp2, s, q * 2, q);
			v.push_back(temp2);
			char temp3[29];
			strcpy_slice(temp3, s, q * 3, q);
			v.push_back(temp3);
			strcpy(s, rotate(s, n));
		}
		sort(v.begin(), v.end(), greater<string>());
		v.erase(unique(v.begin(), v.end()), v.end());

		string hex = v[k - 1];
		int decimal = 0;
		int position = q - 1;
		for (int i = 0; i < hex.length(); i++) {
			char ch = hex[i];
			if (isdigit(ch)) {
				decimal += (ch - '0') * (pow(16, position));
			}
			else {
				decimal += (ch - 'A' + 10) * (pow(16, position));
			}
			position -= 1;
		}

		printf("#%d %d", test_case, decimal);
		printf("\n");
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}