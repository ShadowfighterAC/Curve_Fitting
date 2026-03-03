# Curve Fitting

A C++ program that performs curve fitting of experimental data using the **Least Squares Method (LSS)**.

## Supported Curves

The tool fits data to the following models:

* **Linear Curve**
  y = a + bx

* **Quadratic Curve**
  y = ax² + bx + c

* **Exponential Curve**
  y = abˣ

* **Power Curve**
  y = axᵇ

## Method Used

All curve fitting is performed using the **Least Squares Method**.

## Compilation

```bash
g++ src/main.cpp -o curvefit
```

## Run

```bash
./curvefit
```

## Author

Atharva Chandorkar
