class FoodRatings {
public:
    map<string,set<pair<int,string>>> s;
    unordered_map<string,string> abcd;
    unordered_map<string,int> rat;
    FoodRatings(vector<string>& ff, vector<string>& str, vector<int>& rate) {
        int i=0;
        while(i<ff.size())
        {
            s[str[i]].insert({-rate[i],ff[i]});
            abcd[ff[i]]=str[i];
            rat[ff[i]]=-rate[i];
            i++;
        }
    }
    void change(string food, int newRating){
        int r=rat[food];
        string c=abcd[food];
        s[c].erase({r,food});
        s[c].insert({-newRating,food});
        rat[food]=-newRating;
    }
    void changeRating(string food, int newRating) {
        change(food,newRating);
    }
    
    string highestRated(string cuisine) {
        pair<int,string> p= *(s[cuisine].begin());
        return p.second;
    }
};