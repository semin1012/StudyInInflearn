#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node(int data) : data(data), prev(nullptr), next(nullptr) { }

public:
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class List
{
public:
    List()
    {
        // dummy 노드 추가
        _head = new Node<T>(0);
        _tail = new Node<T>(0);
        _head->next = _tail;
        _tail->prev = _head;
    }

    ~List()
    {
        Node<T>* node = _head;
        while (node) // == (node != nullptr)
        {
            // node 를 바로 삭제시키면 다음으로 이동할 수 없기 때문에
            // 새로운 노드를 사용하여 삭제시키기
            Node<T>* deleteNode = node;
            node = node->next;
            delete deleteNode;
        }
    }

    // [dummy]<->[1]<->[2]<->[3]<->[dummy]
    // [head]                      [tail]
    // 데이터를 찾는 게 느리다. 처음부터 끝까지 봐야 하기 때문에.
    // 그럼 어떻게 중간 삽입/삭제가 빠르냐?

    Node<T>* GetNode(int index)
    {
        Node<T>* node = _head->next;
        if (node == _tail)
            return nullptr;

        for (int i = 0; i < index; i++)
        {
            if (node == _tail->prev) 
            {
                return nullptr;
            }
            node = node->next;
        }
        
        return node;
    }

    void Print()
    {
        Node<T>* node = _head->next;
        while (node != _tail)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }

    Node<T>* AddAtHead(int data)
    {
        //Node* node = new Node(data);

        // 더미 노드가 없을 떄의 코드
        // head 가 없다면 데이터가 아무것도 없다는 것이다
        // 따라서 새로 들어가는 데이터가 시작이자 마지막이 된다
        //if (_head == nullptr) 
        //{
        //    _head = node;
        //    _tail = node;
        //}
        //else
        //{
        //    // next, prev 설정 잊지 말 것
        //    Node* nextNode = _head;
        //    node->next = nextNode;
        //    nextNode->prev = node;
        //    _head = node;
        //}


        // 더미 노드가 있을 경우 if, else 없이 깔끔한 코드
        // head, tail 을 nullptr로 두는 게 아님 
        //       [node]
        // [dummy]<->[nextNode]<->[2]<->[3]<->[dummy]
        // [head]                       [tail]
        Node<T>* node = new Node<T>(data);
        Node<T>* nextNode = _head->next;

        node->next = nextNode;
        nextNode->prev = node;

        _head->next = node;
        node->prev = _head;

        return node;
    }

    //                                    [node]
    // [dummy]<->[1]<->[2]<->[prevNode]<->[dummy]
    // [head]                       [tail]
    Node* AddAtTail(int data)
    {
        Node<T>* node = new Node<T>(data);
        Node<T>* prevNode = _tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = _tail;
        _tail->prev = node;

        return node;
    }

    void Insert(Node<T>* posNode, int data)
    {
        Node<T>* node = new Node<T>(data);
        Node<T>* prevNode = posNode->prev;

        prevNode->next = node;
        node->prev = prevNode;
        node->next = posNode;
        posNode->prev = node;
    }

    Node* Remove(Node<T>* node)
    {
        Node<T>* prevNode = node->prev;
        Node<T>* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;

        return nextNode;
    }

private:
    Node<T>* _head = nullptr;
    Node<T>* _tail = nullptr;
};