#include "catch.hpp"
#include "CircularQueue.h"
#include <string>
TEST_CASE("CircularQueue with unsigned elements") {
	CircularQueue<unsigned> queue(4);

	SECTION("Add 2 elements; check size is 2") {
		queue.push(10);
		queue.push(20);
		REQUIRE(queue.size() == 2);
	}

	SECTION("Add one element and pop one element; check if the queue is empty") {
		queue.push(30);
		queue.pop();
		REQUIRE(queue.empty());
	}

	SECTION("Check first and last element without adding anything (should throw)") {
		REQUIRE_THROWS_AS(queue.front(), std::out_of_range);
		REQUIRE_THROWS_AS(queue.back(), std::out_of_range);
	}

	SECTION("Add 5 elements; check if the first element is the 5th added element") {
		queue.push(40);
		queue.push(50);
		queue.push(60);
		queue.push(70);
		queue.push(50);
		REQUIRE(queue.front() == 50);
	}

	SECTION("Add 1000 elements, pop all of them, and check if they are correct") {
		for (unsigned i = 0; i < 1000; i++) {
			queue.push(i);
		}

		for (unsigned i = 0; i < 1000; i++) {
			REQUIRE(queue.front() == i);
			queue.pop();
		}

	}
}

TEST_CASE("CircularQueue with string elements") {
	CircularQueue<std::string> strQueue(4);

	SECTION("Add 2 elements; check size is 2") {
		strQueue.push("apple");
		strQueue.push("banana");
		REQUIRE(strQueue.size() == 2);
	}

	SECTION("Add one element and pop one element; check if the queue is empty") {
		strQueue.push("cherry");
		strQueue.pop();
		REQUIRE(strQueue.empty());
	}

	SECTION("Check first and last element without adding anything (should throw)") {
		REQUIRE_THROWS_AS(strQueue.front(), std::out_of_range);
		REQUIRE_THROWS_AS(strQueue.back(), std::out_of_range);
	}

	SECTION("Add 5 elements; check if the first element is the 5th added element") {
		strQueue.push("water");
		strQueue.push("ice");
		strQueue.push("fire");
		strQueue.push("rain");
		strQueue.push("rainbow");
		REQUIRE(strQueue.front() == "rainbow");
	}

	SECTION("After adding 2 elements check if the queue is empty") {
		strQueue.push("dog");
		strQueue.push("cat");
		REQUIRE(!strQueue.empty());

	}

	SECTION("Check the size of an empty queue") {
		REQUIRE(strQueue.size() == 0);
	}
}
