#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <chrono>
#include <vector>

typedef std::chrono::high_resolution_clock Clock;

int BubbleSortTxt(int& bubbleTime);
int BubbleSortTxtTwo(int& bubbleTimeTwo);

int QuickSortTxt(int& quickTime);
//int QuickSortTxtTwo(int& quickTimeTwo);

int Partition(int A[], int low, int high)               // To reaarange array (partition point)
{
    int pivot, temp, i;

    pivot = A[high];                                    // pivot is the right most
    i = low - 1;                                        // index smaller element

    for (int j = low; j < high; j++)                    // if element is smaller, swap with higher 
    {
        if (A[j] < pivot)                               // eg if (80 < 70) = false so it would do this then -
        {
            i++;                                        // increment smaller element

            temp = A[i];                                // swapping greater element with lower    
            A[i] = A[j];                        
            A[j] = temp;                                // swap i and j
        }
    }
    if (A[high] < A[i + 1])                             
    {
        temp = A[i + 1];                                 
        A[i + 1] = A[high];
        A[high] = temp;
    }
    return i + 1;

}

void QuickSort(int arr[], int low, int high)
{
    int p;
    if (low < high)
    {
        p = Partition(arr, low, high);                  // find pivot for elements to move to either side

        QuickSort(arr, low, p - 1);                     // call on left of pivot
        QuickSort(arr, p + 1, high);                    // call on right of pivot
    }
}


int main(void)
{
    int bubbleTime{};
    int bubbleTimeTwo{};
    int quickTime{};
    //int quickTimeTwo{};

    BubbleSortTxt(bubbleTime);
    BubbleSortTxtTwo(bubbleTimeTwo);
    QuickSortTxt(quickTime);
    //QuickSortTxtTwo(quickTimeTwo); 

    std::cout << "Bubble - Txt1: " << bubbleTime    << "ms" << std::endl;
    std::cout << "Bubble - Txt2: " << bubbleTimeTwo << "ms" << std::endl;
    std::cout << "Quick - Txt1: "  << quickTime     << "ms" << std::endl;
    //std::cout << "Quick - Txt2: "  << quickTimeTwo  << "ms" << std::endl;

    std::cout << "\nText file One :" << std::endl;
    std::cout << "Bubble Sort - Quick Sort = " << bubbleTime - quickTime << "ms.\n" << std::endl;

    std::cout << "Text file Two :" << std::endl;
    std::cout << "I tried malloc (probably wrong though) but Quick Sort in Text file Two doesn't work" << std::endl;

   
    return 0;
}

int BubbleSortTxt(int& bubbleTime)
{
    auto start_time = Clock::now();

    // open input 1 for readinging
    std::ifstream file;

    file.open("a2_task1_input1.txt", std::ifstream::in);
    if (!file.is_open())
    {
        std::cout << "File not open LOL" << std::endl;
        return 1;
    }

    // read numnber of elements - not really needing
    int numberOfElements;
    file >> numberOfElements;

    // create dynamic array of elements
    int* elements = (int*)malloc(numberOfElements * sizeof(int));       // malloc
    //std::vector<int> elements;                                        // vector

    // read all elements from file into array
    int element;                                                        // malloc and vector
    int index = 0;                                                      // malloc
    while (file >> element) // reads number into element variable
    {
        //elements.push_back(element); // adds back vector              // vector

        elements[index] = element;                                      // malloc
        ++index;                                                        // malloc
    }

    // repeatedly step through input list element by element
    bool didDoSwap = false;
    do
    {
        // set to false, no swaps done yet
        didDoSwap = false;


        // for all elements in vecto, compare and maybe swap
        for (int index = 0; index < numberOfElements - 1; ++index)      // use elements.size() instead of numberOfElements when using vector
        {
            // get this element and next
            int element = elements[index];
            int nextElement = elements[index + 1];

            // if this element is LARGER than next, swap                // change > to < to determin largest to smaller, vice versa
            if (element > nextElement)
            {
                // swap values
                elements[index] = nextElement;
                elements[index + 1] = element;
                didDoSwap = true;
            }

        }

       
    } while (didDoSwap == true);

    // prints sorted numbers, not needed
   /* for (int index = 0; index < numberOfElements; ++index)        // use elements.size() instead of numberOfElements when using vector
    {
        std::cout << elements[index] << std::endl;
    }*/
    
    auto end_time = Clock::now();

   bubbleTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    //std::cout << "Bubble Sort Time difference:"
    //    << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms" << std::endl;

    return bubbleTime;
}

int BubbleSortTxtTwo(int& bubbleTimeTwo)
{
    auto start_time = Clock::now();

    // open input 1 for readinging
    std::ifstream file;

    file.open("a2_task1_input2.txt", std::ifstream::in);
    if (!file.is_open())
    {
        std::cout << "File not open LOL" << std::endl;
        return 1;
    }

    // read numnber of elements - not really needing
    int numberOfElements;
    file >> numberOfElements;

    // create dynamic array of elements
    int* elements = (int*)malloc(numberOfElements * sizeof(int));       // malloc
    //std::vector<int> elements;                                        // vector

    // read all elements from file into array
    int element;                                                        // malloc and vector
    int index = 0;                                                      // malloc
    while (file >> element) // reads number into element variable
    {
        //elements.push_back(element); // adds back vector              // vector

        elements[index] = element;                                      // malloc
        ++index;                                                        // malloc
    }

    // repeatedly step through input list element by element
    bool didDoSwap = false;
    do
    {
        // set to false, no swaps done yet
        didDoSwap = false;


        // for all elements in vecto, compare and maybe swap
        for (int index = 0; index < numberOfElements - 1; ++index)      // use elements.size() instead of numberOfElements when using vector
        {
            // get this element and next
            int element = elements[index];
            int nextElement = elements[index + 1];

            // if this element is LARGER than next, swap                // change > to < to determin largest to smaller, vice versa
            if (element > nextElement)
            {
                // swap values
                elements[index] = nextElement;
                elements[index + 1] = element;
                didDoSwap = true;
            }

        }


    } while (didDoSwap == true);

    // prints sorted numbers, not needed
   /* for (int index = 0; index < numberOfElements; ++index)        // use elements.size() instead of numberOfElements when using vector
    {
        std::cout << elements[index] << std::endl;
    }*/

    auto end_time = Clock::now();

    bubbleTimeTwo = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    //std::cout << "Bubble Sort Time difference:"
    //    << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms" << std::endl;

    return bubbleTimeTwo;
}

int QuickSortTxt(int& quickTime)
{
    auto start_time = Clock::now();

    std::ifstream file;
    file.open("a2_task1_input1.txt", std::ifstream::in);
    if (!file.is_open())
    {
        std::cout << "File not open LOL" << std::endl;
        return 1;
    }

    // read numnber of elements 
    int numberOfElements;
    file >> numberOfElements;

    // create dynamic array of elements
    int* elements = (int*)malloc(numberOfElements * sizeof(int));       // malloc
    //std::vector<int> elements;                                        // vector

    // read all elements from file into array
    int element;                                                        // malloc and vector
    int index = 0;                                                      // malloc

    while (file >> element) // reads number into element variable
    {
        //elements.push_back(element); // adds back vector              // vector

        elements[index] = element;                                      // malloc
        ++index;                                                        // malloc
    }

    QuickSort(elements, 0, numberOfElements - 1);

    auto end_time = Clock::now();

    quickTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    

    //std::cout << "Quick Sort Time difference:"
    //    << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms" << std::endl;

    return quickTime;
}

/*
int QuickSortTxtTwo(int& quickTimeTwo)
{
    auto start_time = Clock::now();

    std::ifstream file;
    file.open("a2_task1_input2.txt", std::ifstream::in);
    if (!file.is_open())
    {
        std::cout << "File not open LOL" << std::endl;
        return 1;
    }

    // read numnber of elements 
    int numberOfElements;
    file >> numberOfElements;

    // create dynamic array of elements
    int* elements = (int*)malloc(numberOfElements * sizeof(int));       // malloc
    //std::vector<int> elements;                                        // vector

    // read all elements from file into array
    int element;                                                        // malloc and vector
    int index = 0;                                                      // malloc

    while (file >> element) // reads number into element variable
    {
        //elements.push_back(element); // adds back vector              // vector

        elementsTwo[index] = element;                                      // malloc
        ++index;                                                        // malloc
    }

    QuickSort(elements, 0, numberOfElements - 1);

    auto end_time = Clock::now();

    quickTimeTwo = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    

    //std::cout << "Quick Sort Time difference:"
    //    << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms" << std::endl;

    return quickTimeTwo;
}
*/ // crashes when trying to sort txt 2




// just digusting code after plenty of trial and error :)

/*
int BubbleSortFunction(void)
{
    auto start = std::chrono::system_clock::now();

    std::string buffer;
    std::ifstream file("a2_task1_input1.txt");

    int *myArray = new int[5000];
    int i = 0;

    if (!file.good() || !file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        exit(1);
    }

    while (getline(file, buffer))			  
    {
            if (file.is_open())
            {
                while (file >> myArray[i])
                {
                    std::cout << myArray[i] << std::endl;
                    i++;
                }
            }

        std::cout << "\n\n";

        for (i = 0; i < 5000; i++)
        {
            for (int j = (i + 1); j < 5000; j++)
            {
                if (myArray[i] > myArray[j])
                {
                    double temp = myArray[i];
                    myArray[i] = myArray[j];
                    myArray[j] = temp;
                }
            }
        }

        for (i = 0; i < 5000; i++)
        {
            std::cout << myArray[i] << ",";
        }

        std::cout << "\n";
    }

    file.close();       // closes the file
    delete[] myArray;   // Idk if this is really needed, do testing

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout
        << "\nTime Elapsed: " << elapsed.count() << "ms.\n" << std::endl;

    system("pause");

    return 0;

}

int partition(int A[], int lo, int hi)
{
    int pivot, temp, i;
    pivot = A[hi];
    i = lo - 1;
    for (int j = lo; j < hi; j++)
    {
        if (A[j] < pivot)
        {
            i = i + 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    if (A[hi] < A[i + 1])
    {
        temp = A[i + 1];
        A[i + 1] = A[hi];
        A[hi] = temp;
    }
    return i + 1;

}

void quickSort(int arr[], int lo, int hi)
{
    int p;
    if (lo < hi)
    {
        p = partition(arr, lo, hi);
        quickSort(arr, lo, p - 1);
        quickSort(arr, p + 1, hi);
    }
}
*/

/*
int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) 
        {
            if (arr[i] <= pivot)
                count++;
        }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot)
            {
                i++;
            }

        while (arr[j] > pivot)
            {
                j--;
            }

        if (i < pivotIndex && j > pivotIndex) 
            {
                std::swap(arr[i++], arr[j--]);
            }
    }

    return pivotIndex;
}

void QuickSort(int myArray[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = Partition(myArray, start, end);

    // Sorting the left part
    QuickSort(myArray, start, p - 1);

    // Sorting the right part
    QuickSort(myArray, p + 1, end);
}

int QuickSortFunction(void)
{
    auto start = std::chrono::system_clock::now();

    std::string buffer;
    std::ifstream file("a2_task1_input1.txt");

    int* myArray = new int[5000];
    int i = 0;

    int n = 5000; // amount of numbers in txt file

    if (!file.good() || !file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        exit(1);
    }

    while (getline(file, buffer))
    {
        if (file.is_open())
        {
            while (file >> myArray[i])
            {
                std::cout << myArray[i] << std::endl;
                i++;
            }
        }

        std::cout << "\n\n";

        QuickSort(myArray, 0, n - 1);

        for (i = 0; i < 5000; i++)
        {
            std::cout << myArray[i] << ",";
        }

        std::cout << "\n";
    }

    file.close();       // closes the file
    delete[] myArray;   // Idk if this is really needed, do testing

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout
        << "\nTime Elapsed: " << elapsed.count() << "ms.\n" << std::endl;

    system("pause");

    return 0;
}
*/

/*auto start = std::chrono::system_clock::now();

    std::string buffer;
    std::ifstream file("a2_task1_input1.txt");

    int* myArray = new int[5000];
    int n = 5000;

    QuickSort(myArray, 0, n - 1);

    file.close();       // closes the file
    delete[] myArray;   // Idk if this is really needed, do testing

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout
        << "\nTime Elapsed: " << elapsed.count() << "ms.\n" << std::endl;

    system("pause");*/

/*
	std::string buffer;

	std::ifstream file("a2_task1_input1.txt"); // read file

	if (!file.good() || !file.is_open())
	{
		std::cout << "Failed to open file." << std::endl;
			exit(1);
	}

	while (getline(file, buffer))			   // output file
	{
		std::cout << buffer << std::endl;
	}

	file.close();

	system("pause");
*/ 




