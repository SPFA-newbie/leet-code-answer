#include<set>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
		del.clear();
		minn=1;
    }
    
    int popSmallest() {
		int ret=minn;
		del.insert(minn);
		while(del.find(minn)!=del.end())minn++;
		return ret;
    }
    
    void addBack(int num) {
		if(del.find(num)!=del.end())
		{
			del.erase(del.find(num));
			if(num<minn)minn=num;
		}
    }
private:
	set<int> del;
	int minn;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
