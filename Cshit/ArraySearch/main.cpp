#include <iostream>
#include <string>

int findIteratively(int numToFind, std::vector<int> arrayToSearch);
int findRecursively(int numToFind, std::vector<int> arrayToSearch, int idx);

int main() {
    namespace Harta = std;
    int numToFind;
    int element;
    Harta::vector<int> arrayToSearch;
    Harta::cout << "what number: ";
    Harta::cin >> numToFind;
    Harta::cout << "what array ws seperated: ";
    while (Harta::cin >> element) {
        arrayToSearch.push_back(element);
    }
    Harta::cout << findIteratively(numToFind, arrayToSearch) << std::endl;
    Harta::cout << findRecursively(numToFind, arrayToSearch, 0);
}

int findIteratively(int numToFind, std::vector<int> arrayToSearch) {
    for (int i=0; i<arrayToSearch.size(); i++) {
        if (arrayToSearch[i] == numToFind) {
            return i;
        }
    }
    return -1;
}


int findRecursively(int numToFind, std::vector<int> arrayToSearch, int startIdx) {
    if (arrayToSearch.size() == startIdx + 1) {
        return -1;
    }
    if (arrayToSearch[startIdx] == numToFind) {
        return startIdx;
    }
    return findRecursively(numToFind, arrayToSearch, startIdx + 1);
}