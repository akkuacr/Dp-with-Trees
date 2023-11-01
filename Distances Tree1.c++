
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
   
   
 
   void dfs_g(int cur,int par)
   {   

        
 
         for(auto x:Graph[cur])
         {
              if(x!=par)
              {
                dfs_g(x,cur);
                // g for the current node
                   
                   g[cur]=max(g[cur],g[x]+1);

              }
         }  
       
       
   }





   void dfs_f(int cur,int par,int dis_par)
   {
        int max_1=-1,max_2=-1;
        for (auto x:Graph[cur])
        {   
              if(x!=par)
              {
                  if(g[x]>max_1){
                    max_2=max_1;
                    max_1=g[x];
                  }else if(g[x]>max_2){
                    max_2 = g[x];
                  }

              }
        }



        for(auto x:Graph[cur])
        {
          if(x!=par)
          {
            //later
            int new_dis_par=dis_par;

            // for(auto y:Graph[cur])
            // {
            //   if(y!=par && y!=x)
            //   {   new_dis_par =max(new_dis_par,g[y]);

            //   }
            // }

            if(g[x] == max_1){
              new_dis_par =max(new_dis_par,max_2);
            }else{
              new_dis_par =max(new_dis_par,max_1);

            }



            dfs_f(x,cur,new_dis_par+1);
              
             //for any node in the subtree 
            f[cur]=max(f[cur],g[x]+1);

            


          }
        }
         //for any node in the supertree
            // supertree =compliment of subtree

        f[cur] = max(f[cur],dis_par+1);

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


   //O(n)
    dfs_g(1,-1);
    //O(n^2)
    dfs_f(1,-1,-1);
  
    for (int i = 1; i <=n; ++i)
    {
      cout<<f[i]<<" ";
    }

    
     
  
       return 0;
   }
