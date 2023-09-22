//Normal dp approach:-

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
  int memo[N][2];
 int dp(int i,bool take ,int par)
 {

      if(memo[i][take]!=-1){return memo[i][take];}
      int ans=take;

      for(auto x:Graph[i])
      {
         if(x!=par)
         {
             if(take)
             {
              ans+=min(dp(x,0,i),dp(x,1,i));

             }else
             {
               ans+=dp(x,1,i);
             }

         }
      }


      return memo[i][take]=ans;

 }





  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  

  memset(memo,-1,sizeof(memo));


   int n;
   cin>>n;
  
    for(int i=0;i<(n-1);i++)
    {
      int x,y;
      cin>>x>>y;
      Graph[x].push_back(y);
      Graph[y].push_back(x);
    }

    cout<<min(dp(1,0,-1),dp(1,1,-1))<<endl;

 
    
 
      return 0;
  }
