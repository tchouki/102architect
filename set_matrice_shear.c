/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** set_matrice_shear.c
*/

#include "include/my.h"

double **set_matrice_shear_x(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
    mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = 1;
    mat[0][1] = nbr1;
    mat[0][2] = 0;
    mat[1][0] = 0;
    mat[1][1] = 1;
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    printf("Shear along axis x %.0f\n", nbr1);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}

double **set_matrice_shear_y(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
    mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[0][2] = 0;
    mat[1][0] = nbr1;
    mat[1][1] = 1;
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    printf("Shear along axis y %.0f\n", nbr1);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}