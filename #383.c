char canConstruct(char * ransomNote, char * magazine){
    int in[26];
    for(int i=0;i<26;i++)
        in[i]=0;
    for(int i=0;magazine[i]!=0;i++)
        in[magazine[i]-'a']++;
    for(int i=0;ransomNote[i]!=0;i++)
        if(in[ransomNote[i]-'a']==0)
            return 0;
        else in[ransomNote[i]-'a']--;
    return 1;
}