# Euclidean Algorithm

## GCD
Given two non-negative integers `a` and `b`, GCD (greatest common divisor) is the largest number which is a divisor of both `a` and `b`.

$$gcd(a,b) = max\{k>0 : (k | a)\ and\ (k | b)\}$$
(`|` denots divisibility)

Note:
1. When both number are zero, their GCD is undefined (it can be any arbitrarily large number)
2. If one of the number is zero, the gcd is the other number.
3. GCD is associative. $gcd(a,b,c)=gcd(a, gcd(b,c))$

#### Algorithm
Originally, the algorithm was formulated as follows: `Subtract the smaller number from the larger one until one of the number is zero.` Because if `g` divides `a` and `b`, it also divides `a-b`.
$$
(a|g)\ and\ (b|g) => (a-b)|g \\
((a-b)|g)\ and\ (b|g) => (a=(b+(a-b)))\ |\ g
$$
This means that sets of common divisors of $\{a,b\}$ and $\{b,a-b\}$ coincides.

Note that `a` remains larger number until `b` is subtracted from it at least $(\left\lfloor{\frac{x}{2}}\right\rfloor)$ times.

$a - \left\lfloor \frac{a}{b} \right\rfloor b = a\ mod\ b$

This results in:
$$
\operatorname{gcd(a, b)} = 
\begin{cases}
    a & \text{if b = 0} \\
    gcd(b, \text{a mod b}) & otherwise.
\end{cases}
$$

Time Complexity: $O(log\ min(a,b))$


