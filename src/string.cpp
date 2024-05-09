#include "string.h"
#include <iostream>


char* nodeToString(list::Node* head) {
    int length = list::length(head);
    char* str = new char[length + 1];
    char* temp = str;
    while (head) {
        *temp++ = head->data;
        head = head->next;
    }
    *temp = '\0';
    return str;
}

String::String(const char* s) {
    head = list::from_string(s);
}

String::String(const String& s) {
    head = list::copy(s.head);
}

String::String(String&& s) : head(s.head) {
    s.head = nullptr;
}

String& String::operator=(const String& s) {
    if (this != &s) {
        list::free(head);
        head = list::copy(s.head);
    }
    return *this;
}

String& String::operator=(String&& s) {
    if (this != &s) {
        list::free(head);
        head = s.head;
        s.head = nullptr;
    }
    return *this;
}

String::~String() {
    list::free(head);
}

void String::swap(String& s) {
    std::swap(head, s.head);
}

bool String::in_bounds(int index) const {
    return index >= 0 && index < size();
}




char String::operator[](int index) const {
    list::Node* node = list::nth(head, index);
    if (node != nullptr) {
        return node->data;
    }
    else {
        return '\0';
    }
}



int String::size() const {
    return list::length(head);
}


String String::reverse() const {
    list::Node* reversed_head = list::reverse(head);
    return String(reversed_head); 


int String::indexOf(char c) const {
    list::Node* node = list::find_char(head, c);
    return list::index(head, node);
}

int String::indexOf(const String& s) const {
    list::Node* node = list::find_list(head, s.head);
    return list::index(head, node);
}

bool String::operator==(const String& s) const {
    return list::compare(head, s.head) == 0;
}


std::strong_ordering String::operator<=>(const String& s) const {
    int result = list::compare(head, s.head);

    if (result == 0)
        return std::strong_ordering::equal;
    else if (result < 0)
        return std::strong_ordering::less;
    else
        return std::strong_ordering::greater;
}


String String::operator+(const String& s) const {
    list::Node* combined_head = list::append(head, s.head);
    String result(combined_head);
    return result;
}

String& String::operator+=(const String& s) {
    list::Node* combined_head = list::append(head, s.head);
    list::free(head);
    head = combined_head;
    return *this;
}

void String::print(std::ostream& out) const {
    list::print(out, head);
}

void String::read(std::istream& in) {
    char buffer[1024];
    if (in >> buffer) {
        list::free(head);
        head = list::from_string(buffer);
    }
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}

String::String(list::Node* head) : head(head) {}


