#include<iostream>
#include<cstring>
using namespace std;

/*
#include<cstring>
int SubStrNum(char * str,char * substr){
    int count=0,cur=0;
    int i=0;
    int len = strlen(str),lensub=strlen(substr);
    char tmp1,tmp2;

    while(i<len){
        if(str[i]==substr[cur]){
            cur++;
            if(cur==lensub){
                cur=0;
                count++;
            }       
        }
        else    cur=0;
        i++;
    }

    return count;
}
*/
#include<iostream>
#include<cstring>
using namespace std;
int SubStrNum(char * str, char * substr)
{
    int n=0,s1=0,s2=0;
    char *p=str;
    s1=strlen(str);//��������
    s2=strlen(substr);//�Ӵ�����
    while(s1>=s2)
    {//����������Ӵ��̣��Ͳ��������ˣ��Ҳ�����
        str=strstr(str,substr);
        if(str!=0){//������0���ҵ���
            n++;
            str+=s2;//�������ҵ��Ӵ���λ�ÿ�ʼ����һ���Ӵ��ĳ���
        }
        else break;//�Ҳ����ˣ�����ѭ��
        s1=strlen(str);
    }
    std::cout<<"match times="<<n;
    return n;
   
}



// int main(){
//     // char str[]="hello  world  hellohell o  you hello",substr[]="hello";
//     char str[]="hhhhhh",substr[]="hh";
//     int n = SubStrNum(str,substr);
//     cout<<"match times="<<n;
//     system("pause");
//     return 0;
// }