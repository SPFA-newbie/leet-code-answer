#include<set>
#include<string>
using namespace std;

struct Pack{
    string name;
    int score;
    Pack(string n, int s) {
        name=n, score=s;
    }
};
struct cmps{
    bool operator()(const Pack &a, const Pack &b) const{
        return a.score==b.score?a.name<b.name:a.score>b.score;
    }
};

class SORTracker {
public:
    bool start;
    set<Pack, cmps> s;
    set<Pack, cmps>::iterator it;
    SORTracker() {
        it=s.end();
        start=true;
    }
    
    void add(string name, int score) {
        s.insert(Pack(name, score));
        if(it==s.end())
            it=s.begin();
        else{
            if(!(it->score==score?it->name<name:it->score>score))
                it--;
        }
    }
    
    string get() {
        if(!start) it++;
        start=false;
        return it->name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
