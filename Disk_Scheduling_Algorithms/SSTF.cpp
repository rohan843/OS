#include <bits/stdc++.h>

using namespace std;

void schedule(int numTracks, int curTrack, vector<int> &queue)
{
    int trackMovement = 0;
    int cur = curTrack;
    int sz = queue.size();
    auto getNearest = [&](int cur)->int{
        int nxt = -1;
        int ni = -1;
        int dist = INT_MAX;
        for(int i = 0; i < queue.size(); i++)
        {
            int itr = queue[i];
            if(itr >= 0)
            {
                if(dist > abs(cur - itr))
                {
                    dist = abs(cur - itr);
                    nxt = itr;
                    ni = i;
                }
            }
        }
        queue[ni] = -1;
        return nxt;
    };
    while(sz--)
    {
        cout<<cur<<" -> ";
        int nxt = getNearest(cur);
        trackMovement += abs(nxt - cur);
        cur = nxt;
    }
    cout<<cur<<endl;
    cout<<"The track movement time is: "<<trackMovement<<endl;
}

int main()
{
    int numTracks = 200;
    int curTrack = 50;
    vector<int> queue = {82, 170, 43, 140, 24, 16, 190};
    schedule(numTracks, curTrack, queue);
    return 0;
}