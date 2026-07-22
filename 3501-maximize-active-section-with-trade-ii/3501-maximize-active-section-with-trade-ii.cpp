class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();
        int one = 0;

        for(char ch : s)
        {
            if(ch == '1')
                one++;
        }

        vector<int> st;
        vector<int> len;
        vector<int> idx(n);

        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(i > 0 && s[i - 1] == '0')
                {
                    len.back()++;
                }
                else
                {
                    st.push_back(i);
                    len.push_back(1);
                    cnt++;
                }
            }

            idx[i] = cnt - 1;
        }

        vector<int> ans;

        if(cnt == 0)
        {
            for(int i = 0; i < queries.size(); i++)
                ans.push_back(one);

            return ans;
        }

        int m = cnt - 1;
        vector<vector<int>> table;

        if(m > 0)
        {
            vector<int> base(m);

            for(int i = 0; i < m; i++)
                base[i] = len[i] + len[i + 1];

            int lg = 32 - __builtin_clz(m);

            table.resize(lg);
            table[0] = base;

            for(int k = 1; k < lg; k++)
            {
                int jump = 1 << (k - 1);
                int sz = m - (1 << k) + 1;

                table[k].resize(sz);

                for(int j = 0; j < sz; j++)
                    table[k][j] = max(table[k - 1][j], table[k - 1][j + jump]);
            }
        }

        for(auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int lg = idx[l];
            int rg = idx[r];

            int left = -1;
            int right = -1;

            if(lg != -1)
                left = len[lg] - (l - st[lg]);

            if(rg != -1)
                right = r - st[rg] + 1;

            int last;

            if(s[r] == '1')
                last = rg;
            else
                last = rg - 1;

            int start = lg + 1;
            int end = last - 1;

            int curr = one;

            if(s[l] == '0' && s[r] == '0' && lg + 1 == rg)
            {
                curr = max(curr, one + left + right);
            }
            else if(start <= end)
            {
                int k = 31 - __builtin_clz(end - start + 1);

                int best = max(table[k][start],
                               table[k][end - (1 << k) + 1]);

                curr = max(curr, one + best);
            }

            if(s[l] == '0' && lg + 1 <= last)
                curr = max(curr, one + left + len[lg + 1]);

            if(s[r] == '0' && lg < rg - 1)
                curr = max(curr, one + right + len[rg - 1]);

            ans.push_back(curr);
        }

        return ans;
    }
};