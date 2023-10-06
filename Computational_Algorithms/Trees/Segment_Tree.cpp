/*SEGMENT TREE*/
/*Segment Trees are pre-computational algorithms used to reduce time comlexity.*/

/*SENARIO: we want to find min and max value in a given range of an array*/
/*algorithm:
    1) create an empty array of size = 4*(size of input array)
        reason for this is at max there will be these many number of indexes.
    2) divide the array about middle index till you get single index for a section.
    3) as you move above the tree keep updating values for parent node as per condtion
    4) you will get desired tree.
*/

/* TREE WILL LOOK LIKE THIS FOR SAY LENGTH OF ORIGINAL ARRAY IS 5
                            [0-5]
                            /    \
                           /       \
                        [0-2]       [3-5]
                        /   \        /    \
                    [0-1]   [2-2]   [3-4]  [5-5]
                    /   \           /    \
                [0-0]   [1-1]      [3-3]  [4-4]

    THESE ARE THE INDEXES SPECIFIED
*/


//this code is for finding min/max in a section of an arrray using segment tree but we can 
//also rectify it for finding sum in a section of an arrray using segment tree.

//time complexity is O(log n) for finding and O(n) for creating the tree
//space complexity is O(4*n) i.e. o(n)

#include<bits/stdc++.h>
using namespace std;

vector<int>arr(100005);//initializing with large space just to ensure that array is inside it.

vector<int>segment((arr.size())*4);

void tree(int node,int lowerIndex,int higherIndex){
    if(lowerIndex==higherIndex){
        segment[node]=arr[lowerIndex];
        return;
    }
    int mid=(lowerIndex+higherIndex)/2;
    tree(node*2+1,lowerIndex,mid);
    tree(node*2+2,mid+1,higherIndex);
    segment[node]=max(segment[node*2+1],segment[node*2+2]);
}

/*TO FIND THE MIN/MAX VALUE IN A PART OF */
int find(int node,int low,int high,int l,int r){
    //here l and r is the range in which we want to find the min/max value
    if(l<=low&&r>=high){
        return segment[node];
    }
    if(l>high||r<low)return INT_MIN;
    int mid=(low+high)/2;
    int first=find(2*node+1,low,mid,l,r);
    int second=find(2*node+2,mid+1,high,l,r);
    return max(first,second);
}
int main(){
    
    //remember initiating array here is not a good practice as it servers no purpose 
    //of precomputation hence always initiate it at begining as a global array.

    int n;//will fill only n spaces out of complete max size.
    cout<<"enter size of the array"<<endl;
    cin>>n;
    cout<<"enter values of elements of array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    tree(0,0,n-1);//to build the tree
    cout<<"value of range minimum index and maximum index"<<endl;
    int l,r;
    cin>>l>>r;
    if(l<0||r>n-1){
        cout<<"out of index please keep input in array range";
        return 0;
    }
    int result=find(0,0,n-1,l,r);//to find the min/max value in a given range.
    if(result==INT_MIN){cout<<"range out of index";}
    else cout<<result;
    return 0;
}
