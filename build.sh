#!/bin/bash

# O primeiro argumento é o nome da pasta
BUILD_DIR=${1:-build}
# O segundo argumento é o tipo de build
BUILD_TYPE=${2:-RELEASE}

# Remove a pasta de build se ela existir
if [ -d "./$BUILD_DIR" ]; then
  rm -rf ./$BUILD_DIR
fi

# Cria a pasta de build
mkdir $BUILD_DIR

# Muda para a pasta de build
cd $BUILD_DIR

# Executa o cmake com o tipo de build especificado
if [ "$BUILD_TYPE" == "DEBUG" ]; then
    cmake .. -DCMAKE_BUILD_TYPE=DEBUG
elif [ "$BUILD_TYPE" == "RELEASE_TESTS" ]; then
    cmake .. -Denable_tests=ON -DCMAKE_BUILD_TYPE=RELEASE
else
    cmake .. -DCMAKE_BUILD_TYPE=RELEASE
fi


make -j$(nproc)