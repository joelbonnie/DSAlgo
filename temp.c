void merge(int lb, int mid, int ub)
{
    int i=lb, j=mid+1, k=lb, b[ub+1];
    while (i<=mid && j<=ub)
    {
        if (arr[i]<=arr[j])
        {
            b[k]=arr[i++];
        }
        else
        {
            b[k]=arr[j++];
        }
        k++;
    }
    if (i>mid)
    {
        while (j<=ub)
        {
            b[k++]=arr[j++];
        }
    }
    else
    {
        while (i<=mid)
        {
            b[k++]=arr[i++];
        }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
}

void mergeSort(int lb, int ub)
{
    int mid;
    if (lb<ub)
    {
        mid = (lb+ub)/2;
        mergeSort(lb,mid);
        mergeSort(mid+1,ub);
        merge(lb,mid,ub);
    }
}