#!/bin/bash

# Function to check if a command exists
command_exists () {
    type "$1" &> /dev/null ;
}

# Check if python3 is installed
if ! command_exists python3; then
    echo "Python3 is not installed. Installing Python3..."
    if command_exists apt-get; then
        sudo apt-get update
        sudo apt-get install -y python3
    elif command_exists yum; then
        sudo yum install -y python3
    elif command_exists brew; then
        brew install python
    else
        echo "Package manager not found. Please install Python3 manually."
        exit 1
    fi
else
    echo "Python3 is already installed."
fi

# Check if pip is installed for python3
if ! command_exists pip3; then
    echo "pip3 is not installed. Installing pip3..."
    python3 -m ensurepip --upgrade
else
    echo "pip3 is already installed."
fi

# Check if splat is installed
if ! python3 -m pip show splat64 &> /dev/null; then
    echo "splat is not installed. Installing splat..."
    python3 -m pip install git+https://github.com/ethteck/splat.git
else
    echo "splat is already installed."
fi
