#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, int> mp;
    // mp[1] = 2;
    // mp[3] = 4;
    // mp[5] = 6;
    // mp[7] = 8;
    // mp[7] = 100;
    
    mp.insert(1,2);
    mp.insert(3,4);
    mp.insert(5,6);
    mp.insert(7,8);
    mp.insert(7,100);
    
//   map<string,int> mp{{"raj",1}, {"man",2}, {"joe",3}};
//   map<int,string> mp{{1,"raj"}, {2,"man"}, {3,"joe"}};


    // m.erase(m.begin(),m.find(5));
    // cout<<m.count(7)<<endl;
    multimap<int,int> :: iterator i;
    // for(i=m.begin(); i!=m.end(); i++)
    //     cout<<(*i).first<<" "<<(*i).second<<endl;
    
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;

    return 0;
}
