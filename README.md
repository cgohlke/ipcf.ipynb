# Pair Correlation Function Analysis of Fluorescence Fluctuations in Big Image Time Series using Python

**A tutorial using Python and scientific libraries to implement pair correlation function (pCF) analysis of a big time series of images from fluorescence microscopy on a personal computer.**

by [Christoph Gohlke](https://www.cgohlke.com)

Updated on December 8, 2023

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

* pair correlation function analysis of fluorescence fluctuations (for example Gratton and Digman lectures)
* programming and nD-array computing (for example Matlab, numpy)
* signal processing, time and frequency domain

#### Minimum computer specifications

* 64-bit Windows 10, macOS, or Linux based operating system
* Core i5 CPU with 4 cores
* 8 GB RAM
* SSD drive with 50 GB free space
* NVIDIA GPU with CUDA drivers
* Web browser supporting WebSockets
* Disabled on-access antivirus scanning for the working and scratch directories

#### Python development environment

* CPython 3.11 64-bit with development header files and libraries
* Python packages: Jupyter, IPython, numpy, scipy, matplotlib, scikit-image, h5py, Cython, dask, numba, and CuPy (optional)
* CUDA Toolkit (optional, used for CuPy)
* A Python distutils compatible C compiler with OpenMP support: Visual Studio 2022 or gcc

#### Tutorial source code and data files

* Clone the source code from the [ipcf.ipynb](https://github.com/cgohlke/ipcf.ipynb) repository to a working directory:

      git clone https://github.com/cgohlke/ipcf.ipynb

* Download and extract the following files from the [Zenodo record](https://zenodo.org/records/10289676) to the ipcf.ipynb directory:

      Simulation_Channel.bin
      Simulation_Channel.ipcf.bin
      nih3t3-egfp_2.zip

* Open the `ipcf.ipynb` notebook from within the ipcf.ipynb directory, for example, using locally installed jupyter or a docker image:

      jupyter-lab ipcf.ipynb
      
      docker run --rm -p 8888:8888 -v ${PWD}/ipcf.ipynb:/home/jovyan/work/ipcf.ipynb jupyter/scipy-notebook:python-3.11
