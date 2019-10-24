#include <stdio.h>
#include <string.h>

typedef enum DIGIVOLUTION {
 BABY, INTRAINING, ROOKIE, CHAMPION, ULTIMATE, MEGA
}digivolution_t;

typedef struct digimon{
    char* name;
    char* name_of_tamer;
    int age;
    int health;
    enum DIGIVOLUTION level;
}digimon_t;

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

digimon_t* get_minimum_health_digimon (digimon_t* array, int array_length)
{
    int min_health = 101;
    digimon_t* result_ptr = NULL;
    for (int i= 0; i < array_length; i++){
        if (array[i].health > 0 && array[i].health <  min_health){
            min_health = array[i].health;
            result_ptr = array + i;
        }
    }
    return result_ptr;
}

int count_digimons_by_level (digimon_t* array, int array_length, digivolution_t level)
{
    int result = 0;
    for (int i = 0; i < array_length; i++) {
        if (array[i].level == level) {
            result++;
        }
    }
    return result;
}

int count_digimons_by_tamers (digimon_t* array, int array_length, const char* tamer)
{
    int result = 0;
    for (int i = 0; i < array_length; i++) {
        if (strcmp (array[i].name_of_tamer, tamer) == 0) {
            result++;
        }
    }
    return result;
}

float average_health_by_tamers (digimon_t* array, int array_length, const char* tamer)
{
    float result = 0;
    int counter = 0;
    for (int i = 0; i < array_length; i++) {
        if (strcmp (array[i].name_of_tamer, tamer) == 0) {
            result += array[i].health;
            counter++;
        }
    }
    return result / counter;
}
int main()
{
    digimon_t digimons[5];
    digimons[0].health = 50;
    digimons[0].level = MEGA;
    digimons[0].name_of_tamer = "Bela";
    digimons[1].health = 40;
    digimons[1].level = BABY;
    digimons[1].name_of_tamer = "Endru";
    digimons[2].health = 90;
    digimons[2].level = BABY;
    digimons[2].name_of_tamer = "Bela";
    digimons[3].health = 20;
    digimons[3].level = INTRAINING;
    digimons[3].name_of_tamer = "Ceda";
    digimons[4].health = 77;
    digimons[4].level = MEGA;
    digimons[4].name_of_tamer = "Hmm";
    printf("Lowest health Digimon's tamer: %s, health: %d, level: %d\n",
            get_minimum_health_digimon(digimons, 5)->name_of_tamer,
            get_minimum_health_digimon(digimons, 5)->health,
            get_minimum_health_digimon(digimons, 5)->level);
    printf("number of BABY level Digimon: %d\n", count_digimons_by_level(digimons, 5, BABY));
    printf("number of Bela tamers Digimon: %d\n", count_digimons_by_tamers(digimons, 5, "Bela"));
    printf("average of Bela tamers Digimon: %f\n", average_health_by_tamers(digimons, 5, "Bela"));
    return 0;
}