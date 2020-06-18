// Time complexity :- O(1)
// Space complexity :- O(n)
class RandomizedSet {
private:
    unordered_map<int, int>store;
    vector<int>all_elements;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        store.clear();
        all_elements.clear();
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(store.find(val) != store.end())
            return false;
        
        store[val] = all_elements.size();
        all_elements.push_back(val);
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(store.find(val) == store.end())
            return false;
        
        int id = store[val];
        all_elements[id] = all_elements[all_elements.size()-1];
        store[all_elements[id]] = id;
        all_elements.pop_back();
        store.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int id = rand() % all_elements.size();
        return all_elements[id];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */