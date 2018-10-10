#include<iostream>
#include<queue>
#include<list>
#include<map>

using namespace std;

enum COLOR{white,gray,black};

struct vertex
{
    string name;
    COLOR color;
    int distance;
    list<string> edge_list;
    string  parent;
};

int main()
{
    map<string,vertex> v_map;
    
    vertex v;

    v.name="v";
    v.edge_list.push_front("r");
    v_map["v"]=v;
    v.edge_list.clear();

    v.name="r";
    v.edge_list.push_front("v");
    v.edge_list.push_front("s");
    v_map["r"]=v;
     v.edge_list.clear();

    v.name="s";
    v.edge_list.push_front("r");
    v.edge_list.push_front("w");
    v_map["s"]=v;
    v.edge_list.clear();

    v.name="w";
    v.edge_list.push_front("s");
    v.edge_list.push_front("t");
    v.edge_list.push_front("x");
    v_map["w"]=v;
     v.edge_list.clear();

    v.name="t";
    v.edge_list.push_front("w");
    v.edge_list.push_front("x");
    v.edge_list.push_front("u");
    v_map["t"]=v;
     v.edge_list.clear();

    v.name="x";
    v.edge_list.push_front("t");
    v.edge_list.push_front("w");
    v.edge_list.push_front("u");
    v.edge_list.push_front("y");
    v_map["x"]=v;
     v.edge_list.clear();

    v.name="u";
    v.edge_list.push_front("t");
    v.edge_list.push_front("x");
    v.edge_list.push_front("y");
    v_map["u"]=v;
     v.edge_list.clear();

    v.name="y";
    v.edge_list.push_front("u");
    v.edge_list.push_front("x");
    v_map["y"]=v;
     v.edge_list.clear();

    
    queue<string> q;
    map<string,vertex>::iterator iter=v_map.begin();
    while(iter!=v_map.end())
    {
        iter->second.color=white;
        iter->second.distance=99;
        iter->second.parent="0";
        iter++;
    }

   // iter=v_map.begin();

    v_map["s"].color=gray;
    v_map["s"].distance=0;
    v_map["s"].parent="0";

    q.push(v_map["s"].name);
    while(!q.empty())
    {
        string v_name=q.front();
        q.pop();
        list<string> edge_list=v_map.at(v_name).edge_list;
        list<string>::iterator l_iter=edge_list.begin();
        while(l_iter!=edge_list.end())
        {   
            string name=*l_iter;
            l_iter++;
            if(v_map[name].color==white)
            {
                v_map[name].color=gray;
                v_map[name].distance=v_map[v_name].distance+1;
                v_map[name].parent=v_name;
                q.push(name);
            }

        }
        v_map[v_name].color=black;   
    }

    iter=v_map.begin();
    while(iter!=v_map.end())
    {
        cout<<iter->second.name<<"  "<<iter->second.color<<" "<<iter->second.distance<<" "<<iter->second.parent<<endl;

        iter++;
    }

    return 1;

}