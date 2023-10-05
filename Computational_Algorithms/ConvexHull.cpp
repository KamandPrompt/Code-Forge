#include <bits/stdc++.h>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
void PrintStack(stack<pair<int, int>> s)
{
    stack<pair<int, int>> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        cout << "(" << temp.top().first << ", " << temp.top().second << ")" << endl;
        s.push(temp.top());
        temp.pop();
    }
}
// standard code to print stack
int main()
{
    int n;
    cout<<"enter the number of points"<<endl;
    cin >> n;
    vector<pair<int, int>> vect;

    for (int i = 0; i < n; i++)
    {
        int k, l;
        cout<<"point1"<<"point2"<<endl;
        cin >> k >> l;
        vect.push_back(make_pair(k, l));
    }

    pair<int, int> min = *min_element(vect.begin(), vect.end());

    vector<pair<double, int>> angles;
    for (int i = 0; i < n; i++)
    {
        if (vect[i] != min)
        {
            double m = atan2(vect[i].second - min.second, vect[i].first - min.first);
            angles.push_back(make_pair(m, i));
        }
    }
    // sorting angles array and storing index w.r.t angles except for min element

    sort(angles.begin(), angles.end(), [](const pair<double, int> &a, const pair<double, int> &b)
         { return a.first < b.first; });

    vector<pair<int, int>> sorted;
    sorted.push_back(min);
    for (const auto &angle : angles)
    {
        sorted.push_back(vect[angle.second]);
    }
    // storing points w.r.t sorted angles using indexes stored earlier

    stack<pair<int, int>> main;
    stack<pair<int, int>> temp;
    for (int i = 0; i < sorted.size(); i++)
    {
        main.push(make_pair(sorted[i].first, sorted[i].second));
        if (main.size() >= 3)
        {
            int area = (sorted[i - 1].first - sorted[i - 2].first) * (sorted[i].second - sorted[i - 2].second) - (sorted[i - 1].second - sorted[i - 2].second) * (sorted[i].first - sorted[i - 2].first);
            // calculating area using parallelogram multiplicaton rule and finding
            // type of angle
            if (area > 0)
            {
                continue;
            }
            else if (area < 0)
            {
                main.pop();
                main.pop();
                sorted.erase(sorted.begin() + (i - 1));
                i -= 2;
            }
            // using graham scan 
            // if clockwise then pop 2 from stack and then again iterate
            // after deleting middle one from original vector
            else
            {
                temp.push(main.top());
                main.pop();
                main.pop();
                main.push(temp.top());
                temp.pop();
            }
            // if area = 0 means points are collinear
            // so delete middle one

        }
    }
    PrintStack(main);
    cout << "(" << sorted[0].first << ", " << sorted[0].second << ")" << endl;
    cout << "Total Points on Convex Hull: " << main.size() << endl;

    return 0;
}
