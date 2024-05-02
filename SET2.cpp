#include <iostream>
#include<bits/stdc++.h>
#include <list>

using namespace std;

class Set {
private:
    list<int> elements;

public:
    // Add element to the set
    void Add(int element) {
        // Check for duplicates before adding
        if (find(elements.begin(), elements.end(), element) != elements.end()) {
            return; // Duplicate element, do nothing
        }
        elements.push_back(element);
    }

    // Remove element from the set
    bool Remove(int element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it == elements.end()) {
            return false; // Element not found
        }
        elements.erase(it);
        return true;
    }

    // Search for element in the set
    bool Search(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Print the elements of the set
    void Print() {
        if (elements.empty()) {
            cout << "Empty set" << endl;
            return;
        }
        cout << "{ ";
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            cout << *it << (next(it) == elements.end() ? " }" : ", ");
        }
        cout << endl;
    }

    // Calculate the union of two sets (pass two sets and a result list)
    static void Union(const list<int>& set1, const list<int>& set2, list<int>& result) {
        result.clear(); // Clear the result list before adding elements

        // Add all unique elements from set1
        for (int element : set1) {
            if (!exists(result.begin(), result.end(), element)) {
                result.push_back(element);
            }
        }

        // Add all unique elements from set2
        for (int element : set2) {
            if (!exists(result.begin(), result.end(), element)) {
                result.push_back(element);
            }
        }
    }

    // Calculate the intersection of two sets (pass two sets and a result list)
    static void Intersection(const list<int>& set1, const list<int>& set2, list<int>& result) {
        result.clear(); // Clear the result list before adding elements

        // Find common elements in both sets
        for (int element : set1) {
            if (exists(set2.begin(), set2.end(), element)) {
                result.push_back(element);
            }
        }
    }

    // Calculate the difference of two sets (pass two sets and a result list)
    static void Difference(const list<int>& set1, const list<int>& set2, list<int>& result) {
        result.clear(); // Clear the result list before adding elements

        // Find elements in set1 that are not in set2
        for (int element : set1) {
            if (!exists(set2.begin(), set2.end(), element)) {
                result.push_back(element);
            }
        }
    }

private:
    // Helper function to check if an element exists in a list
    static bool exists(const list<int>::iterator begin, const list<int>::iterator end, int element) {
        for (auto it = begin; it != end; ++it) {
            if (*it == element) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    list<int> setA;
    setA.push_back(1);
    setA.push_back(3);
    setA.push_back(5);

    list<int> setB;
    setB.push_back(2);
    setB.push_back(3);
    setB.push_back(4);

    cout << "Set A: ";
    setA.Print();

    cout << "Set B: ";
    setB.Print();

    cout << "Search for 4 in Set A: " << (Set::Search(setA, 4) ? "Found" : "Not Found") << endl;
    return 0;
}