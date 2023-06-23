//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */

int seg[4*100005];

void build(int arr[],int i,int l,int h) 
{
    if(l==h) {
        seg[i]=arr[l];
        return;
    }
    int mid=(l+h)/2;
    build(arr,2*i+1,l,mid);
    build(arr,2*i+2,mid+1,h);
    seg[i] = min(seg[2*i+1],seg[2*i+2]);
}

int *constructST(int arr[],int n)
{
  build(arr,0,0,n-1);
  return {};
}


/* The functions returns the
 min element in the range
 from a and b */
 
int query(int i,int l,int r,int a,int b)
{
    if(l>=a && r<=b) return seg[i];
    if(r<a||l>b) return INT_MAX;
    int m=(l+r)/2;
    return min(query(2*i+1,l,m,a,b),query(2*i+2,m+1,r,a,b));
}

int RMQ(int st[] , int n, int a, int b)
{
    return query(0,0,n-1,a,b);
}