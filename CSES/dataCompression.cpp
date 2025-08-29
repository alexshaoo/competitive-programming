#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

struct Node {
  int freq;
  char c;
  Node *left, *right;
  Node() : freq(0), c('\0'), left(nullptr), right(nullptr) {}
  Node(int freq) : freq(freq), c('\0'), left(nullptr), right(nullptr) {}
  Node(int freq, char c) : freq(freq), c(c), left(nullptr), right(nullptr) {}
  Node(Node* l, Node* r)
      : freq(l->freq + r->freq), c('\0'), left(l), right(r) {}
};

struct Cmp {
  bool operator()(const Node* a, const Node* b) const {
    return a->freq > b->freq;
  }
};

void print(Node* node) {
  if (!node) cerr << "node don't exist" << '\n';
  cout << node->c << ' ' << node->freq << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string message;
  cin >> message;
  int n = message.length();
  if (n <= 0) {
    cerr << "bruh send a message" << '\n';
  }
  map<char, int> freq;
  for (char ch : message) freq[ch]++;
  priority_queue<Node*, vector<Node*>, Cmp> pq;
  for (auto& [c, f] : freq) {
    pq.push(new Node(f, c));
  }
  map<char, string> encoding;
  while (pq.size() > 1) {
    Node* r = pq.top();
    pq.pop();
    Node* l = pq.top();
    pq.pop();
    Node* parent = new Node(l, r);
    pq.push(parent);
  }
  Node* root = pq.top();
  
  /*
  for input AABACDACA, can use this (or smth similar) to see results
  there's a bunch of ties so it's not deterministic but the tree pro
  
  print(root);
  print(root->left);
  print(root->right);
  print(root->right->left);
  print(root->right->right);
  print(root->right->left->left);
  print(root->right->left->right);
  */
}
