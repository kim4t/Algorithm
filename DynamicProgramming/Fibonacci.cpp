// O(2^n)
int fib_naive(int n)
{
	if (n == 0 || n == 1)
		return n;
	return fib_naive(n - 2) + fib_naive(n - 1);
}

// O(n)
vector<int> fib_arr{ 0,1 };
int fib_recur_dp(int n)
{
	if (n < fib_arr.size())
		return fib_arr[n];
	int v = fib_naive(n - 2) + fib_naive(n - 1);
	fib_arr.push_back(v);
	return v;
}

// bottom up O(n)
int fib_bottom_up(int n)
{
	if (n == 0 || n == 1)
		return n;
	vector<int> arr{ 0,1 };
	for (int i = 2; i <= n; i++)
	{
		int num = arr[i - 2] + arr[i - 1];
		arr.push_back(num);
	}
	return arr[n];
}
