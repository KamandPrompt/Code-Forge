#include<bits/stdc++.h>
using namespace std;

// CLOSEST PAIR PROBLEM(return d^2 where d is minimum distance between two points)

// --> for given n points in 2-D plane , this algorithm will return square of minimum distance between two points out of all n points

//function to calculate euclidean distance between two points and return square of it TC==>O(1)
long long euc(long long x1,long long y1,long long x2,long long y2)
{
	return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

long long closest_pair_prob(vector<pair<long long,long long>>pnts,int n)
{
    sort(pnts.begin(),pnts.end());//sorting pnts in increasing x coordinate

	set<pair<long long,long long>>ss; //creating set to avoid duplicate points

	long long dis=LLONG_MAX; // taking infinity as square of current minimum distance 

	ss.insert({pnts[0].second,pnts[0].first});// inserting points in set in (y,x) form

	long long j=0; // iterator variable for iterating from starting upto i

	for (long long i = 1; i < n; i++)
	{
		long long curr_min_dist=ceil(sqrt(dis));//current minimum distance

		while(j<i and pnts[j].first<pnts[i].first-curr_min_dist) 
		{
            //if distance between jth points and ith point is more than current minimum distance then erase it from set(if present)
			ss.erase({pnts[j].second, pnts[j].first});
			j++;
		}

		auto l1 =ss.lower_bound({pnts[i].second-curr_min_dist,0});//using inbuilt binary search to search iterator for cur_x-curr_min_dist and cur_x+curr_min_dist
		auto r1 =ss.upper_bound({pnts[i].second+curr_min_dist,0});
        
        //iterating between currx - curr_min_dist and currx + curr_min_dist to check if distance between any of those points and ith points less than curr_min_dist
		for(auto it=l1;it!=r1;it++)
		{
			if(it->second==pnts[i].first and it->first==pnts[i].second){continue;}
			dis=min(dis,euc(it->second,it->first,pnts[i].first,pnts[i].second));
		}

		ss.insert({pnts[i].second,pnts[i].first});
	}
	return dis;
}

int main()
{

// FOR CLOSEST PAIR PROBLEM ---> DRIVER CODE
    long long n;
    cout<<"ENTER NUMBER OF POINTS(N)"<<endl;
    cin>>n;
    vector<pair<long long,long long>>pnts;
    cout<<"ENTER ALL N POINTS in 'x y' format"<<endl;
    for (long long i = 0; i < n; i++)
    {
        long long x,y;
        cin>>x>>y;
        pnts.push_back({x,y});
    }
	long long dist=closest_pair_prob(pnts,n);
	cout<<"SQUARE OF MINIMUM DISTANCE IS  "<<dist<<endl;


    return 0;
}