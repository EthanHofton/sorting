#ifndef sort_hpp
#define sort_hpp

#include <stack>

namespace sort
{
    template<typename T>
    void swap(T* t_list, int t_a, int t_b)
    {
        T tmp = t_list[t_a];
        t_list[t_a] = t_list[t_b];
        t_list[t_b] = tmp;
    }

    template<typename T>
    void move(T* t_list, int t_src, int t_dest)
    {
        if (t_src == t_dest)
        {
            return;
        }

        std::stack<T> sk;
        T val = t_list[t_src];

        for (int i = 0; i <= std::max(t_src, t_dest); i++)
        {
            if (i != t_src)
            {
                sk.push(t_list[i]);
            }
        }

        for (int i = std::max(t_src, t_dest); i >= 0; i--)
        {
            if (i == t_dest)
            {
                t_list[i] = val;
            } else {
                t_list[i] = sk.top();
                sk.pop();
            }
        }
    }

    template<typename T>
    void print_list(T* t_list, int t_size)
    {
        for (int i = 0; i < t_size; i++)
        {
            std::cout << t_list[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    void print_list(T* t_list, int t_a, int t_b)
    {
        for (int i = t_a; i < t_b; i++)
        {
            std::cout << t_list[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    int partition(T *t_list, int t_a, int t_b)
    {
        int lastsmall = t_a;
        for (int i = t_a + 1; i < t_b; i++)
        {
            if (t_list[i] <= t_list[t_a])
            {
                lastsmall++;
                swap<T>(t_list, lastsmall, i);
            }
        }

        swap<T>(t_list, lastsmall, t_a);

        return lastsmall;
    }

    template<typename T>
    void merge(T* t_list, int t_a, int m, int t_b)
    {
        int i, j;
        int *aux = new int[t_b];

        for (i = m + 1; i > t_a; i--)
        {
            aux[i-1] = t_list[i-1];
        }

        for (j = m; j < t_b; j++)
        {
            aux[t_b+m-j] = t_list[j+1];
        }

        for (int k = t_a; k <= t_b; k++)
        {
            if (aux[j] < aux[i])
            {
                t_list[k] = aux[j--];
            } else {
                t_list[k] = aux[i++];
            }
        }

        delete[] aux;
    }

    template<typename T>
    void quicksort(T* t_list, int t_a, int t_b)
    {
        if (t_a >= t_b)
        {
            return;
        }

        int pivot = partition<T>(t_list, t_a, t_b);

        quicksort(t_list, t_a, pivot);
        quicksort(t_list, pivot + 1, t_b);
    }

    template<typename T>
    void bubblesort(T* t_list, int t_a, int t_b)
    {
        for (int i = t_a; i < t_b - 1; i++)
        {
            for (int x = 0; x < t_b - 1; x++)
            {
                if (t_list[x] > t_list[x + 1])
                {
                    swap<T>(t_list, x, x+1);
                }
            }
        }
    }

    template<typename T>
    void insertionsort(T* t_list, int t_a, int t_b)
    {
        for (int i = t_a; i < t_b; i++)
        {
            for (int x = t_a; x < i; x++)
            {
                if (t_list[i] < t_list[x])
                {
                    move<T>(t_list, i, x);
                    break;
                }
            }
        }
    }

    template<typename T>
    void selectionsort(T* t_list, int t_a, int t_b)
    {
        for (int x = t_a; x < t_b; x++)
        {
            int min = x;
            for (int i = x; i < t_b; i++)
            {
                if (t_list[i] < t_list[min])
                {
                    min = i;
                }
            }
            swap<T>(t_list, min, x);
        }
    }

    template<typename T>
    void mergesort(T* t_list, int t_a, int t_b)
    {
        if (t_a >= t_b)
        {
            return;
        }

        int m = (t_a + t_b) / 2;

        mergesort(t_list, t_a, m);
        mergesort(t_list, m + 1, t_b);

        merge<T>(t_list, t_a, m, t_b);
    }
}

#endif