#include "splicedList.hpp"
#include <iostream>
#include <cassert>

SplicedNode::SplicedNode(std::string str)
{
    this->str = str;
    this->prev = nullptr;
    this->next = nullptr;
}

SplicedNode::~SplicedNode()
{
}

SplicedList::SplicedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

SplicedList::~SplicedList()
{
    SplicedNode *curr = this->head;
    while (curr != nullptr)
    {
        SplicedNode *tmp = curr->next;
        delete curr;
        curr = tmp;
    }
}

bool SplicedList::isEmpty()
{
    assert(this->size >= 0);
    if (this->size == 0)
    {
        assert(this->head == nullptr && this->tail == nullptr);
    }
    else if (this->size > 0)
    {
        assert(this->head != nullptr && this->tail != nullptr);
    }
    return this->size == 0;
}

bool SplicedList::exists(std::string &key)
{
    if (this->isEmpty())
    {
        return false;
    }
    auto it = this->map.find(key);
    return it != this->map.end();
}

SplicedNode *SplicedList::pop(std::string &key)
{
    if (this->exists(key))
    {
        SplicedNode *result = this->map[key];
        SplicedNode *prev = result->prev;
        SplicedNode *next = result->next;
        if (result->str == this->head->str)
        {
            this->head = next;
        }
        if (result->str == this->tail->str)
        {
            this->tail = prev;
        }
        if (prev != nullptr)
        {
            prev->next = next;
        }
        if (next != nullptr)
        {
            next->prev = prev;
        }
        result->prev = nullptr;
        result->next = nullptr;
        this->size--;
        this->map.erase(key);
        return result;
    }
    else
    {
        throw SplicedListNonexistentKeyException("Key " + key + " does not exist!");
    }
}

std::string SplicedList::popValue(std::string &key)
{
    return this->pop(key)->str;
}

void SplicedList::insert(std::string key, std::string *after)
{
    if (this->isEmpty())
    {
        SplicedNode *node = new SplicedNode(key);
        this->head = node;
        this->tail = node;
        this->size++;
        this->map[key] = node;
    }
    else
    {
        try
        {
            SplicedNode *node = this->pop(key);
            if (after == nullptr || !this->exists(*after))
            {
                node->prev = this->tail;
                this->tail->next = node;
                this->tail = node;
            }
            else
            {
                SplicedNode *_next = this->map[*after];
                SplicedNode *_prev = _next->prev;
                node->next = _next;
                node->prev = _prev;
                _next->prev = node;
                if (_prev != nullptr)
                {
                    _prev->next = node;
                }
            }
            this->map[key] = node;
            this->size++;
        }
        catch (const SplicedListNonexistentKeyException &e)
        {
            SplicedNode *node = new SplicedNode(key);
            if (after == nullptr || !this->exists(*after))
            {
                node->prev = this->tail;
                this->tail->next = node;
                this->tail = node;
            }
            else
            {
                SplicedNode *_next = this->map[*after];
                SplicedNode *_prev = _next->prev;
                node->next = _next;
                node->prev = _prev;
                _next->prev = node;
                if (_prev != nullptr)
                {
                    _prev->next = node;
                }
            }
            this->map[key] = node;
            this->size++;
            while (this->head->prev != nullptr)
            {
                this->head = this->head->prev;
            }
        }
    }
}

std::pair<std::string *, size_t> SplicedList::getAll()
{
    int arr_size = this->size;
    std::string *arr = new std::string[arr_size];
    SplicedNode *curr = this->head;
    int index = 0;
    while (curr != nullptr)
    {
        arr[index] = curr->str;
        curr = curr->next;
        index++;
    }
    return {arr, arr_size};
}