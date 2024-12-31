#include<iostream>
#include<cstring>

using namespace std;

int main(){
    long long int people = 0, sum = 0, counter;
    cin >> people >> sum;
    counter = sum;
    int *ticket = new int[people + 2];
    memset(ticket, 0, (people + 2) * sizeof(int));
    for (int i = 0; i < sum; i++)
    {
        int temp;
        cin >> temp;
        ticket[temp]++;
    }
    for (int i = 0; i < people+1; i++)
    {
        while (ticket[i]!=0)
        {
            cout<<i;
            counter--;
            if (counter!=0)
            {
                cout << ' ';
            }
            else{
                cout << endl;
            }
            ticket[i]--;
        }
        }
    
    delete[] ticket;
}