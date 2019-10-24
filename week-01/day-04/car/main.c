#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

const char* get_type (struct car one_car)
{
    switch (one_car.type){
        case VOLVO : return "Volvo";
        case TOYOTA : return "Toyota";
        case LAND_ROVER : return "Landrover";
        case TESLA : return "Tesla";
        default: return "";
    }
}

void car_stats (struct car one_car)
{
    if (one_car.type != TESLA){
        printf("Type of Car: %s\n KM: %lf\n Gas: %lf\n\n", get_type(one_car), one_car.km, one_car.gas);
    } else {
        printf("Type of Car: %s\n KM: %lf\n\n", get_type(one_car), one_car.km);
    }
}

int main()
{
    struct car car1 = {TESLA, 40, 5};
    struct car car2 = {VOLVO, 120, 3};
    struct car car3 = {LAND_ROVER, 30, 2};
    struct car car4 = {TOYOTA, 39, 1};
    car_stats(car1);
    car_stats(car2);
    car_stats(car3);
    car_stats(car4);

    return 0;
}