#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

struct v_target
{
    string target_name;
    int distance;
};

struct vertex
{
    string name;
    int key;
    string parent;
    list<v_target> target_list;

};
map<string,vertex> v_map;
bool cmp(string &u,string &v)
{
    return v_map[u].key>v_map[v].key;
}
bool in_set(vector<string> &p_vertex_queue,string v)
{
    int i;
    for(i=0;i<p_vertex_queue.size();i++)
    {
        if(p_vertex_queue[i]==v)
        return true;
    }
    return false;
}

int main()
{
    int i;
    vector<string> p_vertex_queue;
    //初始化
    vertex v;
    v_target target;
    list<v_target> t_list;
    //------------------------------------------------------------
    v.name="a";
    //------------
    target.target_name="b";
    target.distance=4;
    t_list.push_back(target);
    //-----------
    target.target_name="h";
    target.distance=8;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["a"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="b";
    //------------
    target.target_name="a";
    target.distance=4;
    t_list.push_back(target);
    //-----------
    target.target_name="c";
    target.distance=8;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["b"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="c";
    //------------
    target.target_name="b";
    target.distance=8;
    t_list.push_back(target);
    //-----------
    target.target_name="d";
    target.distance=7;
    t_list.push_back(target);
    //-----------
    target.target_name="i";
    target.distance=2;
    t_list.push_back(target);
    target.target_name="f";
    target.distance=4;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["c"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="d";
    //------------
    target.target_name="c";
    target.distance=7;
    t_list.push_back(target);
    //-----------
    target.target_name="e";
    target.distance=9;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["d"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="e";
    //------------
    target.target_name="d";
    target.distance=9;
    t_list.push_back(target);
    //-----------
    target.target_name="f";
    target.distance=10;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["e"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="f";
    //------------
    target.target_name="e";
    target.distance=10;
    t_list.push_back(target);
    //-----------
    target.target_name="c";
    target.distance=4;
    t_list.push_back(target);
    //------------
    target.target_name="d";
    target.distance=14;
    t_list.push_back(target);
    //-----------
    target.target_name="g";
    target.distance=2;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["f"]=v;
    t_list.clear();
    //--------------------------------------------------------------
    v.name="g";
    //------------
    target.target_name="f";
    target.distance=2;
    t_list.push_back(target);
    //-----------
    target.target_name="i";
    target.distance=6;
    t_list.push_back(target);
    //------------
    target.target_name="h";
    target.distance=1;
    t_list.push_back(target);
    
    v.target_list=t_list;

    v_map["g"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="h";
    //------------
    target.target_name="a";
    target.distance=8;
    t_list.push_back(target);
    //-----------
    target.target_name="b";
    target.distance=11;
    t_list.push_back(target);
    //------------
    target.target_name="i";
    target.distance=7;
    t_list.push_back(target);
    //-----------
    target.target_name="g";
    target.distance=1;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["h"]=v;
    t_list.clear();

    //--------------------------------------------------------------
    v.name="i";
    //------------
    target.target_name="c";
    target.distance=2;
    t_list.push_back(target);
    //-----------
    target.target_name="h";
    target.distance=7;
    t_list.push_back(target);
    //------------
    target.target_name="g";
    target.distance=6;
    t_list.push_back(target);

    v.target_list=t_list;

    v_map["i"]=v;
    t_list.clear();





    map<string,vertex>::iterator v_m_iter=v_map.begin();
    while(v_m_iter!=v_map.end())
    {
        v_m_iter->second.key=9999;
        v_m_iter->second.parent="null";
        v_m_iter++;
    }
    v_m_iter->second.key=0;
    //填充优先队列
    v_m_iter=v_map.begin();
    while(v_m_iter!=v_map.end())
    {
        p_vertex_queue.push_back(v_m_iter->second.name);
        v_m_iter++;
    }

    while(p_vertex_queue.size()>0)
    {
        sort(p_vertex_queue.begin(),p_vertex_queue.end(),cmp);
        for(i=0;i<p_vertex_queue.size();i++)
        cout<<p_vertex_queue[i]<<"  ";
        cout<<endl;

        string u=p_vertex_queue[p_vertex_queue.size()-1];
        p_vertex_queue.pop_back();
        list<v_target>::iterator l_iter=v_map[u].target_list.begin();
        while(l_iter!=v_map[u].target_list.end())
        {
            string v=(*l_iter).target_name;
            int w_uv=(*l_iter).distance;
            if(in_set(p_vertex_queue,v)&&w_uv<v_map[v].key)
            {
                v_map[v].parent=u;
                v_map[v].key=w_uv;
            }
            l_iter++;
        }
    }

    v_m_iter=v_map.begin();
    while(v_m_iter!=v_map.end())
    {
        cout<<v_m_iter->second.name<<" parent "<<v_m_iter->second.parent<<endl;
        v_m_iter++;
    }
    return 1;
}