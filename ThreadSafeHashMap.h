//
// Created by Fengwei Zhang on 10/25/22.
//

#ifndef ACWINGSOLUTION_THREADSAFEHASHMAP_H
#define ACWINGSOLUTION_THREADSAFEHASHMAP_H

#include<functional>
#include<mutex>
#include<utility>
#include<list>
#include<algorithm>
#include<iostream>
#include<vector>
#include<memory>
#include<map>

template<typename K, typename V, typename Hash = std::hash<K>>
class ThreadSafeHashMap {
private:
    class BucketType {
    public:
        typedef std::pair<K, V> BucketValue;
        typedef std::list<BucketValue> BucketData;
        typedef typename std::list<BucketValue>::iterator BucketIterator;
        BucketData mData;
        std::mutex mtx;
        
        bool checkIsFind(const BucketValue &bv, const K &key) {
            if (bv.first == key) {
                return true;
            }
            return false;
        }

        BucketIterator findByKey(const K &key) {
            //std::bind中的占位符_1，调用的时候由调用方传入，调用方传入的第一个参数替换_1
            //本里中调用方传入的是BucketValue
            auto it = std::find_if(this->mData.begin(), this->mData.end(),
                                   std::bind(&BucketType::checkIsFind, this, std::placeholders::_1,
                                             key));
            return it;
        }

        V get(const K &key, V defaultValue) {
            std::lock_guard<std::mutex> lk(this->mtx);
            BucketIterator it = this->findByKey(key);
            if (it != this->mData.end()) {
                return it->second;
            }
            return defaultValue;
        }

        void removeByKey(const K &key) {
            std::lock_guard<std::mutex> lk(this->mtx);
            BucketIterator it = this->findByKey(key);
            if (it != this->mData.end()) {
                this->mData.erase(it);
            }
        }

        void addOrUpdata(K key, V value) {
            std::lock_guard<std::mutex> lk(this->mtx);
            //std::cout << "addOrUpdata(K key, V value)开始" << std::endl;
            BucketIterator it = this->findByKey(key);
            if (it != this->mData.end()) { //找到了就更新
                //std::cout << "addOrUpdata(K key, V value)....找到了更新" << std::endl;
                *it = std::move(std::pair<K, V>(std::move(key), std::move(value)));
            } else { //没找到就插入
                //std::pair<K, V> p(std::move(key), std::move(value));
                //std::cout << "addOrUpdata(K key, V value)....未找到插入" << std::endl;
                this->mData.push_back(std::pair<K, V>(std::move(key), std::move(value)));
            }

        }


    };

public:
    ThreadSafeHashMap(int num = 19, Hash hasher = Hash()) {
        //this->mBuckets = std::vector<std::shared_ptr<BucketType>>(num);
        this->mHasher = std::move(hasher);
        for (int i = 0; i < num; i++) {
            this->mBuckets.push_back(std::shared_ptr<BucketType>(new BucketType));
        }
        //std::cout << "ThreadSafeHashMap()......mBuckets.size() = " << this->mBuckets.size() << std::endl;
    }

    virtual ~ThreadSafeHashMap() {

    }

    void addOrUpdateMy(K key, V value) {
        //std::shared_ptr<BucketType> sp = this->positeByHash(key);
        this->positeByHash(key)->addOrUpdata(key, value);
    }

    V getMy(const K &key, V value) {
        return this->positeByHash(key)->get(key, value);
    }

    void removeMy(const K &key) {
        this->positeByHash(key)->removeByKey(key);
    }

    /**
    * 这个需要要把每一个BucketType都锁住，防止获取的时候有BucketType在修改
    */
    std::map<K, V> getAll() {
        //将每一个BucketType都锁住
        std::vector<std::unique_lock<std::mutex>> mtxs;
        for (int i = 0; i < this->mBuckets.size(); i++) {
            mtxs.push_back(std::move(std::unique_lock<std::mutex>(this->mBuckets.at(i)->mtx)));
        }
        //循环遍历取出内容
        std::map<K, V> mapTmp;
        for (int i = 0; i < this->mBuckets.size(); i++) {
            std::shared_ptr<BucketType> sp = this->mBuckets.at(i);
            std::list<std::pair<K, V>> &bd = sp->mData;
            for (auto it = bd.begin(); it != bd.end(); it++) {
                mapTmp.insert(*it);
            }
        }
        return mapTmp;

    }

private:
    /**
    * 根据key计算hash值，根据hash值计算在vecotr中对应位置的BucketType
    */
    std::shared_ptr<BucketType> positeByHash(const K &key) {
        std::size_t h = this->mHasher(key) % this->mBuckets.size();
        //std::cout << "positeByHash(const K& key)....h = " << h << std::endl;
        //std::cout << "this->mBuckets.size() = " << this->mBuckets.size() << std::endl;
        return this->mBuckets.at(h);
    }

    std::vector<std::shared_ptr<BucketType>> mBuckets;
    Hash mHasher;
};

#endif //ACWINGSOLUTION_THREADSAFEHASHMAP_H
