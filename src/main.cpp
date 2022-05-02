#include <iostream>

#include "sort.hpp"
#include "timer.hpp"
#include "random.hpp"

int main(int argc, char** argv)
{
    // int size = 1000;
    // rng::prng prng;
    // int *lista = new int[size];
    // int *listb = new int[size];
    // int *listc = new int[size];
    // int *listd = new int[size];

    // for (int i = 0; i < size; i++)
    // {
    //     int val = prng.randi(1, 1000);
    //     lista[i] = val;
    //     listb[i] = val;
    //     listc[i] = val;
    //     listd[i] = val;
    // }

    // bench::timer t;
    
    // t.start();

    // sort::quicksort<int>(lista, 0, size);

    // t.stop();

    // std::cout << "quicksort: " << t.deltatime() << std::endl;

    // t.start();

    // sort::bubblesort<int>(listb, 0, size);

    // t.stop();

    // std::cout << "bubblesort: " << t.deltatime() << std::endl;

    // t.start();

    // sort::insertionsort<int>(listc, 0, size);

    // t.stop();

    // std::cout << "insertionsort: " << t.deltatime() << std::endl;

    // t.start();

    // sort::selectionsort<int>(listd, 0, size);

    // t.stop();

    // std::cout << "selectionsort: " << t.deltatime() << std::endl;

    // delete[] lista;
    // delete[] listb;
    // delete[] listc;
    // delete[] listd;

    int list[5] = {5, 4, 3, 2, 1};

    sort::print_list<int>(list, 5);
    sort::mergesort(list, 0, 5);
    sort::print_list<int>(list, 5);
}