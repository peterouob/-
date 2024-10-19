/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> cacheRecord;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = cacheRecord.find(key);
        if(it != cacheRecord.end()){
            cache.splice(cache.begin(),cache,cacheRecord[key]);
            cacheRecord[key] = cache.begin();
            return cacheRecord[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cacheRecord.find(key);
        if(it != cacheRecord.end()){
            cache.splice(cache.begin(),cache,cacheRecord[key]);
            cacheRecord[key] = cache.begin();
            cache.begin()->second = value;
        }else{
            if(cacheRecord.size() == size){
                int k = cache.back().first;
                cacheRecord.erase(k);
                cache.pop_back();
            }
            auto data = make_pair(key,value);
            cache.push_front(data);
            cacheRecord[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

