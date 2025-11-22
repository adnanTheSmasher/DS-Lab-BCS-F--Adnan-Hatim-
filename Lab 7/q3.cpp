    #include <iostream>
    #include<vector>
    using namespace std;
    
    struct Runner {
        string name;
        int time;
    };

    void merge(Runner a[], int beg, int mid, int end)
    {
        int i, j, k;
        int n1 = mid - beg + 1;
        int n2 = end - mid;

        Runner* LeftArray = new Runner[n1];
		Runner* RightArray = new Runner[n2];

    
        for (int i = 0; i < n1; i++)
            LeftArray[i] = a[beg + i];
        for (int j = 0; j < n2; j++)
            RightArray[j] = a[mid + 1 + j];

        i = 0; 
        j = 0; 
        k = beg;  

        while (i < n1 && j < n2)
        {
            if (LeftArray[i].time <= RightArray[j].time)
            {
                a[k] = LeftArray[i];
                i++;
            }
            else
            {
                a[k] = RightArray[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            a[k] = LeftArray[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            a[k] = RightArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(Runner a[], int beg, int end)
    {
        if (beg < end)
        {
            int mid = (beg + end) / 2;
            mergeSort(a, beg, mid);
            mergeSort(a, mid + 1, end);
            merge(a, beg, mid, end);
        }
    }


    int main()
    {
        int const SIZE = 10;
        Runner runners[SIZE];

        cout << "Enter names and finish times for" << SIZE <<" runners:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "Runner " << i + 1 << " name and time: ";
            cin >> runners[i].name >> runners[i].time;
        }

        mergeSort(runners, 0, SIZE - 1);

        cout << "\nTop"<< SIZE << " Fastest Runners:\n";
        for (int i = 0; i < 1; i++) {
            cout << i + 1 << ". " << runners[i].name << " - "
                << runners[i].time << " seconds\n";
        }

        return 0;
    }