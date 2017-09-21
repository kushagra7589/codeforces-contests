MAX_SIZE = 1 >> 20

A[MAX_SIZE] = {0}
seg[4 * MAX_SIZE] = {0}

function buildTree(v, l, r):
	if(l == r)
		seg[v] = A[l]
	else
		mid = (l + r) / 2
		buildTree(2*v, l, mid)
		buildTree(2*v + 1, mid + 1, r)
		seg[v] = seg[2*v] + seg[2*v + 1]