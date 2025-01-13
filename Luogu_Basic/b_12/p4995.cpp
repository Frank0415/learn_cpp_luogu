#include<algorithm>
#include<iostream>
#include<vector>
#include<math.h>

#define ll long long int

using namespace std;

int main(){
    ll a,sum;
    cin >> a;
    vector<ll> vec(a);
    for (int i = 0; i < a; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), [](ll a, ll b)
         { return  a > b; });

    ll mid = (a -1) / 2;
    sum = vec[0] * vec[0];

    ll l = 0, r = a - 1;
    while (l < r)
    {
        sum += (vec[r] - vec[l]) * (vec[r] - vec[l]);
        ++l;
        sum += (vec[r] - vec[l]) * (vec[r] - vec[l]);
        --r;
    }

    cout << sum<<endl;

    return 0;
}