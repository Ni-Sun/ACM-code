#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string str[4];

#define lin // linux
// #define win // windows

int main()
{
    #ifdef lin
        str[0]="./data > ./data.in";                    // 数据生成
        str[1]="./correct < ./data.in > ./std.out";       // 正确代码
        str[2]="./To_be_tested < ./data.in > ./solve.out"; // 错误/待测试 代码
        str[3]="diff ./std.out ./solve.out > ./diff.log";
    #endif

    #ifdef win
        str[0]="data.exe > data.in";               // 数据生成
        str[1]="correct.exe < data.in > std.out";    // 正确代码
        str[2]="To_be_tested.exe < data.in > solve.out";  // 错误/待测试 代码
        str[3]="fc std.out solve.out > diff.log";
    #endif
    int T=0;
    while(1)
    {
        cout<<"test case: "<<++T<<"  ";
        for(int i=0;i<3;i++)
            system(str[i].c_str());
        if(system(str[3].c_str()))
        {
            cout<<"WA\n";
            break;
        }
        cout<<"AC\n";
        // system("pause");
    }
}