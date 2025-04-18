// #pragma once

#include <iostream>
#include <cmath>

#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H


/////////////////////////////////////////////////////////////////////////////////////////
// SILU Activation Function

float silu(float x) {
    return x / (1 + exp(-x));
}

/////////////////////////////////////////////////////////////////////////////////////////
// Sigmoid Activation Function

float sig(float x) {
    return 1 / (1 + exp(-x));
}

#endif
