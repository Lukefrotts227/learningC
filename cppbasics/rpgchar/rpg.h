#include <iostream>
#include <map>
#include <string>
#include <vector> 

#define MAX_STATS 100.0
#define MIN_STATS 0.0




std::map<std::string, std::string> keywords; 


class AttributeContainer {
    private:
        std::map<std::string, double> attributes;

    protected:
        bool checkAttribute(double value) {
            return (value <= MAX_STATS) && (value >= MIN_STATS);
        }

    public:
        AttributeContainer() {}

        void setAttribute(const std::string& name, double value) {
            if (checkAttribute(value)) {
                attributes[name] = value;
            }
        }

        double getAttribute(const std::string& name) const {
            auto it = attributes.find(name);
            if (it != attributes.end()) {
                return it->second;
            }
            return -1.0;
        }
        
        AttributeContainer& operator=(const AttributeContainer& other){
            attributes = other.attributes; 
        }
};

class stats : public AttributeContainer {
    public:
        stats() {}
};

class skills : public AttributeContainer {
    public:
        skills() {}
};

class specials : public AttributeContainer {
    public:
        specials() {}
};

class weapon : public AttributeContainer{
    public: 
        weapon() {}
}; 

class clothing : public AttributeContainer{

    public: 
        clothing() {}
}; 

class item : public AttributeContainer{
    public: 
        item() {}
}; 

class morality : public AttributeContainer {
    public: 
        morality() {}
}; 

class character{
    private: 
        stats stat; 
        skills skill; 
        specials special; 
        morality moral;  
        std::vector<weapon> weapons; 
        std::vector<clothing> clothes; 
        std::vector<item> items; 

    public: 
        character(){}

        stats getStat() { return stat; }
        void setStat(stats s) { stat = s; }

        skills getSkill() { return skill; }
        void setSkill(skills s) { skill = s; }

        specials getSpecial() { return special; }
        void setSpecial(specials s) { special = s; }

        morality getMoral() { return moral; }
        void setMoral(morality m) { moral = m; }

        std::vector<weapon> getWeapons() { return weapons; }
        void setWeapons(std::vector<weapon> w) { weapons = w; }

        std::vector<clothing> getClothes() { return clothes; }
        void setClothes(std::vector<clothing> c) { clothes = c; }

        std::vector<item> getItems() { return items; }
        void setItem(std::vector<item> i) { items = i; }



}; 