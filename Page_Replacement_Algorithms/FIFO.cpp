#include <bits/stdc++.h>

using namespace std;

void disp(vector<pair<int, int>> &frames)
{
    for (auto itr : frames)
    {
        cout << itr.first << ' ';
    }
    cout << endl;
}

void allocatePages(int numFrames, vector<int> &refString)
{
    vector<pair<int, int>> frames;
    cout << "The frames at each page fault are: " << endl;
    for (int i = 0; i < refString.size(); i++)
    {
        int itr = refString[i];
        bool found = false;
        for (auto it : frames)
        {
            if (it.first == itr)
            {
                found = true;
            }
        }
        if (found)
        {
            continue;
        }
        else if (frames.size() < numFrames)
        {
            frames.push_back({itr, i});
        }
        else
        {
            // Apply FIFO page replacement
            int mnVal = INT_MAX;
            int mi = -1;
            for (int i = 0; i < frames.size(); i++)
            {
                auto it = frames[i];
                if (it.second < mnVal)
                {
                    mnVal = it.second;
                    mi = i;
                }
            }
            frames[mi] = {itr, i};
        }
        disp(frames);
    }
}

int main()
{
    int numFrames = 3;
    vector<int> refString = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    allocatePages(numFrames, refString);
    return 0;
}