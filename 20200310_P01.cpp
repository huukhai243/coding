#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

set<string> ans;
int find_depth(string u, map<string, pair<string, string> > ancestor) {
    if (u == "0000000") {
        return 0;
    }
    int father_depth = find_depth(ancestor[u].first, ancestor);
    int mother_depth = find_depth(ancestor[u].second, ancestor);
    return max(father_depth, mother_depth) + 1;
}
void dfs(string id, map<string, pair<string, string> > ancestor) {
    ans.insert(id);
    for (auto p : ancestor) {
        if (p.second.first == id || p.second.second == id) {
            dfs(p.first, ancestor);
        }
    }
}

int main() {
    string s, date, father, mother, region, alive;
    map<string, int> born_at;
    map<string, int> people;
    map<string, pair<string, string> > ancestor;
    while(true){
        cin >> s;
        if (s == "*") break;
        else{
            cin >> date >> father >> mother >> alive >> region;
            born_at[date]++;
            people[s]++;
            ancestor[s] = make_pair(father, mother);
        }
    }
    while(true){
        cin >> s;
        if (s == "***") break;
        else{
            if (s == "NUMBER_PEOPLE"){
                cout << people.size() << endl;
            }else if (s == "NUMBER_PEOPLE_BORN_AT"){
                cin >> date;
                cout << born_at[date] << endl;
            }else if (s == "MOST_ALIVE_ANCESTOR"){
                string id;
                cin >> id;
                cout << find_depth(id, ancestor) - 1 << endl;
            }else if (s == "NUMBER_PEOPLE_BORN_BETWEEN"){
                string from_date, end_date;
                cin >> from_date >> end_date;
                int ans = 0;
                auto it = born_at.lower_bound(from_date), it1 = born_at.lower_bound(end_date);
                for (it; it != it1; it++){
                    ans += it->second;
                }
                cout << ans << endl;
            }else if (s == "MAX_UNRELATED_PEOPLE"){
                for (auto p : ancestor) {
                    if (p.second.first != "0000000" && p.second.second != "00000000") {
                        dfs(p.first, ancestor);
                    }
                }
                cout << ans.size() << endl;
            }
        }
    }
}
