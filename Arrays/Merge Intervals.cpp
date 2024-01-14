vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval>v;
    int n = intervals.size();
    int sm = newInterval.start;
    int em = newInterval.end;
    int x = min(sm,em);
    int y = max(sm,em);
    for(int i=0;i<n;i++){
        int si = intervals[i].start;
        int ei = intervals[i].end;
        if(x>=si && x<=ei){ 
            x=si;
        }else if(y>=si && y<=ei){ 
            y=ei;
        }else if(x<si && y<si){
            v.push_back(Interval(x,y));
            x=si;
            y=ei;
        }else if(x>ei){
            v.push_back(intervals[i]);
        }
    }
    v.push_back(Interval(x,y));
    return v;
}