#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];

    EXPECT_EQ(String::strncpy(result, "hello", 10), result);
    EXPECT_STREQ(result, "hello");

    String::strncpy(result, "hello", 5);
    EXPECT_STREQ(result, "hello");

    String::strncpy(result, "hello", 3);
    EXPECT_STREQ(result, "hel");

    String::strncpy(result, "hello", 1);
    EXPECT_STREQ(result, "h");

    String::strncpy(result, "hello", 0);
    EXPECT_STREQ(result, "");

    String::strncpy(result, "", 5);
    EXPECT_STREQ(result, "");

    String::strncpy(result, "a", 5);
    EXPECT_STREQ(result, "a");

    String::strncpy(result, "hi, you!", 8);
    EXPECT_STREQ(result, "hi, you!");
}  

TEST(StringFunction, strcat) {
    char a[20] = "foo";
    EXPECT_EQ(String::strcat(a, "bar"), a);
    EXPECT_STREQ(a, "foobar");

    char b[20] = "";
    String::strcat(b, "abc");
    EXPECT_STREQ(b, "abc");

    char c[20] = "abc";
    String::strcat(c, "");
    EXPECT_STREQ(c, "abc");

    char d[20] = "";
    String::strcat(d, "");
    EXPECT_STREQ(d, "");

    char e[20] = "a";
    String::strcat(e, "b");
    EXPECT_STREQ(e, "ab");

    char f[20] = "hi,";
    String::strcat(f, " you!");
    EXPECT_STREQ(f, "hi, you!");
}

TEST(StringFunction, strncat) {
    char a[20] = "foo";
    EXPECT_EQ(String::strncat(a, "barbaz", 3), a);
    EXPECT_STREQ(a, "foobar");

    char b[20] = "foo";
    String::strncat(b, "bar", 10);
    EXPECT_STREQ(b, "foobar");

    char c[20] = "foo";
    String::strncat(c, "bar", 3);
    EXPECT_STREQ(c, "foobar");

    char d[20] = "foo";
    String::strncat(d, "bar", 0);
    EXPECT_STREQ(d, "foo");

    char e[20] = "foo";
    String::strncat(e, "bar", 1);
    EXPECT_STREQ(e, "foob");

    char f[20] = "";
    String::strncat(f, "abc", 2);
    EXPECT_STREQ(f, "ab");

    char g[20] = "abc";
    String::strncat(g, "", 5);
    EXPECT_STREQ(g, "abc");

    char h[20] = "hi,";
    String::strncat(h, " you!", 5);
    EXPECT_STREQ(h, "hi, you!");
}
TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_EQ(String::strcmp("", ""), 0);
    EXPECT_EQ(String::strcmp("a", "a"), 0);

    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);

    EXPECT_LT(String::strcmp("ab", "abc"), 0);
    EXPECT_GT(String::strcmp("abc", "ab"), 0);

    EXPECT_LT(String::strcmp("", "a"), 0);
    EXPECT_GT(String::strcmp("a", ""), 0);

    EXPECT_LT(String::strcmp("A", "a"), 0);
    EXPECT_GT(String::strcmp("a", "A"), 0);

    EXPECT_LT(String::strcmp("a,", "a."), 0);
    EXPECT_GT(String::strcmp("b", "a"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abc", 3), 0);
    EXPECT_EQ(String::strncmp("abc", "abc", 10), 0);
    EXPECT_EQ(String::strncmp("", "", 5), 0);

    EXPECT_EQ(String::strncmp("abcd", "abce", 3), 0);
    EXPECT_LT(String::strncmp("abcd", "abce", 4), 0);
    EXPECT_GT(String::strncmp("abce", "abcd", 4), 0);

    EXPECT_EQ(String::strncmp("abc", "xyz", 0), 0);

    EXPECT_LT(String::strncmp("a", "b", 1), 0);
    EXPECT_GT(String::strncmp("b", "a", 1), 0);

    EXPECT_LT(String::strncmp("ab", "abc", 3), 0);
    EXPECT_GT(String::strncmp("abc", "ab", 3), 0);

    EXPECT_LT(String::strncmp("", "a", 1), 0);
    EXPECT_GT(String::strncmp("a", "", 1), 0);

    EXPECT_LT(String::strncmp("a,", "a.", 2), 0);
    EXPECT_EQ(String::strncmp("a,", "a.", 1), 0);
}

TEST(StringFunction, reverse_cpy) {
    char a[20];
    String::reverse_cpy(a, "abc");
    EXPECT_STREQ(a, "cba");

    char b[20];
    String::reverse_cpy(b, "");
    EXPECT_STREQ(b, "");

    char c[20];
    String::reverse_cpy(c, "a");
    EXPECT_STREQ(c, "a");

    char d[20];
    String::reverse_cpy(d, "ab");
    EXPECT_STREQ(d, "ba");

    char e[20];
    String::reverse_cpy(e, "racecar");
    EXPECT_STREQ(e, "racecar");

    char f[20];
    String::reverse_cpy(f, "hi, you!");
    EXPECT_STREQ(f, "!uoy ,ih");

    char g[20];
    String::reverse_cpy(g, "12345");
    EXPECT_STREQ(g, "54321");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";

    EXPECT_EQ(String::strchr(s, 'h'), s);
    EXPECT_EQ(String::strchr(s, 'e'), s + 1);
    EXPECT_EQ(String::strchr(s, 'l'), s + 2);
    EXPECT_EQ(String::strchr(s, 'o'), s + 4);

    EXPECT_EQ(String::strchr(s, 'z'), nullptr);
    EXPECT_EQ(String::strchr(s, 'H'), nullptr);

    EXPECT_EQ(String::strchr(s, '\0'), s + 5);

    const char *empty = "";
    EXPECT_EQ(String::strchr(empty, 'a'), nullptr);
    EXPECT_EQ(String::strchr(empty, '\0'), empty);

    const char *one = "a";
    EXPECT_EQ(String::strchr(one, 'a'), one);
    EXPECT_EQ(String::strchr(one, 'b'), nullptr);

    const char *p = "hi, you!";
    EXPECT_EQ(String::strchr(p, ','), p + 2);
    EXPECT_EQ(String::strchr(p, ' '), p + 3);
    EXPECT_EQ(String::strchr(p, '!'), p + 7);
}

TEST(StringFunction, strstr) {
    const char *s = "hello world";

    EXPECT_EQ(String::strstr(s, "hello"), s);
    EXPECT_EQ(String::strstr(s, "world"), s + 6);
    EXPECT_EQ(String::strstr(s, "lo w"), s + 3);
    EXPECT_EQ(String::strstr(s, "o"), s + 4);
    EXPECT_EQ(String::strstr(s, "hello world"), s);

    EXPECT_EQ(String::strstr(s, "xyz"), nullptr);
    EXPECT_EQ(String::strstr(s, "Hello"), nullptr);
    EXPECT_EQ(String::strstr(s, "hello worlds"), nullptr);
    EXPECT_EQ(String::strstr(s, "worlds"), nullptr);

    EXPECT_EQ(String::strstr(s, ""), s);

    const char *empty = "";
    EXPECT_EQ(String::strstr(empty, "a"), nullptr);
    EXPECT_EQ(String::strstr(empty, ""), empty);

    const char *r = "aaab";
    EXPECT_EQ(String::strstr(r, "aab"), r + 1);
    EXPECT_EQ(String::strstr(r, "ab"), r + 2);

    const char *p = "hi, you!";
    EXPECT_EQ(String::strstr(p, ", "), p + 2);
    EXPECT_EQ(String::strstr(p, "!"), p + 7);
}
