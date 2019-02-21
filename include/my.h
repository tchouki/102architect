/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define HELPER "USAGE\n 	./102architect x y tansfo1 arg111 [arg12] [transfo2 arg12 [arg22]] ...\n\nDESCRIPION\n 	x abscissa of the original point\n 	y ordinate of the original point\n\n 	transfo arg1 [arg2]\n 	-t i j 	translation along vector (i, j)\n 	-z m n 	scaling by factors m (x-axis) and n (y-axis)\n 	-r d 	rotation centered in 0 by a d degree angle\n 	-s d 	reflection over the axis passing through 0 with an inclination\n 		angle of d degrees"

typedef struct flags {
	char letter;
	double **(*ptr)(double nbr1, double nbr2, double **mat);
} flags_t;

//set_matrice_shear.c
double **set_matrice_shear_x(double nbr1, double nbr2, double **mat1);
double **set_matrice_shear_y(double nbr1, double nbr2, double **mat1);

//set_matrice.c
double **set_matrice_basic(double nbr1, double nbr2);
double **set_matrice_translation(double nbr1, double nbr2, double **mat1);
double **set_matrice_rotation(double nbr1, double nbr2, double **mat1);
double **set_matrice_scale(double nbr1, double nbr2, double **mat1);
double **set_matrice_reflection(double nbr1, double nbr2, double **mat1);

//main.c
double **mul_matrice(double **mat1, double **mat2);
double **copy_matrice(double **mat1, double **mat2);
int main(int argc, char *argv[]);

#endif