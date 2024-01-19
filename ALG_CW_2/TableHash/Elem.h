//
// Created by motherlode on 22.12.22.
//

#ifndef ALG_CW_2_ELEM_H
#define ALG_CW_2_ELEM_H
#include "string"
class Elem {
private:
    std::string key;
    std::string value;
public:
    explicit Elem(std::string k, std::string v):key(k), value(v){}
    ~Elem() {key.clear(); value.clear();}
    std::string getKey() const {return key;}
    std::string getValue() const {return value;}
    void clear() {key.clear(); value.clear();}
    bool operator == (const Elem& other) {
        return (key == other.key && value == other.value);
    }
};


#endif //ALG_CW_2_ELEM_H
