// Lca using Two pointers
//this is basically the brute force approach

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
  vector<int>depth(N,0),parent(N,0);


  //topological sorting
  vector<int>order;

  void dfs(int cur,int par)
  {
       parent[cur]=par;
       depth[cur]=depth[par]+1;
       for(auto it:Graph[cur])
       {
          if(it!=par)
          {
            dfs(it,cur);
          }
       }
     
  }

  int LCA(int u,int v)
  {
    if(u==v) return u;

    //depth of u is more than v
    if(depth[u]<depth[v]) swap(u,v);

    int diff=depth[u]-depth[v];

    while(diff--)
    {
      u=parent[u];
    }

    while(u!=v)
    {
      u=parent[u];
      v=parent[v];
    }


    return u;

  }

    








  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  




  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Graph[y].push_back(x); 
  }
   depth[0]=-1;
  dfs(1,0);

  // for(int i=1;i<=n;i++)
  // {
  //   cout<<i<<" "<<depth[i]<<" "<<parent[i]<<endl;
  // }



   cout<<LCA(9,12)<<endl;
   cout<<LCA(10,8)<<endl;
    cout<<LCA(9,11)<<endl;
 
      return 0;
  }

//how a binary lifting  can help us to find the LCA

  #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
  
  const int N=1e5+10,M=20;
  vector<int>Graph[N];
  vector<int>depth(N,0);
  int parent[N][M];


  //topological sorting
  vector<int>order;

  void dfs(int cur,int par)
  {
       
       depth[cur]=depth[par]+1;
       parent[cur][0]=par;

       for(int j=1;j<M;j++)
       {
          parent[cur][j]=parent[parent[cur][j-1]][j-1];

       }





       for(auto it:Graph[cur])
       {
          if(it!=par)
          {
            dfs(it,cur);
          }
       }
     
  }

  int LCA(int u,int v)
  {
    if(u==v)return u;

    if(depth[u]<depth[v])swap(u,v);
    
    int diff=depth[u]-depth[v];
    for(int j=M-1;j>=0;j--)
    {
      if((diff>j)&1)
      {
        //means jth bit is set

        u=parent[u][j];

      }
    }

    if(u==v)
    {
      return u;
    }

    //u and v are on the same level

     for(int j=M-1;j>=0;j--)
    {
      if(parent[u][j]!=parent[v][j])
      {
        //means jth bit is set
        u=parent[u][j];
        v=parent[v][j];
      }
    }


    return parent[u][0];


  }

  

  



    








  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  




  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Graph[y].push_back(x); 
  }
   depth[0]=-1;
   memset(parent,0,sizeof(parent));
  dfs(1,0);

  for(int i=1;i<=12;i++)
  {
    cout<<i<<"->";
    for(int j=0;j<4;j++)
    {
      cout<<parent[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<LCA(9,12)<<endl;
  cout<<LCA(9,12)<<endl;
  cout<<LCA(7,12)<<endl;


 
      return 0;
  }
