#pragma once
#include <vector>
#include "ListNode.h"

ListNode* result;

class MergeSortRecursion {
public:
    MergeSortRecursion() {};
    virtual ~MergeSortRecursion() {};

    static void insert(int v,ListNode* res){
        if(res->next == nullptr || res->next->val >= v ){
            ListNode* n = new ListNode(v);
            n->next = res->next;//���������� ���������
            res->next = n;
            return;
        }
        insert(v,res->next);
    }

    static void recursNode(ListNode* inNode){
        if(inNode == nullptr)return;//���������� � ���������� �� ����������� �������
        recursNode(inNode->next);
        insert(inNode->val,result);
    }

    static void conductor(const std::vector<ListNode*>&inVec){
        for(auto n : inVec){ //�������� �� ������� � ���������� �� ��������, ���� �� "nullptr"
            if(n == nullptr) continue;
            else{
                if(result == nullptr)result = n; //��� ����� � �������. ������
                else recursNode(n);
            }
        }
    }
    // Task #1
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        result = nullptr;
        std::vector<ListNode*> vecTwoNode {l1,l2};//������� �������, ���-�� ������������ ����� ������
        conductor(vecTwoNode);
        return result;
    }
    // Task #2
    static ListNode* mergeThreeLists(ListNode* l1, ListNode* l2, ListNode* l3) {
        result = nullptr;
        std::vector<ListNode*> vecThreeNode {l1,l2,l3};
        conductor(vecThreeNode);
        return result; // Please implement
    }
};
