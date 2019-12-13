#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	TMatrix<int> A1(A);
	EXPECT_EQ(A, A1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	TMatrix<int> A1(A);
	A[0][0] = 0;
	EXPECT_NE(A, A1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> A(3);
	EXPECT_EQ(3, A.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	EXPECT_EQ(1, A[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> A(1);
	ASSERT_ANY_THROW(A[-1][0] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{

	TMatrix<int> A(1);
	ASSERT_ANY_THROW(A[1][0] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	ASSERT_NO_THROW(A=A);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	TMatrix<int> A1(1);
	A1[0][0] = 2;
	A = A1;
	EXPECT_EQ(A, A1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> A(1);
	TMatrix<int> A1(2);
	A = A1;
	EXPECT_EQ(2, A.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> A(1);
	TMatrix<int> A1(2);
	A = A1;
	EXPECT_EQ(A, A1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> A(1);
	TMatrix<int> A1(2);
	A = A1;
	EXPECT_EQ(1,A == A1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	EXPECT_EQ(0, A != A);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> A(1);
	TMatrix<int> A1(2);
	EXPECT_EQ(0, A == A1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	cout << A << endl;
	TMatrix<int> A1(1);
	A1[0][0] = 2;
	cout << A1 << endl;
	TMatrix<int> res(1);
	res[0][0] = 3;
	cout << res << endl;
	EXPECT_EQ(res, A + A1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	TMatrix<int> A1(2);
	A1[0][0] = 0;
	A1[0][1] = 1;
	A1[1][0] = 2;
	A1[1][1] = 3;
	cout << A1 << endl;
	ASSERT_ANY_THROW(A + A1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> A(1);
	A[0][0] = 5;
	TMatrix<int> A1(1);
	A1[0][0] = 2;
	TMatrix<int> res(1);
	res[0][0] = 3;
	EXPECT_EQ(res, A - A1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> A(1);
	A[0][0] = 1;
	TMatrix<int> A1(2);
	A1[0][0] = 0;
	A1[0][1] = 1;
	A1[1][0] = 2;
	ASSERT_ANY_THROW(A = A - A1);
}

