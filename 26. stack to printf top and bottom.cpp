#include <bits/stdc++.h>
using namespace std;
void PrintStack(stack<int> s)
{
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	cout << x << ' ';
	PrintStack(s);
	s.push(x);
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	PrintStack(s);
	return 0;
}

