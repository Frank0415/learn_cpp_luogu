#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

void update(vector<vector<int>>& table,int xstart, int xend, int ystart, int yend){
    if (xend-xstart==1)
    {
        return;
    }
    
    int xpivot = (xend+xstart)/2,ypivot = (yend+ystart)/2;
    for (int i = xstart; i < xpivot; i++)
    {
        for (int j =ystart;j<ypivot;j++){
            table[i][j]=0;
        }
    }
    for (int i = xstart; i < xpivot; i++)
    {
        for (int j =ypivot;j<yend;j++){
            table[i][j]=1;
        }
    }
    for (int i = xpivot; i < xend; i++)
    {
        for (int j=ystart; j<yend; j++){
            table[i][j]=1;
        }
    }
    update(table,xpivot,xend,ypivot,yend);
    update(table,xpivot,xend,ystart,ypivot);
    update(table,xstart,xpivot,ypivot,yend);    

}

int main(){
    int size;
    cin >> size;
    size = pow(2,size);
    vector<vector<int>> table;
    table.resize(size, vector<int>(size));
    update(table,0,size,0,size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<table[i][j];
            if (j<size-1)
            {
                cout<< " ";
            }
            
        }
            cout<<endl;

    }
    
}