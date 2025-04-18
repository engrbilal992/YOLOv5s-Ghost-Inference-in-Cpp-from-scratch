//#include <iostream>
//#include <fstream>
//#include "image.h"
//#include "proto.h"
////#include <hls_stream.h>
//
//float out_tensor[1][25200][85];
//
//using namespace std;
//
//int main() {
//
//    // Calling my_top function with the image stream
//    my_top(image, out_tensor);
//
//    // Writing output tensor to file
//    ofstream outputFile("out_tensor.txt");
//    if (outputFile.is_open()) {
//        for (int channel = 0; channel < 1; ++channel) {
//            for (int i = 0; i < 25200; ++i) {
//                for (int j = 0; j < 85; ++j) {
//                    outputFile << "[" << channel << "][" << i << "][" << j << "]: " << out_tensor[channel][i][j] << endl;
//                }
//            }
//        }
//        outputFile.close();
//        cout << "out_tensor.txt saved successfully." << endl;
//    } else {
//        cout << "Unable to open the file." << endl;
//    }
//    return 0;
//}
