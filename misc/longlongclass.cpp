#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class CalLongint{
    private:
        string longint;
    public:
        void init(string longinit) { longint = longinit; }
        void print(){
            cout << longint << endl;
        }
        void add(string addint){
            int a = longint.length();
            int b = addint.length();
            if (a<b) {swap(longint, addint);
                swap(a, b);
            }
            string solution;
            solution.resize(a);
            int curr = 0;
            int adder = 0;
            for (int i = a - 1; i >= 0; i--)
            {
                if ((i-abs(a-b))>=0)
                {
                    curr = longint[i] + addint[i - abs(a - b)] - 96;
                }
                else{
                    curr = longint[i] - 48;
                }
                //cout << curr << endl;
                solution[i] = adder + curr + '0' ;
                //cout << solution[i];
                if (solution[i] >= 58)
                {
                    solution[i] -= 10;
                    adder = 1;
                }
                else{
                    adder = 0;
                }
            }
            if (adder==1){
                solution.insert(0, "1");
            }
            //cout << solution << endl;
            longint = solution;
        }
};

int main(){
    CalLongint ans;
    ans.init("14894329847238947294432432423423423");
    ans.add("423423543254234234324234324234324234");
    ans.print();
}
