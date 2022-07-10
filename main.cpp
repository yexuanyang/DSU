#include<iostream>
#define MAX_FATHER_NUMBER 10000


using namespace std;
int fa[MAX_FATHER_NUMBER + 1];//记录节点的父节点
int depth[MAX_FATHER_NUMBER + 1];//记录以该节点为根节点的子树的深度

inline void init(int n){
    for(int i = 1; i <= n; i ++){//初始化所有的父节点
        fa[i] = i;
        depth[i] = 1;
    }
}

int find(int x){
    return x == fa[x] ? x : (fa[x] = find(fa[x]));//如果x是根节点返回x，不是则返回他父节点的根节点并且把x的父节点变成根节点
}

void merge(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    if(depth[iRoot] <= depth[jRoot]){
        fa[iRoot] = jRoot;
    }else{
        fa[jRoot] = iRoot;
    }
    if(depth[iRoot] == depth [jRoot] && iRoot != jRoot){//深度相同且根节点不同则合并之后树深度加一
        depth[iRoot]++;
    }
}


int main(){
    init(MAX_FATHER_NUMBER);
    int n,m;//n表示元素个数 m表示操作次数
    cin >> n >> m;
    int z,x,y;//z = 1 merge x , y ; z = 2 find xy是不是在同一个并查集
    for(int i = 0; i < m; i ++){
        cin >> z >> x >> y;
        switch(z){
            case 1:
                merge(x,y);
                break;
            case 2:
                if(find(x) == find(y) ){
                    cout << "Y" << endl;
                }else{
                    cout << "N" << endl;
                }
                break;
            default: break;
        }
    }
    return 0;
}