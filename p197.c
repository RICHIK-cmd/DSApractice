#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

typedef struct
{
    int key;
    int value;
} HashMap;

int subarraySum(int arr[], int n, int k)
{
    int pref_sum = 0;
    int ans = 0;

    HashMap mp[SIZE];

    // Initialize hashmap
    for (int i = 0; i < SIZE; i++)
    {
        mp[i].key = 0;
        mp[i].value = 0;
    }

    // We need prefix sum 0 to exist once initially
    // This handles subarrays starting from index 0
    mp[0].key = 0;
    mp[0].value = 1;

    for (int i = 0; i < n; i++)
    {
        pref_sum += arr[i];

        // Check if pref_sum - k exists
        for (int j = 0; j < SIZE; j++)
        {
            if (mp[j].value > 0 && mp[j].key == pref_sum - k)
            {
                ans += mp[j].value;
                break;
            }
        }

        // Check if current prefix sum already exists
        int found = 0;

        for (int j = 0; j < SIZE; j++)
        {
            if (mp[j].value > 0 && mp[j].key == pref_sum)
            {
                mp[j].value++;
                found = 1;
                break;
            }
        }

        // If prefix sum doesn't exist, insert it
        if (found == 0)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (mp[j].value == 0)
                {
                    mp[j].key = pref_sum;
                    mp[j].value = 1;
                    break;
                }
            }
        }
    }

    return ans;
}

int main()
{
    int n, k;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = subarraySum(arr, n, k);

    printf("Number of subarrays with sum %d = %d\n", k, result);

    return 0;
}