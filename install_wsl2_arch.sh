#!/bin/bash

sudo pacman -S base-devel cmake wget curl git python python-pip exa ranger neovim
code .
./install_vscode_extensions.sh
cp ./bashrc_user ~/.bashrc
sudo cp ./bashrc_root /root/.bashrc
cd ~
mkdir -p ./.build
cd ./.build
git clone https://aur.archlinux.org/yay-bin.git
cd ./yay-bin
makepkg -si

