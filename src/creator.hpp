#ifndef __CREATOR__H__
#define __CREATOR__H__

#include <iostream>
#include <random>
#include <memory>
#include <string>
#include <vector>

#include "initializer.hpp"

using std::wstring;
using std::vector;
using std::cout, std::endl;
using std::default_random_engine, std::uniform_int_distribution, std::uniform_real_distribution;
using std::random_device;
using std::shared_ptr, std::make_shared;

random_device __rd;

template<class T>
class creator;

template<class T>
class number_creator;

template<class T>
class real_creator;

template<class T>
class name_creator;



template<class T>
class creator {
public:

    creator(){};
    ~creator(){};

    virtual T create() {};

    static
    shared_ptr<creator<T>>  make_number_creator(T min, T max) {
        shared_ptr<number_creator<T>> nc =  make_shared<number_creator<T>>();
        nc->engine = default_random_engine(__rd());
        nc->distribution = uniform_int_distribution<T>(min, max);
        return nc;
    }

  /**
   *  make_real_creator.
   *  params(0.0, 1.0). only support float double
   *  number in the range [0, 1).
   */
    static
    shared_ptr<creator<T>>  make_real_creator(T min, T max) {
        shared_ptr<real_creator<T>> rc =  make_shared<real_creator<T>>();
        rc->engine = default_random_engine(__rd());
        rc->distribution = uniform_real_distribution<T>(min, max);
        return rc;
    }

    static
    shared_ptr<creator<T>>  make_name_creator() {
        shared_ptr<name_creator<T>> rc =  make_shared<name_creator<T>>();
        rc->engine = default_random_engine(__rd());
        return rc;
    }
};


template<class T>
class number_creator:public creator<T> {
public:

    // number_creator(){};
    // number_creator(number_creator *other) {
    //     engine = other->engine;
    //     distribution = other->distribution;
    // }

    default_random_engine engine; 
    uniform_int_distribution<T> distribution;

    T create() override {
        return distribution(engine);
    }
};

template<class T>
class real_creator :public creator<T> {
public:

    default_random_engine engine; 
    uniform_real_distribution<T> distribution;

    T create() override {
        return distribution(engine);
    }
};


const words first_name_words = initializer::name_creator();

template<class T>
class name_creator :public creator<T> {
private:
    uniform_int_distribution<uint> distribution;
public:
    default_random_engine engine; 

    name_creator() {
        this->distribution = uniform_int_distribution<uint>(0, uint(first_name_words.size()));
    }

    T create() override {
        return first_name_words[this->distribution(engine)];    
    }
};

#endif // !1