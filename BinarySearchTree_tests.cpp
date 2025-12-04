#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"


TEST(default_ctor) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
    ASSERT_EQUAL(tree.size(), 0);
    ASSERT_EQUAL(tree.height(), 0);
}

TEST(empty_and_size) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
    ASSERT_EQUAL(tree.size(), 0);

    tree.insert(10);
    ASSERT_FALSE(tree.empty());
    ASSERT_EQUAL(tree.size(), 1);

    tree.insert(5);
    tree.insert(15);
    ASSERT_FALSE(tree.empty());
    ASSERT_EQUAL(tree.size(), 3);
}

TEST(copy_ctor) {
    BinarySearchTree<int> test;
    test.insert(67);
    test.insert(1);
    test.insert(3);

    BinarySearchTree<int> test2 = test;

    ASSERT_EQUAL(test2.size(), 3);
    ASSERT_TRUE(test2.find(67)!= test2.end());
    ASSERT_TRUE(test2.find(1) != test2.end());
    ASSERT_TRUE(test2.find(3) != test2.end());
    
    test.insert(4);

    ASSERT_TRUE(test2.find(4) == test2.end());

    BinarySearchTree<int> empty;
    BinarySearchTree<int> empty_copy(empty);
    ASSERT_TRUE(empty_copy.empty());
    ASSERT_EQUAL(empty_copy.size(), 0);

    BinarySearchTree<int> single;
    single.insert(42);
    BinarySearchTree<int> single_copy(single);
    ASSERT_EQUAL(single_copy.size(), 1);
    ASSERT_TRUE(single_copy.find(42) != single_copy.end());
}

TEST(test_find) {
    BinarySearchTree<int> test;
    test.insert(67);
    test.insert(1);
    test.insert(3);

    auto it = test.find(67);
    ASSERT_EQUAL(*it, 67);

    auto it2 = test.find(69);
    ASSERT_EQUAL(it2, test.end());
}

TEST(tree_height) {
    BinarySearchTree<int> tree; 
    tree.insert(67);
    
    ASSERT_EQUAL(tree.height(), 1); 

    tree.insert(1);
    tree.insert(2);
    ASSERT_EQUAL(tree.height(), 3);
}

TEST(insert) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    ASSERT_EQUAL(tree.size(), 3);
    ASSERT_TRUE(tree.find(10) != tree.end());
    ASSERT_TRUE(tree.find(5) != tree.end());
    ASSERT_TRUE(tree.find(15) != tree.end());
}

TEST(max) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(20);

    auto it = tree.max_element();
    ASSERT_EQUAL(*it, 20);

    BinarySearchTree<int> empty;
    auto it2 = empty.max_element();
    ASSERT_EQUAL(it2, empty.end());
}

TEST(print) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(20);

    std::ostringstream os;
    tree.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "5 10 15 20 ");
    
    std::ostringstream os1; 
    tree.traverse_preorder(os1);
    ASSERT_EQUAL(os1.str(), "10 5 15 20 ");
     
}

TEST(min_greater_than) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    auto it = tree.min_greater_than(10);
    ASSERT_EQUAL(*it, 15);
    auto it2 = tree.min_greater_than(15);
    ASSERT_EQUAL(it2, tree.end());

    BinarySearchTree<int> empty;
    auto it3 = empty.min_element();
    ASSERT_EQUAL(it3, empty.end());

    BinarySearchTree<int> varchasHasanIdea;
    varchasHasanIdea.insert(5);
    varchasHasanIdea.insert(3);
    varchasHasanIdea.insert(4);
    varchasHasanIdea.insert(2);
    auto it4 = varchasHasanIdea.min_greater_than(3);
    ASSERT_EQUAL(*it4, 4);

    BinarySearchTree<int> anotherIdea;
    anotherIdea.insert(5);
    anotherIdea.insert(3);
    anotherIdea.insert(7);
    anotherIdea.insert(6);
    auto it5 = anotherIdea.min_greater_than(5);
    ASSERT_EQUAL(*it5, 6);

}

TEST(inorder_preorder) {
    BinarySearchTree<char> tree;
    tree.insert('F');
    tree.insert('B');
    tree.insert('D');
    tree.insert('A');
    tree.insert('C');
    tree.insert('E');
    tree.insert('G');
    tree.insert('I');
    tree.insert('H');

    std::ostringstream os_inorder;
    tree.traverse_inorder(os_inorder);
    ASSERT_EQUAL(os_inorder.str(), "A B C D E F G H I ");

    std::ostringstream os_preorder;
    tree.traverse_preorder(os_preorder);
    ASSERT_EQUAL(os_preorder.str(), "F B A D C E G I H ");
}

TEST(confirm_invariants) {
    BinarySearchTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);

    BinarySearchTree<int> tree2 = tree;

    ASSERT_TRUE(tree.check_sorting_invariant());
}




TEST_MAIN()
