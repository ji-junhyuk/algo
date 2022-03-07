#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int i_n;
int i_parent[100];
double d_ans;
vector<pair<double, double>> dd_vec_coord;
vector<pair<double, pair<int, int>>> d_ii_vec_edge;

double find_dist(double d_x1, double d_y1, double d_x2, double d_y2)
{
	double d_dx = (d_x1 - d_x2) * (d_x1 - d_x2);
	double d_dy = (d_y1 - d_y2) * (d_y1 - d_y2);
	double d_dist = sqrt(d_dx + d_dy);
	return d_dist;
}

int get_parent(int i_x)
{
	if (i_parent[i_x] == i_x)
		return i_x;
	else
		return i_parent[i_x] = get_parent(i_parent[i_x]);
}

void union_parent(int i_x, int i_y)
{
	i_x = get_parent(i_x);
	i_y = get_parent(i_y);
	if (i_x < i_y)
		i_parent[i_y] = i_x;
	else
		i_parent[i_x] = i_y;
}

bool find_same_parent(int i_x, int i_y)
{
	i_x = get_parent(i_x);
	i_y = get_parent(i_y);
	if (i_x == i_y)
		return true;
	else
		return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);
	cin >> i_n;

	for (int idx = 0; idx < i_n; ++idx)
	{
		double d_a, d_b;
		cin >> d_a >> d_b;
		dd_vec_coord.push_back(make_pair(d_a, d_b));
	}
	for (int idx = 0; idx < i_n; ++idx)
	{
		double d_x1 = dd_vec_coord[idx].first;
		double d_y1 = dd_vec_coord[idx].second;
		for (int jdx = idx + 1; jdx < i_n; jdx++)
		{
			double d_x2 = dd_vec_coord[jdx].first;
			double d_y2 = dd_vec_coord[jdx].second;
			double d_dist = find_dist(d_x1, d_y1, d_x2, d_y2);
			d_ii_vec_edge.push_back(make_pair(d_dist, make_pair(idx, jdx)));
		}
	}
	for (int idx = 0; idx < i_n; ++idx)
		i_parent[idx] = idx;
	sort(d_ii_vec_edge.begin(), d_ii_vec_edge.end());
	for (int idx = 0; idx < d_ii_vec_edge.size(); ++idx)
	{
		double d_cost = d_ii_vec_edge[idx].first;
		int i_node1 = d_ii_vec_edge[idx].second.first;
		int i_node2 = d_ii_vec_edge[idx].second.second;
		if (find_same_parent(i_node1, i_node2) == false)
		{
			union_parent(i_node1, i_node2);
			d_ans = d_ans + d_cost;
		}
	}
	cout << d_ans << '\n';
}
