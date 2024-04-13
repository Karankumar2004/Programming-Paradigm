#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **arr;

public:
    // Constructor
    Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            cout << "Error: Dimension must be +ve\n";
            return;
        }

        // allocating memory for Matrix
        arr = new int *[rows]; // Allocating memory for rows
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols]; // Allocating memory for cols
        }
    }

    // Destructor
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i]; // Deallocate each row
        }
        delete[] arr; // Now, Deallocate array
    }

    // Setter
    void setValue(int row, int col, int data)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            cout << "Invalid Matrix Index";
            return;
        }
        arr[row][col] = data;
    }

    // Getter
    int getValue(int row, int col)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            cout << "Invalid Matrix Index";
            return -1;
        }
        return arr[row][col];
    }

    // Matrix Addition
    Matrix operator+(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            // cout << "Matrices have not same dimension\n";
            // return;
            throw("Matrices have not same dimension\n");
        }

        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.setValue(i, j, arr[i][j] + other.arr[i][j]);
            }
        }
        return res;
    }

    // Matrix Multiplication
    Matrix operator*(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            // cout << "Matrices have not same dimension\n";
            // return;
            throw("Matrices have not same dimension\n");
        }

        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    res.setValue(i, j, arr[i][k] * other.arr[k][j]);
                }
            }
        }
        return res;
    }

    // Checking two matrices are Equal??
    bool isEqual(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            return false;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] != other.arr[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    // For Transpose
    Matrix transpose()
    {
        Matrix res(cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.setValue(i, j, arr[i][j]);
            }
        }
        return res;
    }

    // SubMatrix
    Matrix subMatrix(int s_row, int s_col, int e_row, int e_col)
    {
        if (s_row < 0 || s_col < 0 || e_row >= rows || e_col >= cols ||
            s_row > e_row || s_col > e_col)
        {
            throw("Invalid subMatrix dimensions");
        }
        // size of subMatrix
        int sub_row = e_row - s_row + 1; // row of submatrix
        int sub_col = e_col - s_col + 1; // col of submatrix
        Matrix matrix(sub_row, sub_col);
        for (int i = 0; i < sub_row; i++)
        {
            for (int j = 0; j < sub_col; j++)
            {
                matrix.setValue(i, j, arr[s_row + i][s_col + j]);
            }
        }
        return matrix;
    }

    // Inverse

    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << getValue(i, j) << " ";
            }
            cout << std::endl;
        }
    }
};
int main()
{
    Matrix A(2, 2);
    A.setValue(0, 0, 1);
    A.setValue(0, 1, 2);
    A.setValue(1, 0, 3);
    A.setValue(1, 1, 4);

    Matrix B(2, 2);
    B.setValue(0, 0, 5);
    B.setValue(0, 1, 6);
    B.setValue(1, 0, 7);
    B.setValue(1, 1, 8);

    cout << "Matrix A" << endl;
    A.show();

    return 0;
}