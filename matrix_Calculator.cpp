#include <iostream>
#include <fstream>
using namespace std;
int A[3][3];
int B[3][3];
int C[3][3];
string matrix = " ";
void takeInput();
void seperater();
void print();
void addition();
void Substraction();
void Multiplication();
void transpose();
void isDiagnol();
void isIdentity();
int main()
{
    while (matrix != "Exit")
    {
        takeInput();
        seperater();
        if (matrix == "C=A+B")
        {
            addition();
        }
        else if (matrix == "C=A-B")
        {
            Substraction();
        }
        else if (matrix == "C=A*B")
        {
            Multiplication();
        }
        print();
        isIdentity();
        isDiagnol();
        transpose();
    }

    return 0;
}
void takeInput()
{
    cout << ">>";
    cin >> matrix;
}
void seperater()
{
    string temp_string = " ";
    int temp_num;
    int temp = 3;
    if (matrix[0] == 'A')
    {
        for (int rows = 0; rows < 3; rows++)
        {
            for (int i = temp, column = 0; i <= 19; i += 2, temp += 2, column++)
            {
                temp_string = matrix[i];
                temp_num = stoi(temp_string);

                A[rows][column] = temp_num;
            }
        }
    }
    else if (matrix[0] == 'B')
    {
        for (int rows = 0; rows < 3; rows++)
        {
            for (int i = temp, column = 0; i <= 19; i += 2, temp += 2, column++)
            {
                temp_string = matrix[i];
                temp_num = stoi(temp_string);

                B[rows][column] = temp_num;
            }
        }
    }
}
void print()
{
    if (matrix == "print(A)")
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                cout << A[row][column] << '\t';
            }
            cout << endl;
        }
    else if (matrix == "print(B)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                cout << B[row][column] << '\t';
            }
            cout << endl;
        }
    }
    else if (matrix == "print(C)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                cout << C[row][column] << '\t';
            }
            cout << endl;
        }
    }
}
void addition()
{

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            C[row][column] = A[row][column] + B[row][column];
        }
    }
}
void Substraction()
{

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            C[row][column] = A[row][column] - B[row][column];
        }
    }
}
void Multiplication()
{
    for (int row = 0; row < 3; row++)
    {
        for (int mid = 0; mid < 3; mid++)
        {
            int sum = 0;
            for (int col = 0; col < 3; col++)
            {
                sum = (A[row][col] * B[col][mid]) + sum; //
            }
            C[row][mid] = sum;
        }
    }
}
void isDiagnol()
{
    bool temp_val = true;
    if (matrix == "isDiagnol(A)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    continue;
                }
                else if (A[row][col] != 0)
                {
                    temp_val= false;
                }
            }
        }
        cout << temp_val<<endl;
    }
    else if (matrix == "isDiagnol(B)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    continue;
                }
                else if (B[row][col] != 0)
                {
                    temp_val=false;
                }
            }
        }
        cout << temp_val<<endl;
    }
    else if (matrix == "isDiagnol(C)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    continue;
                }
                else if (C[row][col] != 0)
                {
                    temp_val= false;
                }
            }
        }
        cout << temp_val<<endl;
    }
}
void isIdentity()
{
    bool temp_value = true;
    if (matrix == "isIdentity(A)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    if (A[row][col] != 1)
                    {
                        temp_value= false;
                    }
                }
                else if (A[row][col] != 0)
                {
                    temp_value= false;
                }
            }
        }
        cout << temp_value<<endl;
    }
    else if (matrix == "isIdentity(B)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    if (B[row][col] != 1)
                    {
                        temp_value= false;
                    }
                }
                else if (B[row][col] != 0)
                {
                    temp_value= false;
                }
            }
        }
        cout<<temp_value<<endl;
    }
    else if (matrix == "isIdentity(C)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col)
                {
                    if (C[row][col] != 1)
                    {
                        temp_value= false;
                    }
                }
                else if (C[row][col] != 0)
                {
                    temp_value=false;
                }
            }
        }
        cout<< temp_value<<endl;
    }
}
void transpose()
{
    int temp = 0;
    if (matrix == "transpose(A)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = row; col < 3; col++)
            {
                temp = A[row][col];
                A[row][col] = A[col][row];
                A[col][row] = temp;
            }
        }
    }
    else if (matrix == "transpose(B)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = row; col < 3; col++)
            {
                temp = B[row][col];
                B[row][col] = B[col][row];
                B[col][row] = temp;
            }
        }
    }
    else if (matrix == "transpose(C)")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = row; col < 3; col++)
            {
                temp = C[row][col];
                C[row][col] = C[col][row];
                C[col][row] = temp;
            }
        }
    }
}