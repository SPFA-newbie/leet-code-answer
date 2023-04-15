#include<string>
using namespace std;

const int B=1000000000;
const int M=1000000;
const int T=1000;

string zn[10]={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string ten[10]={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen","Seventeen", "Eighteen", "Nineteen"};
string ty[11]={"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string lv[4]={"", "Thousand", "Million", "Billion"};

class Solution {
public:
    string sig[1000];
    void sigCreate() {
        sig[0]="";
        for(int i=1;i<1000;i++) {
            string now="";
            int p=i;
            string space="";
            now=now+zn[p/100];
            if(p/100!=0) now=now+" Hundred", space=" ";
            p%=100;
            if(p==0) ;else
            if(p<10) now=now+space+zn[p]; else
            if(p<20) now=now+space+ten[p-10]; 
                else {
                    now=now+space+ty[p/10];
                    space=" ";
                    if(p%10!=0)
                        now=now+space+zn[p%10];
                }
            sig[i]=now;
        }
        return;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        sigCreate();
        string ans="";

        if(num/B!=0)
            ans=ans+sig[num/B]+" "+lv[3]+" ";
        num%=B;
        if(num/M!=0)
            ans=ans+sig[num/M]+" "+lv[2]+" ";
        num%=M;
        if(num/T!=0)
            ans=ans+sig[num/T]+" "+lv[1]+" ";
        num%=T;
        if(num!=0)
            ans=ans+sig[num]+" ";
        
        return ans.substr(0, ans.length()-1);
    }
};
