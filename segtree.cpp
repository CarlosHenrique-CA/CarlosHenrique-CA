#include <bits/stdc++.h>

using namespace std;

void construct(int input[], int segtree[], int low, int high, int pos)
{
    if(low==high)
    {
        segtree[pos]=input[low];
        return;
    }
    int mid=(low + high)/2;
    construct(input, segtree, low, mid, 2 * pos + 1);
    construct(input, segtree, mid + 1, high, 2 * pos + 2);
    segtree[pos]=min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}

int rangeminquery(int segtree[], int qlow, int qhigh, int low, int high, int pos)
{
    if(qlow<=low && qhigh>=high)
    {
        return segtree[pos];
    }
    if(qlow>high || qhigh<low)
    {
        return 999999999;
    }
    int mid=(low + high)/2;
    return min(rangeminquery(segtree, qlow, qhigh, low, mid, 2 * pos + 1),rangeminquery(segtree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

int main()
{
    int input[4]={- 1, 2, 4, 0};
    int segtree[7];
    construct(input, segtree, 0, 3, 0);
    cout<<rangeminquery(segtree, 0, 2, 0, 3, 0)<<endl;
}
