class SmallestInfiniteSet {
public:
    set<int> s;
    int x = 1;
    
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (s.empty()) return x++;
        else {
            int ele = *s.begin();
            s.erase(ele);
            return ele;
        }
    }

    void addBack(int num) {
        if (num >= x) return;
        else s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */