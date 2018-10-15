
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;

struct vertex
{
    string name;
    int key;
    

};

map<string,vertex> v_map;

bool cmp(string &u,string &v)
{
    return v_map[u].key>v_map[v].key;
}

int main()
{
    vector<string> p_vertex_queue;
    vertex temp;
    temp.name="a";
    temp.key=15;
    v_map["a"]=temp;

    temp.name="b";
    temp.key=5;
    v_map["b"]=temp;

    temp.name="c";
    temp.key=13;
    v_map["c"]=temp;

    temp.name="e";
    temp.key=11;
    v_map["e"]=temp;



    map<string,vertex>::iterator v_m_iter=v_map.begin();
    while(v_m_iter!=v_map.end())
    {
        p_vertex_queue.push_back(v_m_iter->second.name);
        cout<<v_m_iter->second.name<<"  ";
        v_m_iter++;
    }

    //cout<<
    cout<<endl;
    int i;
    for(i=0;i<p_vertex_queue.size();i++)
    cout<<v_map[p_vertex_queue[i]].name<<" 55";
    cout <<endl;

    sort(p_vertex_queue.begin(),p_vertex_queue.end(),cmp);

    for(i=0;i<p_vertex_queue.size();i++)
    cout<<v_map[p_vertex_queue[i]].key<<"  ";
    cout <<endl;
    return 1;




}