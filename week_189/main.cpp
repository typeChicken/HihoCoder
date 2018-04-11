 #include <iostream>
/******************************************
 * 题目1 : 小P的强力值
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi在虚拟世界中有一只小宠物小P。小P有K种属性，每种属性的初始值为Ai。小Ho送给了小Hi若干颗药丸，每颗药丸可以提高小P指定属性1点。通过属性值，我们可以计算小P的强力值=(C1(1/B1))*(C2(1/B2))*...*(CK(1/BK))，其中Ci为小P第i项属性的最终值（Ai+药丸增加的属性）。 已知小Ho送给小Hi的药丸一共有N颗，问小P的强力值最高能够达到多少？

输入
第一行包含两个整数N，K，分别表示药丸数和属性种数。

第二行为K个整数A1 - AK，意义如前文所述。

第三行为K个整数B1 - BK，意义如前文所述。

对于30%的数据，满足1<=N<=10, 1<=K<=3

对于100%的数据，满足1<=N<=100000, 1<=K<=10

对于100%的数据，满足1<=Ai<=100, 1<=Bi<=10

输出
输出小P能够达到的最高的强力值。

只要你的结果与正确答案之间的相对或绝对误差不超过千分之一，都被视为正确的输出。

样例输入
5 2
1 1
3 2
样例输出
2.88
 * @return
 */

 using std::cout;
 using std::cin;
 using std::endl;

 double get_param(int A[],int B[],int K);
 int get_max_growth_rate(int A[],int B[],int K);
 double get_P(int A[],int B[],int K);
int main() {
    std::cout << "Hello, World!" << std::endl;
    //N:药丸数
    //K:属性种数
    int N,K;
    int *A = new int [K];//k种属性的初始值
    int *B = new int [K];//k中属性的权重
    cin>>N>>K;
    for(int i=0;i<K;++i)
    {
        cin>>A[i];
    }
    for(int i=0;i<K;++i)
    {
        cin>>B[i];

    }
//    for(int i=0;i<K;++i)
//    {
//        cout<<"A["<<i<<"] = "<<A[i]<<endl;
//        cout<<"B["<<i<<"] = "<<B[i]<<endl;
//    }
//    return 0;
    for(int i=0;i<N;++i)
    {

        cout<<"----------the "<<i<<"result is : "<<get_max_growth_rate(A,B,K)<<endl;
    }
    cout<<"param ; "<<get_P(A,B,K);

    return 0;
}

 //
 int get_max_growth_rate(int A[],int B[],int K)
 {
     double max_growth_rate = 0;
     int growth_index=-1;
     for(int i=0;i<K;++i)
     {
         ++A[i];
         double new_growth_rate = get_param(A,B,K);
         if(new_growth_rate>max_growth_rate);
         {
             growth_index=i;
             max_growth_rate=new_growth_rate;
         }
         --A[i];
     }
     ++A[growth_index];
     return growth_index;
 }

 double get_param(int A[],int B[],int K)
 {
     double old_param = 0;

     for(int i=0;i<K;++i)
     {
         old_param += B[i]/A[i];
     }
     return old_param;
 }

 double get_P(int A[],int B[],int K)
 {
     double p = 1;
     for(int i=0;i<K;++i)
     {
         p*=A[i]^(1/B[i]);
     }
     return p;
 }