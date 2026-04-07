class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,int> indegree;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                indegree[words[i][j]]=0;
            }
        }
        
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<words.size()-1;i++){
            bool flag=false;
            int len = min(words[i].size(), words[i+1].size());
            for(int j=0;j<len;j++){
                if(words[i][j]!=words[i+1][j]){
                    adj[words[i][j]].push_back(words[i+1][j]);
                    indegree[words[i+1][j]]++;
                    flag=true;//jaise hi matches break
                    break;
                }
            }
            if(!flag && words[i].size()>words[i+1].size()) return "";
        }
        
        queue<char> q;
        for(auto it:indegree){
            if(it.second==0){
                q.push(it.first);
            }
        }
        string ans="";
        while(!q.empty()){
            char node=q.front();
            q.pop();
            ans+=node;
            for(auto nei:adj[node]){
                if(indegree[nei]>0){
                    indegree[nei]--;
                }
                if(indegree[nei]==0){
                    q.push(nei);
                }   
            }
        }
        if(ans.size()!=indegree.size()) return "";
        else return ans;

    }
};
