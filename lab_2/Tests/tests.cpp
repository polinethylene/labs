#include <gtest/gtest.h>
#include "../Matrix.h"
#include "../Complex.h"

float higher_number(float a, float b){
    if (a>b){
        return a;
    } else {
        return b;
    }
}

bool compare_two (float a){
    if (a>2){
        return true;
    } else {
        return false;
    }
}

float minus_ten_half(float a){
    return a-10.5;
}

TEST(Array_and_List, Create) {
    DynamicArray<int> array = DynamicArray<int>(10);
    int arr[7] = {1,2,3,4,5,6,7};
    DynamicArray<int> array_2 = DynamicArray<int>(arr, 4);
    ASSERT_EQ (10, array.GetSize());
    ASSERT_EQ (0, array.Get(3));
    ASSERT_ANY_THROW(array.Get(11));
    array.Set(3,12);
    ASSERT_EQ (12, array.Get(3));
    DynamicArray<int> array_3 = DynamicArray<int>(array_2);
    ASSERT_ANY_THROW(array.Resize(-1));
    array.Resize(11);
    ASSERT_EQ (0, array.Get(10));
    ASSERT_EQ (3, array_3.Get(2));

    LinkedList<int> list = LinkedList<int>(arr,5);
    cout << list.Get(2) << endl;
    ASSERT_EQ (1, list.GetFirst());
    ASSERT_EQ (5, list.GetLast());
    list.Append(2);
    list.Prepend(1);
    ASSERT_EQ (1, list.Get(0));
    ASSERT_EQ (2, list.GetLast());
    list.InsertAt(6,4);
    ASSERT_EQ (6, list.Get(4));
    ASSERT_EQ (8, list.GetLength());
}

TEST(Sequence, Create) {
    ArraySequence<int> array = ArraySequence<int>();
    ASSERT_EQ(0, array.GetLength());
    ASSERT_ANY_THROW(array.GetFirst());

    float arr[7] = {1.0,2,-3,4,53.6,6,7.19};
    ArraySequence<float> array_2 = ArraySequence<float>(10);
    ArraySequence<float> array_3 = ArraySequence<float>(arr, 7);
    ASSERT_EQ (10, array_2.GetLength());
    ASSERT_EQ (0, array_2.Get(3));
    ASSERT_ANY_THROW(array.Get(11));
    array.Set(3,12);
    ASSERT_FLOAT_EQ (-3, array_3.Get(2));
    ASSERT_FLOAT_EQ (12, array.Get(3));

    array_3.InsertAt(3.4,4);
    array_3.Prepend(0);
    array_3.Append(1.45);

    ASSERT_FLOAT_EQ (0, array_3.Get(0));
    ASSERT_FLOAT_EQ (53.6, array_3.Get(6));
    ASSERT_FLOAT_EQ (1.45, array_3.GetLast());

    ArraySequence<Complex> list = ArraySequence<Complex>();
    ASSERT_EQ(0, list.GetLength());
    ASSERT_ANY_THROW(list.GetFirst());

    Complex *arr2 = new Complex[4]();
    arr2[0] = Complex(2,3);
    arr2[1] = Complex(-1,2.3);
    arr2[2] = Complex(0,23);
    arr2[3] = Complex(7.8,-3);
    LinkedListSequence<Complex> list_2 = LinkedListSequence<Complex>(12);
    LinkedListSequence<Complex> list_3 = LinkedListSequence<Complex>(arr2, 4);

    ASSERT_EQ (12, list_2.GetLength());
    ASSERT_EQ (Complex(0,0), list_2.Get(3));

    ASSERT_ANY_THROW(list.Get(11));
    list_3.Set(3,Complex(12,3));

    ASSERT_EQ (Complex(0,23), list_3.Get(2));
    ASSERT_EQ (Complex(12,3), list_3.Get(3));
    list_3.InsertAt(Complex(12,2),3);
    list_3.Prepend(Complex(-3,1));
    list_3.Append(Complex(0,0));

    ASSERT_EQ (Complex(-3,1), list_3.Get(0));
    ASSERT_EQ (Complex(12,3), list_3.Get(5));
    ASSERT_EQ (Complex(0,0), list_3.GetLast());
}

TEST(Matrix, Create)
{
    Matrix<int> int_matrix = Matrix<int>(4,3);
    float items[2*3] = {1, 2.6, 3, -5, -6, -7.4};
    Matrix<float> float_matrix = Matrix<float>(items, 2,3);
    ASSERT_ANY_THROW(int_matrix.Get(1,3));
    ASSERT_EQ(0,int_matrix.Get(2,2));
    ASSERT_FLOAT_EQ(2.6,float_matrix.Get(0,1));

    int_matrix.Set(3,2,1);
    ASSERT_EQ(1,int_matrix.Get(3,2));
    ASSERT_ANY_THROW(int_matrix.Set(4,3,6));
}


TEST(LinkedListSequence, Functions)
{
    float arr[7] = {1.0,2,-3,4,53.6,6,7.19};
    float arr2[2] = {3.0,-2.4};
    float arrconcat[9] = {1.0,2,-3,4,53.6,6,7.19,3.0,-2.4};
    float arrsub[4] = {2,-3,4,53.6};
    float arrmap[7] = {-9.5,-8.5, -13.5, -6.5, 43.1, -4.5, -3.31};
    float arrwhere[4] = {4, 53.6, 6, 7.19 };
    float reduce = 53.6;
    LinkedListSequence<float> a = LinkedListSequence<float>(arr, 7);
    LinkedListSequence<float> b = LinkedListSequence<float>(arr2, 2);
    LinkedListSequence<float> concat = LinkedListSequence<float>(arrconcat, 9);
    LinkedListSequence<float> subseq = LinkedListSequence<float>(arrsub, 4);
    LinkedListSequence<float> mapseq = LinkedListSequence<float>(arrmap, 7);
    LinkedListSequence<float> whereseq = LinkedListSequence<float>(arrwhere, 7);
    ASSERT_FLOAT_EQ(concat.Get(7),(a.Concat(&b))->Get(7));
    ASSERT_FLOAT_EQ(subseq.Get(3),(a.GetSubsequence(1,4))->Get(3));
    ASSERT_FLOAT_EQ(mapseq.Get(4),(a.Map(minus_ten_half))->Get(4));
    ASSERT_FLOAT_EQ(whereseq.Get(2),(a.Where(compare_two))->Get(2));
    ASSERT_FLOAT_EQ(reduce,(a.Reduce(higher_number,3)));
}

TEST(ArraySequence, Functions)
{
    float arr[7] = {1.0,2,-3,4,53.6,6,7.19};
    float arr2[2] = {3.0,-2.4};
    float arrconcat[9] = {1.0,2,-3,4,53.6,6,7.19,3.0,-2.4};
    float arrsub[4] = {2,-3,4,53.6};
    float arrmap[7] = {-9.5,-8.5, -13.5, -6.5, 43.1, -4.5, -3.31};
    float arrwhere[4] = {4, 53.6, 6, 7.19 };
    float reduce = 53.6;
    ArraySequence<float> a = ArraySequence<float>(arr, 7);
    ArraySequence<float> b = ArraySequence<float>(arr2, 2);
    ArraySequence<float> concat = ArraySequence<float>(arrconcat, 9);
    ArraySequence<float> subseq = ArraySequence<float>(arrsub, 4);
    ArraySequence<float> mapseq = ArraySequence<float>(arrmap, 7);
    ArraySequence<float> whereseq = ArraySequence<float>(arrwhere, 7);
    ASSERT_FLOAT_EQ(concat.Get(7),(a.Concat(&b))->Get(7));
    ASSERT_FLOAT_EQ(subseq.Get(3),(a.GetSubsequence(1,4))->Get(3));
    ASSERT_FLOAT_EQ(mapseq.Get(4),(a.Map(minus_ten_half))->Get(4));
    ASSERT_FLOAT_EQ(whereseq.Get(2),(a.Where(compare_two))->Get(2));
    ASSERT_FLOAT_EQ(reduce,(a.Reduce(higher_number,3)));
}

TEST(Matrix, Functions)
{
    float items[3*4] = {1, 2.6, 3,
                        -5, -6, -7.4,
                        5.6, 7.8, -9,
                        6.7, 12, 0};
    float items2[3*4] = {1, 1, 1,
                        -5, -6, -7.4,
                        1, 1, 1,
                        6.7, 12, 0};
    float items3[2*4] = {1, 1, 1,
                         -5, -6, -7.4};
    Matrix<float> float_matrix = Matrix<float>(items, 4,3);
    Matrix<float> float_matrix_2 = Matrix<float>(items2, 4,3);
    Matrix<float> float_matrix_3 = Matrix<float>(items3, 2,4);

    float_matrix.ElemTranform_1(1,2,4);
    ASSERT_FLOAT_EQ(-29.6 ,float_matrix.Get(1,2));
    float_matrix.ElemTranform_2(2,0,2);
    ASSERT_FLOAT_EQ(1,float_matrix.Get(2,0));
    float_matrix.ElemTranform_3(4,1,2,3);
    ASSERT_FLOAT_EQ(-76.8,float_matrix.Get(2,2));

    ASSERT_FLOAT_EQ(-148,float_matrix.MatrixMult(5).Get(1,2));
    ASSERT_FLOAT_EQ(-37,float_matrix.MatrixSum(float_matrix_2).Get(1,2));
    ASSERT_ANY_THROW(float_matrix.MatrixSum(float_matrix_3));

    ASSERT_FLOAT_EQ(94.0513,float_matrix.MatrixNorm());

    //ASSERT_FLOAT_EQ(52,float_matrix.MatrixSum(float_matrix_2).Get(1,2));
}

