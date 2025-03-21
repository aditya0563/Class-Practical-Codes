#include <iostream>
using namespace std;

#define TABLE_SIZE 10 // Define the size of the hash table

// Hash table class
class HashTable {
    int* table;

public:
    HashTable() {
        table = new int[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1; // Initialize table entries to -1 (indicating empty slots)
        }
    }

    // Hash function to map keys to indices
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Function to insert an element into the hash table
    void insert(int key) {
        int index = hashFunction(key);

        // Linear probing to handle collisions
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Function to search for an element in the hash table
    int search(int key) {
        int index = hashFunction(key);

        // Linear probing to handle collisions
        int originalIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return index;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }

        return -1; // Key not found
    }

    // Function to print the hash table
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                cout << i << " --> " << table[i] << endl;
            } else {
                cout << i << " --> " << endl;
            }
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht;

    // Insert elements into the hash table
    ht.insert(23);
    ht.insert(34);
    ht.insert(45);
    ht.insert(56);
    ht.insert(67);
    ht.insert(78);
    ht.insert(89);
    ht.insert(90);
    ht.insert(12);
    ht.insert(34); // This will cause a collision and will be resolved using linear probing

    // Print the hash table
    cout << "Hash Table:" << endl;
    ht.printTable();

    // Search for elements in the hash table
    int key = 45;
    int index = ht.search(key);
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found" << endl;
    }

    key = 99;
    index = ht.search(key);
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found" << endl;
    }

    return 0;
}
