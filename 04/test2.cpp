void traverse()
{
	int cur = nxt[0];
	while (cur != -1)
	{
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\m"
}
