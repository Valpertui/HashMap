//
//  HashMap.h
//  HashMap
//
//  Created by Valentin Pertuisot on 23/02/14.
//  Copyright (c) 2014 Power. All rights reserved.
//

#ifndef __HashMap__HashMap__
#define __HashMap__HashMap__

#include <iostream>
#include "HashEntry.hpp"
#define DEFAULT_HASHMAP_SIZE    32

template<class V>
class           HashMap
{
private:
    HashEntry<std::string, V>     *hashMap[DEFAULT_HASHMAP_SIZE][DEFAULT_HASHMAP_SIZE];
    unsigned int        size;
public:
    HashMap() : size(DEFAULT_HASHMAP_SIZE)
    {
    }
    
    void     put(const std::string &key, V value)
    {
        int hash = this->hashFunc(key);
        unsigned int i = 0;
        while (hashMap[hash][i] != NULL && hashMap[hash][i]->getKey() != key)
        {
            if (i + 1 >= size)
                return ;
            ++i;
        }
        hashMap[hash][i] = new HashEntry<std::string, V>(key, value);
        
    }
    
    V                   get(const std::string& key) const
    {
        int hash = this->hashFunc(key);
        unsigned int i = 0;
        while (hashMap[hash][i])
        {
            if (hashMap[hash][i]->getKey() == key)
                return hashMap[hash][i]->getValue();
            ++i;
        }
        return (nullptr);
    }
    
    void                remove(const std::string& key)
    {
        int hash = this->hashFunc(key);
        unsigned int i = 0;
        while (hashMap[hash][i])
        {
            if (hashMap[hash][i]->getKey() == key)
            {
                delete hashMap[hash][i];
                hashMap[hash][i] = nullptr;
                return ;
            }
        ++i;
        }
    }
    
    int                 hashFunc(const std::string& key) const
    {
        return (this->Murmur3_32(key.c_str(), (uint32_t) key.length(), 10) % this->size);
    }
    
    uint32_t Murmur3_32(const char* key, uint32_t len, uint32_t seed) const
    {
        static const uint32_t c1 = 0xcc9e2d51;
        static const uint32_t c2 = 0x1b873593;
        static const uint32_t r1 = 15;
        static const uint32_t r2 = 13;
        static const uint32_t m = 5;
        static const uint32_t n = 0xe6546b64;
        
        uint32_t hash = seed;
        
        uint32_t* keydata = (uint32_t*) key; //used to extract 32 bits at a time
        int keydata_it = 0;
        
        while (len >= 4)
        {
            uint32_t k = keydata[keydata_it++];
            len -= 4;
            
            k *= c1;
            k = (k << r1) | (k >> (32-r1));
            k *= c2;
            
            hash ^= k;
            hash = ((hash << r2) | (hash >> (32-r2)) * m) + n;
        }
        
        const uint8_t * tail = (const uint8_t*)(keydata + keydata_it*4);
        uint32_t k1 = 0;
        
        switch(len & 3) {
            case 3:
                k1 ^= tail[2] << 16;
            case 2:
                k1 ^= tail[1] << 8;
            case 1:
                k1 ^= tail[0];
                
                k1 *= c1;
                k1 = (k1 << r1) | (k1 >> (32-r1));
                k1 *= c2;
                hash ^= k1;
        }
        
        hash ^= len;
        hash ^= (hash >> 16);
        hash *= 0x85ebca6b;
        hash ^= (hash >> 13);
        hash *= 0xc2b2ae35;
        hash ^= (hash >> 16);
        return hash;
    }
};

#endif /* defined(__HashMap__HashMap__) */
