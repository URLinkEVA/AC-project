#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n,m;//n人数，m类型
struct Person
{
    string name;
    int score;
        
    bool operator< (const Person&t) const
    {
        return score < t.score;
    }
    bool operator> (const Person&t) const
    {
        return score > t.score;
    }
}q[N];    

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>q[i].name>>q[i].score;
        
    if(!m) stable_sort(q,q+n,greater<Person>());
    else stable_sort(q,q+n);
    
    for(int i=0;i<n;i++)
        cout<<q[i].name<<' '<<q[i].score<<endl;
        
    return 0;
}
