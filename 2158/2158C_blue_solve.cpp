#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

// ST表 (Sparse Table) 模板
// 用于解决静态区间最值查询 (RMQ) 问题
// 预处理时间复杂度 O(N log N)，查询时间复杂度 O(1)
template <typename T>
struct ST
{
    vector<vector<T>> st;
    vector<int> log_table;
    int n;
    T (*op)(T, T); // 函数指针，用于指定是求最大值还是最小值

    ST(const vector<T> &arr, T (*op)(T, T)) : op(op)
    {
        n = arr.size();
        log_table.resize(n + 1, 0);
        // 预处理 log 值
        for (int i = 2; i <= n; ++i)
        {
            log_table[i] = log_table[i / 2] + 1;
        }
        int k = log_table[n] + 1;
        st.resize(k, vector<T>(n));
        st[0] = arr;
        // 倍增法构建 ST 表
        for (int j = 1; j < k; ++j)
        {
            for (int i = 0; i + (1 << j) <= n; ++i)
            {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    
    // 查询区间 [l, r] 的最值
    T query(int l, int r)
    {
        if (l > r)
            swap(l, r);
        int len = r - l + 1;
        int k = log_table[len];
        // 将区间分为两段覆盖，取最值
        return op(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

ll min_op(ll a, ll b) { return min(a, b); }
ll max_op(ll a, ll b) { return max(a, b); }

// 使用单调栈寻找每个元素左边第一个大于它的元素位置
// 实际上是寻找 abs_b[x] 作为最大值的左边界
vector<int> get_l(const vector<ll> &abs_b)
{
    int n = abs_b.size();
    vector<int> l(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        // 维护一个单调递减栈，弹出比当前元素小或相等的
        while (!st.empty() && abs_b[st.top()] <= abs_b[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            l[i] = st.top();
        }
        st.push(i);
    }
    return l;
}

// 使用单调栈寻找每个元素右边第一个大于等于它的元素位置
// 寻找 abs_b[x] 作为最大值的右边界
vector<int> get_r(const vector<ll> &abs_b)
{
    int n = abs_b.size();
    vector<int> r(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {
        // 维护单调递减栈，注意这里是 <，与 get_l 的 <= 配合处理相等元素的情况
        // 避免重复计算区间
        while (!st.empty() && abs_b[st.top()] < abs_b[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            r[i] = st.top();
        }
        st.push(i);
    }
    return r;
}

// 处理 k 为奇数的情况
// 目标：最大化 sum(a[i...j]) + max(abs_b[i...j])
ll solve_odd(const vector<int> &a, const vector<ll> &abs_b)
{
    int n = a.size();
    if (n == 0)
        return -INF;

    // 计算每个元素作为最大值的控制范围 [l[x]+1, r[x]-1]
    vector<int> l = get_l(abs_b);
    vector<int> r = get_r(abs_b);

    // 计算 a 的前缀和，用于快速计算子数组和
    vector<ll> sum_a(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        sum_a[i + 1] = sum_a[i] + a[i];
    }

    // 构建前缀和的 ST 表，用于快速查询区间内的最小/最大前缀和
    ST<ll> min_st(sum_a, min_op);
    ST<ll> max_st(sum_a, max_op);
    
    ll ans = -INF;
    
    // 枚举每个位置 x，假设 abs_b[x] 是子数组中的最大值 b
    for (int x = 0; x < n; ++x)
    {
        // abs_b[x] 是最大值的有效区间范围 [L, R]
        int L = l[x] + 1;
        int R = r[x] - 1;
        
        // 我们需要找到一个经过 x 的子数组 [i, j] (L <= i <= x <= j <= R)
        // 使得 sum(a[i...j]) 最大
        
        // 1. 计算以 x 结尾的最大后缀和 (在 [L, x] 范围内)
        // sum(a[i...x]) = sum_a[x+1] - sum_a[i]
        // 要最大化这个值，需要在 [L, x] 范围内找到最小的 sum_a[i]
        ll min_sum = min_st.query(L, x);
        ll max_l = sum_a[x + 1] - min_sum;
        
        // 2. 计算以 x 开头的最大前缀和 (在 [x, R] 范围内)
        // sum(a[x...j]) = sum_a[j+1] - sum_a[x]
        // 要最大化这个值，需要在 [x+1, R+1] 范围内找到最大的 sum_a[j+1]
        ll max_sum = max_st.query(x + 1, R + 1);
        ll max_r = max_sum - sum_a[x];
        
        // 3. 合并两部分，注意 a[x] 被计算了两次，需要减去一次
        ll s_max = max_l + max_r - a[x];
        
        // 当前的答案 = 最大子数组和 + 当前的最大 b 值
        ll cur = s_max + abs_b[x];
        ans = max(ans, cur);
    }

    return ans;
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<ll> abs_b(n);
    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;
        abs_b[i] = abs((ll)b);
    }

    ll ans;
    // 如果 k 是偶数
    // 题目性质：当 k 为偶数时，可以通过操作抵消掉 b 的影响
    // 问题退化为求 a 的最大子数组和 (Kadane 算法)
    if (k % 2 == 0)
    {
        int n = a.size();
        ll max_cur = a[0];
        ll maxn = a[0];
        for (int i = 1; i < n; ++i)
        {
            max_cur = max((ll)a[i], max_cur + a[i]);
            maxn = max(maxn, max_cur);
        }
        ans = maxn;
    }
    else
    {
        // 如果 k 是奇数
        // 问题转化为求 max(sum(a[sub]) + max(abs_b[sub]))
        ans = solve_odd(a, abs_b);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}