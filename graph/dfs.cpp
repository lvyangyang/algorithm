#include<iostream>
#include<map>
#include<list>

using namespace std;

enum COLOR{white,gray,black};
struct vertex
{
    string name;
    int d_time;
    int f_time;
    COLOR color;
    int distance;
    list<string> edge_list;
    string  parent;
};

int time=0;

void dfs_visit(map<string,vertex> &v_map,string v)
{   
    time++;
    v_map[v].d_time=time;
    v_map[v].color=gray;
    list<string>::iterator l_iter=v_map[v].edge_list.begin();
    while(l_iter!=v_map[v].edge_list.end())
    {
        if(v_map[*l_iter].color==white)
        {
            v_map[*l_iter].parent=v;
            dfs_visit(v_map,*l_iter);   
        }
        l_iter++;
        
    }
    time++;
    v_map[v].f_time=time;
    v_map[v].color=black;

}

int main()
{   

    map<string,vertex> v_map;


    vertex v;

    v.name="u";
    v.edge_list.push_front("v");
    v.edge_list.push_front("x");
    v_map["u"]=v;
    v.edge_list.clear();

    v.name="v";
    v.edge_list.push_front("y");
    v_map["v"]=v;
    v.edge_list.clear();

    v.name="y";
    v.edge_list.push_front("x");
    v_map["y"]=v;
    v.edge_list.clear();

    v.name="x";
    v.edge_list.push_front("v");
    v_map["x"]=v;
    v.edge_list.clear();

    v.name="w";
    v.edge_list.push_front("y");
    v.edge_list.push_front("z");
    v_map["w"]=v;
    v.edge_list.clear();

    v.name="z";
    v.edge_list.push_front("z");
    v_map["z"]=v;
    v.edge_list.clear();

    map<string,vertex>::iterator iter=v_map.begin();
    while(iter!=v_map.end())
    {
        iter->second.color=white;
        iter->second.distance=99;
       // iter->second.time=0;
        iter->second.parent="0";
        iter++;
    }
    iter=v_map.begin();
    while(iter!=v_map.end())
    {
        if(iter->second.color==white)
        dfs_visit(v_map,iter->second.name);
        iter++;
    }

    iter=v_map.begin();
    while(iter!=v_map.end())
    {
        cout<<iter->second.name<<"  "<<iter->second.color<<" d_time:"<<iter->second.d_time<<" f_time:"<<iter->second.f_time<<" "<<iter->second.parent<<endl;

        iter++;
    }
    return 1;
}