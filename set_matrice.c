/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** set_matrice.c
*/

#include "include/my.h"

double **set_matrice_basic(double nbr1, double nbr2)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
        mat[i] = malloc(sizeof(double) * 1);
    mat[0][0] = nbr1;
    mat[1][0] = nbr2;
    mat[2][0] = 1;  
    return (mat);
}

double **set_matrice_translation(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
    mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[0][2] = nbr1;
    mat[1][0] = 0;
    mat[1][1] = 1;
    mat[1][2] = nbr2;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    printf("Translation along vector (%.0f, %.0f)\n", nbr1, nbr2);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}

double **set_matrice_rotation(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
    mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = cos(nbr1 / (180 / 3.14159265359));
    mat[0][1] = -sin(nbr1 / (180 / 3.14159265359));
    mat[0][2] = 0;
    mat[1][0] = sin(nbr1 / (180 / 3.14159265359));
    mat[1][1] = cos(nbr1 / (180 / 3.14159265359));
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] < 0 && mat[i][j] > -0.0000000001) {
                mat[i][j] *= -1;
            }
        }
    }
    printf("Rotation by a %.0f degree angle\n", nbr1);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}

double **set_matrice_scale(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
        mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = nbr1;
    mat[0][1] = 0;
    mat[0][2] = 0;
    mat[1][0] = 0;
    mat[1][1] = nbr2;
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    printf("Scaling by factors %.0f and %.0f\n", nbr1, nbr2);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}

double **set_matrice_reflection(double nbr1, double nbr2, double **mat1)
{
    double **mat;
    mat = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
    mat[i] = malloc(sizeof(double) * 3);
    mat[0][0] = cos(2 * (nbr1 / (180 / 3.14159265359)));
    mat[0][1] = sin(2 * (nbr1 / (180 / 3.14159265359)));
    mat[0][2] = 0;
    mat[1][0] = sin(2 * (nbr1 / (180 / 3.14159265359)));
    mat[1][1] = -cos(2 * (nbr1 / (180 / 3.14159265359)));
    mat[1][2] = 0;
    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 1;
    printf("Reflection over an axis with an inclination angle of %.0f degrees\n", nbr1);
    printf("%.2f %.2f %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f %.2f %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%.2f %.2f %.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    return (mul_matrice(mat1, mat));
}