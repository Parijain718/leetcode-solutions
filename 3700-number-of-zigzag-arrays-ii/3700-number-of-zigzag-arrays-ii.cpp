class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    vector<long long> multiplyMatVec(
        const Matrix& A,
        const vector<long long>& v) {

        int n = A.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        auto UP = [&](int x) {
            return x;
        };

        auto DOWN = [&](int x) {
            return m + x;
        };

        // Up[v] = sum Down[u], u < v
        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[UP(v)][DOWN(u)] = 1;
            }
        }

        // Down[v] = sum Up[u], u > v
        for (int v = 0; v < m; v++) {
            for (int u = v + 1; u < m; u++) {
                T[DOWN(v)][UP(u)] = 1;
            }
        }

        vector<long long> init(S, 0);

        // length = 2
        for (int v = 0; v < m; v++) {
            init[UP(v)] = v;
            init[DOWN(v)] = m - 1 - v;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState =
            multiplyMatVec(P, init);

        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};