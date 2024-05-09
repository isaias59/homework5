#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.


TEST(ListTests, Compare) {
    Node* const head1 = list::from_string("");
    Node* const head2 = list::from_string("abc");
    EXPECT_EQ(list::compare(head1, head2, 3), -1);
    list::free(head1);
    list::free(head2);
}
TEST(ListTests, Reverse) {
    Node* const head = list::from_string("foo");
    Node* const reversed_head = list::reverse(head);
    Node* reversed_list = reversed_head;

    EXPECT_EQ(reversed_list->data, 'o');
    ASSERT_NE(reversed_list->next, nullptr);

    reversed_list = reversed_list->next;
    EXPECT_EQ(reversed_list->data, 'o');
    ASSERT_NE(reversed_list->next, nullptr);

    reversed_list = reversed_list->next;
    EXPECT_EQ(reversed_list->data, 'f');
    ASSERT_EQ(reversed_list->next, nullptr);

    list::free(head);
    list::free(reversed_head);
}
TEST(ListTests, Append) {
    Node* const head1 = list::from_string("foo");
    Node* const head2 = list::from_string("bar");
    Node* const appended_head = list::append(head1, head2);
    EXPECT_EQ(list::length(appended_head), 6);
    list::free(head1);
    list::free(head2);
    list::free(appended_head);
}
TEST(ListTests, Index) {
    Node* const head = list::from_string("foo");
    Node* const node = list::nth(head, 1);
    EXPECT_EQ(list::index(head, node), 1);
    list::free(head);
}
TEST(ListTests, FindChar) {
    Node* const head = list::from_string("foo");
    Node* const node = list::find_char(head, 'o');
    EXPECT_EQ(node->data, 'o');
    list::free(head);
}
TEST(ListTests, FindList) {
    Node* const haystack = list::from_string("foobar");
    Node* const needle = list::from_string("bar");
    Node* const node = list::find_list(haystack, needle);
    EXPECT_EQ(node->data, 'b');
    list::free(haystack);
    list::free(needle);
}
TEST(ListTests, Nth) {
    Node* const head = list::from_string("foo");
    Node* const node = list::nth(head, 1);
    EXPECT_EQ(node->data, 'o');
    list::free(head);
}
TEST(ListTests, Last) {
    Node* const head = list::from_string("foo");
    Node* const node = list::last(head);
    EXPECT_EQ(node->data, 'o');
    list::free(head);
}
