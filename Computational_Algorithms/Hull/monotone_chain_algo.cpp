// Convex Hull --> Smallest convex set which encloses all points in it

#include<bits/stdc++.h>
using namespace std;

// Custom Data Structure to store points in 2D palne
struct point{
	float x, y;
	point () { x=0,y=0;}
	point(float x1, float y1) {x=x1, y=y1;} 
};

// Custom comparator for point DS
bool comp(point &p1, point &p2){
	if(p1.x!=p2.x) return p1.x<p2.x;
	return p1.y<p2.y;
}

// Calculating orientation of given points using area
int cw(point &a, point &b, point &c){
	double area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	if (area<0) return 1;
    else if (area==0) return 2;
    return 3;
}

vector<point> convex_hull(vector<point> &v){
	if(v.size()==1) return v;
	// Sort given points according to their abscissa (and ordinate in case of tie)
	sort(v.begin(), v.end(), comp);
	point p1=v[0], p2=v.back();

	// Intialise up and down DS to store upper and lower convex hull
	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for(long unsigned int i=1;i<v.size();i++){
		// If current point is a valid point for upper hull
		if(i==v.size()-1 || cw(p1, v[i], p2)==1){
			while(up.size()>=2 && cw(up[up.size()-2], up[up.size()-1], v[i])>1)
				up.pop_back();
			up.push_back(v[i]);
		}

		// If current point is a valid point for lower hull
		if(i==v.size()-1 || cw(p1, v[i], p2)==3 ){
			while(down.size()>=2 && cw(down[down.size()-2], down[down.size()-1], v[i])<3)
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	// Merge both upper and lower hull to get final points in Hull
	for(long unsigned int i=down.size()-2;i>0;i--) up.push_back(down[i]);
	return up;
}

int main(){
    int n;
    cin>>n;
    vector<point> v;
    while(n--){
        float x,y;
        cin>>x>>y;
        point p=point(x,y);
        v.push_back(p);
    }
    vector<point> hull=convex_hull(v);
    cout<<hull.size()<<endl;
    for (auto it:hull) cout<<(long long int)it.x<<" "<<(long long int)it.y<<endl;
}
