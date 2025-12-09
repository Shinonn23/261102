#include <gtest/gtest.h>

// Function to count even and odd numbers
// We'll need to refactor lab6_1.cpp to expose these functions
class NumberCounter {
  public:
    int even_count = 0;
    int odd_count = 0;

    void countNumber(int x) {
        if (x == 0) {
            return;
        }
        if (x % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    void reset() {
        even_count = 0;
        odd_count = 0;
    }
};

class EvenOddCounterTest : public ::testing::Test {
  protected:
    NumberCounter counter;

    void SetUp() override { counter.reset(); }
};

// Tests for counting even numbers
TEST_F(EvenOddCounterTest, CountSingleEvenNumber) {
    counter.countNumber(2);
    EXPECT_EQ(counter.even_count, 1);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, CountMultipleEvenNumbers) {
    counter.countNumber(2);
    counter.countNumber(4);
    counter.countNumber(6);
    EXPECT_EQ(counter.even_count, 3);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, CountLargeEvenNumber) {
    counter.countNumber(1000);
    EXPECT_EQ(counter.even_count, 1);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, CountNegativeEvenNumber) {
    counter.countNumber(-4);
    EXPECT_EQ(counter.even_count, 1);
    EXPECT_EQ(counter.odd_count, 0);
}

// Tests for counting odd numbers
TEST_F(EvenOddCounterTest, CountSingleOddNumber) {
    counter.countNumber(3);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 1);
}

TEST_F(EvenOddCounterTest, CountMultipleOddNumbers) {
    counter.countNumber(1);
    counter.countNumber(3);
    counter.countNumber(5);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 3);
}

TEST_F(EvenOddCounterTest, CountLargeOddNumber) {
    counter.countNumber(999);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 1);
}

TEST_F(EvenOddCounterTest, CountNegativeOddNumber) {
    counter.countNumber(-3);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 1);
}

// Tests for mixed even and odd numbers
TEST_F(EvenOddCounterTest, CountMixedNumbers_Example1) {
    // Example 1: 10, 8, 23, 5, 20, 2, 0
    counter.countNumber(10);
    counter.countNumber(8);
    counter.countNumber(23);
    counter.countNumber(5);
    counter.countNumber(20);
    counter.countNumber(2);
    counter.countNumber(0);
    EXPECT_EQ(counter.even_count, 4);
    EXPECT_EQ(counter.odd_count, 2);
}

TEST_F(EvenOddCounterTest, CountMixedNumbers_Example2) {
    // Example 2: just 0
    counter.countNumber(0);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, CountMixedNumbers_VariousNumbers) {
    counter.countNumber(1);
    counter.countNumber(2);
    counter.countNumber(3);
    counter.countNumber(4);
    counter.countNumber(5);
    counter.countNumber(6);
    EXPECT_EQ(counter.even_count, 3);
    EXPECT_EQ(counter.odd_count, 3);
}

// Tests for special cases
TEST_F(EvenOddCounterTest, ZeroIsNotCounted) {
    counter.countNumber(0);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, MultipleZeros) {
    counter.countNumber(0);
    counter.countNumber(0);
    counter.countNumber(0);
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, CounterReset) {
    counter.countNumber(2);
    counter.countNumber(3);
    EXPECT_EQ(counter.even_count, 1);
    EXPECT_EQ(counter.odd_count, 1);

    counter.reset();
    EXPECT_EQ(counter.even_count, 0);
    EXPECT_EQ(counter.odd_count, 0);
}

TEST_F(EvenOddCounterTest, NegativeAndPositiveMixed) {
    counter.countNumber(-2);
    counter.countNumber(2);
    counter.countNumber(-3);
    counter.countNumber(3);
    EXPECT_EQ(counter.even_count, 2);
    EXPECT_EQ(counter.odd_count, 2);
}

TEST_F(EvenOddCounterTest, LargeSequenceOfNumbers) {
    for (int i = 1; i <= 100; i++) {
        if (i != 0) {
            counter.countNumber(i);
        }
    }
    EXPECT_EQ(counter.even_count, 50);
    EXPECT_EQ(counter.odd_count, 50);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
