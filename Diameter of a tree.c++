// Dp Approach


 #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
  
  const int N=1e5+10;
  vector<int>Graph[N];
  vector<int>visited(N,0);
  int f[N],g[N];

  void dfs(int cur,int par)
  {
      int mx1=0,mx2=0;
     // G[i]=0;
       for(auto x:Graph[cur])
       {
          if(x!=par)
          {   dfs(x,cur);
              g[cur]=max(g[x]+1,g[cur]);
              f[cur]=max(f[x],f[curr]);
              if(g[x]+1>mx1)
              {
                mx2=mx1;
                mx1=g[x]+1;
              }else if(g[x]+1>mx2)
              {mx2=g[x]+1;

              }

            }
        }  

       f[cur]=max(f[cur],mx1+mx2);

  }





  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  




   int n;
   cin>>n;

   for(int i=0;i<(n-1);i++)
   {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
   }




   dfs(1,-1);
   // for(int i=1;i<=n;i++)
   // {
   //  cout<<g[i]<<" ";
   // }cout<<endl;
   cout<<f[1]<<endl;


 
    
 
      return 0;
  }



//aur baki dp approach toh tujhe pta hi 
