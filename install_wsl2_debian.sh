#!/bin/bash

sudo apt-get install build-essential curl wget python3 python3-pip git neovim ranger exa
code .
./install_vscode_extensions.sh
cp ./bashrc_user ~/.bashrc
sudo cp ./bashrc_root /root/.bashrc
