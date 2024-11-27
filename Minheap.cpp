#include <iostream>
using namespace std;
class Heap
{

public:
    int *arr;
    int maxsize;
    int count;

    Heap(int size)
    {

        maxsize = size;
        arr = new int[maxsize];
        count = 0;
    }

    void insertHeap(int value)
    {

        if (count == maxsize)
        {
            return;
        }
        arr[count] = value;
        int temp = count;
        count++;
        while (temp > 0 && arr[(temp - 1) / 2] > arr[temp])
        {
            swap(arr[temp], arr[(temp - 1) / 2]);
            temp = (temp - 1) / 2;
        }
        cout << "Element added\n";
    }

    void print()
    {
        // cout << "Inside print";

        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main(int argc, char const *argv[])
{
    Heap ob(5);
    ob.insertHeap(66);
    ob.insertHeap(9596);
    ob.insertHeap(1);
    ob.insertHeap(35);
    ob.insertHeap(60);
    ob.print();
    return 0;
}
