#include <iostream>
using namespace std;

class Set
{
private:
    int *arr;
    int size;
    int max_size; // Maximum kitna elements set me reh skta hai

public:
    // Construtor
    Set(int max_size = 15)
    {
        this->max_size = max_size;
        this->arr = new int[max_size];
        this->size = 0; // Initially no value it there so size is zero
    }

    // Destructor
    ~Set()
    {
        delete[] arr;
    }

    // INserting the elements in the array
    void add(int val)
    {
        if (size == max_size)
        {
            // cout << "Max size reached\n";

            // We can also incrase the size of array
            /*  max_size = 2*max_size;
              int *temp_array = new int[max_size]; //Naya array banaya jiska size double hai
              for(int i=0;i<size;i++){
                  temp_array[i] = arr[i]; //Abb sare values ko copy krdiya new array
              }
              delete []arr; //Now purane array ke memory ko delete kr diya not the "arr"
              arr = temp_array;
              */
        }

        // Abb new elements ko add karegee
        // First we are checking for the duplicates
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        { // agar duplicates nhi hai
            arr[size++] = val;
        }
    }

    /********Now Set operation************/
    // Union of two sets
    Set unionSet(const Set &other)
    { // Passing as const so that it can't be modifies in function
        // Set operator U(const Set& other){ // ???????/Doubt
        Set res(max_size + other.max_size); // Giving the space of sum of two set

        for (int i = 0; i < size; i++)
        { // Copying values from first set
            res.add(arr[i]);
        }

        // Copying values from 2nd set
        for (int i = 0; i < other.size; i++)
        {
            res.add(other.arr[i]);
        }

        return res;
    }

    // InterSection of two sets
    Set intersection(const Set &other)
    {
        Set res(max(max_size, other.max_size));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < other.size; j++)
            {
                if (arr[i] == other.arr[j])
                {
                    res.add(arr[i]);
                    break; // duplicates store na ho jaye
                }
            }
        }
        return res;
    }

    // Complement of Set relative to universal
    Set complement(const Set &universal)
    {
        Set res(universal.size);
        for (int i = 0; i < universal.size; i++)
        {
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                if (arr[j] == i)
                { // Agar values mil gya then usko add nhi karegee in "res" set
                    flag = false;
                    break;
                }
            }

            // Agar values same nhi mila
            if (flag)
            {
                res.add(i);
            }
        }
        return res;
    }

    // Set difference
    Set differenceSet(const Set &other)
    {                                           // it is just like complement but checking one set realtive to other
        Set res(max(max_size, other.max_size)); // here "this" arr is work as a universal set
        for (int i = 0; i < size; i++)
        {
            bool flag = true;
            for (int j = 0; j < other.size; j++)
            {
                if (arr[i] == other.arr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res.add(arr[i]);
            }
        }
        return res;
    }

    // Checking if two sets are equal or not
    bool isEqual(const Set &other)
    {
        // If size differ then not equal
        if (size != other.size)
            return false;

        // Now checking if all elements present in one set are there in other set
        for (int i = 0; i < size; i++)
        {
            bool flag = true;
            for (int j = 0; j < other.size; j++)
            {
                if (arr[i] != other.arr[j])
                { // If val inone set is not present in other set
                    return false;
                }
            }
        }
        return true;
    }

    // For displaying the Set
    void show()
    {
        cout << "{ ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "}\n";
    }
};

int main()
{
    // Create two sets
    Set set1;
    set1.add(1);
    set1.add(3);
    set1.add(5);
    set1.add(9);
    set1.add(7);
    std::cout << "Set 1: ";
    set1.show();

    Set set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);
    set2.add(9);
    set2.add(1);
    std::cout << "Set 2: ";
    set2.show();

    // Union of set
    Set unionSet = set1.unionSet(set2);
    cout << "Union: ";
    unionSet.show();

    // Intersection of set
    Set intersectionSet = set1.intersection(set2);
    cout << "Intersection: ";
    intersectionSet.show();

    // Complement of set1(universal set has 1-10 elements)
    Set complementSet = set1.complement(set2);
    cout << "Complement: ";
    complementSet.show();

    // Set difference of set(element in set 1 but not in set2)
    Set differenceSet = set1.differenceSet(set2);
    cout << "Difference: ";
    differenceSet.show();

    bool Equal = set1.isEqual(set2);
    cout << "Set1 and Set are equal ? " << (Equal ? "Yes" : "No") << "\n";

    return 0;
}