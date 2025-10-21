#include "test.h"

void test_insert_map()
{
    cout << "Testing the Map Insert() function...." << endl; 

    Map<string, int> map; 
    map.Insert("Hello", 1); 
    assert(map.Size() == 1); 
    map.Insert("World", 2); 
    assert(map.Size() == 2); 
    map.Insert("three",3); 
    map.Insert("four", 4); 
    map.Insert("five", 5); 
    assert(map.Size() == 5); 

    cout << "All tests passed!" << endl; 
}

void test_erase_map()
{
    cout << "Testing the Map Erase() function......" << endl; 
    
    Map<int, int> map; 
    map.Erase(1); 
    assert(map.Size() == 0); 
    map.Insert(1,3); 
    map.Insert(2,4);
    map.Insert(3,7); 
    map.Insert(5,4); 
    map.Erase(1); 
    assert(map.Size() == 3);  

    cout << "All tests passed!!" << endl; 
}

void test_size_map()
{
    cout << "Testing the map Size() function...." << endl; 
    
    Map<int, int> map; 
    assert(map.Size() == 0); 
    map.Insert(1,3); 
    map.Insert(2,4);
    map.Insert(3,7); 
    map.Insert(5,4);
    assert(map.Size() == 4); 

    cout << "All tests passed!!" << endl; 
}

void test_find_map()
{
    cout << "Testing the map Find() function....." << endl; 
    
    Map<int, int> map; 
    assert(map.Find(1) == map.end()); 
    map.Insert(1,1); 
    map.Insert(2,2); 
    map.Insert(3,3); 
    map.Insert(4,4); 
    auto it = map.Find(2); 
    assert(it != map.end()); 

    cout << "All tests passed!!" << endl; 
}


void test_PushBack_vector()
{
    cout << "Testing the array PushBack() function....." << endl;
    
    Vector<int> a;
    a.PushBack(1);
    assert(a.Size() == 1); 
    a.PushBack(2); 
    a.PushBack(3); 
    a.PushBack(4); 
    assert(a.Size() == 4); 

    cout << "All tests passed!!" << endl;
}

void test_PopBack_vector()
{
    cout << "Testing the Vector PopBack() function" << endl; 

    Vector<int> a; 
    a.PopBack();
    assert(a.Size() == 0);
    a.PushBack(1); 
    a.PushBack(2); 
    a.PushBack(3); 
    a.PushBack(4); 
    a.PopBack(); 
    assert(a.Size() == 3); 

    cout << "All tests Passed!!" << endl;
}

void test_Clear_vector()
{
    cout << "Testing the Vector Clear() function...." << endl;
    
    Vector<int> a; 
    a.Clear(); 
    assert(a.Size() == 0);
    a.PushBack(1); 
    a.PushBack(2); 
    a.PushBack(3); 
    a.PushBack(4); 
    a.Clear(); 
    assert(a.Size() == 0); 

    cout << "All tests passed!!" << endl; 
}

void test_Size_vector()
{
    cout << "Testing the Vector Size() function...." << endl; 
    
    Vector<int> a; 
    assert(a.Size() == 0); 
    a.PushBack(1); 
    a.PushBack(2); 
    assert(a.Size() == 2); 

    cout << "All tests passed!!" << endl; 
}
