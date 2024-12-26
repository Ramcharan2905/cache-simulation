#include <bits/stdc++.h>
#include <unistd.h> 
#include <random>
using namespace std;

class CacheBlock
{
public:
    unsigned long long tag;
    int state; // I->0, V->1, MP->2
    vector<int> data;

    CacheBlock(unsigned long long tag = 0, int state = 0, int wordsInBlock = 0)
    {
        this->tag = tag;
        this->state = state;

        data.resize(wordsInBlock);
    }
};

class SetAssociativeCache
{
public:
    int cacheSize;
    int blockSize;
    int associativity;
    int numBlocks;
    int numSets;
    int offsetBits;
    int indexBits;
    int tagBits;
    double hitCount;
    double missCount;
    vector<vector<CacheBlock>> cache;

    SetAssociativeCache(int cacheSize, int blockSize, int associativity, int paBits)
    {
        this->cacheSize = cacheSize;
        this->blockSize = blockSize;
        this->associativity = associativity;

        numBlocks = cacheSize / blockSize;
        numSets = numBlocks / associativity;
        offsetBits = log2(blockSize);
        indexBits = log2(numSets);
        tagBits = paBits - indexBits - offsetBits;

        this->hitCount = 0;
        this->missCount = 0;

        cache.resize(numSets, vector<CacheBlock>(associativity, CacheBlock(0, 0, blockSize / sizeof(int))));
    }

    int log2(int x)
    {
        int res = 0;
        while (x >>= 1)
            ++res;

        return res;
    }

    pair<int, unsigned long long> getIdxAndTag(unsigned long long address)
    {
        int index = (address >> offsetBits) & ((1 << indexBits) - 1);
        unsigned long long tag = address >> (offsetBits + indexBits);

        return {index, tag};
    }

    CacheBlock *Eviction(vector<CacheBlock> &cacheSet)
    {
        for (auto &block : cacheSet)
        {
            if (block.state == 0) 
                return &block;
        }
        
        int randomIndex = rand() % associativity;
        return &cacheSet[randomIndex];
    }

    void BlockAccessReplacement()
    {
        // Placeholder for any replacement information update if needed
    }

    void access(unsigned long long address, bool isWrite)
    {
        auto res = getIdxAndTag(address);
        int index = res.first;
        unsigned long long tag = res.second;

        auto &cacheSet = cache[index];

        for (auto &block : cacheSet)
        {
            if (block.tag == tag && block.state == 1)
            {
                // Cache hit
                hitCount++;
                cout << "Cache hit\n";
                if (isWrite)
                {
                    cout << "Write-through: Write data in cache and main memory." << endl;
                    sleep(1); // Simulate memory operation delay
                }
                else
                    cout << "Read hit: Data found in cache." << endl;

                return;
            }
        }

        // Cache miss
        missCount++;
        cout << "Cache miss\n";
        if (!isWrite)
        {
            CacheBlock *B = Eviction(cacheSet); 

            B->tag = tag;
            B->state = 2; // Memory Pending

            BlockAccessReplacement();

            cout << "Fetching data from memory into cache for read miss\n";
            sleep(1); // Simulate memory fetch delay
            B->state = 1; 
        }
        else
        {
            cout << "Write miss (No-write-allocate): Write directly to main memory." << endl;
            sleep(1); // Simulate memory write delay
        }
    }

    double getHitRate() 
    {
        return (hitCount) / (hitCount + missCount) * 100;
    }
};

int main()
{
    srand(time(0));

    int cacheSize = 32 * 1024; 
    int blockSize = 64;        
    int associativity = 8;     
    int paBits = 40;           

    SetAssociativeCache cache(cacheSize, blockSize, associativity, paBits);

    const int numAccesses = 100; 

    unsigned long long baseAddress = 0x123456789; 
    std::default_random_engine generator(time(0));
    std::normal_distribution<double> distribution(baseAddress, 100); // mean=baseAddress, stddev=100
    for (int i = 0; i < numAccesses; i++)
    {
        unsigned long long address = static_cast<unsigned long long>(distribution(generator));

        bool isWrite = rand() % 2; 
        cout << "Accessing address: 0x" << hex << address << dec << (isWrite ? " (Write)" : " (Read)") << endl;

        cache.access(address, isWrite);
    }

    cout << "\nCache Hit Rate: " << cache.getHitRate() << "%\n";

    return 0;
}