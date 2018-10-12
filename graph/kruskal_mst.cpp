#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<tuple>
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
            v_set_vec.at(index1).insert(v_set_vec.at(index2).begin(),v_set_vec.at(index2).edn());
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
           temp_edge.d_name=(*l_iter).target;
           temp_edge.distance=(*l_iter).distance;
           edge_vec.push_back(temp_edge);
           l_iter++;
       }
       iter++;
        
    }
    //排序
    sort(edge_vec.begin(),edge_vec.end(),less_than);
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