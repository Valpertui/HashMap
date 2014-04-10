//
//  main.cpp
//  HashMap
//
//  Created by Valentin Pertuisot on 23/02/14.
//  Copyright (c) 2014 Power. All rights reserved.
//

#include <iostream>
#include "HashMap.hpp"

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)(argv);
    HashMap<std::string> *stringMap = new HashMap<std::string>;
    std::string test = "test";
    std::string toto = "toto";
    stringMap->put(test, "titi");
    stringMap->put(toto, "toto");
    
    std::cout << stringMap->get(test) << " " << stringMap->get(toto) << std::endl;
    
    stringMap->put(test, "tata");
    std::cout << stringMap->get(test) << " " << stringMap->get(toto) << std::endl;
    stringMap->remove(test);
    stringMap->put(test, "tete");
    std::cout << stringMap->get(test) << " " << stringMap->get(toto) << std::endl;
    
    return 0;
}

