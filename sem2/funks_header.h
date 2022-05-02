#pragma once

// funks.cpp
void printIntArr(int* arr, int arrSize);
int** newMatrix(int n, int m);
void scanfMatrix(int** matrix, int n, int m);
void printMatrix(int** matrix, int n, int m);
void deleteMatrix(int** matrix, int rows);
int** prodMatrix(int** nm_Mat, int** mk_Mat, int n, int m, int k);
void copyMatrix(int** Destination, int** Source, int n, int m);

// 3_reverse_n_delete.cpp
char* strrpl(char* origin, char* rplmnt, int begin);
