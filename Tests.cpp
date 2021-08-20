// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer 
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}
*/

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(5);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, VectorMaxSizeIsGreaterOrEqual)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);
    ASSERT_TRUE(collection->size() <= collection->max_size());

    // 1 entry
    add_entries(1);
    ASSERT_EQ(collection->size(), 1);
    ASSERT_TRUE(collection->size() <= collection->max_size());
    // 5 entries
    add_entries(4);
    ASSERT_EQ(collection->size(), 5);
    ASSERT_TRUE(collection->size() <= collection->max_size());
    // 10 entries
    add_entries(5);
    ASSERT_EQ(collection->size(), 10);
    ASSERT_TRUE(collection->size() <= collection->max_size());
}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, VectorCapacityIsGreaterOrEqual)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);
    ASSERT_TRUE(collection->size() <= collection->capacity());

    // 1 entry
    add_entries(1);
    ASSERT_EQ(collection->size(), 1);
    ASSERT_TRUE(collection->size() <= collection->capacity());
    // 5 entries
    add_entries(4);
    ASSERT_EQ(collection->size(), 5);
    ASSERT_TRUE(collection->size() <= collection->capacity());
    // 10 entries
    add_entries(5);
    ASSERT_EQ(collection->size(), 10);
    ASSERT_TRUE(collection->size() <= collection->capacity());
}
// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizingIncreasesCollection)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);

    // Resize, collection is increased by 1
    collection->resize(1);
    ASSERT_EQ(collection->size(), 1);
}
// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, ResizingDecreasesCollection)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);

    // Resize, collection is increased by 5
    collection->resize(5);
    ASSERT_EQ(collection->size(), 5);

    // Resize, collection is decreased to 1
    collection->resize(1);
    ASSERT_EQ(collection->size(), 1);
}
// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizingDecreasesCollectionToZero)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);

    // Resize, collection is increased by 5
    collection->resize(5);
    ASSERT_EQ(collection->size(), 5);

    // Resize, collection is decreased to 0
    collection->resize(0);
    ASSERT_EQ(collection->size(), 0);
}
// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection)
{
    // Empty, the size is 0
    ASSERT_TRUE(collection->empty());

    // 5 entries added to collection
    add_entries(5);
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 5);

    // Clear erases collection
    collection->clear();
    ASSERT_TRUE(collection->empty());
}
// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseEreasesCollection)
{
    // Empty, the size is 0
    ASSERT_TRUE(collection->empty());

    // 5 entries added to collection
    add_entries(5);
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 5);

    // Erase(begin, end) erases collection
    collection->erase(collection->begin(), collection->end());
    ASSERT_TRUE(collection->empty());
}
// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacityButNotSize)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);
    ASSERT_EQ(collection->capacity(), 0);

    // Reserve increases capacity but not size of collection
    collection->reserve(5);
    ASSERT_EQ(collection->capacity(), 5);
    ASSERT_EQ(collection->size(), 0);
    ASSERT_NE(collection->size(), 5);
}
// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, ExceptionThrownIfOutOfBounds)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);
    ASSERT_EQ(collection->capacity(), 0);

    // Add one entry, Exception is thrown when accessing index 1
    add_entries(1);

    bool inRange = true;

    try
    {
        collection->at(1);
    }
    catch (std::out_of_range&)
    {
        inRange = false;
    }

    ASSERT_TRUE(inRange);
}
// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
// Positive Custom Test: pop_back decreases size
TEST_F(CollectionTest, PopBackDecreasesCollection)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);
    
    // Add 5 entries, size is increased
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);

    // Pop Back, size is decreased to 4
    collection->pop_back();
    ASSERT_EQ(collection->size(), 4);
}
// Negative Custom Test: Calling reserve with argument greater than max size throws a length_error exception
TEST_F(CollectionTest, ReserveGreaterThanMaxSizeThrowsException)
{
    // Empty, the size is 0
    ASSERT_EQ(collection->size(), 0);

    bool inLength = true;
    // Reserve with argument greater than max_size
    try
    {
        collection->reserve(collection->max_size() + 1);
    }
    catch (std::length_error&)
    {
        inLength = false;
    }
    ASSERT_TRUE(inLength);
}