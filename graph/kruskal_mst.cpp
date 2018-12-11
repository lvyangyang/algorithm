#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

struct v_target
{
    string target_name;
    int distance;
};

struct edge
{
    string s_name;
    string d_name;
    int distance;
};

struct vertex
{
    string name;
    list<v_target> target_list;
};

bool less_than(edge &A,edge &B)
{
   return  A.distance<B.distance;
}

bool set_find_combine(vector<set<string>> &v_set_vec,string u,string v)
{
    int v_size=v_set_vec.size();
    int i,index1,index2;
    bool in_set_1=false,in_set_2=false;
    for(i=0;i<v_size;i++)
    {
        if(v_set_vec.at(i).count(u)!=0)
        {
            index1=i;
            in_set_1=true;
            if(v_set_vec.at(i).count(v)!=0)
            return true;
            break;
        }
    }
    for(i=0;i<v_size;i++)
    {
        if(v_set_vec.at(i).count(v)!=0)
        {
            in_set_2=true;
            index2=i;
        }
        break;
    }
    if(in_set_1)
    {
        if(in_set_2)
        {
            v_set_vec.at(index1).insert(v_set_vec.at(index2).begin(),v_set_vec.at(index2).end());
            v_set_vec.erase(v_set_vec.begin()+index2);
        }else{
            v_set_vec.at(index1).insert(v);
        }
    }else{
        if(in_set_2)
        {
            v_set_vec.at(index2).insert(u);
        }else{
            set<string> temp_set;
            temp_set.insert(u);
            temp_set.insert(v);
            v_set_vec.push_back(temp_set);
        }
    }
    return false;

}

int main()
{
    map<string,vertex> v_map;
    vector<set<string>> v_set_vec;
    vector<edge> edge_vec;
    set<edge> treed_edge;

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


    
    //获得所有的边
    map<string,vertex>::iterator iter=v_map.begin();
    list<v_target>::iterator l_iter;
    while(iter!=v_map.end())
    {
       edge temp_edge;
       temp_edge.s_name=iter->first;
       list<v_target> *target=&iter->second.target_list;
       l_iter=target->begin();
       while(l_iter!=target->end())
       {    
           temp_edge.d_name=(*l_iter).target_name;
           temp_edge.distance=(*l_iter).distance;
           edge_vec.push_back(temp_edge);
           l_iter++;
       }
       iter++;
        
    }
    //...............

    //排序
    sort(edge_vec.begin(),edge_vec.end(),less_than);
    //寻找安全边
    vector<edge>::iterator edge_vec_iter=edge_vec.begin();
    while(edge_vec_iter!=edge_vec.end())
    {
        if(set_find_combine(v_set_vec,(*edge_vec_iter).s_name,(*edge_vec_iter).d_name)==false)
        {
            treed_edge.insert(*edge_vec_iter);
        }

        edge_vec_iter++;
    }

}