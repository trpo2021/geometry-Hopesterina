#include <ctest.h>
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

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(area_search, area_1)
{
    float radius = 0;

    int real = area_f(radius);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_2)
{
    float radius = 1;

    int real = area_f(radius);

    int exp = 3.1416;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_3)
{
    float radius = 2;

    int real = area_f(radius);

    int exp = 12.5664;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_4)
{
    float radius = 10;

    int real = area_f(radius);

    int exp = 314.16;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_1)
{
    float radius = 0;

    int real = perimetr_f(radius);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_2)
{
    float radius = 1;

    int real = perimetr_f(radius);

    int exp = 6.2832;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_3)
{
    float radius = 2;

    int real = perimetr_f(radius);

    int exp = 12.5664;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_4)
{
    float radius = 10;

    int real = perimetr_f(radius);

    int exp = 62.832;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, part_of_name)
{
    char str[2] = {"c"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, empty_name)
{
    char str[1] = {""};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char str[8] = {"8circle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_2)
{
    char str[8] = {"Cicle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_3)
{
    char str[8] = {"Circl"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_4)
{
    char str[8] = {"Oval"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_5)
{
    char str[8] = {"8848"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char str[7] = {"Circle"};

    int real = name_verification(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error)
{
    char str[8] = {" Circle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_2)
{
    char str[8] = {"C ircle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_3)
{
    char str[8] = {"Cir cle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, small_letter)
{
    char str[7] = {"circle"};

    int real = name_verification(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, empty_data)
{
    char str[9] = {"Circle"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, empty_data_2)
{
    char str[9] = {"Circle()"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, correct_data)
{
    char str[16] = {"Circle(0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space)
{
    char str[16] = {"Circle( 0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space_2)
{
    char str[17] = {"Circle (0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_lost_number)
{
    char str[16] = {"Circle(0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_2)
{
    char str[16] = {"Circle(0 0 ,8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_3)
{
    char str[20] = {"Circle(0, 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_bracket)
{
    char str[16] = {"Circle(0 0, 8"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_bracket_2)
{
    char str[14] = {"Circle0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_minus)
{
    char str[15] = {"Circle(-0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_excess)
{
    char str[17] = {"Circle( 0 0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_2)
{
    char str[16] = {"Circle (0 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_6)
{
    char str[16] = {"Circle(0 . 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_7)
{
    char str[16] = {"Circle(0 - 0, 8)"};

    int real = checking_parameters_figure(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}