//����������ڼ���һ����ϵͳ�ĸ���ָ��
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
    scanf("%lf%d%d",&lambda,&T,&pay);//���빺�����������͸���ʱ�������
    double ExpectOfSer = 0,VarOfSer = 0;
    for(int i = 0;i < T;i++){//�������ʱ����ѧ����
        int tempsum = 0;
        scanf("%d%d%lf",&a,&b,&p1);
        for(int j = 0;j < 200;j++){
            tempsum += (rand() % (b-a))+ a + 1;
        }
        p[i] = p1;//��¼ÿ�μ���õ��Ľ���ʱ������ĸ���
        modul[i] = ((double)((tempsum/200)*2 + pay)/60);//��¼ÿ�μ���õ��Ľ���ʱ������ľ�ֵ
//        printf("---%d\n",tempsum/200);
        ExpectOfSer += modul[i]*p1;//������ѧ����
    }
    for(int i = 0;i <T;i++){
        VarOfSer += (modul[i] - ExpectOfSer) * (modul[i] - ExpectOfSer) * p[i];
    }//���㷽��
    printf("-- e %f\n",ExpectOfSer);
    printf("---d %f\n",VarOfSer);
    double mu = 1/ExpectOfSer,rho = lambda/mu,sigma2 = VarOfSer;//����ƽ���ӳ��Ͳ���rho��rho�������ڼ�����и��ʣ�
    double Lq = (lambda * lambda * sigma2 + rho * rho)/2 * (1 - rho);//����ƽ���Ŷӳ�
    double Wq = Lq/lambda;//����ƽ���Ŷ�ʱ��
    double Ws = ExpectOfSer + Wq;//����ƽ������ʱ��
    cout<<"ƽ���ӳ�:"<<Lq + rho<<endl<<"ƽ���Ŷӳ�:"<<Lq<<endl<<"ƽ���Ŷ�ʱ��"<<Wq<<endl<<"ƽ������ʱ��"<<Ws<<endl<<"���и���"<<1 - rho<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
