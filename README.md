# YOLOv5s-Ghost Inference in C++ from Scratch

## Overview

This repository contains a **pure C++ implementation** of the YOLOv5s-Ghost object detection model, written entirely from scratch without using any external deep learning frameworks or image processing libraries. The project performs inference on 640x640 RGB images and outputs bounding box coordinates, confidence scores, and class labels for 80 COCO dataset classes.

This implementation faithfully reconstructs the YOLOv5s-Ghost architecture — including convolutional layers, Ghost modules, Spatial Pyramid Pooling (SPP), and Non-Maximum Suppression (NMS) — using only **C++11** and the **cmath** standard library.

---

## Features

- ⚡ **YOLOv5s-Ghost Architecture**  
  Implements a compact YOLOv5 variant with Ghost modules for reduced computational complexity.

- 💻 **Pure C++ Implementation**  
  Written entirely from scratch using standard **C++11** and `<cmath>`. No OpenCV, PyTorch, or TensorFlow used.

- 📦 **Non-Maximum Suppression (NMS)**  
  Includes confidence thresholding (`0.4`) and IoU-based NMS (`0.5`) for output filtering.

- 📚 **COCO Class Support**  
  Supports 80 object categories including: `person`, `car`, `dog`, and more.

- 🧩 **Modular Design**  
  Separates neural network inference logic (`my_top.cpp`) from detection post-processing (`tb.cpp`).

- 🧰 **Makefile Included**  
  Simplifies compilation with `g++` for CPU execution.

---

## Prerequisites

- C++11-compliant compiler (e.g., `g++`).
- `make` utility for easy compilation.
- Manually prepared image data (due to no external image libraries).

---

## Getting Started

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/engrbilal992/YOLOv5s-Ghost-Inference-in-Cpp-from-scratch.git
cd YOLOv5s-Ghost-Inference-in-Cpp-from-scratch
```

---

### 2️⃣ Prepare Dependencies

Ensure the following header files are present in your project:

```
image.h, proto.h, headers.h, hardware_modules.h
```

These hold pre-trained weights, helper functions, and data structures for the model.

---

### 3️⃣ Build the Project

Compile using the Makefile:

```bash
make
```

This will generate an `object_detection` executable.

---

### 4️⃣ Run Inference

Run the detector:

```bash
./object_detection
```

**Input:**  
Modify `tb.cpp` to load or define a 640x640 RGB image as an array.

**Output:**  
Results will print in this format:

```
xyxy: [x1, y1, x2, y2] conf: <confidence> cls: <class_name>
```

**Example:**

```
xyxy: [100.5, 150.2, 200.7, 250.9] conf: 0.85 cls: person  
xyxy: [300.1, 320.4, 400.2, 420.8] conf: 0.78 cls: car  
```

---

### 5️⃣ Clean Up

Remove compiled binaries:

```bash
make clean
```

---

## Project Structure

| File / Folder            | Purpose                                                      |
|---------------------------|--------------------------------------------------------------|
| `tb.cpp`                  | Main file: post-processing and detection output.             |
| `my_top.cpp`              | Neural network inference core.                              |
| `headers/`                | Contains weights, utility functions, and data structures.   |
| `Makefile`                | Compilation script for `g++`.                               |

---

## Customization

- **Image Loading:**  
  You can write your own function in `tb.cpp` to load or define input images.

- **Threshold Adjustment:**  
  Modify `conf_thres` and `iou_thres` in `tb.cpp` to fine-tune detection sensitivity.

- **Model Weights:**  
  Replace `kernel` and `bias` arrays in `headers.h` to use your custom-trained YOLOv5s-Ghost weights.

---

## Limitations

- Image data must be provided as an array (no OpenCV or external libraries used).
- Model weights are hardcoded in `headers.h`.
- Focused on clarity and correctness rather than maximum runtime performance.

---

## Acknowledgment

If you use this work in academic research, commercial projects, or any derivative work,  
**please give credit to the original author**:

```
Muhammad Bilal Sajid  
Email: bilalsajid695@gmail.com  
GitHub: https://github.com/engrbilal992/YOLOv5s-Ghost-Inference-in-Cpp-from-scratch  
Contact: +92 314 5844461
```

Your acknowledgment is genuinely appreciated!

---

## Credits

Inspired by the YOLOv5 architecture and GhostNet for lightweight convolutional neural networks.  
This project was created for educational and research purposes to showcase pure C++ object detection from scratch.

---
