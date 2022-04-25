#include <bits/stdc++.h>

using namespace std;

void schedule(int numTracks, int curTrack, vector<int> &queue)
{
    int trackMovements = 0;
    int cur = curTrack;
    for (auto itr : queue)
    {
        cout << cur << " -> ";
        trackMovements += abs(itr - cur);
        cur = itr;
    }
    cout << cur << endl;
    cout << "The total number of track movements needed are: " << trackMovements << endl;
}

int main()
{
    int numTracks = 200;
    int curTrack = 50;
    vector<int> queue = {82, 170, 43, 140, 24, 16, 190};
    schedule(numTracks, curTrack, queue);
    return 0;
}