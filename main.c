/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** main.c
*/

#include "include/my.h"

static const flags_t flags[6] = {
    {'t', &set_matrice_translation},
    {'z', &set_matrice_scale},
    {'r', &set_matrice_rotation},
    {'s', &set_matrice_reflection},
    {'x', &set_matrice_shear_x},
    {'y', &set_matrice_shear_y}
};

double **mul_matrice(double **mat1, double **mat2)
{
    double **result;

    result = malloc(sizeof(double*) * 3);
    for (int i = 0; i < 3; i++)
        result[i] = malloc(sizeof(double) * 3);
    result = set_matrice_basic(0, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][0] += mat1[j][0] * mat2[i][j];
        }
    }
    return (result);
}

double **copy_matrice(double **mat1, double **mat2)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat1[i][j] = mat2[i][j];
        }
    }
    return (mat1);
}

int main(int argc, char *argv[])
{
    int i = 1;
    double **mat1 = malloc(sizeof(double*) * 3);

    if (argv[1] != NULL) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            printf("%s\n", HELPER);
    }
    if (argc < 3) {
        printf("BAD ARGUMENT\n");
        return (84);
    }
    while (i < argc) {
        if (argv[1][0] < '0' || argv[1][0] > '9')
            return (84);
        if (argv[2][0] < '0' || argv[2][0] > '9')
            return (84);
        if (argv[i][0] == '-' && (argv[i][1] == 'r' || argv[i][1] == 's')) {
            if (argc < i + 2)
                return (84);
            if ((argv[i + 1][0] < '0' || argv[i + 1][0] > '9') && argv[i + 1][0] != '-')
                return (84);
            i += 1;
        }
        if (argv[i][0] == '-' && (argv[i][1] == 't' || argv[i][1] == 'z')) {
            if (argc < i + 3)
                return (84);
            if ((argv[i + 1][0] < '0' || argv[i + 1][0] > '9') && argv[i + 1][0] != '-') 
                return (84);
            if ((argv[i + 2][0] < '0' || argv[i + 2][0] > '9') && argv[i + 2][0] != '-') 
                return (84);
            i += 2;
        }
        i++;
    }
    i = 1;
    for (int i = 0; i < 3; i++)
        mat1[i] = malloc(sizeof(double) * 1);
    mat1 = set_matrice_basic(atof(argv[1]), atof(argv[2]));
    while (i < argc) {
        if (argv[i][0] == '-' && (argv[i][1] == 'r' || argv[i][1] == 's' || argv[i][1] == 'x' || argv[i][1] == 'y')) {
            for (int j = 2; j < 6; j++) {
                if (argv[i][1] == flags[j].letter) {
                    mat1 = flags[j].ptr(atof(argv[i + 1]), 0, mat1);
                    mat1[2][0] = 1;
                }
            }
            i += 1;
        }
        else if (argv[i][0] == '-' && (argv[i][1] == 't' || argv[i][1] == 'z')) {
            for (int j = 0; j < 2; j++) {
                if (argv[i][1] == flags[j].letter) {
                    mat1 = flags[j].ptr(atof(argv[i + 1]), atof(argv[i + 2]), mat1);
                    mat1[2][0] = 1;
                }
            }
            i += 2;
        }
        i++;
    }
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", atof(argv[1]), atof(argv[2]), mat1[0][0], mat1[1][0]);
    return (0);
}