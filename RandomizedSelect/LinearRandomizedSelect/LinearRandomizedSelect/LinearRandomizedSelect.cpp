/*
 * ����ʱ��ѡ�������ԭ�����㷨���Ż�
 */
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
/**
 * \brief ��������x���л��֣�����x�������е�λ��
 * \param array ��Ѱ����
 * \param left ���������
 * \param right �������Ҳ�
 * \param x ����Ԫ��
 * \return ����x�������е�λ��
 */
int Partition(vector<int> array,int left,int right,int x)
{
    //�͵�һ��λ�ý���
    for(int i=left;i<=right;i++)
    {
        if(array[i]==x)
        {
            swap(array[left],array[i]);
            break;
        }
    }

    int i=left+1;
    int j=right;

    while(i<=j)
    {
        while(i<=j && array[i]<=x)
        {
            i++;
        }
        while(i<=j && array[j]>=x)
        {
            j--;
        }
        if(i<j)
        {
            swap(array[i],array[j]);
        }
    }
    swap(array[left],array[j]);
    return j;
}

int Select(vector<int> array,int left,int right,int k)
{
    //������С��75���������ֱ�����򷵻�������Ҫ��ֵ
    if(right-left<75)
    {
        sort(array.begin()+left,array.begin()+right+1);

        return array[left+k-1];
    }

    //����������75������������ÿ5��һ����Ȼ���ٽ�������
    for(int i=0;i<(right-left-4)/5;i++)
    {
        //ÿ5��һ���������
        sort(array.begin()+left+5*i,array.begin()+left+5*i+5);

        //����λ������ǰ�漸λ
        swap(array[left+i],array[left+i*5+2]);
    }

    //���������ǵ���λ��
    int x=Select(array,left,left+(right-left-4)/5,(right-left-4)/(5*2)+1);

    //���������λ������������
    int r=Partition(array,left,right,x);

    //�жϵ�ǰ��res�ڵڼ���λ��
    int res=r-left+1;

    if(res>k)
    {
        return Select(array,left,r-1,k);
    }else
    {
        return Select(array,r+1,right,k-res);
    }
}
vector<int> test;
int main(){

    srand((int)time(0));
    int index=0;

    while(index<100000)
    {
        int num=rand() % RAND_MAX * (rand() % 100); //���ɴ������
        test.push_back(num);
        index++;
    }
    
    cout<<endl<<endl;
    cout<<"�� 66666 С��Ԫ��Ϊ "<<Select(test,0,99999,66666)<<endl;

    return 0;
}
