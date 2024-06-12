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
    s1=strlen(str);//长串长度
    s2=strlen(substr);//子串长度
    while(s1>=s2)
    {//长串如果比子串短，就不用再找了，找不到的
        str=strstr(str,substr);
        if(str!=0){//不等于0，找到了
            n++;
            str+=s2;//长串从找到子串的位置开始后移一个子串的长度
        }
        else break;//找不到了，跳出循环
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