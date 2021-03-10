# Pair Correlation Function Analysis of Fluorescence Fluctuations in Big Image Time Series using Python

**A tutorial using Python and scientific libraries to implement pair correlation function (pCF) analysis of a big time series of images from fluorescence microscopy on a personal computer.**

by [Christoph Gohlke](https://www.lfd.uci.edu/~gohlke/), Laboratory for Fluorescence Dynamics, University of California, Irvine

Updated on March 10, 2021

Presented at the [Big Data Image Processing & Analysis](http://bigdipa.ccbs.uci.edu/) BigDIPA workshops 2016, 2017, and 2018

Supported by the National Institute of Health grant numbers 1R25EB022366-01 and 2P41GM103540-31

Released under the creative commons [Attribution 4.0 International](https://creativecommons.org/licenses/by/4.0/) license

## Abstract

Spatiotemporal analysis of fluorescence fluctuations of optical microscopy measurements on living samples is a powerful tool that can provide insight into dynamic molecular processes of high biological relevance (Di Rienzo et al., 2016).

Pair correlation function (pCF) analysis of fluorescence microscopy image time series acquired using very fast cameras is one of the emerging and promising spatiotemporal techniques. However, it is computationally very expensive, and the analysis of big image data sets used to take hours or be impractical on personal computers.

In this tutorial, we use the open-source Python programming language and scientific libraries to compute the pCF analysis of a large time series of fluorescence images acquired with Selective Plane Illumination Microscopy (SPIM).

First, we implement a function to calculate the cross-correlation of two time series. We demonstrate the limitations of Python for efficient numerical computations and several ways to overcome them.

Next, we implement the pCF analysis of a small simulated image time series and optimize its speed by almost two orders of magnitude.

Finally, we use this pCF analysis function to analyze a multi-gigabyte image time series in small, overlapping chunks.

This is a tutorial on computing pair correlations in big images. Refer to the references for an introduction to the pair correlation method and how the computed pair correlations can be analyzed and visualized to study molecular flow in cells.

## Requirements

To follow this tutorial and run its code, the following prerequisites are needed:

#### Familiarity with

* pair correlation function analysis of fluorescence fluctuations (e.g. Gratton and Digman lectures)
* programming and nD-array computing (e.g. Matlab, numpy)
* signal processing, time and frequency domain

#### Minimum computer specifications

* 64-bit Windows 10, macOS, or Linux based operating system
* Core i5 CPU with 4 cores
* 8 GB RAM
* SSD drive with 50 GB free space
* NVIDIA GPU with CUDA drivers
* A modern web browser supporting WebSockets
* Disabled on-access antivirus scanning for the working and scratch directories

#### Python development environment

* CPython 3.8 64-bit with development header files and libraries
* Python packages: Jupyter, IPython, numpy, scipy, matplotlib, scikit-image, h5py, Cython, dask, numba, and CuPy (optional)
* CUDA Toolkit (optional, used for CuPy)
* A Python distutils compatible C compiler with OpenMP support: Visual Studio 2019 or gcc

#### Tutorial source code and data files

* Clone the source code from the [ipcf.ipynb](https://github.com/cgohlke/ipcf.ipynb) repository to a working directory:

      git clone https://github.com/cgohlke/ipcf.ipynb

* Extract the example data files from the [Simulation_Channel.bin.zip](https://drive.google.com/open?id=1cQZezCCvjdmBsUAju7lbhRVLLpwgA6vx) and [nih3t3-egfp_2.zip](https://drive.google.com/open?id=15KvCU6ntCdBmq6j1QwDZRRFB8uf9wh0V) archives to the ipcf.ipynb directory:

      unzip Simulation_Channel.bin.zip -d ipcf.ipynb
      unzip nih3t3-egfp_2.zip -d ipcf.ipynb

* Open the `ipcf.ipynb` notebook from within the ipcf.ipynb directory, e.g. using locally installed jupyter or a docker image, e.g.:

      jupyter-nbclassic ipcf.ipynb
      
      docker run --rm -p 8888:8888 -v ${PWD}/ipcf.ipynb:/home/jovyan/work/ipcf.ipynb jupyter/scipy-notebook:d990a62010ae
