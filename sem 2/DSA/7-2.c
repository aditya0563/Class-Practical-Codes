#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Define the size of the hash table

// Hash table structure
typedef struct {
    int table[TABLE_SIZE];
} HashTable;

// Function to initialize the hash table
void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = -1; // Initialize table entries to -1 (indicating empty slots)
    }
}

// Hash function to map keys to indices
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert an element into the hash table
void insert(HashTable* ht, int key) {
    int index = hashFunction(key);

    // Linear probing to handle collisions
    while (ht->table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    ht->table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Function to search for an element in the hash table
int search(HashTable* ht, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    // Linear probing to handle collisions
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) {
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
void printTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != -1) {
            printf("%d --> %d\n", i, ht->table[i]);
        } else {
            printf("%d --> \n", i);
        }
    }
}

int main() {
    HashTable ht;
    initHashTable(&ht);

    // Insert elements into the hash table
    insert(&ht, 23);
    insert(&ht, 34);
    insert(&ht, 45);
    insert(&ht, 56);
    insert(&ht, 67);
    insert(&ht, 78);
    insert(&ht, 89);
    insert(&ht, 90);
    insert(&ht, 12);
    insert(&ht, 34); // This will cause a collision and will be resolved using linear probing

    // Print the hash table
    printf("Hash Table:\n");
    printTable(&ht);

    // Search for elements in the hash table
    int key = 45;
    int index = search(&ht, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }

    key = 99;
    index = search(&ht, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }

    return 0;
}
