//Insertion Sort
class insertionSort{
public:
  insertionSort(int* arr,int N);
  void sort(int* arr,int N);
  void swap(int* arr,int i,int j);
};
insertionSort::insertionSort(int* arr,int N){
  sort(arr,N);
}
void insertionSort::sort(int* arr,int N){
  for(int i=1;i<N;i++)
  {
      for(int j=i;j>=1;j--)
      {
          compares++;
          if(arr[j]<arr[j-1])
              {
                exchanges++;
                swap(arr,j,j-1);
                visual(arr);
              }
          else
              break;
      }
  }
}
void insertionSort::swap(int* arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


//Selection Sort
class selectionSort{
public:
  selectionSort(int* arr,int N);
  void sort(int* arr,int N);
  void swap(int* arr,int i,int j);
};
selectionSort::selectionSort(int* arr,int N){
  sort(arr,N);
}
void selectionSort::sort(int* arr,int N)
{
    for(int i=0;i<N-1;i++)
    {
        int ind = i;
        for(int j=i+1;j<N;j++)
        {
            compares++;
            if(arr[j]<arr[ind])
                ind = j;
            visual(arr);
        }
        exchanges++;
        swap(arr,i,ind);
        visual(arr);
    }
}
void selectionSort::swap(int* arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



// Quick Sort
class quickSort{
public:
  quickSort(int* arr,int N);
  void sort(int* arr,int lo,int hi);
  void sort_shuffle(int* arr,int i,int j);
  int part(int* arr,int lo,int hi);
  void swap(int* arr,int i,int j);
};
quickSort::quickSort(int* arr,int N){
  sort_shuffle(arr,0,N);
}
void quickSort::sort_shuffle(int* arr,int i,int j)
{
  std::random_shuffle(arr,arr+j);
  sort(arr,i,j);
}
void  quickSort::sort(int* arr,int lo,int hi)
{
  visual(arr);
  if(lo>=hi)
  return;
  int j = part(arr,lo,hi);
  sort(arr,lo,j-1);
  visual(arr);
  sort(arr,j+1,hi);
  visual(arr);
}

int quickSort::part(int* arr,int lo,int hi)
{
    int i = lo,j = hi+1;
    while(true)
    {
        while(arr[++i]<arr[lo])
        {
          compares++;
            if(i == hi)
                break;
        }
        while(arr[lo]<arr[--j])
        {
          compares++;
            if(j==lo)
                break;
        }
        if(i>=j)
            break;
        exchanges++;
        swap(arr,i,j);
        visual(arr);
    }
    exchanges++;
    swap(arr,lo,j);
    visual(arr);
    return j;
}
void quickSort::swap(int* arr,int i,int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


//Merge Sort
class mergeSort{
public:
  mergeSort(int* arr,int N);
  void sort(int* arr,int* aux,int lo,int hi);
  void merge(int* arr,int* aux,int low,int mid, int high);
};
mergeSort::mergeSort(int* arr,int N){
  int aux[N];
  for(int i=0;i<N;i++){
    aux[i] = arr[i];
  }
  sort(arr,aux,0,N-1);
}
void mergeSort::sort(int* arr,int* aux,int low,int high)
{
  compares++;
  if(low>=high)
  return;
  int mid = low + (high-low)/2;
  
  sort(arr,aux,low,mid);
  visual(arr);
  sort(arr,aux,mid+1,high);
  visual(arr);
  merge(arr,aux,low,mid,high);
  visual(arr);
}
void mergeSort::merge(int* arr,int* aux,int low,int mid, int high)
{
    int i=low,j=mid+1;
    // This step can be optimized by alternatively using aux and arr array
    // as the auxilary array
    for(int i=0;i<N;i++)
    {
      aux[i] = arr[i];
    }
    for(int k=low;k<=high;k++)
    {
        if(i>mid)
        {
            arr[k] = aux[j++];
            compares++;
            exchanges++;
        }
        else if(j>high)
        {
            arr[k] = aux[i++];
            compares++;
            exchanges++;
        }
        else if(aux[i]>aux[j])
        {
            arr[k] = aux[j++];
            compares++;
            exchanges++;
        }
        else
        {
            arr[k] = aux[i++];
            compares++;
            exchanges++;
        }
        visual(arr);
    }
}

//Heap Sort
class heapSort{
public:
  heapSort(int* arr,int N);
  void heapify(int* arr, int N, int i);
  void sort(int* arr,int N);
  void swap(int* arr,int i,int j);
};
heapSort::heapSort(int* arr,int N){
  sort(arr,N);
}

void heapSort::heapify(int* arr, int N, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest]){
        compares++;
        largest = left;
      }
  
    // If right child is larger than largest so far
    if (right < N && arr[right] > arr[largest]){
        compares++;
        largest = right;
      }
  
    // If largest is not root
    if (largest != i) {
        compares++;

        exchanges++;
        swap(arr, i, largest);
  
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
        visual(arr);
    }
    visual(arr);
}

void heapSort::sort(int* arr,int N)
{
      // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
        visual(arr);
      }

        // One by one extract an element from heap
    for (int i = N - 1; i >= 0; i--) {
        // Move current root to end
        exchanges++;
        swap(arr, 0, i);
  
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
        visual(arr);
    }

}

void heapSort::swap(int* arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}