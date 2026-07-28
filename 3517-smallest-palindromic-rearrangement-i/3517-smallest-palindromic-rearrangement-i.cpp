class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> m;
        if(s.size()<4)return s;
        int i,n,a,b,j;
        char c='!';
        string ans;
        vector<int> v(26,0);
        for(i=0;i<s.size();i++){
             v[s[i]-'a']++;
        }
        for(i=0;i<26;i++){
            if(v[i]%2!=0){
                c=char(i+'a');
            }
            for(j=0;j<v[i]/2;j++){
              ans.push_back(char(i+'a'));
            }
        }
      string r=ans;
      if(c!='!')ans.push_back(c);
      reverse(r.begin(),r.end());
      return ans+r;

    }
};