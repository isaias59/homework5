
#include "list.hpp"
#include <iostream>
#include <cstring>

namespace list {

    Node* from_string(const char* s) {
        if (!s) return nullptr;
        Node* head = nullptr;
        Node* tail = nullptr;
        while (*s) {
            Node* new_node = new Node{ *s++, nullptr };
            if (!head) head = new_node;
            else tail->next = new_node;
            tail = new_node;
        }
        return head;
    }

    void free(Node* head) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print(std::ostream& out, Node* head) {
        while (head) {
            out << head->data;
            head = head->next;
        }
    }

    Node* copy(Node* head) {
        if (!head) return nullptr;
        Node* new_head = nullptr;
        Node* new_tail = nullptr;
        while (head) {
            Node* new_node = new Node{ head->data, nullptr };
            if (!new_head) new_head = new_node;
            else new_tail->next = new_node;
            new_tail = new_node;
            head = head->next;
        }
        return new_head;
    }

    /*int compare(Node* lhs, Node* rhs) {
        while (lhs && rhs && lhs->data == rhs->data) {
            lhs = lhs->next;
            rhs = rhs->next;
        }
        if (!lhs && !rhs) return 0; 
        if (!lhs) return -1; 
        if (!rhs) return 1; 
        return (lhs->data < rhs->data) ? -1 : 1;
    }*/
    int compare(Node* lhs, Node* rhs) {
        while (lhs && rhs) {
            if (lhs->data != rhs->data) {
                if (lhs->data < rhs->data) {
                    return -1;
                }
                else {
                    return 1;
                }
            }
            lhs = lhs->next;
            rhs = rhs->next;
        }

        if (lhs == rhs) {
            return 0; 
        }
        else if (lhs) {
            return 1; 
        }
        else {
            return -1; 
        }
    }
   
   int compare(Node* lhs, Node* rhs, int n) {
    while (n-- > 0 && lhs != nullptr && rhs != nullptr) {
        if (lhs->data != rhs->data) {
            return (lhs->data < rhs->data) ? -1 : 1;
        }
        lhs = lhs->next;
        rhs = rhs->next;
    }

    if (n < 0) {
        return 0; 
    } else if (lhs == nullptr && rhs != nullptr) {
        return -1; // lhs is shorter than rhs
    } else if (lhs != nullptr && rhs == nullptr) {
        return 1; 
    } else {
        return 0; 
    }
}

    int length(Node* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

   /* Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }*/

    Node* reverse(Node* head) {
        Node* new_head = nullptr;
        while (head) {
            Node* new_node = new Node{ head->data, nullptr };
            new_node->next = new_head;
            new_head = new_node;
            head = head->next;
        }
        return new_head;
    }

    Node* append(Node* lhs, Node* rhs) {
        if (!lhs) return copy(rhs);
        Node* head = copy(lhs);
        Node* tail = head;
        while (tail->next) tail = tail->next;
        tail->next = copy(rhs);
        return head;
    }

   
    int index(Node* head, Node* node) {
        int index = 0;

        while (head != nullptr && head != node) {
            head = head->next;
            index++;
        }

        if (head == nullptr) {
            return -1;
        }

        else {
            return index;
        }
    }

    Node* find_char(Node* head, char c) {
        while (head) {
            if (head->data == c) return head;
            head = head->next;
        }
        return nullptr;
    }

    Node* find_list(Node* haystack, Node* needle) {
        if (!needle) return haystack;
        Node* h = haystack;
        while (h) {
            Node* n = needle;
            Node* h2 = h;
            while (h2 && n && h2->data == n->data) {
                h2 = h2->next;
                n = n->next;
            }
            if (!n) return h;
            h = h->next;
        }
        return nullptr;
    }

    Node* nth(Node* head, int n) {
        while (n-- > 0 && head) {
            head = head->next;
        }
        return head;
    }

    Node* last(Node* head) {
        if (!head) return nullptr;
        while (head->next) {
            head = head->next;
        }
        return head;
    }

} 
