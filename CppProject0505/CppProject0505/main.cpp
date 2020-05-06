#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <array>
using namespace std;


#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <array>
using namespace std;



class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<vector<int>>> bb;
        if (buildings.size() == 0) return buildings;
        for (vector<int> building : buildings) {
            vector<vector<int>> buildings_format;
            vector<int> building_format0;
            building_format0.push_back(building[0]);
            building_format0.push_back(building[2]);

            buildings_format.push_back(building_format0);

            vector<int> building_format1;
            building_format1.push_back(building[1]);
            building_format1.push_back(0);
            buildings_format.push_back(building_format1);
            bb.push_back(buildings_format);
        }
        //    cout << bb[0][0][0] << bb[0][0][1] << bb[0][1][0] << bb[0][1][1] <<endl;
        //    cout << bb[1][0][0] << bb[1][0][1] << bb[1][1][0] << bb[1][1][1] <<endl;
        //vector<vector<int>> answer = Merge(bb, 0, bb.size() - 1); //= merge(bb[0], bb[1]);//
        return Merge(bb, 0, bb.size() - 1);;
    }
    vector<vector<int>> Merge(vector<vector<vector<int>>>& buildings, int left,  int right) {
        if (left == right) {
            return buildings[left];
        }
        if (left + 1 == right) {
            return merge(buildings[left], buildings[right]);
        }
        int mid = (left + right) / 2;
        vector<vector<int>> ans1 = Merge(buildings, left, mid);
        vector<vector<int>> ans2 = Merge(buildings, mid + 1, right);
        return merge(ans1, ans2);
    }

    vector<vector<int>> merge(vector<vector<int>>& b1, vector<vector<int>>& b2) {
        auto it1 = b1.begin();
        auto it2 = b2.begin();
        vector<vector<int>> answer;
        int h1 = 0;
        int h2 = 0;
        int h = 0;
        int prev = 0;

        while (it1 != b1.end() || it2 != b2.end()) {
            int x = 0;
            // cout << h << " " << prev << endl;
            if (it2 == b2.end() || (it1 != b1.end() && it1->at(0) < it2->at(0))) {
                h1 = (*it1)[1];
                x = it1->at(0);
                it1++;
            }
            else if (it1 == b1.end() || (it2 != b2.end() && it1->at(0) > it2->at(0))) {
                h2 = (*it2)[1];
                x = it2->at(0);
                it2++;
            }
            else {
                h1 = (it1->at(1));
                h2 = (it2->at(1));
                x = it1->at(0);
                it1++;
                it2++;
            }
            h = std::max(h1, h2);
            if (h != prev) {
                vector<int> vec;
                vec.push_back(x);
                vec.push_back(h);
                answer.push_back(vec);
            }
            prev = h;
        }
        return answer;
    }
};

 


int main(int argc, const char* argv[]) {
    map<int, string> tree;
    tree.insert(pair<int, string>(1111, "one"));
    
    cout << tree.find(1111)->second << endl;
    cout << tree.at(1111) << endl;
    cout << tree[1111] << endl;
    
    map<int, string> *p = &tree;
    cout << p->at(1111) << endl;
    cout << (*p)[1111] << endl;
    
    return -1;
}
