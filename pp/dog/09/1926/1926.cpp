#include <iostream>
# define MAX_LEN 1000000
using namespace std;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_queue
{
	int front;
	int rear;
	t_point point[MAX_LEN];
} 	t_queue;

void queue_init(t_queue *pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int q_is_empty(t_queue *pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}

int next_pos_idx(int pos)
{
	if (pos == MAX_LEN - 1)
		return 0;
	else 
		return pos + 1;
}

void enqueue(t_queue *pq, int x, int y)
{
	if (next_pos_idx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = next_pos_idx(pq->rear);
	pq->point[pq->rear].x = x;
	pq->point[pq->rear].y = y;
}

t_point deque(t_queue *pq)
{
	if (q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = next_pos_idx(pq->front);
	return pq->point[pq->front];
}

t_point front(t_queue *pq)
{
	return (pq->point[pq->front]);
}

t_point peek(t_queue *pq)
{
	if (q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->point[next_pos_idx(pq->front)];
}

int	board[501][501];
int	visited[501][501];
int	dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int	n, m;
int	picture_size, picture_number;
int	area;
int	curr_x, curr_y;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	t_queue queue;
	queue_init(&queue);

	cin >> n >> m;
	for (int idx = 0; idx < n; ++idx)
		for (int jdx = 0; jdx < m; ++jdx)
			cin >> board[idx][jdx];
	for (int idx = 0; idx < n; ++idx)
	{
		for (int jdx = 0; jdx < m; ++jdx)
		{
			if (board[idx][jdx] == 0 || visited[idx][jdx])
				continue ;
			picture_number++;
			visited[idx][jdx] = 1;
			enqueue(&queue, idx, jdx);
			area = 0;
			while (!q_is_empty(&queue))
			{
				area++;
				t_point point;
				point = front(&queue);
				deque(&queue);
				for (int dir = 0; dir < 4; ++dir)
				{
					curr_x = point.x + dx[dir];
					curr_y = point.y + dy[dir];
					if (curr_x < 0 || curr_x >= n || curr_y < 0 || curr_y >= m)
						continue;
					if (visited[curr_x][curr_y] || board[curr_x][curr_y] != 1)
						continue;
					visited[curr_x][curr_y] = 1;
					enqueue(&queue, curr_x, curr_y);
				}
			}
			picture_size = max(picture_size, area);
		}
	}
	cout << picture_number << '\n' << picture_size;
}
