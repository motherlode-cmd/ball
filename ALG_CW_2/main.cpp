#include <iostream>
#include "string"
#include "TableHash/HashTable.h"
#include "TableHash/GeneratorTests.h"
int main() {
    HashTable table;
    GeneratorTests test;
    test.test_add(table, 10, 15);
    test.count_find(table, 5);
    test.test_deleted(table, 5);
    return 0;
}
