#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int one = 1, two = 2;
        int res = 0;
        for (int i = 2; i < number; ++i) {
            res = one + two;
            one = two;
            two = res;
        }
        return res;
    }
};

/*
    对于本题,前提只有 一次 1阶或者2阶的跳法。
    
    a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);
    
    b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)
    
    c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 
    
    d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2
    
    e.可以发现最终得出的是一个斐波那契数列：
*/

