#ifndef SPLICEDLIST_HPP
#define SPLICEDLIST_HPP

#include <iostream>
#include <unordered_map>

class SplicedListNonexistentKeyException : public std::exception
{
private:
    std::string message;

public:
    explicit SplicedListNonexistentKeyException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class SplicedNode
{
private:
public:
    SplicedNode(std::string str);
    ~SplicedNode();
    std::string str;
    SplicedNode *prev;
    SplicedNode *next;
};

class SplicedList
{
private:
    std::unordered_map<std::string, SplicedNode *> map;
    SplicedNode *head;
    SplicedNode *tail;
    int size;
    bool isEmpty();
    SplicedNode *pop(std::string &key);

public:
    SplicedList();
    ~SplicedList();
    bool exists(std::string &key);
    std::string popValue(std::string &key);
    void insert(std::string key, std::string *after = nullptr);
    std::pair<std::string *, size_t> getAll();
};

#endif