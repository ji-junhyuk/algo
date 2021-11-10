const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

fill(pre, pre + MX, -1);
fill(nxt, nxt + MX, -1);
