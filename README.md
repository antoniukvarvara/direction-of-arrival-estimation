# Direction of Arrival (DoA) Estimation & Simulation Tool

A comprehensive desktop application designed for mathematical modeling, simulation, and spatial spectral analysis in signal processing. The tool provides a graphical environment to simulate signal sources, introduce noise, and evaluate the resolution capabilities of advanced Direction of Arrival (DoA) estimation algorithms.

---

##  Tech Stack & Architecture Overview

The project is built using a hybrid architecture, combining the performance and low-level control of **C++** with the rapid data visualization capabilities of **Python**.

* **Frontend / GUI:** C++ Windows Forms – provides an intuitive user interface for configuring simulation parameters (number of sources, SNR, sensor array configuration).
* **Backend / Core Logic:** C++ Core Modules – handles signal generation, data extraction, and the computational heavy lifting of correlation matrices.
* **Visualization Engine:** Python (NumPy, Matplotlib) – integrated via inter-process communication to process computed spatial spectrum data and render high-quality, professional plots.

---

## Implemented Algorithms

The core focuses on high-resolution subspace-based estimation methodologies evaluated under Additive White Gaussian Noise (AWGN) conditions:

1.  **MUSIC (Multiple Signal Classification):** Realizes eigenvalue decomposition of the correlation matrix to separate the signal and noise subspaces, performing a grid search over the steering vectors to identify peak arrivals.
2.  **ESPRIT (Estimation of Signal Parameters via Rotational Invariance Techniques):** Exploits the rotational invariance property of sensor pairs to estimate angles directly without computationally expensive grid searches, significantly improving execution speed.

---

## Key Features

* **Dynamic Simulation:** Simulate multiple signal sources with adjustable incident angles and signal-to-noise ratios (SNR).
* **Cross-Language Integration:** Seamless file-based data exchange and script execution between C++ business logic and Python plotting modules.
* **Comparative Analysis:** Provides empirical data regarding the accuracy, angular resolution limits, and execution speed of MUSIC vs. ESPRIT.
* **Robust Architecture:** Designed with clear separation of concerns, backed by UML modeling and modular code architecture.

---

## Repository Structure

* `MainForm.h` / `MainForm.cpp` — UI layout, event handling, and parameter collection.
* `Signals.h` / `Methods.h` — Core mathematical logic, signal simulation, and matrix operations.
* `Sources.h` / `Sources.cpp` — Data structures representing signal arrays and wave sources.
* `Music.py` — Python-side implementation of advanced subspace matrix processing.
* `plot_spectrum.py` — Matplotlib configuration script for rendering spatial spectrum graphs.

---

## Prerequisites & Installation

To run this project locally, ensure you have the following installed:
1. Visual Studio (with C++ desktop development workload).
2. Python 3.x with `numpy` and `matplotlib` packages installed.

### How to run:
1. Clone the repository.
2. Open `DirectionOfArrival.sln` in Visual Studio.
3. Build and run the solution in `x64` configuration.
