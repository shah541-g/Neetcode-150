#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        string res = "";
        int l = 0, r = store[key].size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (store[key][mid].second<=timestamp){
                res = store[key][mid].first;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    TimeMap obj;

    // Test Case 1
    obj.set("foo", "bar", 1);
    cout << obj.get("foo", 1) << endl; // bar
    cout << obj.get("foo", 3) << endl; // bar

    // Test Case 2
    obj.set("foo", "bar2", 4);
    cout << obj.get("foo", 4) << endl; // bar2
    cout << obj.get("foo", 5) << endl; // bar2

    // Test Case 3
    TimeMap obj2;

    obj2.set("love", "high", 10);
    obj2.set("love", "low", 20);

    cout << obj2.get("love", 5) << endl;  // ""
    cout << obj2.get("love", 10) << endl; // high
    cout << obj2.get("love", 15) << endl; // high
    cout << obj2.get("love", 20) << endl; // low
    cout << obj2.get("love", 25) << endl; // low

    // Test Case 4
    TimeMap obj3;

    obj3.set("key1", "value1", 1);
    obj3.set("key1", "value2", 3);
    obj3.set("key1", "value3", 5);

    cout << obj3.get("key1", 0) << endl; // ""
    cout << obj3.get("key1", 1) << endl; // value1
    cout << obj3.get("key1", 2) << endl; // value1
    cout << obj3.get("key1", 3) << endl; // value2
    cout << obj3.get("key1", 4) << endl; // value2
    cout << obj3.get("key1", 5) << endl; // value3
    cout << obj3.get("key1", 10) << endl; // value3

    // Test Case 5
    TimeMap obj4;

    obj4.set("a", "apple", 2);
    obj4.set("b", "banana", 5);

    cout << obj4.get("a", 1) << endl; // ""
    cout << obj4.get("a", 2) << endl; // apple
    cout << obj4.get("b", 4) << endl; // ""
    cout << obj4.get("b", 5) << endl; // banana
    cout << obj4.get("c", 10) << endl; // ""

    return 0;
}