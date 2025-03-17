// Binary Modular Exponentiation
// mod > 0
template<typename T>
T binModExp(T base, T exp, T mod) {
    T ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) ans = ans * base % mod;
        base = base * base % mod; 
        exp >>= 1;
    }
    return ans;
}
// Binary Modular Inverse
// mod is a prime number
// base % mod != 0
template<typename T>
T binModInv(T base, T mod) {
    return binModExp(base, mod - 2, mod);
}
