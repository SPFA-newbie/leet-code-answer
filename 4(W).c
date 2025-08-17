double FindMiddle(int *nums, int start, int end)
{
    if ((end - start + 1 ) % 2 == 1) {
        return nums[(end - start) / 2];
    } else {
        return (nums[(end - start) / 2] + nums[(end - start) / 2 + 1]) / 2.0;
    }
}

void SwapArray(int **nums1, int **nums2, int **start1, int **end1, int **start2, int **end2)
{
    int *temp;
    temp = (*nums1);  (*nums1) = (*nums2);   (*nums2) = temp;
    temp = (*start1); (*start1) = (*start2); (*start2) = temp;
    temp = (*end1);   (*end1) = (*end2);     (*end2) = temp;
}

void FindRange(int *nums1, int *nums2, int *start1, int *end1, int *start2, int *end2)
{
    double middle1 = FindMiddle(nums1, *start1, *end1);
    double middle2 = FindMiddle(nums2, *start2, *end2);
    if (middle2 < middle1) {
        SwapArray(&nums1, &nums2, &start1, &end1, &start2, &end2);
        double temp = middle1;
        middle1 = middle2;
        middle2 = temp;
    }
    (*start1) = ((*end1) - (*start1)) / 2;
    (*end2) = ((*end2) - (*start2) + 1) / 2;
    int l = (*start1);
    int r = (*end1);
    int mid = (l + r + 1) / 2;
    while (l != r) {
        if (nums1[mid] > nums2[*end2]) {
            r = mid;
        } else {
            l = mid;
        }
        mid = (l + r + 1) / 2;
        if (r - l == 1) {
            if (nums1[r] == nums2[*end2]) {
                l = r;
            }
            break;
        }
    }
    (*end1) = l;
    
    l = (*start2);
    r = (*end2);
    mid = (l + r) / 2;
    while (l != r) {
        if (nums2[mid] < nums1[*start1]) {
            l = mid;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;
        if (r - l == 1) {
            if (nums2[l] == nums1[*start1]) {
                r = l;
            }
            break;
        }
    }
    (*start2) = r;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size == 0) {
        return FindMiddle(nums2, 0, nums2Size - 1);
    }
    if (nums2Size == 0) {
        return FindMiddle(nums1, 0, nums1Size - 1);
    }
    int start1 = 0;
    int start2 = 0;
    int end1 = nums1Size - 1;
    int end2 = nums2Size - 1;
    while (end1 - start1 > 1 && end2 - start2 > 1) {
        FindRange(nums1, nums2, &start1, &end1, &start2, &end2);
        if (nums1[start1] == nums1[end1] && nums2[start2] == nums2[end2] && nums1[end1] == nums2[end2]) {
            return nums1[start1];
        }
        if (abs(FindMiddle(nums1, start1, end1) - FindMiddle(nums2, start2, end2)) < 1e-10) {
            return FindMiddle(nums1, start1, end1);
        }
    }
    if (start1 == end1 && start2 == end2) {
        return (nums1[start1] + nums2[start2]) / 2.0;
    } else if (start1 != end1 && start2 != end2) {
        int arr[4];
        arr[0] = nums1[start1];
        arr[1] = nums1[end1];
        arr[2] = nums2[start2];
        arr[3] = nums2[end2];
        int maxx = arr[0];
        int minn = arr[0];
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            maxx = (maxx > arr[i] ? maxx : arr[i]);
            minn = (minn < arr[i] ? minn : arr[i]);
            sum += arr[i];
        }
        return (sum - maxx - minn) / 2.0;
    } else if (start1 != end1) {
        if (nums2[start2] > nums1[end1]) {
            return nums1[end1];
        } else if (nums2[start2] < nums1[start1]) {
            return nums1[start1];
        }
        return nums2[start2];
    } else {
        if (nums1[start1] > nums2[end2]) {
            return nums2[end2];
        } else if (nums1[start1] < nums2[start2]) {
            return nums2[start2];
        }
        return nums1[start1];
    }
}
