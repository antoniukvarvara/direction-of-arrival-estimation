#pragma once
#pragma managed(push, off) 
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;

typedef complex<double> cd;

class SubspaceMethods {
public:
    //МЬЮЗІК!!
  
    //масив значень спектра
    vector<double> computeMUSIC(const MatrixXcd& R, int M, double d, int D) {
        SelfAdjointEigenSolver<MatrixXcd> solver(R);     // розклад матриці на власні значення та власні вектори

        MatrixXcd En = solver.eigenvectors().leftCols(M - D);  // шумовий підпростір- вектори що відповідають найменшим значенням. Eigen сортує власні значення за зростанням

        vector<double> spectrum;
        for (int angle = -90; angle <= 90; ++angle) {
            VectorXcd a(M);
            double theta_rad = angle * EIGEN_PI / 180.0;

            for (int m = 0; m < M; ++m) {
                double phase = -2.0 * EIGEN_PI * d * m * sin(theta_rad);
                a(m) = exp(cd(0, phase));
            }  // формування напрямного вектора для поточного кута

            // Обчислення просторового спектра
            cd denominator = a.adjoint() * En * En.adjoint() * a;
            spectrum.push_back(1.0 / abs(denominator));
        }
        return spectrum;
    }

    //ЕСПРІТ!!!
    
    //масив конкретних знайдених кутів 
    vector<double> computeESPRIT(const MatrixXcd& R, int M, double d, int D) {
        SelfAdjointEigenSolver<MatrixXcd> solver(R);
      
        MatrixXcd Es = solver.eigenvectors().rightCols(D);  //сигнальний підпростір- вектори що відповідають найбільшим значенням

        // дві підрешітки 
        MatrixXcd E1 = Es.topRows(M - 1);
        MatrixXcd E2 = Es.bottomRows(M - 1);

        MatrixXcd Psi = E1.householderQr().solve(E2);  //розвязання перевизначеної системи методом найменших квадратів

        //власні значення матриці повороту псі
        ComplexEigenSolver<MatrixXcd> ces(Psi);
        VectorXcd eigenvalues = ces.eigenvalues();

        vector<double> estimated_angles;
        for (int i = 0; i < D; ++i) {
            double phi = arg(eigenvalues(i)); // фаза
            double sin_theta = phi / (-2.0 * EIGEN_PI * d);

            if (sin_theta > 1.0) sin_theta = 1.0;
            if (sin_theta < -1.0) sin_theta = -1.0;

            //назад у градуси
            double angle = asin(sin_theta) * 180.0 / EIGEN_PI;
            estimated_angles.push_back(angle);
        }
        return estimated_angles;
    }
};
#pragma managed(pop)