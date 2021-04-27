#pragma once

struct circle {
    int x;
    int y;
    float r;
};

int name_verification(char* input_arr);
int checking_parameters_figure(char* input_arr);
float area_f(float radius);
float perimetr_f(float radius);
void print_intersects(int ncircle, struct circle* data_circle);