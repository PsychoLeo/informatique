#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>

#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << endl
#define ll long long
#define fi first
#define se second
#define vll vector<long long>

using namespace std;

struct Matrix {

	pair<int, int> format;
	vector<vll> M;

	Matrix (int n, int p, bool fillWithInput=true) {
		format.fi = n;
		format.se = p;
		M.resize(n, vll(p)); // declaring Matrix inside init function
		if (fillWithInput) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<p; j++) {
					scanf("%lld", &M[i][j]);
				}
			}
		}
		else {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					M[i][j] = 0;
				}
			}
		}
	}

	// Matrix operator += (Matrix& other) {
	// 	assert (format.fi == other.format.fi && format.se == other.format.se); 
	// 	for (int i=0; i<format.fi; i++) {
	// 		for (int j=0; j<format.se; j++) {
	// 			M[i][j] += other.M[i][j];
	// 		}
	// 	}
	// }

	Matrix operator * (const Matrix& other) {
		assert (format.se == other.format.fi);
		int newN = format.fi, newP = other.format.se;
		Matrix R = Matrix(newN, newP, false);
		for (int i=0; i<newN; i++) {
			for (int j=0; j<newP; j++) {
				for (int k=0; k<format.se; k++) {
					R.M[i][j] += M[i][k]*other.M[k][j];
				}
			}
		}
		return R;
	}

	// friend Matrix operator *= (int k, Matrix&m) {
	// 	for (int i=0; i<m.format.fi; i++) {
	// 		for (int j=0; j<m.format.se; j++) {
	// 			m.M[i][j] *= k;
	// 		}
	// 	}
	// 	return m;
	// }

	void printMatrix() {
		for (int i=0; i<format.fi; i++) {
			for (int j=0; j<format.se; j++) {
				printf("%lld ", M[i][j]);
			}
			printf("\n");
		}
	}
};

Matrix pow(Matrix m, int p) {
	// Supposons que la matrice est carrée
	assert (m.format.fi == m.format.se);
	Matrix R = Matrix(m.format.fi, m.format.fi, false); 
	for (int i=0; i<m.format.fi; i++) {
		R.M[i][i] = 1; // on remplit la diagonale
	}
	while (p > 0) {
		if (p & 1) {
			R = R*m;
		}
		p >>= 1;
		m = (m*m);
	}
	return R;
}

int main() {
	int n, p; // format of the matrix
	scanf("%d %d", &n, &p);
	Matrix m = Matrix(n, p);
	char oper; // operations to complete
	cin >> oper;
	if (oper ==  '*') { 
		int n2, p2; cin >> n2 >> p2;
		Matrix m2 = Matrix(n2, p2);
		Matrix R = m*m2;
		R.printMatrix();
	}
	else if (oper == '^') {
		int k; cin >> k;
		Matrix R = pow(m, k);
		R.printMatrix();
	}
	else {
		cout << "Invalid operation : " << oper << "\n";
	}
}
