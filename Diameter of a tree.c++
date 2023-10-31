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
   int f[N],g[N];
   
   
 
   void dfs(int cur,int par)
   {   

         int max_1=0,max_2=0;
 
         for(auto x:Graph[cur])
         {
              if(x!=par)
              {
                dfs(x,cur);
                // g for the current node
                g[cur] = max(g[x]+1,g[cur]);
                
                f[cur]=max(f[x],f[cur]);
                 
                //max 2 values of g[x]
                if((g[x]+1)>max_1)
                {
                  max_2=max_1;
                  max_1 = g[x]+1;
                }else
                if((g[x]+1)>max_2)
                {
                  max_2=g[x]+1;

                }

              }
         }


         f[cur]=max(f[cur],max_1+max_2);
       
       
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
    
  //  memset(dp,0,sizeof(dp));

    dfs(1,-1);
  
   cout<<f[1]<<endl;

    
     
  
       return 0;
   }
