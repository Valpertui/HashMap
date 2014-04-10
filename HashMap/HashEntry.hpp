//
//  HashEntry.h
//  HashMap
//
//  Created by Valentin Pertuisot on 23/02/14.
//  Copyright (c) 2014 Power. All rights reserved.
//

#ifndef __HashMap__HashEntry__
#define __HashMap__HashEntry__

#include <iostream>

template <class K, class V>
class       HashEntry
{
private:
    K       key;
    V       value;
public:
    HashEntry()
    {
    };
    HashEntry(const K& key, const V& value) : key(key), value(value)
    {
    };
    
    K       getKey() const
    {
        return key;
    };
    
    void    setKey(const K& key)
    {
        this->key = key;
    };
    
    V       getValue() const
    {
        return value;
    };
    
    void    setValue(const V& value)
    {
        this->value = value;
    }
};

#endif /* defined(__HashMap__HashEntry__) */
