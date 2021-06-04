#include <gtest/gtest.h>
#include "../b_tree.h"
#include "../Set/Set.h"
#include "../functions.h"

TEST(BTree, Create) {
    BTree<int> tree = BTree<int>();
    int arr[7] = {1,2,3,4,5,6,7};
    BTree<int> tree_2 = BTree<int>(arr, 7);
    BTree<int> tree_3 = BTree<int>(tree_2);

    ASSERT_ANY_THROW(tree.PostOrderR()->Get(0));
    ASSERT_TRUE(tree_2.FindElem(5));
    ASSERT_FALSE(tree_2.FindElem(10));
    ASSERT_TRUE (tree_2.FindSubtree(tree_3.GetSubtree(5)));
    tree.AddElem(8);
    tree.RemoveElem(9);
    ASSERT_TRUE(tree.FindElem(8));
    tree_2.RemoveElem(7);
    ASSERT_FALSE(tree_2.FindElem(7));
}

TEST(Set, Create) {
    Set<int> set = Set<int>();
    ASSERT_ANY_THROW(set.GetSet()->Get(0));

    float arr[7] = {1.0,2,-3,4,53.6,6,7.19};
    float arr1[7] = {-3,1.0,2,4,6,7.19,53.6};
    LinkedListSequence<float> a = LinkedListSequence<float> (arr1,7);
    Set<float> set2 = Set<float>(arr,7);
    Set<float> set3 = Set<float>(set2);

    set2.AddElem(2);
    set2.RemoveElem(2);
    ASSERT_FALSE(set2.FindElem(2));
    ASSERT_EQ(a.Get(2),set3.GetSet()->Get(2));

    int arr2[2] = {1,-3};
    Set<int> set1 = Set<int>(arr2,2);
    set1.RemoveElem(1);
    set1.RemoveElem(-3);
    ASSERT_TRUE(set1.IsEqual(&set));
}

TEST(BTree, Functions) {
    int arr[] = {1,2,3,4};
    int arr1[] = {3,6,9,12};
    int arr2[] = {3,4};
    BTree<int> tree = BTree<int>(arr, 4);
    BTree<int> tree1 = BTree<int>(arr1,4);
    ASSERT_EQ(tree.InOrderR()->Get(2),3);
    ASSERT_EQ(tree.InOrderRR()->Get(2),2);
    ASSERT_TRUE(*(tree.GetSubtree(3)->PreOrderR()) == *(BTree<int>(arr2,2).PreOrderR()));

    int arr3[] = {1,0,0,1};
    BTree<int> *mapTree = tree.Map(mod_two);
    ASSERT_TRUE(*(mapTree->PreOrderR()) == LinkedListSequence<int>(arr3,4));
    Complex arr4[] = {Complex(0,1),Complex(5,6),Complex(5,6)};
    Complex arr5[] = {Complex(5,6),Complex(5,6)};
    BTree<Complex> tree3 = BTree<Complex>(arr4,3);
    BTree<Complex> *whereTree = tree3.Where(comp_mod_two);
    ASSERT_TRUE(*(whereTree->PreOrderR()) == LinkedListSequence<Complex>(arr5,2));
    float arr6[2] = {34.5, 23.1};
    BTree<float> tree5 = BTree<float>(arr6,2);
    float reduce = tree5.Reduce(higher_number, 5);
    ASSERT_FLOAT_EQ(reduce, 34.5);

    int arr7[] = {0,0,1,1,1,2,3,4};
    ASSERT_TRUE(*(tree.Concat(mapTree)->InOrderR()) == LinkedListSequence<int>(arr7,8));
    int arr8[] = {4};
    string path = "rr";
    ASSERT_TRUE(*(tree.AdressTree(path)->InOrderR()) == LinkedListSequence<int>(arr8,1));
}

TEST(Set, Functions) {
    int arr[] = {1,2,3,4};
    int arr1[] = {3,6,9,12};
    int arr2[] = {0,1};
    Set<int> set = Set<int>(arr,4);
    Set<int> set1 = Set<int>(arr1,4);
    Set<int> set2 = Set<int>(arr2,2);
    Set<int> *mapSet1 = set.Map(mult_tree);
    Set<int> *mapSet2 = set.Map(mod_two);
    ASSERT_TRUE(mapSet1->IsEqual(&set1));
    ASSERT_TRUE(mapSet2->IsEqual(&set2));

    Complex arr3[] = {Complex(0,1),Complex(5,6),Complex(5,6)};
    Complex arr4[] = {Complex(5,6)};
    Set<Complex> set3 = Set<Complex>(arr3,3);
    Set<Complex> set4 = Set<Complex>(arr4,1);
    Set<Complex> *whereSet3 = set3.Where(comp_mod_two);
    ASSERT_TRUE(whereSet3->IsEqual(&set4));

    float arr5[2] = {34.5, 23.1};
    Set<float> set5 = Set<float>(arr5,2);
    float reduce = set5.Reduce(higher_number, 5);
    ASSERT_FLOAT_EQ(reduce, 34.5);
}

TEST(Set, Operations) {
    int arr[] = {1,2,3,4};
    int arr1[] = {3,6,9,12};
    int arr2[] = {1,2,4,3,6,9,12};
    int arr3[] = {3};
    int arr4[] = {1,2,4};
    Set<int> set = Set<int>(arr,4);
    Set<int> set1 = Set<int>(arr1,4);
    Set<int> set2 = Set<int>(arr2,7);
    Set<int> set3 = Set<int>(arr3,1);
    Set<int> set4 = Set<int>(arr4,3);

    Set<int> *uni = set.Union(&set1);
    Set<int> *inter = set.Intersection(&set1);
    Set<int> *comp = set.RelComplement(&set1);
    ASSERT_TRUE(uni->IsEqual(&set2));
    ASSERT_TRUE(inter->IsEqual(&set3));
    ASSERT_TRUE(comp->IsEqual(&set4));

    ASSERT_TRUE(set.FindSubSet(&set4));
    ASSERT_FALSE(set.FindSubSet(&set2));
}

