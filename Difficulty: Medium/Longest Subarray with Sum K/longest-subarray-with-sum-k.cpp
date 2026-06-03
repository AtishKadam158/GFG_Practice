class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long, int> mp;
        int n = arr.size();
        long long sum = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == k)
                max_len = max(max_len, i + 1);

            long long temp = sum - k;

            if (mp.count(temp))
                max_len = max(max_len, i - mp[temp]);

            if (!mp.count(sum))
                mp[sum] = i;
        }

        return max_len;
    }
};