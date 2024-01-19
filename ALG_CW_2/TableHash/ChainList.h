
#ifndef ALG_CW_2_CHAINLIST_H
#define ALG_CW_2_CHAINLIST_H
#include "string"
#include <iostream>
#include "Elem.h"
class ChainList {
private:
    ChainList * next = nullptr;
    Elem data = Elem("","");
    bool is_define = false;
public:
    ChainList() = default;
    explicit ChainList(Elem &elem) {
        next = nullptr;
        data = elem;
        is_define = true;
    }

    void addNode(Elem elem, int& counter_add) {
        if(data.getKey() == "" && data.getValue() == "") {
            this->data = elem;
        }
        else if(data.getKey() == elem.getKey()){
            data = elem;
        }
        else if(this->next == nullptr) {
            counter_add++;
            this->next = new ChainList(elem);
        }
        else {
            counter_add++;
            this->next->addNode(elem, counter_add);
        }
    }

    void remove(std::string key, int &count, int &count_rm) {
        if(data.getKey() == key) {
            count--;
            if(next != nullptr) {
                this->data = next->data;
                this->next = next->next;
            } else {
                data.clear();
            }
        } else {
            if(next != nullptr){
                count_rm++;
                next->remove(key, count, count_rm);
            }
        }
    }

    Elem getValue(std::string key, int &counter) const {
        if(data.getKey() == key) {
            return data;
        }
        else if(next != nullptr){
            counter++;
            return next->getValue(key, counter);
        }
        else return Elem(key,"Not Found\n");
    }

    ChainList * getNext() {
        if(next != nullptr) return next;
        return nullptr;
    }

    bool is_defined() {
        return data.getKey() != "" && data.getValue() != "";
    }
    ~ChainList() {
        if(next != nullptr) {
            delete next;
        }
    }

    void print_all_list() {
        std::cout<<data.getKey() << '-' << data.getValue() <<std::endl;
        if(next != nullptr) {
            next->print_all_list();
        }
    }
    void clear() {
        data.clear();
        if(next != nullptr) {
            next->clear();
        }
    }
};


#endif //ALG_CW_2_CHAINLIST_H
