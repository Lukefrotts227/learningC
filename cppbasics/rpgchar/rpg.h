#include <iostream> 
#include <vector> 
#include <string> 
#include <map> 


#define MAX_STATS 100.0
#define MIN_STATS 0.0

using namespace std; 

class stats {
private:
    map<std::string, double> statistics;

public:
    stats() {}

    bool statCheck(double stat) {
        return (stat <= MAX_STATS) && (stat >= MIN_STATS);
    }

    void setStat(const string& name, double value) {
        if (statCheck(value)) {
            statistics[name] = value;
        }
    }

    double getStat(const string& name) const {
        auto it = statistics.find(name);
        if (it != statistics.end()) {
            return it->second;
        }
        return 0.0;
    }
};


class skills{
    private: 

    public: 
}; 


class specials{
    private: 

    public: 
}; 

class weapon{
    private: 

    public: 


}; 

class clothing{
    private: 

    public: 
}; 

class item{
    private: 

    public: 
}; 