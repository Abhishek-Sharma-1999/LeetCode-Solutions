class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkInMp;    //id-{entrystation,entryTime}
    unordered_map<string,pair<int,int>>checkOutMp;  //route-{totalTimeTaken,count}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &it=checkInMp[id];
        int entryTime=it.second;    //entry time kitna lga tha
        int timeTaken=t-entryTime;  //kitna time lga  (entryStation-FinalStation)
        string entryStation=it.first;
        string route=entryStation+"_"+stationName;
        checkOutMp[route].first+=timeTaken; //total time jo lag rha hai
        checkOutMp[route].second+=1; // no. of people  
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"_"+endStation;
        auto &it=checkOutMp[route];
        return (double)it.first/it.second;  // total time/no. of people
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */