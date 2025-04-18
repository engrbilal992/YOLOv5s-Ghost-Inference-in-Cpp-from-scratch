#pragma once

#define BATCH 1
//Input Image Dimensions for layer one 1x3x640x640
//////////////////////////////////////// Parameters//////////////////////////////////////////////////

#define IN_CHANNEL1 3
#define IN_ARRAY1 640

// Parameters of Kernel for first Layer

#define KERNEL1 6
#define FEATURE_MAP1 32

//Parameters for Padding And Stride of layer one
#define PAD1 2
#define STRIDE1 2

// Output Layer 1 dimensions 
#define OUTPUT1 ((IN_ARRAY1 + PAD1 + PAD1 - KERNEL1) / STRIDE1 + 1)
#define BIASES1 32

// 32x3x6x6 (weights)
// 32 (biases)
// Image_size will be 32x320x320

////////////////////////////////// layer one done ////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL2 32
#define IN_ARRAY2 320

// kernel

#define KERNEL2 3
#define FEATURE_MAP2 32

//Parameters for Padding And Stride of layer two

#define PAD2 1
#define STRIDE2 2

// Output Layer 2 dimensions
#define OUTPUT2 ((IN_ARRAY2 + PAD2 + PAD2 - KERNEL2) / STRIDE2 + 1)
#define BIASES2 32

// 32x32x3x3 (weights)
// 32 (biases)
// Image_size will be 32x160x160

////////////////////////layer two done////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL3 1
#define IN_ARRAY3 160

//kernel


#define KERNEL3 5
#define FEATURE_MAP3 32

//Parameters for Padding And Stride of layer three

#define PAD3 2
#define STRIDE3 1

//output layer 3 dimensions

#define OUTPUT3 ((IN_ARRAY3 + PAD3 + PAD3 - KERNEL3) / STRIDE3 + 1)
#define BIASES3 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x160x160

////////////////layer three done////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL4 64
#define IN_ARRAY4 160

//kernel

#define KERNEL4 1
#define FEATURE_MAP4 32

//Parameters for Padding And Stride of layer four

#define PAD4 0
#define STRIDE4 1

//output layer 4 dimensions

#define OUTPUT4 ((IN_ARRAY4 + PAD4 + PAD4 - KERNEL4) / STRIDE4 + 1)
#define BIASES4 32

// 32x64x1x1 (weights)
// 32 (biases)
// Image_size will be 32x160x160

////////////////layer Four done////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL5 32
#define IN_ARRAY5 160

//kernel

#define KERNEL5 1
#define FEATURE_MAP5 8

//Parameters for Padding And Stride of layer five

#define PAD5 0
#define STRIDE5 1

//output layer 5 dimensions

#define OUTPUT5 ((IN_ARRAY5 + PAD5 + PAD5 - KERNEL5) / STRIDE5 + 1)
#define BIASES5 8

// 8x32x1x1 (weights)
// 8 (biases)
// Image_size will be 8x160x160

////////////////layer five done////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL6 1
#define IN_ARRAY6 160

//kernel

#define KERNEL6 5
#define FEATURE_MAP6 8

//Parameters for Padding And Stride

#define PAD6 2
#define STRIDE6 1

//output layer dimensions

#define OUTPUT6 ((IN_ARRAY6 + PAD6 + PAD6 - KERNEL6) / STRIDE6 + 1)
#define BIASES6 8

// 8x1x5x5 (weights)
// 8 (biases)
// Image_size will be 8x160x160

//////////layer six done//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL7 16
#define IN_ARRAY7 160

//kernel

#define KERNEL7 1
#define FEATURE_MAP7 16

//Parameters for Padding And Stride

#define PAD7 0
#define STRIDE7 1

//output layer dimensions

#define OUTPUT7 ((IN_ARRAY7 + PAD7 + PAD7 - KERNEL7) / STRIDE7 + 1)
#define BIASES7 16

// 16x16x1x1 (weights)
// 16 (biases)
// Image_size will be 16x160x160

/////////////layer 7 done //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL8 1
#define IN_ARRAY8 160

//kernel

#define KERNEL8 5
#define FEATURE_MAP8 16

//Parameters for Padding And Stride

#define PAD8 2
#define STRIDE8 1

//output layer dimensions

#define OUTPUT8 ((IN_ARRAY8 + PAD8 + PAD8 - KERNEL8) / STRIDE8 + 1)
#define BIASES8 16

// 16x1x5x5 (weights)
// 16 (biases)
// Image_size will be 16x160x160

////////Layer 8 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL9 64
#define IN_ARRAY9 160

//kernel

#define KERNEL9 1
#define FEATURE_MAP9 32

//Parameters for Padding And Stride

#define PAD9 0
#define STRIDE9 1

//output layer dimensions

#define OUTPUT9 ((IN_ARRAY9 + PAD9 + PAD9 - KERNEL9) / STRIDE9 + 1)
#define BIASES9 32

// 32x64x1x1 (weights)
// 32 (biases)
// Image_size will be 32x160x160

////////Layer 9 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL10 64
#define IN_ARRAY10 160

//kernel

#define KERNEL10 1
#define FEATURE_MAP10 64

//Parameters for Padding And Stride

#define PAD10 0
#define STRIDE10 1

//output layer dimensions

#define OUTPUT10 ((IN_ARRAY10 + PAD10 + PAD10 - KERNEL10) / STRIDE10 + 1)
#define BIASES10 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x160x160

////////Layer 10 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL11 64
#define IN_ARRAY11 160

//kernel

#define KERNEL11 3
#define FEATURE_MAP11 64

//Parameters for Padding And Stride

#define PAD11 1
#define STRIDE11 2

//output layer dimensions

#define OUTPUT11 ((IN_ARRAY11 + PAD11 + PAD11 - KERNEL11) / STRIDE11 + 1)
#define BIASES11 64

// 64x64x3x3 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 11 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL12 1
#define IN_ARRAY12 80

//kernel

#define KERNEL12 5
#define FEATURE_MAP12 64

//Parameters for Padding And Stride

#define PAD12 2
#define STRIDE12 1

//output layer dimensions

#define OUTPUT12 ((IN_ARRAY12 + PAD12 + PAD12 - KERNEL12) / STRIDE12 + 1)
#define BIASES12 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 12 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL13 128
#define IN_ARRAY13 80

//kernel

#define KERNEL13 1
#define FEATURE_MAP13 64

//Parameters for Padding And Stride

#define PAD13 0
#define STRIDE13 1

//output layer dimensions

#define OUTPUT13 ((IN_ARRAY13 + PAD13 + PAD13 - KERNEL13) / STRIDE13 + 1)
#define BIASES13 64

// 64x128x1x1 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 13 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL14 64
#define IN_ARRAY14 80

//kernel

#define KERNEL14 1
#define FEATURE_MAP14 16

//Parameters for Padding And Stride

#define PAD14 0
#define STRIDE14 1

//output layer dimensions

#define OUTPUT14 ((IN_ARRAY14 + PAD14 + PAD14 - KERNEL14) / STRIDE14 + 1)
#define BIASES14 16

// 16x64x1x1 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 14 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL15 1
#define IN_ARRAY15 80

//kernel

#define KERNEL15 5
#define FEATURE_MAP15 16

//Parameters for Padding And Stride

#define PAD15 2
#define STRIDE15 1

//output layer dimensions

#define OUTPUT15 ((IN_ARRAY15 + PAD15 + PAD15 - KERNEL15) / STRIDE15 + 1)
#define BIASES15 16

// 16x1x5x5 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 15 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define IN_CHANNEL16 32
#define IN_ARRAY16 80

//kernel

#define KERNEL16 1
#define FEATURE_MAP16 32

//Parameters for Padding And Stride

#define PAD16 0
#define STRIDE16 1

//output layer dimensions

#define OUTPUT16 ((IN_ARRAY16 + PAD16 + PAD16 - KERNEL16) / STRIDE16 + 1)
#define BIASES16 32

// 32x32x1x1 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 16 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL17 1
#define IN_ARRAY17 80

//kernel

#define KERNEL17 5
#define FEATURE_MAP17 32

//Parameters for Padding And Stride

#define PAD17 2
#define STRIDE17 1

//output layer dimensions

#define OUTPUT17 ((IN_ARRAY17 + PAD17 + PAD17 - KERNEL17) / STRIDE17 + 1)
#define BIASES17 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 17 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL18 64
#define IN_ARRAY18 80

//kernel

#define KERNEL18 1
#define FEATURE_MAP18 16

//Parameters for Padding And Stride

#define PAD18 0
#define STRIDE18 1

//output layer dimensions

#define OUTPUT18 ((IN_ARRAY18 + PAD18 + PAD18 - KERNEL18) / STRIDE18 + 1)
#define BIASES18 16

// 16x64x1x1 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 18 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL19 1
#define IN_ARRAY19 80

//kernel

#define KERNEL19 5
#define FEATURE_MAP19 16

//Parameters for Padding And Stride

#define PAD19 2
#define STRIDE19 1

//output layer dimensions

#define OUTPUT19 ((IN_ARRAY19 + PAD19 + PAD19 - KERNEL19) / STRIDE19 + 1)
#define BIASES19 16

// 16x1x5x5 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 19 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL20 32
#define IN_ARRAY20 80

//kernel

#define KERNEL20 1
#define FEATURE_MAP20 32

//Parameters for Padding And Stride

#define PAD20 0
#define STRIDE20 1

//output layer dimensions

#define OUTPUT20 ((IN_ARRAY20 + PAD20 + PAD20 - KERNEL20) / STRIDE20 + 1)
#define BIASES20 32

// 32x32x1x1 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 20 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL21 1
#define IN_ARRAY21 80

//kernel

#define KERNEL21 5
#define FEATURE_MAP21 32

//Parameters for Padding And Stride

#define PAD21 2
#define STRIDE21 1

//output layer dimensions

#define OUTPUT21 ((IN_ARRAY21 + PAD21 + PAD21 - KERNEL21) / STRIDE21 + 1)
#define BIASES21 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 21 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL22 128
#define IN_ARRAY22 80

//kernel

#define KERNEL22 1
#define FEATURE_MAP22 64

//Parameters for Padding And Stride

#define PAD22 0
#define STRIDE22 1

//output layer dimensions

#define OUTPUT22 ((IN_ARRAY22 + PAD22 + PAD22 - KERNEL22) / STRIDE22 + 1)
#define BIASES22 64

// 64x128x1x1 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 22 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL23 128
#define IN_ARRAY23 80

//kernel

#define KERNEL23 1
#define FEATURE_MAP23 128

//Parameters for Padding And Stride

#define PAD23 0
#define STRIDE23 1

//output layer dimensions

#define OUTPUT23 ((IN_ARRAY23 + PAD23 + PAD23 - KERNEL23) / STRIDE23 + 1)
#define BIASES23 128

// 128x128x1x1 (weights)
// 128 (biases)
// Image_size will be 128x80x80

////////Layer 23 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL24 128
#define IN_ARRAY24 80

//kernel

#define KERNEL24 3
#define FEATURE_MAP24 128

//Parameters for Padding And Stride

#define PAD24 1
#define STRIDE24 2

//output layer dimensions

#define OUTPUT24 ((IN_ARRAY24 + PAD24 + PAD24 - KERNEL24) / STRIDE24 + 1)
#define BIASES24 128

// 128x128x3x3 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 24 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL25 1
#define IN_ARRAY25 40

//kernel

#define KERNEL25 5
#define FEATURE_MAP25 128

//Parameters for Padding And Stride

#define PAD25 2
#define STRIDE25 1

//output layer dimensions

#define OUTPUT25 ((IN_ARRAY25 + PAD25 + PAD25 - KERNEL25) / STRIDE25 + 1)
#define BIASES25 128

// 128x1x5x5 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 25 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL26 256
#define IN_ARRAY26 40

//kernel

#define KERNEL26 1
#define FEATURE_MAP26 128

//Parameters for Padding And Stride

#define PAD26 0
#define STRIDE26 1

//output layer dimensions

#define OUTPUT26 ((IN_ARRAY26 + PAD26 + PAD26 - KERNEL26) / STRIDE26 + 1)
#define BIASES26 128

// 128x256x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 26 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL27 128
#define IN_ARRAY27 40

//kernel

#define KERNEL27 1
#define FEATURE_MAP27 32

//Parameters for Padding And Stride

#define PAD27 0
#define STRIDE27 1

//output layer dimensions

#define OUTPUT27 ((IN_ARRAY27 + PAD27 + PAD27 - KERNEL27) / STRIDE27 + 1)
#define BIASES27 32

// 32x128x1x1 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 27 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL28 1
#define IN_ARRAY28 40

//kernel

#define KERNEL28 5
#define FEATURE_MAP28 32

//Parameters for Padding And Stride

#define PAD28 2
#define STRIDE28 1

//output layer dimensions

#define OUTPUT28 ((IN_ARRAY28 + PAD28 + PAD28 - KERNEL28) / STRIDE28 + 1)
#define BIASES28 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 28 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL29 64
#define IN_ARRAY29 40

//kernel

#define KERNEL29 1
#define FEATURE_MAP29 64

//Parameters for Padding And Stride

#define PAD29 0
#define STRIDE29 1

//output layer dimensions

#define OUTPUT29 ((IN_ARRAY29 + PAD29 + PAD29 - KERNEL29) / STRIDE29 + 1)
#define BIASES29 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 29 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL30 1
#define IN_ARRAY30 40

//kernel

#define KERNEL30 5
#define FEATURE_MAP30 64

//Parameters for Padding And Stride

#define PAD30 2
#define STRIDE30 1

//output layer dimensions

#define OUTPUT30 ((IN_ARRAY30 + PAD30 + PAD30 - KERNEL30) / STRIDE30 + 1)
#define BIASES30 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 30 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL31 128
#define IN_ARRAY31 40

//kernel

#define KERNEL31 1
#define FEATURE_MAP31 32

//Parameters for Padding And Stride

#define PAD31 0
#define STRIDE31 1

//output layer dimensions

#define OUTPUT31 ((IN_ARRAY31 + PAD31 + PAD31 - KERNEL31) / STRIDE31 + 1)
#define BIASES31 32

// 32x128x1x1 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 31 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL32 1
#define IN_ARRAY32 40

//kernel

#define KERNEL32 5
#define FEATURE_MAP32 32

//Parameters for Padding And Stride

#define PAD32 2
#define STRIDE32 1

//output layer dimensions

#define OUTPUT32 ((IN_ARRAY32 + PAD32 + PAD32 - KERNEL32) / STRIDE32 + 1)
#define BIASES32 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 32 done ////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL33 64
#define IN_ARRAY33 40

//kernel

#define KERNEL33 1
#define FEATURE_MAP33 64

//Parameters for Padding And Stride

#define PAD33 0
#define STRIDE33 1

//output layer dimensions

#define OUTPUT33 ((IN_ARRAY33 + PAD33 + PAD33 - KERNEL33) / STRIDE33 + 1)
#define BIASES33 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 33 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL34 1
#define IN_ARRAY34 40

//kernel

#define KERNEL34 5
#define FEATURE_MAP34 64

//Parameters for Padding And Stride

#define PAD34 2
#define STRIDE34 1

//output layer dimensions

#define OUTPUT34 ((IN_ARRAY34 + PAD34 + PAD34 - KERNEL34) / STRIDE34 + 1)
#define BIASES34 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 34 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL35 128
#define IN_ARRAY35 40

//kernel

#define KERNEL35 1
#define FEATURE_MAP35 32

//Parameters for Padding And Stride

#define PAD35 0
#define STRIDE35 1

//output layer dimensions

#define OUTPUT35 ((IN_ARRAY35 + PAD35 + PAD35 - KERNEL35) / STRIDE35 + 1)
#define BIASES35 32

// 32x128x1x1 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 35 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL36 1
#define IN_ARRAY36 40

//kernel

#define KERNEL36 5
#define FEATURE_MAP36 32

//Parameters for Padding And Stride

#define PAD36 2
#define STRIDE36 1

//output layer dimensions

#define OUTPUT36 ((IN_ARRAY36 + PAD36 + PAD36 - KERNEL36) / STRIDE36 + 1)
#define BIASES36 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 36 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL37 64
#define IN_ARRAY37 40

//kernel

#define KERNEL37 1
#define FEATURE_MAP37 64

//Parameters for Padding And Stride

#define PAD37 0
#define STRIDE37 1

//output layer dimensions

#define OUTPUT37 ((IN_ARRAY37 + PAD37 + PAD37 - KERNEL37) / STRIDE37 + 1)
#define BIASES37 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 37 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL38 1
#define IN_ARRAY38 40

//kernel

#define KERNEL38 5
#define FEATURE_MAP38 64

//Parameters for Padding And Stride

#define PAD38 2
#define STRIDE38 1

//output layer dimensions

#define OUTPUT38 ((IN_ARRAY38 + PAD38 + PAD38 - KERNEL38) / STRIDE38 + 1)
#define BIASES38 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 38 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL39 256
#define IN_ARRAY39 40

//kernel

#define KERNEL39 1
#define FEATURE_MAP39 128

//Parameters for Padding And Stride

#define PAD39 0
#define STRIDE39 1

//output layer dimensions

#define OUTPUT39 ((IN_ARRAY39 + PAD39 + PAD39 - KERNEL39) / STRIDE39 + 1)
#define BIASES39 128

// 128x256x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 39 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL40 256
#define IN_ARRAY40 40

//kernel

#define KERNEL40 1
#define FEATURE_MAP40 256

//Parameters for Padding And Stride

#define PAD40 0
#define STRIDE40 1

//output layer dimensions

#define OUTPUT40 ((IN_ARRAY40 + PAD40 + PAD40 - KERNEL40) / STRIDE40 + 1)
#define BIASES40 256

// 256x256x1x1 (weights)
// 256 (biases)
// Image_size will be 256x40x40

////////Layer 40 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL41 256
#define IN_ARRAY41 40

//kernel

#define KERNEL41 3
#define FEATURE_MAP41 256

//Parameters for Padding And Stride

#define PAD41 1
#define STRIDE41 2

//output layer dimensions

#define OUTPUT41 ((IN_ARRAY41 + PAD41 + PAD41 - KERNEL41) / STRIDE41 + 1)
#define BIASES41 256

// 256x256x3x3 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 41 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL42 1
#define IN_ARRAY42 20

//kernel

#define KERNEL42 5
#define FEATURE_MAP42 256

//Parameters for Padding And Stride

#define PAD42 2
#define STRIDE42 1

//output layer dimensions

#define OUTPUT42 ((IN_ARRAY42 + PAD42 + PAD42 - KERNEL42) / STRIDE42 + 1)
#define BIASES42 256

// 256x1x5x5 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 42 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL43 512
#define IN_ARRAY43 20

//kernel

#define KERNEL43 1
#define FEATURE_MAP43 256

//Parameters for Padding And Stride

#define PAD43 0
#define STRIDE43 1

//output layer dimensions

#define OUTPUT43 ((IN_ARRAY43 + PAD43 + PAD43 - KERNEL43) / STRIDE43 + 1)
#define BIASES43 256

// 256x512x1x1 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 43 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL44 256
#define IN_ARRAY44 20

//kernel

#define KERNEL44 1
#define FEATURE_MAP44 64

//Parameters for Padding And Stride

#define PAD44 0
#define STRIDE44 1

//output layer dimensions

#define OUTPUT44 ((IN_ARRAY44 + PAD44 + PAD44 - KERNEL44) / STRIDE44 + 1)
#define BIASES44 64

// 64x256x1x1 (weights)
// 64 (biases)
// Image_size will be 64x20x20

////////Layer 44 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL45 1
#define IN_ARRAY45 20

//kernel

#define KERNEL45 5
#define FEATURE_MAP45 64

//Parameters for Padding And Stride

#define PAD45 2
#define STRIDE45 1

//output layer dimensions

#define OUTPUT45 ((IN_ARRAY45 + PAD45 + PAD45 - KERNEL45) / STRIDE45 + 1)
#define BIASES45 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x20x20

////////Layer 45 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL46 128
#define IN_ARRAY46 20

//kernel

#define KERNEL46 1
#define FEATURE_MAP46 128

//Parameters for Padding And Stride

#define PAD46 0
#define STRIDE46 1

//output layer dimensions

#define OUTPUT46 ((IN_ARRAY46 + PAD46 + PAD46 - KERNEL46) / STRIDE46 + 1)
#define BIASES46 128

// 128x128x1x1 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 46 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL47 1
#define IN_ARRAY47 20

//kernel

#define KERNEL47 5
#define FEATURE_MAP47 128

//Parameters for Padding And Stride

#define PAD47 2
#define STRIDE47 1

//output layer dimensions

#define OUTPUT47 ((IN_ARRAY47 + PAD47 + PAD47 - KERNEL47) / STRIDE47 + 1)
#define BIASES47 128

// 128x1x5x5 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 47 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL48 512
#define IN_ARRAY48 20

//kernel

#define KERNEL48 1
#define FEATURE_MAP48 256

//Parameters for Padding And Stride

#define PAD48 0
#define STRIDE48 1

//output layer dimensions

#define OUTPUT48 ((IN_ARRAY48 + PAD48 + PAD48 - KERNEL48) / STRIDE48 + 1)
#define BIASES48 256

// 256x512x1x1 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 48 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL49 512
#define IN_ARRAY49 20

//kernel

#define KERNEL49 1
#define FEATURE_MAP49 512

//Parameters for Padding And Stride

#define PAD49 0
#define STRIDE49 1

//output layer dimensions

#define OUTPUT49 ((IN_ARRAY49 + PAD49 + PAD49 - KERNEL49) / STRIDE49 + 1)
#define BIASES49 512

// 512x512x1x1 (weights)
// 512 (biases)
// Image_size will be 512x20x20

////////Layer 49 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL50 512
#define IN_ARRAY50 20

//kernel

#define KERNEL50 1
#define KERNEL50P 5
#define FEATURE_MAP50 256

//Parameters for Padding And Stride

#define PAD50 0
#define PAD50P 2
#define STRIDE50 1

//output layer dimensions

#define OUTPUT50 ((IN_ARRAY50 + PAD50 + PAD50 - KERNEL50) / STRIDE50 + 1)
#define BIASES50 256

// 256x512x1x1 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 50 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL51 1024
#define IN_ARRAY51 20

//kernel

#define KERNEL51 1
#define FEATURE_MAP51 512

//Parameters for Padding And Stride

#define PAD51 0
#define STRIDE51 1

//output layer dimensions

#define OUTPUT51 ((IN_ARRAY51 + PAD51 + PAD51 - KERNEL51) / STRIDE51 + 1)
#define BIASES51 512

// 512x1024x1x1 (weights)
// 512 (biases)
// Image_size will be 512x20x20

////////Layer 51 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL52 512
#define IN_ARRAY52 20

//kernel

#define KERNEL52 1
#define FEATURE_MAP52 128

//Parameters for Padding And Stride

#define PAD52 0
#define STRIDE52 1

//output layer dimensions

#define OUTPUT52 ((IN_ARRAY52 + PAD52 + PAD52 - KERNEL52) / STRIDE52 + 1)
#define BIASES52 128

// 128x512x1x1 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 52 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL53 1
#define IN_ARRAY53 20

//kernel

#define KERNEL53 5
#define FEATURE_MAP53 128
#define FEATURE_MAP53S 256

//Parameters for Padding And Stride

#define PAD53 2
#define STRIDE53 1

//output layer dimensions

#define OUTPUT53 ((IN_ARRAY53 + PAD53 + PAD53 - KERNEL53) / STRIDE53 + 1)
#define OUTPUT53S 40
#define BIASES53 128

// 128x1x5x5 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 53 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL54 512
#define IN_ARRAY54 40

//kernel

#define KERNEL54 1
#define FEATURE_MAP54 128

//Parameters for Padding And Stride

#define PAD54 0
#define STRIDE54 1

//output layer dimensions

#define OUTPUT54 ((IN_ARRAY54 + PAD54 + PAD54 - KERNEL54) / STRIDE54 + 1)
#define BIASES54 128

// 128x512x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 54 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL55 128
#define IN_ARRAY55 40

//kernel

#define KERNEL55 1
#define FEATURE_MAP55 32

//Parameters for Padding And Stride

#define PAD55 0
#define STRIDE55 1

//output layer dimensions

#define OUTPUT55 ((IN_ARRAY55 + PAD55 + PAD55 - KERNEL55) / STRIDE55 + 1)
#define BIASES55 32

// 32x128x1x1 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 55 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL56 1
#define IN_ARRAY56 40

//kernel

#define KERNEL56 5
#define FEATURE_MAP56 32

//Parameters for Padding And Stride

#define PAD56 2
#define STRIDE56 1

//output layer dimensions

#define OUTPUT56 ((IN_ARRAY56 + PAD56 + PAD56 - KERNEL56) / STRIDE56 + 1)
#define BIASES56 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 56 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL57 64
#define IN_ARRAY57 40

//kernel

#define KERNEL57 1
#define FEATURE_MAP57 64

//Parameters for Padding And Stride

#define PAD57 0
#define STRIDE57 1

//output layer dimensions

#define OUTPUT57 ((IN_ARRAY57 + PAD57 + PAD57 - KERNEL57) / STRIDE57 + 1)
#define BIASES57 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 57 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL58 1
#define IN_ARRAY58 40

//kernel

#define KERNEL58 5
#define FEATURE_MAP58 64

//Parameters for Padding And Stride

#define PAD58 2
#define STRIDE58 1

//output layer dimensions

#define OUTPUT58 ((IN_ARRAY58 + PAD58 + PAD58 - KERNEL58) / STRIDE58 + 1)
#define BIASES58 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 58 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL59 512
#define IN_ARRAY59 40

//kernel

#define KERNEL59 1
#define FEATURE_MAP59 128

//Parameters for Padding And Stride

#define PAD59 0
#define STRIDE59 1

//output layer dimensions

#define OUTPUT59 ((IN_ARRAY59 + PAD59 + PAD59 - KERNEL59) / STRIDE59 + 1)
#define BIASES59 128

// 128x512x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 59 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL60 256
#define IN_ARRAY60 40

//kernel

#define KERNEL60 1
#define FEATURE_MAP60 256

//Parameters for Padding And Stride

#define PAD60 0
#define STRIDE60 1

//output layer dimensions

#define OUTPUT60 ((IN_ARRAY60 + PAD60 + PAD60 - KERNEL60) / STRIDE60 + 1)
#define BIASES60 256

// 256x256x1x1 (weights)
// 256 (biases)
// Image_size will be 256x40x40

////////Layer 60 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL61 256
#define IN_ARRAY61 40

//kernel

#define KERNEL61 1
#define FEATURE_MAP61 64

//Parameters for Padding And Stride

#define PAD61 0
#define STRIDE61 1

//output layer dimensions

#define OUTPUT61 ((IN_ARRAY61 + PAD61 + PAD61 - KERNEL61) / STRIDE61 + 1)
#define BIASES61 64

// 64x256x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 61 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL62 1
#define IN_ARRAY62 40

//kernel

#define KERNEL62 5
#define FEATURE_MAP62 64
#define FEATURE_MAP62S 128

//Parameters for Padding And Stride

#define PAD62 2
#define STRIDE62 1

//output layer dimensions

#define OUTPUT62 ((IN_ARRAY62 + PAD62 + PAD62 - KERNEL62) / STRIDE62 + 1)
#define OUTPUT62S 80
#define BIASES62 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 62 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL63 256
#define IN_ARRAY63 80

//kernel

#define KERNEL63 1
#define FEATURE_MAP63 64

//Parameters for Padding And Stride

#define PAD63 0
#define STRIDE63 1

//output layer dimensions

#define OUTPUT63 ((IN_ARRAY63 + PAD63 + PAD63 - KERNEL63) / STRIDE63 + 1)
#define BIASES63 64

// 64x256x1x1 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 63 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL64 64
#define IN_ARRAY64 80

//kernel

#define KERNEL64 1
#define FEATURE_MAP64 16

//Parameters for Padding And Stride

#define PAD64 0
#define STRIDE64 1

//output layer dimensions

#define OUTPUT64 ((IN_ARRAY64 + PAD64 + PAD64 - KERNEL64) / STRIDE64 + 1)
#define BIASES64 16

// 16x64x1x1 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 64 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL65 1
#define IN_ARRAY65 80

//kernel

#define KERNEL65 5
#define FEATURE_MAP65 16

//Parameters for Padding And Stride

#define PAD65 2
#define STRIDE65 1

//output layer dimensions

#define OUTPUT65 ((IN_ARRAY65 + PAD65 + PAD65 - KERNEL65) / STRIDE65 + 1)
#define BIASES65 16

// 16x1x5x5 (weights)
// 16 (biases)
// Image_size will be 16x80x80

////////Layer 65 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL66 32
#define IN_ARRAY66 80

//kernel

#define KERNEL66 1
#define FEATURE_MAP66 32

//Parameters for Padding And Stride

#define PAD66 0
#define STRIDE66 1

//output layer dimensions

#define OUTPUT66 ((IN_ARRAY66 + PAD66 + PAD66 - KERNEL66) / STRIDE66 + 1)
#define BIASES66 32

// 32x32x1x1 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 66 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL67 1
#define IN_ARRAY67 80

//kernel

#define KERNEL67 5
#define FEATURE_MAP67 32

//Parameters for Padding And Stride

#define PAD67 2
#define STRIDE67 1

//output layer dimensions

#define OUTPUT67 ((IN_ARRAY67 + PAD67 + PAD67 - KERNEL67) / STRIDE67 + 1)
#define BIASES67 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x80x80

////////Layer 67 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL68 256
#define IN_ARRAY68 80

//kernel

#define KERNEL68 1
#define FEATURE_MAP68 64

//Parameters for Padding And Stride

#define PAD68 0
#define STRIDE68 1

//output layer dimensions

#define OUTPUT68 ((IN_ARRAY68 + PAD68 + PAD68 - KERNEL68) / STRIDE68 + 1)
#define BIASES68 64

// 64x256x1x1 (weights)
// 64 (biases)
// Image_size will be 64x80x80

////////Layer 68 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL69 128
#define IN_ARRAY69 80

//kernel

#define KERNEL69 1
#define FEATURE_MAP69 128

//Parameters for Padding And Stride

#define PAD69 0
#define STRIDE69 1

//output layer dimensions

#define OUTPUT69 ((IN_ARRAY69 + PAD69 + PAD69 - KERNEL69) / STRIDE69 + 1)
#define BIASES69 128

// 128x128x1x1 (weights)
// 128 (biases)
// Image_size will be 128x80x80

////////Layer 69 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL70 128
#define IN_ARRAY70 80

//kernel

#define KERNEL70 3
#define FEATURE_MAP70 64

//Parameters for Padding And Stride

#define PAD70 1
#define STRIDE70 2

//output layer dimensions

#define OUTPUT70 ((IN_ARRAY70 + PAD70 + PAD70 - KERNEL70) / STRIDE70 + 1)
#define BIASES70 64

// 64x128x3x3 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 70 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL71 1
#define IN_ARRAY71 40

//kernel

#define KERNEL71 5
#define FEATURE_MAP71 64

//Parameters for Padding And Stride

#define PAD71 2
#define STRIDE71 1

//output layer dimensions

#define OUTPUT71 ((IN_ARRAY71 + PAD71 + PAD71 - KERNEL71) / STRIDE71 + 1)
#define BIASES71 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 71 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL72 256
#define IN_ARRAY72 40

//kernel

#define KERNEL72 1
#define FEATURE_MAP72 128

//Parameters for Padding And Stride

#define PAD72 0
#define STRIDE72 1

//output layer dimensions

#define OUTPUT72 ((IN_ARRAY72 + PAD72 + PAD72 - KERNEL72) / STRIDE72 + 1)
#define BIASES72 128

// 128x256x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 72 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL73 128
#define IN_ARRAY73 40

//kernel

#define KERNEL73 1
#define FEATURE_MAP73 32

//Parameters for Padding And Stride

#define PAD73 0
#define STRIDE73 1

//output layer dimensions

#define OUTPUT73 ((IN_ARRAY73 + PAD73 + PAD73 - KERNEL73) / STRIDE73 + 1)
#define BIASES73 32

// 32x128x1x1 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 73 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL74 1
#define IN_ARRAY74 40

//kernel

#define KERNEL74 5
#define FEATURE_MAP74 32

//Parameters for Padding And Stride

#define PAD74 2
#define STRIDE74 1

//output layer dimensions

#define OUTPUT74 ((IN_ARRAY74 + PAD74 + PAD74 - KERNEL74) / STRIDE74 + 1)
#define BIASES74 32

// 32x1x5x5 (weights)
// 32 (biases)
// Image_size will be 32x40x40

////////Layer 74 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL75 64
#define IN_ARRAY75 40

//kernel

#define KERNEL75 1
#define FEATURE_MAP75 64

//Parameters for Padding And Stride

#define PAD75 0
#define STRIDE75 1

//output layer dimensions

#define OUTPUT75 ((IN_ARRAY75 + PAD75 + PAD75 - KERNEL75) / STRIDE75 + 1)
#define BIASES75 64

// 64x64x1x1 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 75 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL76 1
#define IN_ARRAY76 40

//kernel

#define KERNEL76 5
#define FEATURE_MAP76 64

//Parameters for Padding And Stride

#define PAD76 2
#define STRIDE76 1

//output layer dimensions

#define OUTPUT76 ((IN_ARRAY76 + PAD76 + PAD76 - KERNEL76) / STRIDE76 + 1)
#define BIASES76 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x40x40

////////Layer 76 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL77 256
#define IN_ARRAY77 40

//kernel

#define KERNEL77 1
#define FEATURE_MAP77 128

//Parameters for Padding And Stride

#define PAD77 0
#define STRIDE77 1

//output layer dimensions

#define OUTPUT77 ((IN_ARRAY77 + PAD77 + PAD77 - KERNEL77) / STRIDE77 + 1)
#define BIASES77 128

// 128x256x1x1 (weights)
// 128 (biases)
// Image_size will be 128x40x40

////////Layer 77 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL78 256
#define IN_ARRAY78 40

//kernel

#define KERNEL78 1
#define FEATURE_MAP78 256

//Parameters for Padding And Stride

#define PAD78 0
#define STRIDE78 1

//output layer dimensions

#define OUTPUT78 ((IN_ARRAY78 + PAD78 + PAD78 - KERNEL78) / STRIDE78 + 1)
#define BIASES78 256

// 256x256x1x1 (weights)
// 256 (biases)
// Image_size will be 256x40x40

////////Layer 78 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL79 256
#define IN_ARRAY79 40

//kernel

#define KERNEL79 3
#define FEATURE_MAP79 128

//Parameters for Padding And Stride

#define PAD79 1
#define STRIDE79 2

//output layer dimensions

#define OUTPUT79 ((IN_ARRAY79 + PAD79 + PAD79 - KERNEL79) / STRIDE79 + 1)
#define BIASES79 128

// 128x256x3x3 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 79 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL80 1
#define IN_ARRAY80 20

//kernel

#define KERNEL80 5
#define FEATURE_MAP80 128

//Parameters for Padding And Stride

#define PAD80 2
#define STRIDE80 1

//output layer dimensions

#define OUTPUT80 ((IN_ARRAY80 + PAD80 + PAD80 - KERNEL80) / STRIDE80 + 1)
#define BIASES80 128

// 128x1x5x5 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 80 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL81 512
#define IN_ARRAY81 20

//kernel

#define KERNEL81 1
#define FEATURE_MAP81 256

//Parameters for Padding And Stride

#define PAD81 0
#define STRIDE81 1

//output layer dimensions

#define OUTPUT81 ((IN_ARRAY81 + PAD81 + PAD81 - KERNEL81) / STRIDE81 + 1)
#define BIASES81 256

// 256x512x1x1 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 81 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL82 256
#define IN_ARRAY82 20

//kernel

#define KERNEL82 1
#define FEATURE_MAP82 64

//Parameters for Padding And Stride

#define PAD82 0
#define STRIDE82 1

//output layer dimensions

#define OUTPUT82 ((IN_ARRAY82 + PAD82 + PAD82 - KERNEL82) / STRIDE82 + 1)
#define BIASES82 64

// 64x256x1x1 (weights)
// 64 (biases)
// Image_size will be 64x20x20

////////Layer 82 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL83 1
#define IN_ARRAY83 20

//kernel

#define KERNEL83 5
#define FEATURE_MAP83 64

//Parameters for Padding And Stride

#define PAD83 2
#define STRIDE83 1

//output layer dimensions

#define OUTPUT83 ((IN_ARRAY83 + PAD83 + PAD83 - KERNEL83) / STRIDE83 + 1)
#define BIASES83 64

// 64x1x5x5 (weights)
// 64 (biases)
// Image_size will be 64x20x20

////////Layer 83 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL84 128
#define IN_ARRAY84 20

//kernel

#define KERNEL84 1
#define FEATURE_MAP84 128

//Parameters for Padding And Stride

#define PAD84 0
#define STRIDE84 1

//output layer dimensions

#define OUTPUT84 ((IN_ARRAY84 + PAD84 + PAD84 - KERNEL84) / STRIDE84 + 1)
#define BIASES84 128

// 128x128x1x1 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 84 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL85 1
#define IN_ARRAY85 20

//kernel

#define KERNEL85 5
#define FEATURE_MAP85 128

//Parameters for Padding And Stride

#define PAD85 2
#define STRIDE85 1

//output layer dimensions

#define OUTPUT85 ((IN_ARRAY85 + PAD85 + PAD85 - KERNEL85) / STRIDE85 + 1)
#define BIASES85 128

// 128x1x5x5 (weights)
// 128 (biases)
// Image_size will be 128x20x20

////////Layer 85 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL86 512
#define IN_ARRAY86 20

//kernel

#define KERNEL86 1
#define FEATURE_MAP86 256

//Parameters for Padding And Stride

#define PAD86 0
#define STRIDE86 1

//output layer dimensions

#define OUTPUT86 ((IN_ARRAY86 + PAD86 + PAD86 - KERNEL86) / STRIDE86 + 1)
#define BIASES86 256

// 256x512x1x1 (weights)
// 256 (biases)
// Image_size will be 256x20x20

////////Layer 86 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL87 512
#define IN_ARRAY87 20

//kernel

#define KERNEL87 1
#define FEATURE_MAP87 512

//Parameters for Padding And Stride

#define PAD87 0
#define STRIDE87 1

//output layer dimensions

#define OUTPUT87 ((IN_ARRAY87 + PAD87 + PAD87 - KERNEL87) / STRIDE87 + 1)
#define BIASES87 512

// 512x512x1x1 (weights)
// 512 (biases)
// Image_size will be 512x20x20

////////Layer 87 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL88 512
#define IN_ARRAY88 20

//kernel

#define KERNEL88 1
#define FEATURE_MAP88 255

//Parameters for Padding And Stride

#define PAD88 0
#define STRIDE88 1

//output layer dimensions

#define OUTPUT88 ((IN_ARRAY88 + PAD88 + PAD88 - KERNEL88) / STRIDE88 + 1)
#define BIASES88 255

// 255x512x1x1 (weights)
// 255 (biases)
// Image_size will be 255x20x20

////////Layer 88 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL89 256
#define IN_ARRAY89 40

//kernel

#define KERNEL89 1
#define FEATURE_MAP89 255

//Parameters for Padding And Stride

#define PAD89 0
#define STRIDE89 1

//output layer dimensions

#define OUTPUT89 ((IN_ARRAY89 + PAD89 + PAD89 - KERNEL89) / STRIDE89 + 1)
#define BIASES89 255

// 255x256x1x1 (weights)
// 255 (biases)
// Image_size will be 255x40x40

////////Layer 89 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define IN_CHANNEL90 128
#define IN_ARRAY90 80

//kernel

#define KERNEL90 1
#define FEATURE_MAP90 255

//Parameters for Padding And Stride

#define PAD90 0
#define STRIDE90 1

//output layer dimensions

#define OUTPUT90 ((IN_ARRAY90 + PAD90 + PAD90 - KERNEL90) / STRIDE90 + 1)
#define BIASES90 255

// 255x128x1x1 (weights)
// 255 (biases)
// Image_size will be 255x80x80

////////Layer 90 done ////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

