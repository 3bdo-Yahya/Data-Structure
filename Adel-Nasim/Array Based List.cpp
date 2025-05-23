#include <iostream>
#include <cassert>

using namespace std;

class arrayListType
{
public:
    arrayListType(int size = 100);
    arrayListType(arrayListType &otherList); // copy constructor
    ~arrayListType();                        // destructor

    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void print();
    bool isItemAtEqual(int loc, int item);
    void insertAt(int loc, int item);
    void insertEnd(int item);
    void removeAt(int loc);
    void retrieveAt(int loc, int &item);
    void replaceAt(int loc, int item);
    void clearList();
    int seqSearch(int item);
    void insertNoDuplicate(int item);
    void remove(int item);

private:
    int *list;   // array to hold the list elements
    int length;  // to store the length of the list
    int maxSize; // to store the maximum size of the list
};

arrayListType::arrayListType(int size)
{
    /* initilize the private members */
    if (size <= 0)
    {
        cout << " Wrong Size " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;
    list = new int[maxSize];
    assert(list != NULL); // terminate if unable to allocate memory space
}

arrayListType::arrayListType(arrayListType &otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new int[maxSize]; // create the array
    assert(list != NULL);    // terminate if unable to allocate memory space

    for (int j = 0; j < length; j++) // copy otherList
        list[j] = otherList.list[j];
}

arrayListType::~arrayListType()
{
    delete[] list;
}

bool arrayListType::isEmpty()
{
    return (length == 0);
}

bool arrayListType::isFull()
{
    return (length == maxSize);
}

int arrayListType::listSize()
{
    return length;
}

int arrayListType::maxListSize()
{
    return maxSize;
}

void arrayListType::print()
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

bool arrayListType::isItemAtEqual(int loc, int item)
{
    if (loc < 0 || loc >= length)
        return false;
    else
        return (list[loc] == item);
}

void arrayListType::insertAt(int loc, int item)
{
    if (isFull())
        cout << " The List is Full " << endl;
    else if (loc < 0 || loc > length)
        cout << "Out of Range " << endl;
    else
    {
        for (int i = length; i > loc; i--)
            list[i] = list[i - 1]; // shift right

        list[loc] = item; // insert the item at the specified position
        length++;         // increment the length
    }
}

void arrayListType::insertEnd(int item)
{
    if (isFull())
        cout << " The List is Full " << endl;
    else
        list[length++] = item;
}
void arrayListType::retrieveAt(int loc, int &item)
{
    if (loc < 0 || loc >= length)
        cout << "Out of Range " << endl;
    else
        item = list[loc];
}

void arrayListType::replaceAt(int loc, int item)
{
    if (loc < 0 || loc >= length)
        cout << "Out of Range " << endl;
    else
        list[loc] = item;
}

void arrayListType::clearList()
{
    length = 0;
}

int arrayListType::seqSearch(int item)
{
    for (int loc = 0; loc < length; loc++)
        if (list[loc] == item)
            return loc;
    return -1;
}

void arrayListType::insertNoDuplicate(int item)
{
    if (isFull())
        cout << " The List is Full " << endl;
    else
    {
        int flag = seqSearch(item);
        if (flag == -1)
            list[length++] = item;
        else
            cout << "No duplicates are allowed." << endl;
    }
}

void arrayListType::remove(int item)
{
    int loc = seqSearch(item);
    if (loc == -1)
        cout << "The item to be deleted is not in the list" << endl;
    else
        removeAt(loc);
}

void arrayListType::removeAt(int loc)
{
    if (loc < 0 || loc >= length)
        cout << "The location of the item to be removed is out of range." << endl;
    else
    {
        for (int i = loc; i < length - 1; i++)
            list[i] = list[i + 1];

        length--;
    }
}

int main()
{
    arrayListType lst1;
    for (int i = 0; i < 20; i++)
        lst1.insertAt(i, i * i);

    lst1.print();

    int x;
    lst1.retrieveAt(10, x);

    cout << x << endl;

    arrayListType lst2(lst1);

    lst2.print();

    return 0;
}