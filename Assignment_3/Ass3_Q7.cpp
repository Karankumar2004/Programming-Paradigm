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
    int getValue(int row, int col, int data)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            cout << "Invalid Matrix Index";
            return;
        }
        return arr[row][col];
    }

    // Matrix Addition
    Matrix operator+(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices have not same dimension\n";
            return;
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
            cout << "Matrices have not same dimension\n";
            return;
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
        return false;
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

    void show()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << arr[i][j] << " ";
            }
            cout << std::endl;
        }
    }
};
int main()
{
    Matrix mat1(2, 2);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(1, 0, 3);
    mat1.setValue(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.setValue(0, 0, 5);
    mat2.setValue(0, 1, 6);
    mat2.setValue(1, 0, 7);
    mat2.setValue(1, 1, 8);

        return 0;
}