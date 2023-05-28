#include <iostream>
using namespace std;
int
main ()
{
  int n, m, i, j, k;
  cout << "Enter the number of processes: ";
  cin >> n;
  cout << "Enter the number of resources: ";
  cin >> m;
  int alloc[n][m], max[n][m], avail[m];
  for (i = 0; i < n; i++)
    {
      cout << "Enter the Allocation Matrix for ";
      cout << "P " << i << ": ";
      for (j = 0; j < m; j++)
	{
	  cin >> alloc[i][j];
	}
    }

  cout << endl;
  for (i = 0; i < n; i++)
    {
      cout << "Enter the Max Matrix for ";
      cout << "P " << i << ": ";
      for (j = 0; j < m; j++)
	{
	  cin >> max[i][j];
	}
    }
  cout << endl;
  cout << "Enter the Available Resources: ";
  
  for (i = 0; i < m; i++)
    {
      cin >> avail[i];
    }
    
  int f[n], ans[n], ind = 0;
  
  for (k = 0; k < n; k++)
    {
      f[k] = 0;
    }
    
  int need[n][m];
  
  for (i = 0; i < n; i++)
{
for (j = 0; j < m; j++)
{
	need[i][j] = max[i][j] - alloc[i][j];
}
}
    
    
int y = 0;
for (k = 0; k < m; k++)
{
    for (i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            int flag = 0;
            for (j = 0; j < m; j++)
            {
                if (need[i][j] > avail[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                ans[ind++] = i;
                for (y = 0; y < m; y++)
                {
                    avail[y] += alloc[i][y];
                }
                f[i] = 1;
            }
        }
    }
}

    
cout << endl;

int flag = 1;
  
for (int i = 0; i < n; i++)
{
      if (f[i] == 0)
	{
	  flag = 0;
	  cout << "The following system is not safe";
	  break;
	}
}
  cout << endl;
  if (flag == 1)
    {
      cout << "Following is the SAFE Sequence :\n";
      for (i = 0; i < n - 1; i++)
	cout << " P" << ans[i] << " ->";
      cout << " P" << ans[n - 1];
    }
  return 0;
}
