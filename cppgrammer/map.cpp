#include <iostream>
#include <map>

using namespace std;

map<string, int> testMap;

int main()
{
    // insert
    testMap.insert(make_pair("A", 1));
    testMap.insert(make_pair("B", 5));
    testMap.insert(make_pair("C", 8));

    // map can't find by the index but only by the key
    cout << testMap["C"] << endl;

    // check if the key exists in the map
    if(testMap.count("G") == 0){
        cout << "there's nothing for G" << endl;
    }

    // count
    cout << testMap.count("B") << endl;

    return 0;
}