# Curve_Fitting

A C++ program for fitting experimental data to mathematical curves using the **Least Squares Method (LSS)**.

## Supported Curves

The program performs curve fitting for:

* **Linear Curve**
  y = a + bx

* **Quadratic Curve**
  y = ax² + bx + c

* **Exponential Curve**
  y = abˣ

* **Power Curve**
  y = axᵇ

## Method Used

All models are fitted using the **Least Squares Method (LSS)**.

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
