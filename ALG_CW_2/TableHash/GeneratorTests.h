//
// Created by motherlode on 22.12.22.
//

#ifndef ALG_CW_2_GENERATORTESTS_H
#define ALG_CW_2_GENERATORTESTS_H
#include "HashTable.h"
#include "vector"
class GeneratorTests {
private:
    std::vector <std::string> genericKeys;
    int absolut(int a){return a > 0 ? a : -a;}
    std::string gen_key(int max_len) {
        std::string current_key;
        for(int j = 0; j < absolut(rand()) % max_len; j++) {
            current_key += (char)absolut(rand()%(126-38) + 38);
        }
        return  current_key;
    }
public:
    void test_add(HashTable& table, int count, int max_len) {
        int count_add = 1;
        for(int i = 0; i < count; i++) {
            std::string current_key = gen_key(max_len);
            std::string current_value = "Value" + std::to_string(i);
            table.add(current_key, current_value, count_add);
            std::cout<<"Add_key "<< current_key <<' '<< i <<' '<< count_add << std::endl;
            genericKeys.push_back(current_key);
            count_add = 1;
        }
    }
    void count_find(HashTable& table, int counter) {
        int count_find = 1;
        for(int i = 0; i < counter; i++) {
            int current_key = absolut(rand()) % genericKeys.size();
            table.get_value(genericKeys[current_key], count_find);
            std::cout<<"Find_key "<<genericKeys[current_key] << ' '<< i << ' '<< count_find << std::endl;
            count_find = 1;
        }
    }

    void test_deleted(HashTable& table, int counter) {
        int count_remove = 1;
        for(int i = 0; i < counter; i++) {
            int current_key = absolut(rand()) % genericKeys.size();
            table.remove(genericKeys[current_key], count_remove);
            std::cout<<"Remove_key "<<genericKeys[current_key] << ' '<< i << ' '<< count_remove << std::endl;
            count_remove = 1;
        }
    }
};


#endif //ALG_CW_2_GENERATORTESTS_H
