#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    string key;
    int value;
};

struct SymbolTable {
    Item arr[100];
    int n = 0; 

    void put(string k, int v) {
        
        for (int i = 0; i < n; i++)
            if (arr[i].key == k) { arr[i].value = v; return; }

        // th�m v�o ptu m?i v�o cu?i
        arr[n++] = { k, v };

        // gi? m?ng lu�n c� th? t?
        sort(arr, arr + n, [](Item a, Item b) { return a.key < b.key; });
    }

    
    int get(string k) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m].key == k) return arr[m].value;
            else if (arr[m].key < k) l = m + 1;
            else r = m - 1;
        }
        return -1; 
    }

   // x�a ptu
    void del(string k) {
        for (int i = 0; i < n; i++) {
            if (arr[i].key == k) {
                for (int j = i; j < n - 1; j++)
                    arr[j] = arr[j + 1];
                n--;
                return;
            }
        }
    }

    void print() {
        cout << "Symbol Table (Ordered Array): ";
        for (int i = 0; i < n; i++)
            cout << "(" << arr[i].key << "," << arr[i].value << ") ";
        cout << endl;
    }
};
