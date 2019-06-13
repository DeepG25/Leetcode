//Solution 
//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> S;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i] == "C")
            {
                S.pop();
            }
            else if(ops[i] == "D")
            {
                int top = S.top();
                S.push(2*top);
            }
            else if(ops[i] == "+")
            {
                int top = S.top();
                S.pop();
                int top_next = S.top();
                S.push(top);
                S.push(top + top_next);
            }
            else
            {
                int x = stoi(ops[i]);
                S.push(x);
            }
        }
        int sum = 0;
        while(!S.empty())
        {
            sum = sum + S.top();
            S.pop();
        }
        return sum;
    }
};
