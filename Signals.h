#pragma once
#pragma managed(push, off) 

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <random>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;

typedef complex<double> cd;

class SignalGenerator {
public:
    int M;      //антени
    double d;   //в≥дстань м≥ж ними

    SignalGenerator(int m_antennas, double spacing) : M(m_antennas), d(spacing) {}

    //генерац≥€ матриц≥ спостережень
    MatrixXcd generateData(const vector<double>& angles_deg, double snr_db, int snapshots) {
        int D = static_cast<int>(angles_deg.size());

        //матриц€ напр€мних вектор≥в
        MatrixXcd A(M, D);
        for (int i = 0; i < D; ++i) {
            double theta_rad = angles_deg[i] * EIGEN_PI / 180.0;
            for (int m = 0; m < M; ++m) {
                double phase = -2.0 * EIGEN_PI * d * m * sin(theta_rad);
                A(m, i) = exp(cd(0, phase)); // e^(-j * фаза)
            }
        }

        //матриц€ випром≥нених сигнал≥в 
        //генер. незалежн≥ комплексн≥ сигнали
        MatrixXcd S = MatrixXcd::Zero(D, snapshots);
        default_random_engine gen_s;
        uniform_real_distribution<double> phase_dist(0.0, 2.0 * EIGEN_PI);
        for (int i = 0; i < D; ++i) {
            for (int t = 0; t < snapshots; ++t) {
                S(i, t) = exp(cd(0, phase_dist(gen_s)));//випадкова початкова фаза дл€ кожного в≥дл≥ку ≥м≥туЇ некорельован≥ джерела
            }
        }

        //матриц€ шуму
        double snr_linear = pow(10, snr_db / 10.0);
        double sigma = sqrt(1.0 / (2.0 * snr_linear)); //сигнал потужн≥стю 1,тому шум 1/снр. /2 у€вна та д≥йсна частини

        default_random_engine gen_n;
        normal_distribution<double> noise_dist(0.0, sigma);

        MatrixXcd N(M, snapshots);
        for (int m = 0; m < M; ++m) {
            for (int t = 0; t < snapshots; ++t) {
                N(m, t) = cd(noise_dist(gen_n), noise_dist(gen_n));
            }
        }

        //матриц€ прийн€тих сигнал≥в
        MatrixXcd X = A * S + N;
        return X;
    }

    //обчисленн€ корел€ц≥йноњ матриц≥
    MatrixXcd computeCorrelationMatrix(const MatrixXcd& X) {
        double N = (double)X.cols(); 
        return (X * X.adjoint()) / N; //R=(X*X^H)/N
    }
};
#pragma managed(pop) 