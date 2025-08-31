# Binary Exponentation
Binary Exponentiation  (or exponentation by squaring) allows to calculate $a^n$ in using only $O(logn)$ multiplications.

It can be used with any operations that have the property of **associativity**.

$(X.Y).Z = X.(Y.Z)$

### Algorithm
$$
\operatorname{a^n} = 
\begin{cases}
    1 & \text{if } n==0 \\
    ({a^{n/2}})^{2} & \text{if } n>0 \text{ and } n \text{ even} \\
    (a^{(n-1)/2})^2 & \text{if } n>0 \text{ and } n \text{ odd}
\end{cases}
$$

Time Complexity: $O(log(n))$ \
Space Complexity: $O(1)$
