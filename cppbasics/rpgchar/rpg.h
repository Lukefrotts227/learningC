#include <iostream>
#include <map>
#include <string>
#include <vector> 

#define MAX_STATS 100.0
#define MIN_STATS 0.0




class description {
    public: 
        std::string desc1; 
        std::string desc2; 
        std::string desc3;

        description() {}
        description(std::string d1) : desc1(d1) {}

        friend std::ostream& operator<<(std::ostream& os, description& obj){
            os << obj.desc1; 
            return os; 
        }

}; 

std::map<std::string, description*> keywords; 


void key_init(){
    keywords["strength"] = new description("determines how strong the player is");
    keywords["speed"] = new description("determines how fast your player can move"); 
    keywords["durability"] = new description("determines the punishment your character can take");
    keywords["edurance"] = new description("determines your characters ability to endure long-term stuff");
    keywords["stamina"] = new description("determines how much physical energy your character has"); 
    keywords["agility"] = new description("determines how quick and agile your character is"); 
    keywords["dexterity"] = new description("determines you characters fine motor skills"); 
    keywords["intellect"] = new description("determines your characters overall intellect"); 
    keywords["willpower"] = new description("determines you characters strength of will"); 
    keywords["magic"] = new description("determines you characters magical aptitude"); 


}


class AttributeContainer {
    private:
        std::map<std::string, double> attributes;

    protected:
        bool checkAttribute(double value) {
            return (value <= MAX_STATS) && (value >= MIN_STATS);
        }

    public:
        AttributeContainer() {}

        void addToAttribute(const std::string& name, double value){
            if(checkAttribute(value+attributes[name])){
                attributes[name] += value; 
            }
        }

        void subtractFromAttribute(const std::string& name, double value){
            if(checkAttribute(attributes[name] - value)){
                attributes[name] -= value; 
            }
        }

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
        
        void operator=(const AttributeContainer& other){
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