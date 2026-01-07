#include <iostream>
using namespace std;

int main() {
    int nBlocks, nFiles;
    cout << "Enter total number of disk blocks: ";
    cin >> nBlocks;

    int disk[50]; // assuming max 50 blocks
    for(int i=0; i<nBlocks; i++) disk[i] = -1; // -1 indicates free block

    cout << "Enter number of files: ";
    cin >> nFiles;

    for(int f=0; f<nFiles; f++){
        int size, start;
        cout << "\nFile " << f+1 << ":\n";
        cout << "Enter file size (in blocks): ";
        cin >> size;

        // 1. Sequential Allocation
        cout << "Enter starting block for sequential allocation: ";
        cin >> start;

        bool sequentialSuccess = true;
        for(int i=start; i<start+size; i++){
            if(i >= nBlocks || disk[i] != -1){
                sequentialSuccess = false;
                break;
            }
        }

        if(sequentialSuccess){
            for(int i=start; i<start+size; i++)
                disk[i] = f;
            cout << "Sequential Allocation successful at blocks: ";
            for(int i=start; i<start+size; i++)
                cout << i << " ";
            cout << endl;
        } else {
            cout << "Sequential Allocation failed (blocks not free or out of range).\n";
        }

        // 2. Linked Allocation
        int linkedBlocks[50]; // max 50 blocks per file
        bool linkedSuccess = true;
        cout << "Enter block numbers for linked allocation: ";
        for(int i=0; i<size; i++){
            int b; cin >> b;
            if(b < 0 || b >= nBlocks || disk[b] != -1){
                cout << "Block " << b << " not free or invalid. Skipping linked allocation.\n";
                linkedSuccess = false;
                break;
            }
            linkedBlocks[i] = b;
        }

        if(linkedSuccess){
            for(int i=0; i<size; i++)
                disk[linkedBlocks[i]] = f;
            cout << "Linked Allocation successful: ";
            for(int i=0; i<size; i++)
                cout << linkedBlocks[i] << " -> ";
            cout << "NULL\n";
        }

        // 3. Indexed Allocation
        int indexBlock[50]; // max 50 blocks per file
        bool indexSuccess = true;
        cout << "Enter block numbers for indexed allocation: ";
        for(int i=0; i<size; i++){
            int b; cin >> b;
            if(b < 0 || b >= nBlocks || disk[b] != -1){
                cout << "Block " << b << " not free or invalid. Skipping indexed allocation.\n";
                indexSuccess = false;
                break;
            }
            indexBlock[i] = b;
        }

        if(indexSuccess){
            for(int i=0; i<size; i++)
                disk[indexBlock[i]] = f;
            cout << "Indexed Allocation successful. Index block points to: ";
            for(int i=0; i<size; i++) cout << indexBlock[i] << " ";
            cout << endl;
        }
    }

    // Display disk usage
    cout << "\nDisk Block Status:\n";
    for(int i=0; i<nBlocks; i++)
        cout << "Block " << i << ": " << (disk[i]==-1?"Free":("File "+to_string(disk[i]))) << endl;

    return 0;
}
