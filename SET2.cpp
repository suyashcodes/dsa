#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Set {
private:

public:
    list<int> elements;
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
    void Print() const {
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
            if (find(result.begin(), result.end(), element) == result.end()) {
                result.push_back(element);
            }
        }

        // Add all unique elements from set2
        for (int element : set2) {
            if (find(result.begin(), result.end(), element) == result.end()) {
                result.push_back(element);
            }
        }
    }

    // Calculate the intersection of two sets (pass two sets and a result list)
    static void Intersection(const list<int>& set1, const list<int>& set2, list<int>& result) {
        result.clear(); // Clear the result list before adding elements

        // Find common elements in both sets
        for (int element : set1) {
            if (find(set2.begin(), set2.end(), element) != set2.end()) {
                result.push_back(element);
            }
        }
    }

    // Calculate the difference of two sets (pass two sets and a result list)
    static void Difference(const list<int>& set1, const list<int>& set2, list<int>& result) {
        result.clear(); // Clear the result list before adding elements

        // Find elements in set1 that are not in set2
        for (int element : set1) {
            if (find(set2.begin(), set2.end(), element) == set2.end()) {
                result.push_back(element);
            }
        }
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
    for (int elem : setA) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set B: ";
    for (int elem : setB) {
        cout << elem << " ";
    }
    cout << endl;

    // Union
    list<int> unionResult;
    Set::Union(setA, setB, unionResult);
    cout << "Union of Set A and Set B: ";
    for (int elem : unionResult) {
        cout << elem << " ";
    }
    cout << endl;

    // Intersection
    list<int> intersectionResult;
    Set::Intersection(setA, setB, intersectionResult);
    cout << "Intersection of Set A and Set B: ";
    for (int elem : intersectionResult) {
        cout << elem << " ";
    }
    cout << endl;

    // Difference A - B
    list<int> differenceAB;
    Set::Difference(setA, setB, differenceAB);
    cout << "Difference of Set A - Set B: ";
    for (int elem : differenceAB) {
        cout << elem << " ";
    }
    cout << endl;

    // Difference B - A
    list<int> differenceBA;
    Set::Difference(setB, setA, differenceBA);
    cout << "Difference of Set B - Set A: ";
    for (int elem : differenceBA) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
