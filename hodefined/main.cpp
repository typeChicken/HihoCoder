#include <iostream>
/**************************************
 *
 * @return
 * 题目1 : 小Ho的防护盾
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Ho的虚拟城市正在遭受小Hi的攻击，小Hi用来攻击小Ho城市的武器是一艘歼星舰，这艘歼星舰会以T(T为大于0的整数)个单位时间的间隔向小Ho的城市轰击。歼星舰总共有N枚炮弹，其中第i枚会造成Ai点伤害值。

幸好小Ho的城市有K层护盾，每层护盾可以抵挡M点伤害。当某次轰击使得伤害值达或超过M时，该层护盾就会被击碎；该次轰击溢出的伤害不会作用于下一层护盾；下一次轰击将由下一层护盾承受。

同时，受损但尚未被击碎护盾会以每单位时间减少1点伤害值的速度修复自己，直到伤害值降为0。这就意味着小Hi的攻击间隔T越大，小Ho撑过这N枚炮弹的可能性就越大。

那么问题来了，小Hi的攻击间隔T至少需要是多少，小Ho城市的防护护盾才能不被全部击破？

为了使题目不存在歧义，规定：

小Hi的第i次攻击发生在时刻(i-1)*T

小Ho的第i次修复发生在时刻i-0.5

输入
第一行包含3个整数N、M和K，意义如前文所述。

第二行包含N个整数A1 - AN，表示小Hi第i枚炮弹的伤害值。

对于30%的数据，满足N<=100

对于100%的数据，满足1<=N<=100000

对于100%的数据，满足1<=K<=10, 1<=Ai, M<=100000

输出
输出使得小Ho城市的防护护盾不被全部击破的小Hi攻击间隔的最小值。如果不存在这样的T，则输出-1。

样例输入
3 5 1
3 3 3
样例输出
3
 *************************************/
//using std::cout;
//using std::cin;
//using std::endl;
//int main() {
//    int N;//炮弹数量
//    int M;//每层护盾抵挡伤害
//    int K;//护盾层数
//    int T=0;//攻击间隔
//    int *damage_array;
//  cout<<"请分别输入炮弹数量（N），每层护盾可以抵挡的伤害（M），护盾层数（K）"<<endl;
//    cin>>N>>M>>K;
//    cout<<"N:"<<N<<"  M:"<<M<<"  K:"<<K<<endl;
//    cout<<"please input each cannonball damage."<<endl;
//    damage_array = new int[N];
//    for(int i=0;i<N;++i)
//    {
//        cin>>damage_array[i];
//    }
//
//    //设置初始攻击间隔为0，从最后一发炮弹算起，
//    /************************************
//     *
//     */
//}
//void begin_attack(int& cannonball_num,int& shield_value,int& shield_num,int* damage_array, int  accack_interval [])
//{
//    if(cannonball_num==0 || shield_value==0)
//        return ;
//    //如果护盾层数大于炮弹数，直接返回
//    if(shield_num>cannonball_num)
//        return ;
//
//}


#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool simulate(vector<int> &attacks, int t, int k, int m) {
    int currentM = m;
    for (int i = 0; i < (int)attacks.size(); i++) {
        currentM = currentM - attacks[i];
        if (currentM <= 0) {
            k--;
            currentM = m;
        }

        if (k <= 0) {
            return false;
        }

        currentM = min(m, currentM + t);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> attacks(n);

    int maxT = 0;
    for (int i = 0; i < n; i++) {
        cin >> attacks[i];
        maxT = max(attacks[i], maxT);
    }

    int left = 1, right = maxT;
    int minT = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        /* cout << mid << "(" << left << ',' << right << ")" << ':'; */
        if (simulate(attacks, mid, k, m)) {
            right = mid - 1;
            /* cout << "OK" << endl; */
            minT = mid;
        } else {
            left = mid + 1;
            /* cout << "not OK" << endl; */
        }
    }
}

