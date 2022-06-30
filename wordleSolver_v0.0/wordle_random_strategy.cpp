#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #define push_back pb
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <string> dict; //stores the words imported from in.text

void input(){
	freopen("in.text","r",stdin);  //imports data
	string s;
	while(cin>>s)
	{
		dict.push_back(s.substr(1,5));
	}
}

const int BLACK=0, YELLOW=1, GREEN=2;  // to assign value to the colour


struct Word{
	int a[5];
	
	bool operator ==(const Word& equal2)const{
		for(int i=0;i<5;i++)
		{
			if(a[i]!=equal2.a[i])
				return false;
		}
		return true;
	}
	bool is_perfect()const {
		for(int i=0;i<5;i++)
			if(a[i]!=GREEN)
				return false;
		return true;	
	}
	
	void show(string test)
	{
		cout<<test<<"\n";
		// vector<char> black,green,yellow;
		for(int i=0;i<5;i++)
		{
			if(a[i]==BLACK)
			{
				cout<<"B ";
			}
			else
			if(a[i]==GREEN)
			{
				// green.push_back(test[i]);
				cout<<"G ";
			}
			else
			{
				// yellow.push_back(test[i]);
				cout<<"Y ";
			}	
		}
		cout<<"\n";
	}
};


Word check(string hidden, string test)
{
	Word word;
	int used[5];
	memset(used,0,sizeof(used));
	for(int i=0;i<5;i++)
	{
		word.a[i]=BLACK;
		if(hidden[i]==test[i])
		{
			used[i]=1;
			word.a[i]=GREEN;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(word.a[i]==BLACK)
		{
			for(int j=0;j<5;j++)
			{
				if(used[i]==0 && hidden[j]==test[i])
				{
					word.a[i]=YELLOW;
				}
			}
		}
	}
	
	return word;
}


void random_strat(string hidden){
   vector<string> remaining = dict;
   int ct=0;
   while(true)	
   {
   	
   	string test=remaining[rand() % remaining.size()];
   	Word word=check(hidden,test);
   	cout<<remaining.size()<<"\n";
   	word.show(test);
   	if(word.is_perfect()){
   		break;
   	} 
   	vector<string> remaining_after;
   	for(string remove:remaining)
   	{
   		if(check(remove,test)==word)
   		{
   			remaining_after.push_back(remove);
   		}
   	}
   	remaining = remaining_after;
   }
}


signed main()
{
#ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin); 
  freopen("output.txt","w",stdout);
#endif
 
  IOS;
  
  input();
  srand(time(0));
  string hidden=dict[rand()%dict.size()];
  cout<<"HIDDEN: "<<hidden<<"\n";
  // for(string s:{"CODER","MATHS","FORCE","EVERY","ADDER","ELDER","PEARS"})
  // {
  //    check(hidden,s).show(s);
  // }
  random_strat(hidden);
  
  

  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";  
  cin.clear();
  cin.get();
  return 0;
}