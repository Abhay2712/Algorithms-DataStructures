class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> s{folder[0]};
        for(int i=1; i<folder.size(); i++)
        {
            auto& f = folder[i];
            string& last = s.back();

            if(f.size() > last.size() &&
               f[last.size()] == '/' && 
               f.compare(0, last.size(), last) == 0)
                continue;

            s.push_back(f);
        }
        return s;
    }
};