#include<iostream>
#include <time.h>
#include<stdio.h>

using namespace std;
typedef unsigned char byte;

const int arr_len = 8000000;
const int number_of_access = 1000;
const char* msg = "Time: %d ** With step: %d \n";
const int times_len = 13;

unsigned int calculate_time(clock_t start, clock_t end);
void calculate_caches(int* times);

int main() {
    byte byte_arr[arr_len];
    int times[times_len];
    int counter = 0;

    for(int step = 1; step < arr_len / 2; step = step * 2)
    {
        clock_t start_time = clock();
        for (int i = 0; i < number_of_access; i++)
        {   
            int index = (i * step) % arr_len;
            byte_arr[index]++;
        }
        clock_t end_time = clock();

        times[counter++] = calculate_time(start_time, end_time);
    }

    calculate_caches(times);
}

unsigned int calculate_time(clock_t start, clock_t end) {
    unsigned int total_time_ticks = (unsigned int)(end - start);
    return total_time_ticks;
}

void calculate_caches(int* times) {
    int tmp = times[0];
    int counter = 0;
    for (int i = 0; i < times_len; i++) {
        if (times[i] / tmp >= 3) {
            tmp = times[i];
            counter = i;
        }
    }

    printf("Cache has less than 2^%d bytes free space \n", counter);
}