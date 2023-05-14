#include <bits/stdc++.h>

using namespace std;

bool custom(vector<int> v1, vector<int> v2)
{
    return (v1[1]<=v2[1]);
}

class Solution {
public:
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people)
    {
        sort(people.begin(), people.end(), custom);

        vector<vector<int> > v;
        for (int i=0; i < people.size(); i++)
        {
            int pos = 0, k = people[i][1];
            while(pos < v.size())
            {
                if (k == 0)
                {
                    while(pos < v.size() && v[pos][0] < people[i][0])
                        pos++;
                    break;
                }

                if (v[pos][0] >= people[i][0])
                    k--;

                pos++;
            }

            v.insert(v.begin()+pos, people[i]);
        }

        return v;
    }
};

int main()
{
    Solution obj;
    int N, a, b;
    cin >> N;
    vector<vector<int> > v;

    for (int i=0; i < N; i++)
    {
        cin >> a >> b;
        vector<int> v1;
        v1.push_back(a);
        v1.push_back(b);
        v.push_back(v1);
    }

    vector<vector<int> > ans = obj.reconstructQueue(v);

    for (int i=0; i < v.size(); i++)
        cout << ans[i][0] << " " << ans [i][1] << " - ";

    return 0;
}
