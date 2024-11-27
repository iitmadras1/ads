#include <iostream>
using namespace std;

class Heap
{

public:
    int *arr;
    int elementnum;
    int maxsize;

    Heap(int size)
    {
        arr = new int[size];
        maxsize = size;
        elementnum = 0;
    }

    void insertHeap(int value)
    {

        if (elementnum == maxsize)
        {
            cout << "Heap overflown\n";
            return;
        }

        arr[elementnum] = value;
        int temp = elementnum;
        elementnum++;
        sortHeap(temp);
        cout << "Value added \n";
    }

    void sortHeap(int help)
    {

        while (help > 0 && arr[(help - 1) / 2] < arr[help])
        {
            if (arr[(help - 1) / 2] < arr[help])
            {
                swap(arr[(help - 1) / 2], arr[help]);
                help = (help - 1) / 2;
            }
        }
    }

    void print()
    {

        for (int i = 0; i < elementnum; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Heap ob(5);
    cout << "Hello";
    ob.insertHeap(10);
    ob.insertHeap(56);
    ob.insertHeap(1);
    ob.insertHeap(896);
    ob.insertHeap(65);
    // ob.insertHeap(650);
    ob.print();
    cout << "Hello";
    return 0;
}
