#include <iostream>

#include "string.hpp"

using namespace std;

String::String(const char *s) {
    strncpy(buf, s, MAXLEN - 1);
}

String::String(const String &s) {
    strcpy(buf, s.buf);
}

String::~String() {
}

int String::size() const {
    return strlen(buf);
}

void String::print(ostream &out) const {
    out << buf;
}

ostream &operator<<(ostream &out, const String &s) {
    s.print(out);
    return out;
}

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0')
        ++len;
    return len;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    for ( ; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int i = 0;
    while (dest[i] != '\0')
        ++i;
    int j = 0;
    for ( ; src[j] != '\0'; ++j)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int i = 0;
    while (dest[i] != '\0')
        ++i;
    int j = 0;
    for ( ; src[j] != '\0' && j < n; ++j)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && left[i] == right[i])
        ++i;
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n) {
    int i = 0;
    while (i < n && left[i] != '\0' && left[i] == right[i])
        ++i;
    if (i == n)
        return 0;
    return left[i] - right[i];
}

void String::reverse_cpy(char *dest, const char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

const char *String::strchr(const char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c)
            return str + i;
        ++i;
    }
    if (c == '\0')
        return str + i;
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle) {
    if (needle[0] == '\0')
        return haystack;
    for (int i = 0; haystack[i] != '\0'; ++i) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j])
            ++j;
        if (needle[j] == '\0')
            return haystack + i;
    }
    return nullptr;
}

String &String::operator=(const String &s) {
    if (this != &s)
        strcpy(buf, s.buf);
    return *this;
}

char &String::operator[](int index) {
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
    return buf[index];
}

String String::reverse() const {
    String result;
    reverse_cpy(result.buf, buf);
    return result;
}

int String::indexOf(char c) const {
    const char *p = strchr(buf, c);
    if (p == nullptr)
        return -1;
    return p - buf;
}

int String::indexOf(const String &s) const {
    const char *p = strstr(buf, s.buf);
    if (p == nullptr)
        return -1;
    return p - buf;
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}