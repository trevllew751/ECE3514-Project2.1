#include "catch.hpp"
#include "LinkedList.hpp"

TEST_CASE("Test construction")
{
    INFO("Hint: Checking basic construction");
    LinkedList<int> ll;
    REQUIRE(ll.isEmpty());
    REQUIRE(ll.getLength() == 0);
}


TEST_CASE("Test isEmpty()", "[LinkedList]") {
    LinkedList<int> ll;
    REQUIRE(ll.isEmpty());
    REQUIRE(ll.insert(1, 1));
    REQUIRE_FALSE(ll.isEmpty());
}

TEST_CASE("Test getLength()", "[LinkedList]") {
    LinkedList<int> ll;
    ll.insert(1, 1);
    ll.insert(1, 1);
    ll.insert(1, 1);
    ll.insert(1, 1);
    REQUIRE(ll.getLength() == 4);
}

TEST_CASE("Test insert(int, T) and getEntry(int)", "[LinkedList]") {
    LinkedList<int> ll;
    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    REQUIRE_FALSE(ll.isEmpty());
    REQUIRE(ll.getLength() == 4);
    REQUIRE(ll.getEntry(1) == 1);
    REQUIRE(ll.getEntry(2) == 2);
    REQUIRE(ll.getEntry(3) == 3);
    REQUIRE(ll.getEntry(4) == 4);

    LinkedList<int> ll1;
    ll1.insert(1, 1);
    ll1.insert(1, 2);
    ll1.insert(1, 3);
    ll1.insert(1, 4);
    REQUIRE(ll1.getEntry(1) == 4);
    REQUIRE(ll1.getEntry(2) == 3);
    REQUIRE(ll1.getEntry(3) == 2);
    REQUIRE(ll1.getEntry(4) == 1);
    REQUIRE_THROWS(ll.getEntry(10000));
}

TEST_CASE("Test remove(int)", "[LinkedList]") {
    LinkedList<int> ll;
    REQUIRE_FALSE(ll.remove(1));
    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    REQUIRE(ll.remove(1));
    REQUIRE(ll.getEntry(1) == 2);
    REQUIRE(ll.remove(1));
    REQUIRE(ll.getEntry(1) == 3);
    REQUIRE(ll.remove(1));
    REQUIRE(ll.getEntry(1) == 4);
    REQUIRE(ll.remove(1));
    REQUIRE_FALSE(ll.remove(1));
    REQUIRE(ll.isEmpty());

    LinkedList<int> ll1;
    ll1.insert(1, 1);
    ll1.insert(2, 2);
    ll1.insert(3, 3);
    ll1.insert(4, 4);
    REQUIRE(ll1.remove(2));
    REQUIRE(ll1.getEntry(2) == 3);
    REQUIRE(ll1.remove(1));
    REQUIRE(ll1.getEntry(2) == 4);
    REQUIRE(ll1.remove(1));
    REQUIRE(ll1.getEntry(1) == 4);
    REQUIRE(ll1.remove(1));
    REQUIRE(ll1.isEmpty());
}

TEST_CASE("Test clear()", "[LinkedList]") {
    LinkedList<int> ll;
    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    REQUIRE_FALSE(ll.isEmpty());
    ll.clear();
    REQUIRE(ll.isEmpty());
}

TEST_CASE("Test setEntry(int, T)", "[LinkedList]") {
    LinkedList<int> ll;
    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    REQUIRE(ll.setEntry(1, 4) == 1);
    REQUIRE(ll.getEntry(1) == 4);
    REQUIRE(ll.setEntry(2, 3) == 2);
    REQUIRE(ll.getEntry(2) == 3);
    REQUIRE(ll.setEntry(3, 2) == 3);
    REQUIRE(ll.getEntry(3) == 2);
    REQUIRE(ll.setEntry(4, 1) == 4);
    REQUIRE(ll.getEntry(4) == 1);
}