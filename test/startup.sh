#!/bin/sh

set -e

export LINEAR_ALGEBRA_CONFIG=libcblas.so 
./startup_cblas

export LINEAR_ALGEBRA_CONFIG=libf77blas.so 
./startup_f77blas
