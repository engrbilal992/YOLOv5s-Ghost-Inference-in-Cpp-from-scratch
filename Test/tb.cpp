#include <iostream>
#include <algorithm>
#include "image.h"
#include "proto.h"

float out_tensor[1][25200][85];

const float conf_thres = 0.4;
const float iou_thres = 0.5;
const int max_det = 300;

struct Detection {
    float xyxy[4];
    float conf;
    int cls;
};

const char* classes[] = {
    "person", "bicycle", "car", "motorcycle", "airplane",
    "bus", "train", "truck", "boat", "traffic light",
    "fire hydrant", "stop sign", "parking meter", "bench",
    "bird", "cat", "dog", "horse", "sheep",
    "cow", "elephant", "bear", "zebra", "giraffe",
    "backpack", "umbrella", "handbag", "tie", "suitcase",
    "frisbee", "skis", "snowboard", "sports ball", "kite",
    "baseball bat", "baseball glove", "skateboard", "surfboard",
    "tennis racket", "bottle", "wine glass", "cup", "fork",
    "knife", "spoon", "bowl", "banana", "apple",
    "sandwich", "orange", "broccoli", "carrot", "hot dog",
    "pizza", "donut", "cake", "chair", "couch",
    "potted plant", "bed", "dining table", "toilet", "tv",
    "laptop", "mouse", "remote", "keyboard", "cell phone",
    "microwave", "oven", "toaster", "sink", "refrigerator",
    "book", "clock", "vase", "scissors", "teddy bear",
    "hair drier", "toothbrush"
};

void xywh2xyxy(float xyxy[4], const float xywh[4]) {
    xyxy[0] = xywh[0] - xywh[2] / 2;  // top left x
    xyxy[1] = xywh[1] - xywh[3] / 2;  // top left y
    xyxy[2] = xywh[0] + xywh[2] / 2;  // bottom right x
    xyxy[3] = xywh[1] + xywh[3] / 2;  // bottom right y
}

float calculate_iou(const float box1[4], const float box2[4]) {
    float x1 = std::max(box1[0], box2[0]);
    float y1 = std::max(box1[1], box2[1]);
    float x2 = std::min(box1[2], box2[2]);
    float y2 = std::min(box1[3], box2[3]);

    float intersection = std::max(0.0f, x2 - x1) * std::max(0.0f, y2 - y1);
    float area_box1 = (box1[2] - box1[0]) * (box1[3] - box1[1]);
    float area_box2 = (box2[2] - box2[0]) * (box2[3] - box2[1]);

    float iou = intersection / (area_box1 + area_box2 - intersection);
    return iou;
}

void apply_conf_threshold(float out_tensor[1][25200][85]) {
    for (int i = 0; i < 25200; ++i) {
        if (out_tensor[0][i][4] < conf_thres) {
            out_tensor[0][i][4] = 0.0;
        } else {
            for (int j = 5; j < 85; ++j) {
                out_tensor[0][i][j] *= out_tensor[0][i][4];
            }
        }
    }
}

void insertion_sort(Detection arr[], int n) {
    for (int i = 1; i < n; ++i) {
        Detection key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].conf < key.conf) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int linear_search(Detection arr[], int n, const float xyxy[4], float iou_thres) {
    for (int i = 0; i < n; ++i) {
        float iou = calculate_iou(arr[i].xyxy, xyxy);
        if (iou > iou_thres) {
            return i;
        }
    }
    return -1;
}

void nms(float out_tensor[1][25200][85], Detection detections[]) {
    Detection filtered_detections[25200];
    int filtered_count = 0;

    for (int i = 0; i < 25200; ++i) {
        Detection det;
        xywh2xyxy(det.xyxy, out_tensor[0][i]);
        det.conf = out_tensor[0][i][4];
        det.cls = std::distance(out_tensor[0][i] + 5, std::max_element(out_tensor[0][i] + 5, out_tensor[0][i] + 85));

        if (det.conf > 0.0) {
            filtered_detections[filtered_count++] = det;
        }
    }

    insertion_sort(filtered_detections, filtered_count);

    Detection nms_detections[max_det];
    int nms_count = 0;
    for (int i = 0; i < filtered_count; ++i) {
        int idx = linear_search(nms_detections, nms_count, filtered_detections[i].xyxy, iou_thres);
        if (idx == -1) {
            nms_detections[nms_count++] = filtered_detections[i];
        }
        if (nms_count >= max_det) {
            break;
        }
    }

    for (int i = 0; i < nms_count; ++i) {
        std::cout << "xyxy: [" << nms_detections[i].xyxy[0] << ", " << nms_detections[i].xyxy[1] << ", " << nms_detections[i].xyxy[2] << ", " << nms_detections[i].xyxy[3] << "] ";
        std::cout << "conf: " << nms_detections[i].conf << " cls: " << classes[nms_detections[i].cls] << std::endl;
    }
}

void my_nms(float out_tensor[1][25200][85],Detection detections[max_det]) {
    apply_conf_threshold(out_tensor);
    nms(out_tensor, detections);
}

Detection detections[max_det];

int main() {
	// My top function
	my_top(image, out_tensor);
    my_nms(out_tensor,detections);
    return 0;
}
