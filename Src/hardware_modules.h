#pragma once

#include "activations.h"

#ifndef HARDWARE_MODULES_H
#define HARDWARE_MODULES_H

////////////////////////////////////// CONVOLUTION FUNC IMAGE ////////////////////////////////////////////
template<typename InputType, typename KernelType, typename BiasType, typename OutputType,
         int FEATURE_MAP, int OUTPUT, int IN_CHANNEL, int KERNEL, int STRIDE, int IN_ARRAY, int PAD>

void conv1(InputType input[IN_CHANNEL][IN_ARRAY][IN_ARRAY],
			 KernelType kernel[FEATURE_MAP][IN_CHANNEL][KERNEL][KERNEL],
			 BiasType bias[FEATURE_MAP],
			 OutputType output[FEATURE_MAP * OUTPUT * OUTPUT]) {
    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = 0;
                for (int ic = 0; ic < IN_CHANNEL; ic++) {
                    for (int kh = 0; kh < KERNEL; kh++) {
                        for (int kw = 0; kw < KERNEL; kw++) {
                            int input_row = oh * STRIDE + kh - PAD;
                            int input_col = ow * STRIDE + kw - PAD;
                            if (input_row >= 0 && input_row < IN_ARRAY && input_col >= 0 && input_col < IN_ARRAY) {
                                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] +=
								input[ic][input_row][input_col] * kernel[oc][ic][kh][kw];
                            }
                        }
                    }
                }
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] += bias[oc];
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = silu(output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow]);
            }
        }
    }
}

//////////////////CONVOLUTION FUNC //////////////////////////////////////////////////////////////////
template<typename InputType, typename KernelType, typename BiasType, typename OutputType,
         int FEATURE_MAP, int OUTPUT, int IN_CHANNEL, int KERNEL, int STRIDE, int IN_ARRAY, int PAD>

void conv(InputType input[IN_CHANNEL*IN_ARRAY*IN_ARRAY],
          KernelType kernel[FEATURE_MAP][IN_CHANNEL][KERNEL][KERNEL],
          BiasType bias[FEATURE_MAP],
          OutputType output[FEATURE_MAP*OUTPUT*OUTPUT],
          bool apply_activation = true) { // Added boolean parameter with default value true, false for no silu

    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = 0;
                for (int ic = 0; ic < IN_CHANNEL; ic++) {
                    for (int kh = 0; kh < KERNEL; kh++) {
                        for (int kw = 0; kw < KERNEL; kw++) {
                            int input_row = oh * STRIDE + kh - PAD;
                            int input_col = ow * STRIDE + kw - PAD;
                            if (input_row >= 0 && input_row < IN_ARRAY && input_col >= 0 && input_col < IN_ARRAY) {
                                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] +=
								input[ic * IN_ARRAY * IN_ARRAY + input_row * IN_ARRAY + input_col] * kernel[oc][ic][kh][kw];
                            }
                        }
                    }
                }
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] += bias[oc];
                if (apply_activation) {
                    output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = silu(output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow]);
                }
            }
        }
    }
}

//////////////////CONVOLUTION FUNC 2 //////////////////////////////////////////////////////////////////
template<typename InputType, typename KernelType, typename BiasType, typename OutputType,
         int FEATURE_MAP, int OUTPUT, int IN_CHANNEL, int KERNEL, int STRIDE, int IN_ARRAY, int PAD>

void conv2(InputType input[IN_CHANNEL*IN_ARRAY*IN_ARRAY],
           KernelType kernel[FEATURE_MAP][IN_CHANNEL][KERNEL][KERNEL],
           BiasType bias[FEATURE_MAP],
           OutputType output[FEATURE_MAP*OUTPUT*OUTPUT],
		   bool apply_activation = true) { // Added boolean parameter with default value true, false for no silu

    // Now perform convolution same hai ye
    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
//#pragma HLS PIPELINE
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = 0;
                for (int ic = 0; ic < IN_CHANNEL; ic++) {
                    for (int kh = 0; kh < KERNEL; kh++) {
                        for (int kw = 0; kw < KERNEL; kw++) {
                            int input_row = oh * STRIDE + kh - PAD;
                            int input_col = ow * STRIDE + kw - PAD;
                            if (input_row >= 0 && input_row < IN_ARRAY && input_col >= 0 && input_col < IN_ARRAY) {
                                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] +=
								input[oc * IN_CHANNEL * IN_ARRAY * IN_ARRAY + ic * IN_ARRAY * IN_ARRAY + input_row * IN_ARRAY + input_col] * kernel[oc][ic][kh][kw];
                            }
                        }
                    }
                }
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] += bias[oc];
                if (apply_activation) {
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = silu(output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow]);
                }
            }
        }
    }
}

/////////////////// CONCAT TWO LAYERS FUNC /////////////////////////////////////////////////////
template<int FEATURE_MAP, int OUTPUT>

void concat(float output[FEATURE_MAP*OUTPUT*OUTPUT], float outputtwo[FEATURE_MAP*OUTPUT*OUTPUT],
		float output_cat[2*FEATURE_MAP*OUTPUT*OUTPUT]) {
    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
                output_cat[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow];
                output_cat[FEATURE_MAP * OUTPUT * OUTPUT + oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = outputtwo[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow];
            }
        }
    }
}

/////////////////// CONCAT TWO LAYERS FUNC ADD //////////////////////////////////////////////////
template<int FEATURE_MAP, int OUTPUT>

void conadd(float output[FEATURE_MAP*OUTPUT*OUTPUT], float outputtwo[FEATURE_MAP*OUTPUT*OUTPUT],
		float output_cat[2*FEATURE_MAP*OUTPUT*OUTPUT], float outputthree[FEATURE_MAP*2*OUTPUT*OUTPUT]) {
    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
                output_cat[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow];
                output_cat[FEATURE_MAP * OUTPUT * OUTPUT + oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = outputtwo[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow];
            }
        }
    }
// ADD
	for (int oc = 0; oc < FEATURE_MAP*2; oc++) {
		for (int oh = 0; oh < OUTPUT; oh++) {
			for (int ow = 0; ow < OUTPUT; ow++) {
				output_cat[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] +=outputthree[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow];
			}
		}
	}
}

/////////////////////////////////// MAX POOLING /////////////////////////////////////////////////////
template<typename InputType, typename OutputType,
         int FEATURE_MAP, int OUTPUT>

void spp(InputType input[FEATURE_MAP*OUTPUT*OUTPUT],
        OutputType output[FEATURE_MAP*OUTPUT*OUTPUT]){

    // MAX POOLING
    for (int oc = 0; oc < FEATURE_MAP; oc++) {
        for (int oh = 0; oh < OUTPUT; oh++) {
            for (int ow = 0; ow < OUTPUT; ow++) {
                float max_val = 0.0;
                for (int kh = 0; kh < KERNEL50P; kh++) {
                    for (int kw = 0; kw < KERNEL50P; kw++) {
                        int padded_oh = oh + kh - 2;
                        int padded_ow = ow + kw - 2;
					if (padded_oh >= 0 && padded_oh < OUTPUT && padded_ow >= 0 && padded_ow < OUTPUT) {
                            max_val = std::max(max_val, input[oc * OUTPUT * OUTPUT + padded_oh * OUTPUT + padded_ow]);
                        }
                    }
                }
                output[oc * OUTPUT * OUTPUT + oh * OUTPUT + ow] = max_val;
            }
        }
    }
}

///////////////////////////////////////////////////////UPSAMPLING///////////////////////////////////////////////////
template<typename InputType, typename OutputType,
         int FEATURE_MAPS, int OUTPUTS, int FEATURE_MAP, int OUTPUT>
void us(InputType input[FEATURE_MAP*OUTPUT*OUTPUT],
        OutputType output[FEATURE_MAPS*OUTPUTS*OUTPUTS]){
// Perform asymmetric upsampling
	for (int oc = 0; oc < FEATURE_MAPS; ++oc) {
		for (int oh = 0; oh < OUTPUTS; ++oh) {
			for (int ow = 0; ow < OUTPUTS; ++ow) {
				// Calculate the corresponding position in the original tensor
				float originalX = static_cast<float>(oh) / 2;
				float originalY = static_cast<float>(ow) / 2;
				// Use floor mode for nearest-neighbor interpolation
				size_t x0 = static_cast<size_t>(originalX);
				size_t y0 = static_cast<size_t>(originalY);
				// Update the output tensor using asymmetric coordinate transformation
				output[oc * OUTPUTS * OUTPUTS + oh * OUTPUTS + ow] = input[oc * OUTPUT * OUTPUT + x0 * OUTPUT + y0];
			}
		}
	}
}

#endif
