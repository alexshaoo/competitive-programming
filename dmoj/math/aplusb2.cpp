#include <bits/stdc++.h>
using namespace std;

string sum(string str1, string str2) { 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main() {
  int num;
  cin >> num;
  for (int p=0; p<num; p++) {
    string first, second;
    cin >> first >> second;
    if ((first=="0"&&second=="0") || ((first.substr(1, first.size())==second&&first[0]=='-')||(first==second.substr(1, second.size())&&second[0]=='-'))) {
      cout << "0\n";
      continue;
    }
    if (first[0]!='-' && second[0]!='-') {
      cout << sum(first, second) << '\n';
    } else if (first[0]=='-' && second[0]=='-') {
      cout << "-" << sum(first.substr(1, first.size()), second.substr(1, second.size())) << '\n';
    } else {
      string prefix="";
      if (first[0]=='-') {
        swap(first, second);
      }
      second = second.substr(1, second.size());
      if (first.size()<second.size() || (first.size()==second.size() && first<second)) {
        prefix = "-";
        swap(first, second);
      }
      int zeroes = 0;
      while (second[second.size()-1-zeroes]=='0') {
        zeroes++;
      }
      string complement = "";
      for (int i=0; i<second.size()-zeroes-1; i++) {
        complement += ((9-(second[i]-'0'))+'0');
      }
      complement += ((10-(second[second.size()-zeroes-1]-'0')+'0'));
      for (int i=0; i<zeroes; i++) {
        complement += '0';
      }
      string nines = "";
      for (int i=0; i<first.size()-second.size(); i++) {
        nines += '9';
      }
      complement = nines + complement;
      string add = sum(first, complement);
      add = add.substr(1, add.size());
      zeroes = 0;
      while (add[zeroes]=='0') {
        zeroes++;
      }
      cout << prefix << add.substr(zeroes, add.size()) << '\n';
    }
  }
}


// int main() {
    // int asdf;
    // std::cin >> asdf;
    // for (int jkl = 0; jkl < asdf; jkl++){
    // std::string a,b;
    // std::cin >> a;
    // std::cin >> b;
    // int sa = a.size();
    // int sb = b.size();
    // // get sum
    // int out[std::max(sa,sb)+1];
    // for (int i = 0; i <= std::max(sa,sb); i++) out[i]=0;
    // for (int i = 0; i < sa; i++) {
        // if (a[0] == '-') {
            // if (i > 0) out[sa-1-i] -= a[i]-'0';
        // }
        // else out[sa-1-i]+=a[i]-'0';
    // }
    // for (int i = 0; i < sb; i++) {
        // if (b[0] == '-') {
            // if (i > 0) out[sb-1-i] -= b[i]-'0';
        // }
        // else out[sb-1-i]+=b[i]-'0';
    // }
    // // smooth out the sum
    // for (int i = 0; i < std::max(sa,sb); i++) {
        // while (out[i] < 0) {
            // out[i] += 10;
            // out[i+1]--;
        // }
        // while (out[i] > 9) {
            // out[i] -= 10;
            // out[i+1]++;
        // }
    // }
    // // print out the sum
    // if (out[std::max(sa,sb)]==-1) {
        // // is negative
        // std::cout << '-';
        // // now get the difference from zero
        // int diff[std::max(sa,sb)+1];
        // for (int i = 0; i <= std::max(sa,sb); i++) diff[i]=0;
        // for (int i = 0; i < std::max(sa,sb); i++) {
            // if (out[i] > 9) {
                // out[i] -= 10;
                // out[i+1]++;
            // }
            // if (out[i]==0) diff[i]=0;
            // else {
                // diff[i] = 10-out[i];
                // out[i] = 0;
                // out[i+1]++;
            // }
        // }
        // // print properly
        // int print = std::max(sa,sb)-1;
        // while (diff[print]==0&&print>0)print--;
        // for (int i = print; i>=0; i--) std::cout << diff[i];
    // }
    // else {
        // // is positive
        // int print = std::max(sa,sb);
        // while (out[print]==0&&print>0)print--;
        // for (int i = print; i>=0; i--) std::cout << out[i];
    // }
    // std::cout << "\n";
    // }
// }