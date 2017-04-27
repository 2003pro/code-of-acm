//这个程序用于计算一种子系统的各项指标
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int T,a,b,pay;
double p1,modul[7],lambda,p[7];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out,txt","w",stdout);
    scanf("%lf%d%d",&lambda,&T,&pay);//输入购买件数类别数和付款时间的期望
    double ExpectOfSer = 0,VarOfSer = 0;
    for(int i = 0;i < T;i++){//计算服务时间数学期望
        int tempsum = 0;
        scanf("%d%d%lf",&a,&b,&p1);
        for(int j = 0;j < 200;j++){
            tempsum += (rand() % (b-a))+ a + 1;
        }
        p[i] = p1;//记录每次计算得到的结算时间的类别的概率
        modul[i] = ((double)((tempsum/200)*2 + pay)/60);//记录每次计算得到的结算时间的类别的均值
//        printf("---%d\n",tempsum/200);
        ExpectOfSer += modul[i]*p1;//计算数学期望
    }
    for(int i = 0;i <T;i++){
        VarOfSer += (modul[i] - ExpectOfSer) * (modul[i] - ExpectOfSer) * p[i];
    }//计算方差
    printf("-- e %f\n",ExpectOfSer);
    printf("---d %f\n",VarOfSer);
    double mu = 1/ExpectOfSer,rho = lambda/mu,sigma2 = VarOfSer;//计算平均队长和参数rho（rho后面用于计算空闲概率）
    double Lq = (lambda * lambda * sigma2 + rho * rho)/2 * (1 - rho);//计算平均排队长
    double Wq = Lq/lambda;//计算平均排队时间
    double Ws = ExpectOfSer + Wq;//计算平均逗留时间
    cout<<"平均队长:"<<Lq + rho<<endl<<"平均排队长:"<<Lq<<endl<<"平均排队时间"<<Wq<<endl<<"平均逗留时间"<<Ws<<endl<<"空闲概率"<<1 - rho<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
