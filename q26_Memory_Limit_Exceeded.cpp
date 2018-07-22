class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        if(words.size()==0) return r;
        unordered_map<int,vector<int>> patt;
        int end=s.size();
        
        for(int i=0;i<words.size();++i){
            int found=s.find(words[i]);
            end-=words[i].size();
            while(found!=string::npos){
                patt[found].push_back(i+1);
                found=s.find(words[i],found+1);
            }
        }
        for(int i=0;i<=end;++i){
            if(patt[i].size()==0) continue;
            int drop(0),posi(i);
            int* flags=new int[words.size()]();
            for(int j=0;j<words.size();++j){
                if(patt[posi].size()){
                    if(flags[patt[posi][0]-1]==patt[posi].size()){
                        drop=1;
                        break;
                    }
                    flags[patt[posi][0]-1]+=1;
                    posi+=words[patt[posi][0]-1].size();
                    continue;
                }
                drop=1;
                break;
            }
            if(drop) {
                delete(flags);
                continue;
            }
            r.push_back(i);
            delete(flags);
        }
        return r;
    }
};
