# cgohlke/ipcf-notebook

# A Jupyter notebook environment without CUDA to run the image pair correlation
# function (ipcf) tutorial at https://github.com/cgohlke/ipcf.ipynb

# modified from
# https://github.com/jupyter/docker-stacks/blob/master/scipy-notebook/Dockerfile

ARG BASE_CONTAINER=jupyter/minimal-notebook:d990a62010ae
FROM $BASE_CONTAINER

LABEL maintainer="Christoph Gohlke <cgohlke@uci.edu>"

USER root

# dvipng+cm-super for latex labels
RUN apt-get update && \
    apt-get install -y --no-install-recommends dvipng cm-super && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

USER $NB_UID

# Matplotlib cache
ENV XDG_CACHE_HOME="/home/${NB_USER}/.cache/"

# Install Python 3 packages
RUN conda install --quiet --yes \
    'beautifulsoup4=4.9.*' \
    'conda-forge::blas=*=openblas' \
    'cython=0.29.*' \
    'dask=2021.2.*' \
    'h5py=3.1.*' \
    'ipywidgets=7.6.*' \
    'ipympl=0.6.*'\
    'matplotlib-base=3.3.*' \
    'numba=0.52.*' \
    'pandas=1.2.*' \
    'psutil=5.8.*' \
    'scikit-image=0.18.*' \
    'scipy=1.6.*' \
    'tifffile=2021.3.5' \
    'widgetsnbextension=3.5.*' && \
    conda clean --all -f -y && \
    fix-permissions "${CONDA_DIR}" && \
    MPLBACKEND=Agg python -c "import matplotlib.pyplot" && \
    jupyter nbextension enable --py widgetsnbextension  && \
    fix-permissions "/home/${NB_USER}"

USER $NB_USER