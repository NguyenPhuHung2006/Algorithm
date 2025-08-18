#include <iostream>
#include <vector>
using namespace std;

class Segment
{
private:
	vector<int> tree;
	vector<int>& arr;
	int treeSize;
	void build(int node, int left, int right) 
	{
		if(left == right)
		{
			tree[node] = arr[left];
			return;
		}
		int mid = (left + right) / 2;
		build(2 * node + 1, left, mid);
		build(2 * node + 2, mid + 1, right);

		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

public:
	Segment(vector<int>& a) : arr(a)
	{
		int n = arr.size();
		treeSize = 4 * n;
		tree.assign(treeSize, 0);
		build(0, 0, n - 1);
	}

	int query(int node, int l, int r, int ql, int qr)
	{
		if(r < ql || l > qr)
			return 0;
		if(l >= ql && r <= qr)
			return tree[node];

		int mid = (l + r) / 2;

		int left = query(2 * node + 1, l, mid, ql, qr);
		int right = query(2 * node + 2, mid + 1, r, ql, qr);
		return left + right;
	}

	void update(int node, int l, int r, int index, int value)
	{
		if(l == r && l == index)
		{
			arr[index] = value;
			tree[node] = value;
			return;
		}

		int mid = (l + r) / 2;
		
		if(l <= index && index <= mid)
			update(2 * node + 1, l, mid, index, value);
		else
			update(2 * node + 2, mid + 1, r, index, value);

		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

};

int main()
{
	vector<int> a = {1 ,2, 3, 4, 5, 6};
	Segment segment(a);
	cout << segment.query(0, 0, a.size() - 1, 1, 3) << endl;
	segment.update(0, 0, a.size() - 1, 1, 10);
	cout << segment.query(0, 0, a.size() - 1, 1, 3);
}
