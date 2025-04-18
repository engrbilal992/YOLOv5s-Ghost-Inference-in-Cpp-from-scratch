#include "headers.h"
#include "hardware_modules.h"

/*
    This is the top function having inputs of image of size 640x640 RGB
	and convolutional modules,concatenation modules,sigmoid linear unit (SILU)
	modules, Reshape, sigmoid, depth wise and point wise convs, upsampling modules,
	spatial pyramid pooling module (SPP), transposing of tensors. and extensive
	calculations, The output will be raw prediction of size 25200x85 , containing
	xywh and class confidence scores, following with class probabilites.
*/


/*
 Headers.h file contains all headers files including kernel values, parameters,
 activation file, and argument file.
*/

void my_top(float image[3][640][640], float out_tensor[1][25200][85]) {

// Layer 1 // PAD=2
	conv1<float, float, float, float, FEATURE_MAP1, OUTPUT1, IN_CHANNEL1, KERNEL1, STRIDE1, IN_ARRAY1, PAD1>(
		image, kernel1, bias1, output1);

// Layer 2 // PAD=1
	conv<float, float, float, float, FEATURE_MAP2, OUTPUT2, IN_CHANNEL2, KERNEL2, STRIDE2, IN_ARRAY2, PAD2>(
	    output1, kernel2, bias2, output2);

// Layer 3 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP3, OUTPUT3, IN_CHANNEL3, KERNEL3, STRIDE3, IN_ARRAY3, PAD3>(
	    output2, kernel3, bias3, output3);

// Concat Layer 2,3
	concat<FEATURE_MAP3,OUTPUT3>(output2, output3, output3_cat);

// Layer 4 // PAD=0
	conv<float, float, float, float, FEATURE_MAP4, OUTPUT4, IN_CHANNEL4, KERNEL4, STRIDE4, IN_ARRAY4, PAD4>(
		output3_cat, kernel4, bias4, output1);

// Layer 5 // PAD=0
	conv<float, float, float, float, FEATURE_MAP5, OUTPUT5, IN_CHANNEL5, KERNEL5, STRIDE5, IN_ARRAY5, PAD5>(
		output1, kernel5, bias5, output2);

// Layer 6 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP6, OUTPUT6, IN_CHANNEL6, KERNEL6, STRIDE6, IN_ARRAY6, PAD6>(
		output2, kernel6, bias6, output3);

// Concat Layer 5,6
	concat<FEATURE_MAP5,OUTPUT5>(output2, output3, output4);

// Layer 7 // PAD=0 // No SILU
	conv<float, float, float, float, FEATURE_MAP7, OUTPUT7, IN_CHANNEL7, KERNEL7, STRIDE7, IN_ARRAY7, PAD7>(
		output4, kernel7, bias7, output2, false);

// Layer 8 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP8, OUTPUT8, IN_CHANNEL8, KERNEL8, STRIDE8, IN_ARRAY8, PAD8>(
		output2, kernel8, bias8, output3, false);

// Concat Layer 7,8 ADD 4
	conadd<FEATURE_MAP8,OUTPUT8>(output2, output3, output4, output1);

// Layer 9 // PAD=0
	conv<float, float, float, float, FEATURE_MAP9, OUTPUT9, IN_CHANNEL9, KERNEL9, STRIDE9, IN_ARRAY9, PAD9>(
		output3_cat, kernel9, bias9, output1);

// Concat Layer 8_cat,9
	concat<FEATURE_MAP9,OUTPUT9>(output4, output1, output3);

// Layer 10 // PAD=0
	conv<float, float, float, float, FEATURE_MAP10, OUTPUT10, IN_CHANNEL10, KERNEL10, STRIDE10, IN_ARRAY10, PAD10>(
		output3, kernel10, bias10, output1);

// Layer 11 // PAD=1
	conv<float, float, float, float, FEATURE_MAP11, OUTPUT11, IN_CHANNEL11, KERNEL11, STRIDE11, IN_ARRAY11, PAD11>(
		output1, kernel11, bias11, output3);

// Layer 12 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP12, OUTPUT12, IN_CHANNEL12, KERNEL12, STRIDE12, IN_ARRAY12, PAD12>(
		output3, kernel12, bias12, output1);

// Concat Layer 11,12
	concat<FEATURE_MAP12,OUTPUT12>(output3, output1, output3_cat);

// Layer 13 // PAD=0
	conv<float, float, float, float, FEATURE_MAP13, OUTPUT13, IN_CHANNEL13, KERNEL13, STRIDE13, IN_ARRAY13, PAD13>(
		output3_cat, kernel13, bias13, output1);

// Layer 14 // PAD=0
	conv<float, float, float, float, FEATURE_MAP14, OUTPUT14, IN_CHANNEL14, KERNEL14, STRIDE14, IN_ARRAY14, PAD14>(
		output1, kernel14, bias14, output2);

// Layer 15 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP15, OUTPUT15, IN_CHANNEL15, KERNEL15, STRIDE15, IN_ARRAY15, PAD15>(
		output2, kernel15, bias15, output3);

// Concat Layer 14,15
	concat<FEATURE_MAP15,OUTPUT15>(output2, output3, output4);

// Layer 16 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP16, OUTPUT16, IN_CHANNEL16, KERNEL16, STRIDE16, IN_ARRAY16, PAD16>(
		output4, kernel16, bias16, output2, false);

// Layer 17 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP17, OUTPUT17, IN_CHANNEL17, KERNEL17, STRIDE17, IN_ARRAY17, PAD17>(
		output2, kernel17, bias17, output4, false);

// Concat Layer 16,17 ADD 13
	conadd<FEATURE_MAP17,OUTPUT17>(output2, output4, output3, output1);

// Layer 18 // PAD=0
	conv<float, float, float, float, FEATURE_MAP18, OUTPUT18, IN_CHANNEL18, KERNEL18, STRIDE18, IN_ARRAY18, PAD18>(
		output3, kernel18, bias18, output1);

// Layer 19 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP19, OUTPUT19, IN_CHANNEL19, KERNEL19, STRIDE19, IN_ARRAY19, PAD19>(
		output1, kernel19, bias19, output2);

// Concat Layer 18,19
	concat<FEATURE_MAP19,OUTPUT19>(output1, output2, output4);

// Layer 20 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP20, OUTPUT20, IN_CHANNEL20, KERNEL20, STRIDE20, IN_ARRAY20, PAD20>(
		output4, kernel20, bias20, output2, false);

// Layer 21 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP21, OUTPUT21, IN_CHANNEL21, KERNEL21, STRIDE21, IN_ARRAY21, PAD21>(
		output2, kernel21, bias21, output1, false);

// Concat Layer 20,21 ADD 17_cat
	conadd<FEATURE_MAP21,OUTPUT21>(output2, output1, output4, output3);

// Layer 22 // PAD=0
	conv<float, float, float, float, FEATURE_MAP22, OUTPUT22, IN_CHANNEL22, KERNEL22, STRIDE22, IN_ARRAY22, PAD22>(
		output3_cat, kernel22, bias22, output2);

// Concat Layer 21_cat,22
	concat<FEATURE_MAP22,OUTPUT22>(output4, output2, output1);

// Layer 23 // PAD=0
	conv<float, float, float, float, FEATURE_MAP23, OUTPUT23, IN_CHANNEL23, KERNEL23, STRIDE23, IN_ARRAY23, PAD23>(
		output1, kernel23, bias23, output4);

// Layer 24 // PAD=1
	conv<float, float, float, float, FEATURE_MAP24, OUTPUT24, IN_CHANNEL24, KERNEL24, STRIDE24, IN_ARRAY24, PAD24>(
		output4, kernel24, bias24, output2);

// Layer 25 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP25, OUTPUT25, IN_CHANNEL25, KERNEL25, STRIDE25, IN_ARRAY25, PAD25>(
		output2, kernel25, bias25, output3);

// Concat Layer 24,25
	concat<FEATURE_MAP25,OUTPUT25>(output2, output3, output1);

// Layer 26 // PAD=0
	conv<float, float, float, float, FEATURE_MAP26, OUTPUT26, IN_CHANNEL26, KERNEL26, STRIDE26, IN_ARRAY26, PAD26>(
		output1, kernel26, bias26, output2);

// Layer 27 // PAD=0
	conv<float, float, float, float, FEATURE_MAP27, OUTPUT27, IN_CHANNEL27, KERNEL27, STRIDE27, IN_ARRAY27, PAD27>(
		output2, kernel27, bias27, output3);

// Layer 28 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP28, OUTPUT28, IN_CHANNEL28, KERNEL28, STRIDE28, IN_ARRAY28, PAD28>(
		output3, kernel28, bias28, output5);

// Concat Layer 27,28
	concat<FEATURE_MAP28,OUTPUT28>(output3, output5, output3_cat);

// Layer 29 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP29, OUTPUT29, IN_CHANNEL29, KERNEL29, STRIDE29, IN_ARRAY29, PAD29>(
		output3_cat, kernel29, bias29, output3, false);

// Layer 30 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP30, OUTPUT30, IN_CHANNEL30, KERNEL30, STRIDE30, IN_ARRAY30, PAD30>(
		output3, kernel30, bias30, output5, false);

// Concat Layer 29,30 ADD 26
	conadd<FEATURE_MAP30,OUTPUT30>(output3, output5, output3_cat, output2);

// Layer 31 // PAD=0
	conv<float, float, float, float, FEATURE_MAP31, OUTPUT31, IN_CHANNEL31, KERNEL31, STRIDE31, IN_ARRAY31, PAD31>(
		output3_cat, kernel31, bias31, output2);

// Layer 32 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP32, OUTPUT32, IN_CHANNEL32, KERNEL32, STRIDE32, IN_ARRAY32, PAD32>(
		output2, kernel32, bias32, output3);

// Concat Layer 31,32
	concat<FEATURE_MAP32,OUTPUT32>(output2, output3, output5);

// Layer 33 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP33, OUTPUT33, IN_CHANNEL33, KERNEL33, STRIDE33, IN_ARRAY33, PAD33>(
		output5, kernel33, bias33, output2, false);

// Layer 34 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP34, OUTPUT34, IN_CHANNEL34, KERNEL34, STRIDE34, IN_ARRAY34, PAD34>(
		output2, kernel34, bias34, output5,false);

// Concat Layer 33,34 ADD 30_cat
	conadd<FEATURE_MAP34,OUTPUT34>(output2, output5, output3, output3_cat);

// Layer 35 // PAD=0
	conv<float, float, float, float, FEATURE_MAP35, OUTPUT35, IN_CHANNEL35, KERNEL35, STRIDE35, IN_ARRAY35, PAD35>(
		output3, kernel35, bias35, output3_cat);

// Layer 36 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP36, OUTPUT36, IN_CHANNEL36, KERNEL36, STRIDE36, IN_ARRAY36, PAD36>(
		output3_cat, kernel36, bias36, output2);

// Concat Layer 35,36
	concat<FEATURE_MAP36,OUTPUT36>(output3_cat, output2, output5);

// Layer 37 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP37, OUTPUT37, IN_CHANNEL37, KERNEL37, STRIDE37, IN_ARRAY37, PAD37>(
		output5, kernel37, bias37, output2,false);

// Layer 38 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP38, OUTPUT38, IN_CHANNEL38, KERNEL38, STRIDE38, IN_ARRAY38, PAD38>(
		output2, kernel38, bias38, output3_cat,false);

// Concat Layer 37,38 ADD 34_cat
	conadd<FEATURE_MAP38,OUTPUT38>(output2, output3_cat, output5, output3);

// Layer 39 // PAD=0
	conv<float, float, float, float, FEATURE_MAP39, OUTPUT39, IN_CHANNEL39, KERNEL39, STRIDE39, IN_ARRAY39, PAD39>(
		output1, kernel39, bias39, output2);

// Concat Layer 38_cat,39
	concat<FEATURE_MAP39,OUTPUT39>(output5, output2, output3_cat);

// Layer 40 // PAD=0
	conv<float, float, float, float, FEATURE_MAP40, OUTPUT40, IN_CHANNEL40, KERNEL40, STRIDE40, IN_ARRAY40, PAD40>(
		output3_cat, kernel40, bias40, output1);

// Layer 41 // PAD=1
	conv<float, float, float, float, FEATURE_MAP41, OUTPUT41, IN_CHANNEL41, KERNEL41, STRIDE41, IN_ARRAY41, PAD41>(
		output1, kernel41, bias41, output2);

// Layer 42 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP42, OUTPUT42, IN_CHANNEL42, KERNEL42, STRIDE42, IN_ARRAY42, PAD42>(
		output2, kernel42, bias42, output3);

// Concat Layer 41,42
	concat<FEATURE_MAP42,OUTPUT42>(output2, output3, output3_cat);

// Layer 43 // PAD=0
	conv<float, float, float, float, FEATURE_MAP43, OUTPUT43, IN_CHANNEL43, KERNEL43, STRIDE43, IN_ARRAY43, PAD43>(
		output3_cat, kernel43, bias43, output2);

// Layer 44 // PAD=0
	conv<float, float, float, float, FEATURE_MAP44, OUTPUT44, IN_CHANNEL44, KERNEL44, STRIDE44, IN_ARRAY44, PAD44>(
		output2, kernel44, bias44, output3);

// Layer 45 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP45, OUTPUT45, IN_CHANNEL45, KERNEL45, STRIDE45, IN_ARRAY45, PAD45>(
		output3, kernel45, bias45, output5);

// Concat Layer 44,45
	concat<FEATURE_MAP45,OUTPUT45>(output3, output5, output6);

// Layer 46 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP46, OUTPUT46, IN_CHANNEL46, KERNEL46, STRIDE46, IN_ARRAY46, PAD46>(
		output6, kernel46, bias46, output5,false);

// Layer 47 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP47, OUTPUT47, IN_CHANNEL47, KERNEL47, STRIDE47, IN_ARRAY47, PAD47>(
		output5, kernel47, bias47, output3,false);

// Concat Layer 46,47 ADD 43
	conadd<FEATURE_MAP47,OUTPUT47>(output5, output3, output6, output2);

// Layer 48 // PAD=0
	conv<float, float, float, float, FEATURE_MAP48, OUTPUT48, IN_CHANNEL48, KERNEL48, STRIDE48, IN_ARRAY48, PAD48>(
		output3_cat, kernel48, bias48, output2);

// Concat Layer 47_cat,48
	concat<FEATURE_MAP48,OUTPUT48>(output6, output2, output3);

// Layer 49 // PAD=0
	conv<float, float, float, float, FEATURE_MAP49, OUTPUT49, IN_CHANNEL49, KERNEL49, STRIDE49, IN_ARRAY49, PAD49>(
		output3, kernel49, bias49, output3_cat);

// Layer 50 // PAD=0
	conv<float, float, float, float, FEATURE_MAP50, OUTPUT50, IN_CHANNEL50, KERNEL50, STRIDE50, IN_ARRAY50, PAD50>(
		output3_cat, kernel50, bias50, output6);

///////////////////// POOLING LAYERS (SPP) ////////////////////////////////////////////////////////////////////////
	spp<float,float,FEATURE_MAP50,OUTPUT50>(output6,output5);
	spp<float,float,FEATURE_MAP50,OUTPUT50>(output5,output3);
	spp<float,float,FEATURE_MAP50,OUTPUT50>(output3,output2);

	// Layer 50, 50p1, p2, p3 concatenation
	for (int oc = 0; oc < FEATURE_MAP50; oc++) {
	    for (int oh = 0; oh < OUTPUT50; oh++) {
	        for (int ow = 0; ow < OUTPUT50; ow++) {
	            output3_cat[oc * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow] = output6[oc * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow];
	            output3_cat[(oc + FEATURE_MAP50) * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow] = output5[oc * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow];
	            output3_cat[(oc + 2 * FEATURE_MAP50) * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow] = output3[oc * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow];
	            output3_cat[(oc + 3 * FEATURE_MAP50) * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow] = output2[oc * OUTPUT50 * OUTPUT50 + oh * OUTPUT50 + ow];
	        }
	    }
	}

////////////////////////////////////// DONE WITH POOLING /////////////////////////////////////////////////////////
// Layer 51 // PAD=0
   	conv<float, float, float, float, FEATURE_MAP51, OUTPUT51, IN_CHANNEL51, KERNEL51, STRIDE51, IN_ARRAY51, PAD51>(
   		output3_cat, kernel51, bias51, output3);

//////////////////////////////////BACKBONE DONE //////////////////////////////////////////////////////////////////
// Layer 52 // PAD=0
	conv<float, float, float, float, FEATURE_MAP52, OUTPUT52, IN_CHANNEL52, KERNEL52, STRIDE52, IN_ARRAY52, PAD52>(
		output3, kernel52, bias52, output3_cat);

// Layer 53 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP53, OUTPUT53, IN_CHANNEL53, KERNEL53, STRIDE53, IN_ARRAY53, PAD53>(
		output3_cat, kernel53, bias53, output3);

// Concat Layer 52,53
	concat<FEATURE_MAP53,OUTPUT53>(output3_cat, output3, output6);

// Up Sampling 53_cat
	us<float, float, FEATURE_MAP53S, OUTPUT53S, FEATURE_MAP53, OUTPUT53>(output6,output3);

// Concat Layer 53S,40
	concat<FEATURE_MAP53S,OUTPUT53S>(output3, output1, output3_cat);

// Layer 54 // PAD=0
	conv<float, float, float, float, FEATURE_MAP54, OUTPUT54, IN_CHANNEL54, KERNEL54, STRIDE54, IN_ARRAY54, PAD54>(
		output3_cat, kernel54, bias54, output1);

// Layer 55 // PAD=0
	conv<float, float, float, float, FEATURE_MAP55, OUTPUT55, IN_CHANNEL55, KERNEL55, STRIDE55, IN_ARRAY55, PAD55>(
		output1, kernel55, bias55, output2);

// Layer 56 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP56, OUTPUT56, IN_CHANNEL56, KERNEL56, STRIDE56, IN_ARRAY56, PAD56>(
		output2, kernel56, bias56, output5);

// Concat Layer 55,56
	concat<FEATURE_MAP56,OUTPUT56>(output2, output5, output3);

// Layer 57 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP57, OUTPUT57, IN_CHANNEL57, KERNEL57, STRIDE57, IN_ARRAY57, PAD57>(
		output3, kernel57, bias57, output2, false);

// Layer 58 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP58, OUTPUT58, IN_CHANNEL58, KERNEL58, STRIDE58, IN_ARRAY58, PAD58>(
		output2, kernel58, bias58, output5, false);

// Concat Layer 57,58 ADD 54
	conadd<FEATURE_MAP58,OUTPUT58>(output2, output5, output3, output1);

// Layer 59 // PAD=0
	conv<float, float, float, float, FEATURE_MAP59, OUTPUT59, IN_CHANNEL59, KERNEL59, STRIDE59, IN_ARRAY59, PAD59>(
		output3_cat, kernel59, bias59, output2);

// Concat Layer 58_cat,59
	concat<FEATURE_MAP59,OUTPUT59>(output3, output2, output1);

// Layer 60 // PAD=0
	conv<float, float, float, float, FEATURE_MAP60, OUTPUT60, IN_CHANNEL60, KERNEL60, STRIDE60, IN_ARRAY60, PAD60>(
		output1, kernel60, bias60, output2);

// Layer 61 // PAD=0
	conv<float, float, float, float, FEATURE_MAP61, OUTPUT61, IN_CHANNEL61, KERNEL61, STRIDE61, IN_ARRAY61, PAD61>(
		output2, kernel61, bias61, output3_cat);

// Layer 62 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP62, OUTPUT62, IN_CHANNEL62, KERNEL62, STRIDE62, IN_ARRAY62, PAD62>(
		output3_cat, kernel62, bias62, output2);

// Concat Layer 61,62
	concat<FEATURE_MAP62,OUTPUT62>(output3_cat, output2, output3);

// Up Sampling 62_cat
	us<float, float, FEATURE_MAP62S, OUTPUT62S, FEATURE_MAP62, OUTPUT62>(output3,output3_cat);

// Concat Layer 62S,23
	concat<FEATURE_MAP62S,OUTPUT62S>(output3_cat, output4, output1);

// Layer 63 // PAD=0
	conv<float, float, float, float, FEATURE_MAP63, OUTPUT63, IN_CHANNEL63, KERNEL63, STRIDE63, IN_ARRAY63, PAD63>(
		output1, kernel63, bias63, output2);

// Layer 64 // PAD=0
	conv<float, float, float, float, FEATURE_MAP64, OUTPUT64, IN_CHANNEL64, KERNEL64, STRIDE64, IN_ARRAY64, PAD64>(
		output2, kernel64, bias64, output4);

// Layer 65 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP65, OUTPUT65, IN_CHANNEL65, KERNEL65, STRIDE65, IN_ARRAY65, PAD65>(
		output4, kernel65, bias65, output5);

// Concat Layer 64,65
	concat<FEATURE_MAP65,OUTPUT65>(output4, output5, output3_cat);

// Layer 66 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP66, OUTPUT66, IN_CHANNEL66, KERNEL66, STRIDE66, IN_ARRAY66, PAD66>(
		output3_cat, kernel66, bias66, output5,false);

// Layer 67 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP67, OUTPUT67, IN_CHANNEL67, KERNEL67, STRIDE67, IN_ARRAY67, PAD67>(
		output5, kernel67, bias67, output4,false);

// Concat Layer 66,67 ADD 63
	conadd<FEATURE_MAP67,OUTPUT67>(output5, output4, output3_cat, output2);

// Layer 68 // PAD=0
	conv<float, float, float, float, FEATURE_MAP68, OUTPUT68, IN_CHANNEL68, KERNEL68, STRIDE68, IN_ARRAY68, PAD68>(
		output1, kernel68, bias68, output2);

// Concat Layer 67_cat,68
	concat<FEATURE_MAP68,OUTPUT68>(output3_cat, output2, output1);

// Layer 69 // PAD=0
	conv<float, float, float, float, FEATURE_MAP69, OUTPUT69, IN_CHANNEL69, KERNEL69, STRIDE69, IN_ARRAY69, PAD69>(
		output1, kernel69, bias69, output3_cat);

// Layer 90 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP90, OUTPUT90, IN_CHANNEL90, KERNEL90, STRIDE90, IN_ARRAY90, PAD90>(
		output3_cat, kernel90, bias90, output1, false);

//////////////////////////////////////////////// HEAD //////////////////////////////////////////////////////////
// Head 1
	int oc = 0, oh = 0, ow = 0, ic = 0;
	for (int i = 0; i < 3 * 85 * 80 * 80; ++i) {
	    oc = i / (85 * 80 * 80);
	    oh = (i % (85 * 80 * 80)) / (80 * 80);
	    ow = ((i % (85 * 80 * 80)) % (80 * 80)) / 80;
	    ic = ((i % (85 * 80 * 80)) % (80 * 80)) % 80;

	    // Indexing into 1D tensor array
	    int flat_index = (oc * 80 * 80 * 85) + (ow * 80 * 85) + (ic * 85) + oh;
	    output4[flat_index] = sig(output1[i]);
	}
	// SPLIT and Concat (using 1D tensor array)
	for (int dim1 = 0; dim1 < 3; ++dim1) {
	    for (int dim2 = 0; dim2 < 80; ++dim2) {
	        for (int dim3 = 0; dim3 < 80; ++dim3) {
	            // Manipulate channels 0-1 for tensor1 functionality
	            for (int dim4 = 0; dim4 < 2; ++dim4) {
	                int flat_index = (dim1 * 80 * 80 * 85) + (dim2 * 80 * 85) + (dim3 * 85) + dim4;
	                // Perform operations
	                output4[flat_index] = 2 * output4[flat_index];
	                output4[flat_index] += b123[0][dim1][dim2][dim3][dim4];
	                output4[flat_index] *= 8;
	            }
	            // Manipulate channels 2-3 for tensor2 functionality
	            for (int dim4 = 2; dim4 < 4; ++dim4) {
	                int t4 = dim4 - 2;
	                int flat_index = (dim1 * 80 * 80 * 85) + (dim2 * 80 * 85) + (dim3 * 85) + dim4;
	                output4[flat_index] = 2 * output4[flat_index];
	                output4[flat_index] *= output4[flat_index];
	                output4[flat_index] *= b223[0][dim1][dim2][dim3][t4];
	            }
	        }
	    }
	}
	// Reshaping and saving the output values directly in out_tensor
	for (int i = 0; i < 3; ++i) {
	    for (int j = 0; j < 80; ++j) {
	        for (int k = 0; k < 80; ++k) {
	            for (int l = 0; l < 85; ++l) {
	                int index = i * 6400 + j * 80 + k;
	                // Map the 1D tensor array back to out_tensor
	                out_tensor[0][index][l] = output4[(i * 80 * 80 * 85) + (j * 80 * 85) + (k * 85) + l];
	            }
	        }
	    }
	}
// Layer 70 // PAD=0
	conv<float, float, float, float, FEATURE_MAP70, OUTPUT70, IN_CHANNEL70, KERNEL70, STRIDE70, IN_ARRAY70, PAD70>(
		output3_cat, kernel70, bias70, output2);

// Layer 71 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP71, OUTPUT71, IN_CHANNEL71, KERNEL71, STRIDE71, IN_ARRAY71, PAD71>(
		output2, kernel71, bias71, output4);

// Concat Layer 70,71 and 62_cat
	concat<FEATURE_MAP71,OUTPUT71>(output2, output4, output3_cat);

// Concat now with output62_cat
	for (int oc = 0; oc < 2*FEATURE_MAP71; oc++) {
		for (int oh = 0; oh < OUTPUT71; oh++) {
			for (int ow = 0; ow < OUTPUT71; ow++) {
				output3_cat[(oc + 2 * FEATURE_MAP71) * OUTPUT71 * OUTPUT71 + oh * OUTPUT71 + ow] = output3[oc * OUTPUT71 * OUTPUT71 + oh * OUTPUT71 + ow];
			}
		}
	}

// Layer 72 // PAD=0
	conv<float, float, float, float, FEATURE_MAP72, OUTPUT72, IN_CHANNEL72, KERNEL72, STRIDE72, IN_ARRAY72, PAD72>(
		output3_cat, kernel72, bias72, output2);

// Layer 73 // PAD=0
	conv<float, float, float, float, FEATURE_MAP73, OUTPUT73, IN_CHANNEL73, KERNEL73, STRIDE73, IN_ARRAY73, PAD73>(
		output2, kernel73, bias73, output3);

// Layer 74 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP74, OUTPUT74, IN_CHANNEL74, KERNEL74, STRIDE74, IN_ARRAY74, PAD74>(
		output3, kernel74, bias74, output4);

// Concat Layer 73,74
	concat<FEATURE_MAP74,OUTPUT74>(output3, output4, output1);

// Layer 75 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP75, OUTPUT75, IN_CHANNEL75, KERNEL75, STRIDE75, IN_ARRAY75, PAD75>(
		output1, kernel75, bias75, output4,false);

// Layer 76 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP76, OUTPUT76, IN_CHANNEL76, KERNEL76, STRIDE76, IN_ARRAY76, PAD76>(
		output4, kernel76, bias76, output5,false);

// Concat Layer 75,76 ADD 72
	conadd<FEATURE_MAP76,OUTPUT76>(output4, output5, output1, output2);

// Layer 77 // PAD=0
	conv<float, float, float, float, FEATURE_MAP77, OUTPUT77, IN_CHANNEL77, KERNEL77, STRIDE77, IN_ARRAY77, PAD77>(
		output3_cat, kernel77, bias77, output2);

// Concat Layer 76_cat,77
	concat<FEATURE_MAP77,OUTPUT77>(output1, output2, output3_cat);

// Layer 78 // PAD=0
	conv<float, float, float, float, FEATURE_MAP78, OUTPUT78, IN_CHANNEL78, KERNEL78, STRIDE78, IN_ARRAY78, PAD78>(
		output3_cat, kernel78, bias78, output2);

// Layer 89 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP89, OUTPUT89, IN_CHANNEL89, KERNEL89, STRIDE89, IN_ARRAY89, PAD89>(
		output2, kernel89, bias89, output1,false);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Head 2
	oc = 0, oh = 0, ow = 0, ic = 0;
	for (int i = 0; i < 3 * 85 * 40 * 40; ++i) {
	    oc = i / (85 * 40 * 40);
	    oh = (i % (85 * 40 * 40)) / (40 * 40);
	    ow = ((i % (85 * 40 * 40)) % (40 * 40)) / 40;
	    ic = ((i % (85 * 40 * 40)) % (40 * 40)) % 40;
	    // Indexing into 1D tensor array
	    int flat_index = (oc * 40 * 40 * 85) + (ow * 40 * 85) + (ic * 85) + oh;
	    output4[flat_index] = sig(output1[i]);
	}

	// SPLIT and Concat (using 1D tensor array)
	for (int dim1 = 0; dim1 < 3; ++dim1) {
	    for (int dim2 = 0; dim2 < 40; ++dim2) {
	        for (int dim3 = 0; dim3 < 40; ++dim3) {
	            // Manipulate channels 0-1 for tensor1 functionality
	            for (int dim4 = 0; dim4 < 2; ++dim4) {
	                int flat_index = (dim1 * 40 * 40 * 85) + (dim2 * 40 * 85) + (dim3 * 85) + dim4;
	                output4[flat_index] = 2 * output4[flat_index];
	                output4[flat_index] += b12[0][dim1][dim2][dim3][dim4];
	                output4[flat_index] *= 16;
	            }
	            // Manipulate channels 2-3 for tensor2 functionality
	            for (int dim4 = 2; dim4 < 4; ++dim4) {
	                int t4 = dim4 - 2;
	                int flat_index = (dim1 * 40 * 40 * 85) + (dim2 * 40 * 85) + (dim3 * 85) + dim4;
	                output4[flat_index] = 2 * output4[flat_index];
	                output4[flat_index] *= output4[flat_index];
	                output4[flat_index] *= b22[0][dim1][dim2][dim3][t4];
	            }
	        }
	    }
	}
	// Reshaping and saving the output values directly in out_tensor
	for (int i = 0; i < 3; ++i) {
	    for (int j = 0; j < 40; ++j) {
	        for (int k = 0; k < 40; ++k) {
	            for (int l = 0; l < 85; ++l) {
	                int index = i * 1600 + j * 40 + k;
	                out_tensor[0][19200 + index][l] = output4[(i * 40 * 40 * 85) + (j * 40 * 85) + (k * 85) + l];
	            }
	        }
	    }
	}
// Layer 79 // PAD=1
	conv<float, float, float, float, FEATURE_MAP79, OUTPUT79, IN_CHANNEL79, KERNEL79, STRIDE79, IN_ARRAY79, PAD79>(
		output2, kernel79, bias79, output4);

// Layer 80 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP80, OUTPUT80, IN_CHANNEL80, KERNEL80, STRIDE80, IN_ARRAY80, PAD80>(
		output4, kernel80, bias80, output5);

// Concat Layer 79,80, and 53_cat
	concat<FEATURE_MAP80,OUTPUT80>(output4, output5, output3_cat);

// and 53_cat
	for (int oc = 0; oc < 2*FEATURE_MAP80; oc++) {
		for (int oh = 0; oh < OUTPUT80; oh++) {
			for (int ow = 0; ow < OUTPUT80; ow++) {
				output3_cat[(oc + 2 * FEATURE_MAP80) * OUTPUT80 * OUTPUT80 + oh * OUTPUT80 + ow] = output6[oc * OUTPUT80 * OUTPUT80 + oh * OUTPUT80 + ow];
			}
		}
	}

// Layer 81 // PAD=0
	conv<float, float, float, float, FEATURE_MAP81, OUTPUT81, IN_CHANNEL81, KERNEL81, STRIDE81, IN_ARRAY81, PAD81>(
		output3_cat, kernel81, bias81, output6);

// Layer 82 // PAD=0
	conv<float, float, float, float, FEATURE_MAP82, OUTPUT82, IN_CHANNEL82, KERNEL82, STRIDE82, IN_ARRAY82, PAD82>(
		output6, kernel82, bias82, output2);

// Layer 83 // PAD=2
	conv2<float, float, float, float, FEATURE_MAP83, OUTPUT83, IN_CHANNEL83, KERNEL83, STRIDE83, IN_ARRAY83, PAD83>(
		output2, kernel83, bias83, output3);

// Concat Layer 82,83
	concat<FEATURE_MAP83,OUTPUT83>(output2, output3, output1);

// Layer 84 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP84, OUTPUT84, IN_CHANNEL84, KERNEL84, STRIDE84, IN_ARRAY84, PAD84>(
		output1, kernel84, bias84, output4,false);

// Layer 85 // PAD=2 // No SILU
	conv2<float, float, float, float, FEATURE_MAP85, OUTPUT85, IN_CHANNEL85, KERNEL85, STRIDE85, IN_ARRAY85, PAD85>(
		output4, kernel85, bias85, output5,false);

// Concat Layer 84,85 ADD 81
	conadd<FEATURE_MAP85,OUTPUT85>(output4, output5, output1, output6);

// Layer 86 // PAD=0
	conv<float, float, float, float, FEATURE_MAP86, OUTPUT86, IN_CHANNEL86, KERNEL86, STRIDE86, IN_ARRAY86, PAD86>(
		output3_cat, kernel86, bias86, output2);

// Concat Layer 85_cat,86
	concat<FEATURE_MAP86,OUTPUT86>(output1, output2, output3_cat);

// Layer 87 // PAD=0
	conv<float, float, float, float, FEATURE_MAP87, OUTPUT87, IN_CHANNEL87, KERNEL87, STRIDE87, IN_ARRAY87, PAD87>(
		output3_cat, kernel87, bias87, output2);

// Layer 88 // PAD=0 // NO SILU
	conv<float, float, float, float, FEATURE_MAP88, OUTPUT88, IN_CHANNEL88, KERNEL88, STRIDE88, IN_ARRAY88, PAD88>(
		output2, kernel88, bias88, output1,false);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Head 3
	oc = 0, oh = 0, ow = 0, ic = 0;
	for (int i = 0; i < 3 * 85 * 20 * 20; ++i) {
		oc = i / (85 * 20 * 20);
		oh = (i % (85 * 20 * 20)) / (20 * 20);
		ow = ((i % (85 * 20 * 20)) % (20 * 20)) / 20;
		ic = ((i % (85 * 20 * 20)) % (20 * 20)) % 20;
		// Indexing into 1D tensor array
		int flat_index = (oc * 20 * 20 * 85) + (ow * 20 * 85) + (ic * 85) + oh;
		output4[flat_index] = sig(output1[i]);
	}

	// SPLIT and Concat (using 1D tensor array)
	for (int dim1 = 0; dim1 < 3; ++dim1) {
		for (int dim2 = 0; dim2 < 20; ++dim2) {
			for (int dim3 = 0; dim3 < 20; ++dim3) {
				// Manipulate channels 0-1 for tensor1 functionality
				for (int dim4 = 0; dim4 < 2; ++dim4) {
					int flat_index = (dim1 * 20 * 20 * 85) + (dim2 * 20 * 85) + (dim3 * 85) + dim4;
					output4[flat_index] = 2 * output4[flat_index];
					output4[flat_index] += b1[0][dim1][dim2][dim3][dim4];
					output4[flat_index] *= 32;
				}
				// Manipulate channels 2-3 for tensor2 functionality
				for (int dim4 = 2; dim4 < 4; ++dim4) {
					int t4 = dim4 - 2;
					int flat_index = (dim1 * 20 * 20 * 85) + (dim2 * 20 * 85) + (dim3 * 85) + dim4;
					output4[flat_index] = 2 * output4[flat_index];
					output4[flat_index] *= output4[flat_index];
					output4[flat_index] *= b2[0][dim1][dim2][dim3][t4];
				}
			}
		}
	}
	// Reshaping and saving the output values directly in out_tensor
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 20; ++j) {
			for (int k = 0; k < 20; ++k) {
				for (int l = 0; l < 85; ++l) {
					int index = i * (20 * 20) + j * 20 + k;
					out_tensor[0][24000 + index][l] = output4[(i * 20 * 20 * 85) + (j * 20 * 85) + (k * 85) + l];
				}
			}
		}
	}
}
