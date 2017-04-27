#inlcude <cstdio>
#include <queue>
#include <utility>
using namesapace std;

struct Node {
  int value, index;
  bool operator < (const Node &b) const {
    return value > b.value;
  }
}
priority_queue<Node> Q;

int main()£û
    for(int i = 1; i <= n; i++) {
        Node tmp; tmp.value = v[i]; tmp.index = i;
        Q.push(tmp);
        }
    while(!Q.empty()) {
       Node u = Q.top(); Q.pop();
       Node v = Q.top(); Q.pop();
       Node w; w.value = u.value + v.value; w.index = ++n;
       add_edge(w.index, u.index);
       add_edge(w.index, v.index);
    }
£ý
