#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

// ��������� ������ ��� �������
template<typename T>
T**& GetMemory(T**& pmatrix, size_t const rows, size_t const columns)
{
    size_t i = 0;
    try
    {
        pmatrix = new T * [rows];
        for (i = 0; i < rows; ++i)
            pmatrix[i] = 0;
        for (i = 0; i < rows; ++i)
            pmatrix[i] = new T[columns];
    }
    catch (std::bad_alloc const& exc)
    {
        std::cerr << "GetMemory: Exception: ���������� ��������� ������\n\n";
        for (i = 0; i < rows; ++i)
        {
            delete[] pmatrix[i];
            pmatrix[i] = 0;
        }
        delete[] pmatrix;
        pmatrix = 0;
        throw;
    }
    return pmatrix;
}

// ����������� ������ ��-��� �������
template<typename T>
void FreeMemory(T** pmatrix, size_t const rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] pmatrix[i];
        pmatrix[i] = 0;
    }
    delete[] pmatrix;
    pmatrix = 0;
}

// ��������� ������� �� �����
template<typename T>
T**& FillFromFile(std::string const& filepath, T**& pmatrix, size_t& rows, size_t& columns)
{
    try
    {
        std::ifstream ifs(filepath.c_str());
        if (ifs.is_open())
        {
            ifs >> rows >> columns;
            if (!rows || !columns)
                throw "������ ������ �����\n";
            GetMemory(pmatrix, rows, columns);
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < columns; ++j)
                {
                    ifs >> pmatrix[i][j];
                }
            }
            if (!ifs)
                throw "������ ������ �����\n";
            ifs.close();
        }
        else
            std::cerr << "FillFromFile: ���������� �������� �����\n";
    }
    catch (char const* e)
    {
        std::cerr << "FillFromFile: Exception: " << e << "\n\n";
        throw;
    }
    return pmatrix;
}

// ����� ������� � �����
template<typename T>
std::ostream& MatrixToStream(T* const* const pmatrix, size_t const rows, size_t const columns, std::ostream& ost = std::cout)
{
    ost << "\n-------------------------MatrixToStream-------------------------------\n";
    ost << "������: " << rows << " x " << columns << "\n";
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            ost << std::setw(13) << std::left << pmatrix[i][j];
        }
        ost << "\n\n";
    }
    ost << "\n----------------------------------------------------------------------\n";
    return ost;
}

// ��������� ������� �� �����
double* MultiplicationArrayToNumber(double* parray, size_t const columns, double const number)
{
    for (size_t j = 0; j < columns; ++j)
    {
        parray[j] = parray[j] * number;
    }
    return parray;
}

// ��������� ������� 2 �� ������� 1 (��� ������ �����)
double* SubtractionOfArrays(double* parray1, double* parray2, size_t const columns)
{
    for (size_t j = 0; j < columns; ++j)
    {
        parray1[j] = parray1[j] - parray2[j];
    }
    return parray1;
}

// ����� ���� ��������
void SwapArrays(double* parray1, double* parray2, size_t const columns)
{
    double* ptmparray = new double[columns];
    memcpy(ptmparray, parray1, columns * sizeof(double));
    memcpy(parray1, parray2, columns * sizeof(double));
    memcpy(parray2, ptmparray, columns * sizeof(double));
    delete[] ptmparray;
    ptmparray = 0;
}

// ����� ������, ���������� � �������� ������� ������������ ������� �� ���� �����
size_t MaxRowIndex(double** pdmatrix, size_t const rows, size_t const columnindex)
{
    size_t maxrowindex = columnindex, i, j;
    for (i = columnindex + 1; i < rows; ++i)
    {
        if (pdmatrix[i][columnindex] > pdmatrix[columnindex][columnindex])
            maxrowindex = i;
    }
    return maxrowindex;
}

// ���������� ������� � ������������ ����
double** MakeTriangularMatrix(double** pdmatrix, size_t const rows, size_t const columns)
{
    if (rows + 1 == columns)
    {
        size_t i = 0, j = 0, k = 0, maxrowindex = 0;
        double* prowcopy = new double[columns];
        for (j = 0; j < rows - 1; ++j)
        {
            maxrowindex = MaxRowIndex(pdmatrix, rows, j);
            if (maxrowindex != j)
                SwapArrays(pdmatrix[maxrowindex], pdmatrix[j], columns);
            if (double(0) != pdmatrix[j][j])
            {
                MultiplicationArrayToNumber(pdmatrix[j], columns, 1 / pdmatrix[j][j]);
                for (i = j + 1; i < rows; ++i)
                {
                    memcpy(prowcopy, pdmatrix[j], columns * sizeof(double));
                    MultiplicationArrayToNumber(prowcopy, columns, pdmatrix[i][j]);
                    SubtractionOfArrays(pdmatrix[i], prowcopy, columns);
                }
            }
        }
        delete[] prowcopy;
        prowcopy = 0;
        // �������� ������� �� ������������(���� � ����� ����� ���� ����, � � ������ �� ����)
        for (i = 0; i < rows; ++i)
        {
            bool zerorow = true;
            for (j = 0; j < columns - 1; ++j)
            {
                if (pdmatrix[i][j] != double(0))
                    zerorow = false;
            }
            if (zerorow && pdmatrix[i][columns - 1] != double(0))
            {
                std::cout << "\nC������ �����������\n\n";
                break;
            }
            else if (zerorow && pdmatrix[i][columns - 1] == double(0))
            {
                std::cout << "\nC������ ����� ����������� ��������� �������\n\n";
                break;
            }
        }
    }
    else
        std::cerr << "�� ���������: rows + 1 == columns\n";
    return pdmatrix;
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string const filepath("input.txt"); // ���� � ��������
    size_t rows = 0, columns = 0;
    double** pdmatrix = 0;
    FillFromFile(filepath, pdmatrix, rows, columns);
    std::cout << "�������� �������:\n";
    MatrixToStream(pdmatrix, rows, columns);
    MakeTriangularMatrix(pdmatrix, rows, columns);
    std::cout << "����������� �������:\n";
    MatrixToStream(pdmatrix, rows, columns);
    FreeMemory(pdmatrix, rows);
    return 0;
}