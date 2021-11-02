int a[21];
int b[21][21];

// Way 1
memset(a, 0, sizeof a);
memset(b, 0, sizeof b);


// Way 2
int idx;
idx = 0;
while (idx < 21)
{
	a[idx] = 0;
	idx++;
}

int idx;
int jdx;

idx = 0;
while (idx < 21)
{
	jdx = 0;
	while (jdx < 21)
	{
		b[i][j] = 0;
		jdx++;
	}
	idx++;
}

// Way 3
fill(a, a + 21, 0);

int idx;
idx = 0;
while (idx < 21)
{
	fill(b[idx], b[idx] + 21, 0);
	idx++;
}
