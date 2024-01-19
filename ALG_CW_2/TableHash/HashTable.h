#ifndef ALG_CW_2_HASHTABLE_H
#define ALG_CW_2_HASHTABLE_H
#include "ChainList.h"
class HashTable {
private:
    int size = 1000;
    ChainList ** data_arr = nullptr;
    int count = 0;
public:
    explicit HashTable(){
        data_arr = new ChainList * [size];
        for(int i = 0; i < size; i++) {
            data_arr[i] = new ChainList();
        }
    }

    ~HashTable() {
        for(int i = 0; i < size; i++) {
            if(data_arr[i]->is_defined())
                delete data_arr[i];
        }
        delete [] data_arr;
    }

    void add(std::string key, std::string value, int &count_add) {
        int ind = hash(key);
        data_arr[ind]->addNode(Elem(key, value), count_add);
        count++;
    }

    void remove(std::string key, int& count_rm) {
        int id = hash(key);
        if(data_arr[id]->is_defined()) {
            data_arr[id]->remove(key, count, count_rm);
        }
    }

    std::string get_value(std::string key, int &counter) {
        int ind = hash(key);
        if(!data_arr[ind]->is_defined()) return "No_any";
        return (data_arr[ind]->getValue(key, counter)).getValue();
    }

    void print() {
        for(int i = 0; i < size; i++) {
            if(data_arr[i]->is_defined()) {
                std::cout<<"Coll"<<std::endl;
                data_arr[i]->print_all_list();
            }
        }
    }

    int get_size(){
        return count;
    }
private:
    long long hash(std::string s) {
        long long a = 0;
        for(int i = 0; i < s.size(); i++) {
            a *= 10;
            a += (int)s[i];
        }
        return a > 0 ? a % size : (-a) % size;
    }
};


#endif //ALG_CW_2_HASHTABLE_H
