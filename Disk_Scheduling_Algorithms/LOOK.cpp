// Direction towards the larger value

#include <bits/stdc++.h>

using namespace std;

void schedule(int numTracks, int curTrack, vector<int> &queue)
{
    priority_queue<int> lesser;
    priority_queue<int, vector<int>, greater<int>> greater;
    int cur = curTrack;
    int trackMovement = 0;
    for(auto itr: queue)
    {
        if(itr >= cur)
        {
            greater.push(itr);
        }
        else
        {
            lesser.push(itr);
        }
    }
    while(!greater.empty())
    {
        cout<<cur<<" -> ";
        int nxt = greater.top();
        greater.pop();
        trackMovement += abs(cur - nxt);
        cur = nxt;
    }
    while(!lesser.empty())
    {
        cout<<cur<<" -> ";
        int nxt = lesser.top();
        lesser.pop();
        trackMovement += abs(nxt - cur);
        cur = nxt;
    }
    cout<<cur<<endl;
    cout<<"The number of track movements are: "<<trackMovement<<endl;
}

int main()
{
    int numTracks = 200;
    int curTrack = 50;
    vector<int> queue = {82, 170, 43, 140, 24, 16, 190};
    schedule(numTracks, curTrack, queue);
    return 0;
}