//在一个没有重复数字循环排序的数组中查找target的位置
//思路：不能直接二分法
//需要判断target是落在左半区间还是右半区间

class Solution {  
public:  
    int search(int A[], int n, int target) {  
        if(NULL == A || 0 == n)  
            return -1;  
        int left = 0, right = n-1, mid = 0;  
        while(left <= right)  
        {  
            mid = left+(right-left)/2;  
            if(A[mid] == target)  
                return mid;  
            else if(A[mid] > A[right])
			//左边是排好序的，则判断target是否落在左半区间
            {  
                if(A[left] <= target && target < A[mid])  
                    right = mid - 1;  
                else  
                    left = mid + 1;  
  
            }  
            else
			//右边是排好序的，则判断target是否落在右半区间
            {  
                if(A[mid] < target && target <= A[right])  
                    left = mid + 1;  
                else  
                    right = mid - 1;  
            }  
        }  
        return -1;  
    }  
}; 

//在一个有重复数字循环排序的数组中查找target的位置
//思路：不能直接二分法
//需要判断target是落在左半区间还是右半区间，和没有重复的数组的判断方法不同，因为有可能中间元素等于左右两端的元素
class Solution {  
public:  
    bool search(int A[], int n, int target) {  
        if(NULL == A || 0 == n)  
            return false;  
        int left = 0, right = n-1, mid = 0;  
        while(left <= right)  
        {  
            mid = left+(right-left)/2;  
            if(A[mid] == target)  
                return true;  
            bool isLeft = true;  
            for(int i = left; i <= mid; ++i)  
			//判断左边是排好序的还是右边是排好序的
			//如果左边是排好序的，则左边的所有数都应该小于等于A[mid]
                if(A[i] > A[mid])  
                {  
                    isLeft = false;  
                    break;  
                }  
            if(isLeft)//left  
            {  
                if(A[left] <= target && target < A[mid])  
                    right = mid - 1;  
                else  
                    left = mid + 1;  
  
            }  
            else//right  
            {  
                if(A[mid] < target && target <= A[right])  
                    left = mid + 1;  
                else  
                    right = mid - 1;  
            }  
        }  
  
        return false;  
    }  
}; 