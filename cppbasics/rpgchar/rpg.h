#include <iostream>
#include <map>
#include <string>

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

    public: 
        character(){}

}; 